
#include "task.h"
#include "motion.h"

void led_task(void);

volatile u8 TaskExeFlag = 0;

typedef struct
{
    const u16 period;
    u16 count;
    void (*taskHook)(void);
} Task_t;

#define TASK_TOTAL      2

Task_t Task[TASK_TOTAL] =
{
    { 20/5, 0, Motor_Task },
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
