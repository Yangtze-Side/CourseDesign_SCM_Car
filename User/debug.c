
#include "debug.h"
#include "system.h"
#include "imu_app.h"

void Debug_Log_Task(void)
{
    // user_printf("[IMU] Pitch: %d, Roll: %d, Yaw: %d\r\n", (int)EulerAngle.pitch, (int)EulerAngle.roll, (int)(EulerAngle.yaw));
    P10 ^= 1;
}
