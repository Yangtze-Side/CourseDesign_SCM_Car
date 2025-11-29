/**
 * @file motion_control.c
 * @author Zach (zachary-yue@qq.com)
 * 
 * @brief These control functions are exposed to external data, such as uart data,
 *        while using motor.h APIs to set motor behavior.
 * 
 * @version 0.1
 * @date 2025-11-13
 * 
 */
#include "motion_control.h"
#include "imu_app.h"
#include "us.h"
#include "communication.h"
#include "music_header.h"
#include "led.h"


/*------------------------------------------ User Determine -----------------------------------------*/

#define AC_Stuck_CALLBACK()                         app_music_start(4)
#define AC_OutOfStuck_CALLBACK()                    app_music_stop()

/*--------------------------------------- Contants & Variables --------------------------------------*/

#define G_PID_Kp                                2.40f
#define G_PID_Ki                                0.05f
#define G_PID_Kd                                4.2f
#define G_PID_IntMax                            50.0f
#define G_PID_IntDis                            5.0f
#define G_PID_DeMax                             20.0f
#define G_PID_UMax                              100.0f

#define AF_PID_Kp                               5.3f
#define AF_PID_Ki                               0.050f
#define AF_PID_Kd                               4.20f
#define AF_PID_IntMax                           50.0f
#define AF_PID_IntDis                           5.0f
#define AF_PID_DeMax                            30.0f
#define AF_PID_UMax                             100.0f

PosPID_t g_pid;            // yaw loop pid controller of gravity control mode
PosPID_t enc_pid;          // yaw loop pid controller of encoder control mode
PosPID_t af_pid;           // auto follow mode pid controller
static BOOL Motion_AC_Stuck = FALSE;
static BOOL Motion_AF_Alone = FALSE;

/*-------------------------------------------- Functions -------------------------------------------*/

/**
 * @brief Do some initialization work.
 * 
 */
void Motion_Control_Init(void)
{
    PosPID_Init(&g_pid, G_PID_Kp, G_PID_Ki, G_PID_Kd, G_PID_IntMax, G_PID_IntDis, G_PID_DeMax, G_PID_UMax);
    PosPID_Init(&enc_pid, G_PID_Kp, G_PID_Ki, G_PID_Kd, G_PID_IntMax, G_PID_IntDis, G_PID_DeMax, G_PID_UMax);
    PosPID_Init(&af_pid, AF_PID_Kp, AF_PID_Ki, AF_PID_Kd, AF_PID_IntMax, AF_PID_IntDis, AF_PID_DeMax, AF_PID_UMax);
}

/**
 * @brief Set motor state (i.e. mode).
 * 
 */
void Motion_Control_SetState(void)
{
    static u8 Last_State = Motor_State_OFF;
    u8 Now_State;
    
    if (Motor_IsEnabled()) Motor_SetState(Comm_MotorMode);
    else Motor_SetState(Motor_State_OFF);
    
    Now_State = Motor_GetState();
    if (Now_State != Last_State)
    {
        switch (Now_State)
        {
            case Motor_State_GRAVITY: Motion_Control_GravPIDClear(); break;
            case Motor_State_ENCODER: Motion_Control_EncoderPIDClear(); break;
            case Motor_State_AUTOFOLLOW: Motion_Control_AFPIDClear(); break;
        }
        if (Now_State != Motor_State_OFF) LED1_Flash();
    }
    Last_State = Now_State;
}

/*-------------------------------------------- Joystick Mode -------------------------------------------*/

/**
 * @brief Set motion parameters by joystick controller mode.
 * 
 * @param cs An interface for motor.c.
 */
void Motion_Control_ByJoystick(CarSpeed_t *cs)
{
    cs->x = Comm_JoysModeData.vx;
    cs->y = Comm_JoysModeData.vy;
    cs->w = Comm_JoysModeData.vw;
}

/*-------------------------------------------- Gravity Mode -------------------------------------------*/

/**
 * @brief Set motion parameters by gravity controller mode.
 * 
 * @param cs An interface for motor.c.
 */
