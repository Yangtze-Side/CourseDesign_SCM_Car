
#include "us.h"

#define US_vSound_cmPERus               (340e-4f)
#define US_CNT2Dist_Factor              (US_vSound_cmPERus / 4.0f)      // fosc = 24M, psc = 12, CNT val step is 0.5 us
#define US_Cnt2Dist_cm(cnt, dist)       {                       \
    float disttmp = ((u16)(cnt)) * US_CNT2Dist_Factor;          \
    disttmp < 40.0f ? (disttmp = 0.0f) : (disttmp -= 40.0f);    \
    (dist) = disttmp;                                           \
}

US_Data_t  US_Data = { 0.0f, 0.0f, 0.0f, 0.0f };
static u8  us_state = 0;
static u16 US_Timer_CountStart = 0;


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
            US_F_StartSignal();
            US_Timer_CountStart = US_Timer_ReadCounter();
            us_state = 1;       // state1: is measuring
        } break;

        case 1:
        {
            // If us_state is still 1 after 30 ms, the distance must greater than 5m.
            US_Data.F = US_DATA_MAX_cm;
            us_state = 2;
        }   // without a break, start next mesurement immediatly

        case 2:
        {
            US_B_StartSignal();
            US_Timer_CountStart = US_Timer_ReadCounter();
            us_state = 3;       // state3: is measuring
        } break;

        case 3:
        {
            // If us_state is still 3 after 30 ms, the distance must greater than 5m.
            US_Data.F = US_DATA_MAX_cm;
            us_state = 4;
        }   // without a break, start next mesurement immediatly

        case 4:
        {
            US_L_StartSignal();
            US_Timer_CountStart = US_Timer_ReadCounter();
            us_state = 5;       // state5: is measuring
        } break;

        case 5:
        {
            // If us_state is still 5 after 30 ms, the distance must greater than 5m.
            US_Data.F = US_DATA_MAX_cm;
            us_state = 6;
        }   // without a break, start next mesurement immediatly

        case 6:
        {
            US_R_StartSignal();
            US_Timer_CountStart = US_Timer_ReadCounter();
            us_state = 7;       // state7: is measuring
        } break;

        case 7:
        {
            // If us_state is still 7 after 30 ms, the distance must greater than 5m.
            US_Data.F = US_DATA_MAX_cm;
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
        US_Cnt2Dist_cm(US_Timer_ReadCounter() - US_Timer_CountStart, US_Data.F);
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
        US_Cnt2Dist_cm(US_Timer_ReadCounter() - US_Timer_CountStart, US_Data.B);
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
        US_Cnt2Dist_cm(US_Timer_ReadCounter() - US_Timer_CountStart, US_Data.L);
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
        US_Cnt2Dist_cm(US_Timer_ReadCounter() - US_Timer_CountStart, US_Data.R);
        us_state = 0;
    }
}
