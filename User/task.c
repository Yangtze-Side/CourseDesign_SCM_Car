
#include "task.h"
#include "motion.h"
#include "imu_app.h"
#include "system.h"
#include "us.h"
#include "communication.h"
#include "dht11.h"
#include "key_SLD.h"
#include "led.h"
#include "debug.h"

volatile BOOL TaskExeFlag = 0;

typedef struct
{
    const u16 period;
    u16 count;
    const void (*taskHook)(void);
} Task_t;

#define TASK_TOTAL      7

Task_t Task[TASK_TOTAL] =
{
    { 30/5, 0, US_Task_30ms },
    { 20/5, 0, KeySLD_Task },
    { 5/5, 0, IMU_Update },

    { 20/5, 0, Motor_Task },
    // { 20/5, 0, Dht11_Task },     // 安排在中断里执行
    // { 500/5, 0, Debug_Log_Task },
    { 60/5, 0, Comm_SendTask },
    { 5/5, 0, sys_uart_recv_task_5ms },

    { 25/5, 0, led_task_25ms },
};

/**
 * @brief 任务调度器通过函数指针调用任务函数。
 *        当 Keil 编译器的优化等级 >= 2 (Data overlaying) 时，编译器会根据所有函数之间的调用关系生成一个
 *        树结构，并可能将编译器认为的没有相互调用关系的函数，其内部变量分时复用在同一个物理地址上。这是为
 *        了应对 8051 内核单片机内存小的劣势而产生的技术。而函数指针这种间接调用函数的方式不能被编译器识别，
 *        这就导致编译器错误地将可能同时需要使用的变量放在了同一个内存地址，产生冲突。
 * 
 */
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

    // 假装调用一下这些函数
    if (i > TASK_TOTAL)
    {
        US_Task_30ms();
        KeySLD_Task();
        IMU_Update();
        Motor_Task();
        // Dht11_Task();
        Debug_Log_Task();
        Comm_SendTask();
        sys_uart_recv_task_5ms();
        led_task_25ms();
    }
}
