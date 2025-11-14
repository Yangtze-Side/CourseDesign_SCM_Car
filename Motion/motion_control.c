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
#include "algorithm.h"
#include "imu_app.h"
#include "us.h"
#include "communication.h"

#define G_PI_Kp                                 0.0f
#define G_PI_Ki                                 0.0f
#define G_PI_IntMax                             0.0f
#define G_PI_IntDis                             0.0f
#define G_PI_UMax                               0.0f

#define AF_PID_Kp                               0.0f
#define AF_PID_Ki                               0.0f
#define AF_PID_Kd                               0.0f
#define AF_PID_IntMax                           0.0f
#define AF_PID_IntDis                           0.0f
#define AF_PID_DeMax                            0.0f
#define AF_PID_UMax                             0.0f

static PosPI_t g_pi;            // yaw loop pi controller of gravity control mode
static PosPID_t af_pid;         // auto follow mode pid controller

/*-------------------------------------------- Functions -------------------------------------------*/

/**
 * @brief Do some initialization work.
 * 
 */
void Motion_Control_Init(void)
{
    PosPI_Init(&g_pi, G_PI_Kp, G_PI_Ki, G_PI_IntMax, G_PI_IntDis, G_PI_UMax);
    PosPID_Init(&af_pid, AF_PID_Kp, AF_PID_Ki, AF_PID_Kd, AF_PID_IntMax, AF_PID_IntDis, AF_PID_DeMax, AF_PID_UMax);
}

/**
 * @brief Set motor state (i.e. mode).
 * 
 */
void Motion_Control_SetState(void)
{
    if (Motor_IsEnabled()) Motor_SetState(Comm_MotorMode);
    else Motor_SetState(Motor_State_OFF);
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
    PosPI_Update(&g_pi, Comm_GravModeData.target_yaw - EulerAngle.yaw);

    cs->x = Comm_GravModeData.vx;
    cs->y = Comm_GravModeData.vy;
    cs->w = g_pi.u;
}

/**
 * @brief Clear data of gravity mode pi controller.
 * 
 */
void Motion_Control_GravPIClear(void)
{
    PosPI_Clear(&g_pi);
}


/*-------------------------------------------- Auto Cruise -------------------------------------------*/

#define AC_CarSpeed_Default             (50.0f)
#define AC_DistThres_cm                 (30.0f)
#define AC_Stuck_vW                     (30.0f)
#define AC_CarDir_None                  0
#define AC_CarDir_Front                 1
#define AC_CarDir_Back                  2
#define AC_CarDir_Left                  3
#define AC_CarDir_Right                 4


static u8 AC_CarDir = AC_CarDir_Front;

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
    // If the distance of current direction is defficient or the car has stucked
    if ((AC_CarDir == AC_CarDir_Front && US_Data.F < AC_DistThres_cm) ||
        (AC_CarDir == AC_CarDir_Back  && US_Data.B < AC_DistThres_cm) ||
        (AC_CarDir == AC_CarDir_Left  && US_Data.L < AC_DistThres_cm) ||
        (AC_CarDir == AC_CarDir_Right && US_Data.R < AC_DistThres_cm) ||
        (AC_CarDir == AC_CarDir_None))
    {
        // Go to direction where distance is sufficient
        if (US_Data.F > AC_DistThres_cm) Motion_Auto_Go(cs, AC_CarDir_Front);
        else if (US_Data.R > AC_DistThres_cm) Motion_Auto_Go(cs, AC_CarDir_Right);
        else if (US_Data.B > AC_DistThres_cm) Motion_Auto_Go(cs, AC_CarDir_Back);
        else if (US_Data.L > AC_DistThres_cm) Motion_Auto_Go(cs, AC_CarDir_Left);
        // Or keep stucked and self-spinning if all directions are not distance-enough
        else Motion_Auto_Go(cs, AC_CarDir_None);
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
    }
    else
    {
        cs->y = 0;
        cs->x = 0;
        cs->w = 0;
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