void Motion_Control_ByGravity(CarSpeed_t *cs)
{
    PosPID_Update(&g_pid, Comm_GravModeData.target_yaw - EulerAngle.yaw);

    cs->x = Comm_GravModeData.vx;
    cs->y = Comm_GravModeData.vy;
    cs->w = g_pid.u;
}

/**
 * @brief Clear data of gravity mode pid controller.
 * 
 */
void Motion_Control_GravPIDClear(void)
{
    PosPID_Clear(&g_pid);
}

/*-------------------------------------------- Encoder Control -------------------------------------------*/

void Motion_Control_ByEncoder(CarSpeed_t *cs)
{
    PosPID_Update(&enc_pid, Comm_EncoderModeData.target_yaw - EulerAngle.yaw);

    cs->x = Comm_EncoderModeData.vx;
    cs->y = Comm_EncoderModeData.vy;
    cs->w = enc_pid.u;
}

/**
 * @brief Clear data of encoder mode pid controller.
 * 
 */
void Motion_Control_EncoderPIDClear(void)
{
    PosPID_Clear(&enc_pid);
}

/*-------------------------------------------- Auto Cruise -------------------------------------------*/

#define AC_CarSpeed_Default             (50.0f)
#define AC_DistThres1_cm                (30.0f)
#define AC_DistThres2_cm                (40.0f)
#define AC_Stuck_vW                     (30.0f)
#define AC_CarDir_None                  0
#define AC_CarDir_Front                 1
#define AC_CarDir_Right                 2
#define AC_CarDir_Back                  3
#define AC_CarDir_Left                  4
#define AC_IncInqIndex(idx)             (++(idx) > 3 ? (idx) = 0 : (idx))


static u8 AC_CarDir = AC_CarDir_Front;
void Motion_Control_AC_SingWhenStuck(void);


static void Motion_Auto_Go(CarSpeed_t *cs, u8 dir)
{
    AC_CarDir = dir;
    switch (dir)
    {
        case AC_CarDir_Front: { cs->x = 0; cs->y =  AC_CarSpeed_Default; cs->w = 0; } break;
        case AC_CarDir_Back:  { cs->x = 0; cs->y = -AC_CarSpeed_Default; cs->w = 0; } break;
        case AC_CarDir_Left:  { cs->x = -AC_CarSpeed_Default; cs->y = 0; cs->w = 0; } break;
        case AC_CarDir_Right: { cs->x =  AC_CarSpeed_Default; cs->y = 0; cs->w = 0; } break;
        case AC_CarDir_None:  { cs->x = 0; cs->y = 0; cs->w = AC_Stuck_vW; } break;
        default: break;
    }
}

/**
 * @brief Auto cruise mode.
 * 
 * @param cs An interface for motor.c.
 */
