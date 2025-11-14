
#include "us.h"

#define US_vSound_cmPERus               (340e-4f)
#define US_CNT2Dist_Factor              (US_vSound_cmPERus / 4.0f)      // fosc = 24M, psc = 12, CNT val step is 0.5 us
#define US_Cnt2Dist_cm(cnt)             ((cnt) * US_CNT2Dist_Factor)

US_Data_t US_Data = { 0, 0, 0, 0 };
static u8 us_state = 0;


/**
 * @brief Ultra sonic mesurement task, execute every 30ms.
 * 
 */
void US_Task_30ms(void)
{
    switch (us_state)
    {
        case 0:
        {
US_TASK_CASE0:
            US_Timer_Clear();
            US_F_StartSignal();
            US_Timer_Start();
            us_state = 1;       // state1: is measuring
        } break;

        case 1:
        {
            // If us_state is still 1 after 30 ms, the distance must greater than 5m.
            US_Data.F = US_DATA_MAX_cm;
            US_Timer_Stop();
            us_state = 2;
        }   // without a break, start next mesurement immediatly

        case 2:
        {
            US_Timer_Clear();
            US_B_StartSignal();
            US_Timer_Start();
            us_state = 3;       // state3: is measuring
        } break;

        case 3:
        {
            // If us_state is still 3 after 30 ms, the distance must greater than 5m.
            US_Data.F = US_DATA_MAX_cm;
            US_Timer_Stop();
            us_state = 4;
        }   // without a break, start next mesurement immediatly

        case 4:
        {
            US_Timer_Clear();
            US_L_StartSignal();
            US_Timer_Start();
            us_state = 5;       // state5: is measuring
        } break;

        case 5:
        {
            // If us_state is still 5 after 30 ms, the distance must greater than 5m.
            US_Data.F = US_DATA_MAX_cm;
            US_Timer_Stop();
            us_state = 6;
        }   // without a break, start next mesurement immediatly

        case 6:
        {
            US_Timer_Clear();
            US_R_StartSignal();
            US_Timer_Start();
            us_state = 7;       // state7: is measuring
        } break;

        case 7:
        {
            // If us_state is still 7 after 30 ms, the distance must greater than 5m.
            US_Data.F = US_DATA_MAX_cm;
            US_Timer_Stop();
            us_state = 0;
            goto US_TASK_CASE0;     // start next mesurement immediatly
        } break;

        default: break;
    }
}


/**
 * @brief US front sensor echo pin external interrupt handler.
 * 
 */
void US_F_INT_Handler(void)
{
    if (us_state == 1)
    {
        US_Timer_Stop();
        US_Data.F = US_Cnt2Dist_cm(US_Timer_ReadCounter());
        us_state = 2;
    }
}

/**
 * @brief US back sensor echo pin external interrupt handler.
 * 
 */
void US_B_INT_Handler(void)
{
    if (us_state == 3)
    {
        US_Timer_Stop();
        US_Data.B = US_Cnt2Dist_cm(US_Timer_ReadCounter());
        us_state = 4;
    }
}

/**
 * @brief US left sensor echo pin external interrupt handler.
 * 
 */
void US_L_INT_Handler(void)
{
    if (us_state == 5)
    {
        US_Timer_Stop();
        US_Data.L = US_Cnt2Dist_cm(US_Timer_ReadCounter());
        us_state = 6;
    }
}

/**
 * @brief US right sensor echo pin external interrupt handler.
 * 
 */
void US_R_INT_Handler(void)
{
    if (us_state == 7)
    {
        US_Timer_Stop();
        US_Data.R = US_Cnt2Dist_cm(US_Timer_ReadCounter());
        us_state = 0;
    }
}
