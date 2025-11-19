
#include "debug.h"
#include "system.h"
#include "imu_app.h"

void Debug_Log_Task(void)
{
    user_printf("[IMU] Pitch: %.6f, Roll: %.6f, Yaw: %.6f\r\n", EulerAngle.pitch, EulerAngle.roll, EulerAngle.yaw);
    // P10 ^= 1;
}
