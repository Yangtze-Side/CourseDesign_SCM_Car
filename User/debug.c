
#include "debug.h"
#include "system.h"
#include "imu_app.h"
#include "us.h"

void Debug_Log_Task(void)
{
    // user_printf("[IMU] Pitch: %.6f, Roll: %.6f, Yaw: %.6f\r\n", EulerAngle.pitch, EulerAngle.roll, EulerAngle.yaw);
    // P10 ^= 1;
    // user_printf("F: %f, B: %f, L: %f, R: %f\r\n", US_Data.F, US_Data.B, US_Data.L, US_Data.R);
}