void Motion_Control_AutoCruise(CarSpeed_t *cs)
{
#if 1
    u8 inq_index = 0xff;
    u8 inq_total = 3;
    switch (AC_CarDir)
    {
        case AC_CarDir_Front:
        {
            if (US_Data.F < AC_DistThres1_cm) inq_index = 1;
        } break;
        case AC_CarDir_Right:
        {
            if (US_Data.R < AC_DistThres1_cm) inq_index = 2;
        } break;
        case AC_CarDir_Back:
        {
            if (US_Data.B < AC_DistThres1_cm) inq_index = 3;
        } break;
        case AC_CarDir_Left:
        {
            if (US_Data.L < AC_DistThres1_cm) inq_index = 0;
        } break;
        case AC_CarDir_None:
        {
            inq_index = 0;
            inq_total = 4;
        } break;
    }
    if (inq_index != 0xff)
    {
        u8 new_dir = 0;
        BOOL dir_exist = FALSE;
        u8 i = 0;
        float dist[4];
        dist[0] = US_Data.F;
        dist[1] = US_Data.R;
        dist[2] = US_Data.B;
        dist[3] = US_Data.L;
        for (; i < inq_total; AC_IncInqIndex(inq_index), i++)
        {
            if (dist[inq_index] > AC_DistThres2_cm)
            {
                new_dir = inq_index + 1;
                dir_exist = TRUE;
                break;
            }
        }
        Motion_Auto_Go(cs, new_dir);
        Motion_AC_Stuck = dir_exist;
    }
#else
    // If the distance of current direction is defficient or the car has stucked
    if ((AC_CarDir == AC_CarDir_Front && US_Data.F < AC_DistThres1_cm) ||
        (AC_CarDir == AC_CarDir_Back  && US_Data.B < AC_DistThres1_cm) ||
        (AC_CarDir == AC_CarDir_Left  && US_Data.L < AC_DistThres1_cm) ||
        (AC_CarDir == AC_CarDir_Right && US_Data.R < AC_DistThres1_cm) ||
        (AC_CarDir == AC_CarDir_None))
    {
        // Go to direction where distance is sufficient
        if (US_Data.F > AC_DistThres2_cm)
        {
            Motion_Auto_Go(cs, AC_CarDir_Front);
            Motion_AC_Stuck = FALSE;
        }
        else if (US_Data.R > AC_DistThres2_cm)
        {
            Motion_Auto_Go(cs, AC_CarDir_Right);
            Motion_AC_Stuck = FALSE;
        }
        else if (US_Data.B > AC_DistThres2_cm)
        {
            Motion_Auto_Go(cs, AC_CarDir_Back);
            Motion_AC_Stuck = FALSE;
        }
        else if (US_Data.L > AC_DistThres2_cm)
        {
            Motion_Auto_Go(cs, AC_CarDir_Left);
            Motion_AC_Stuck = FALSE;
        }
        // Or keep stucked and self-spinning if all directions are not distance-enough
        else
        {
            Motion_Auto_Go(cs, AC_CarDir_None);
            Motion_AC_Stuck = TRUE;
        }
    }
    else
    {
        Motion_Auto_Go(cs, AC_CarDir);
        Motion_AC_Stuck = FALSE;
    }
    #endif
    Motion_Control_AC_SingWhenStuck();
}

/**
 * @brief Get status that if the car has stucked.
 * 
 * @return BOOL If the car has stucked.
 */
BOOL Motion_IsACStucked(void)
{
    return Motion_AC_Stuck;
}

#define Motion_Control_AC_StuckCnt_THRES        20
#define Motion_Control_AC_OutOfStuckCnt_THRES   20

/**
 * @brief 四面楚歌时唱歌。
 * @note  当四面楚歌持续一段时间以后唱歌，解除一段时间后停止。
 * 
 */
void Motion_Control_AC_SingWhenStuck(void)
{
    static u8 stuck_cnt = 0;
    static u8 out_of_stuck_cnt = 0;

    if (Motion_AC_Stuck)
    {
        out_of_stuck_cnt = 0;
        if (++stuck_cnt >= Motion_Control_AC_StuckCnt_THRES)
        {
            stuck_cnt = 0;
            AC_Stuck_CALLBACK();
        }
    }
    else
    {
        stuck_cnt = 0;
        if (++out_of_stuck_cnt >= Motion_Control_AC_OutOfStuckCnt_THRES)
        {
            out_of_stuck_cnt = 0;
            AC_OutOfStuck_CALLBACK();
        }
    }
}


/*-------------------------------------------- Auto Follow -------------------------------------------*/

#define AF_EffectiveDist_cm                 100.0f
#define AF_CenterDist_cm                    30.0f

void Motion_Control_AutoFollow(CarSpeed_t *cs)
{
    // Effective only when distance of front sensor is in [0, AF_EffectiveDist_cm]
    // And will keep the object from AF_CenterDist_cm
    if (US_Data.F < AF_EffectiveDist_cm)
    {
        PosPID_Update(&af_pid, US_Data.F - AF_CenterDist_cm);
        cs->y = af_pid.u;
        cs->x = 0;
        cs->w = 0;
        Motion_AF_Alone = FALSE;
    }
    else
    {
        cs->y = 0;
        cs->x = 0;
        cs->w = 0;
        Motion_AF_Alone = TRUE;
    }
}

/**
 * @brief Clear data of auto follow mode pid controller.
 * 
 */
void Motion_Control_AFPIDClear(void)
{
    PosPID_Clear(&af_pid);
}

/**
 * @brief Get the status that if the car is alone.
 * 
 * @return BOOL If the car is alone
 */
BOOL Motion_IsAFAlone(void)
{
    return Motion_AF_Alone;
}
