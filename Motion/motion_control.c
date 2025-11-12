
#include "motion_control.h"
#include "algorithm.h"
#include "imu_app.h"

#define G_PI_Kp                                 0.0f
#define G_PI_Ki                                 0.0f
#define G_PI_IntMax                             0.0f
#define G_PI_IntDis                             0.0f
#define G_PI_UMax                               0.0f

static PosPI_t g_pi;


/**
 * @brief Do some initialization work.
 * 
 */
void Motion_Control_Init(void)
{
    PosPI_Init(&g_pi, G_PI_Kp, G_PI_Ki, G_PI_IntMax, G_PI_IntDis, G_PI_UMax);
}


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
