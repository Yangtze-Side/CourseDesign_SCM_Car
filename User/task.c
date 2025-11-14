
#include "task.h"
#include "motion.h"
#include "imu_app.h"
#include "system.h"
#include "us.h"
#include "communication.h"
#include "dht11.h"

void led_task(void);

volatile u8 TaskExeFlag = 0;

typedef struct
{
    const u16 period;
    u16 count;
    void (*taskHook)(void);
} Task_t;

#define TASK_TOTAL      7

Task_t Task[TASK_TOTAL] =
{
    { 30/5, 0, US_Task_30ms },
    { 5/5, 0, IMU_Update },

    { 20/5, 0, Motor_Task },
    { 100/5, 0, Dht11_Task },
    { 60/5, 0, Comm_SendTask },
    { 5/5, 0, sys_uart_recv_task_5ms },

    { 500/5, 0, led_task },
};

void TaskExe(void)
{
    u8 i = 0;
    for (; i < TASK_TOTAL; i++)
    {
        if (++Task[i].count >= Task[i].period)
        {
            Task[i].count = 0;
            if (Task[i].taskHook != NULL)
            {
                Task[i].taskHook();
            }
        }
    }
}
