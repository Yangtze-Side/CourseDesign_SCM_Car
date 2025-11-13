
#include "motion_control.h"
#include "algorithm.h"
#include "imu_app.h"
#include "us.h"

#define G_PI_Kp                                 0.0f
#define G_PI_Ki                                 0.0f
#define G_PI_IntMax                             0.0f
#define G_PI_IntDis                             0.0f
#define G_PI_UMax                               0.0f

static PosPI_t g_pi;            // yaw loop pi controller of gravity control mode


/**
 * @brief Do some initialization work.
 * 
 */
void Motion_Control_Init(void)
{
    PosPI_Init(&g_pi, G_PI_Kp, G_PI_Ki, G_PI_IntMax, G_PI_IntDis, G_PI_UMax);
}

/*-------------------------------------------- Joystick Mode -------------------------------------------*/

/**
 * @brief Set motion parameters by joystick controller mode.
 * 
 * @param cs An interface for motor.c.
 */
void Motion_Control_ByJoystick(CarSpeed_t *cs)
{
    // 仅表示思路，不是真正代码
    float target_vx, target_vy, target_vw;  // 这些 target 值来自遥控器串口接收数据解析
    cs->x = target_vx;
    cs->y = target_vy;
    cs->w = target_vw;
}

/*-------------------------------------------- Gravity Mode -------------------------------------------*/

/**
 * @brief Set motion parameters by gravity controller mode.
 * 
 * @param cs An interface for motor.c.
 */
void Motion_Control_ByGravity(CarSpeed_t *cs)
{
    // 仅表示思路，不是真正代码
    float target_yaw;
    float target_vx, target_vy, target_vw;      // 其中 vx 和 vy 和 yaw 来自串口数据解析，vw 需要计算

    PosPI_Update(&g_pi, target_yaw - EulerAngle.yaw);
    target_vw = g_pi.u;

    cs->x = target_vx;
    cs->y = target_vy;
    cs->w = target_vw;
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
