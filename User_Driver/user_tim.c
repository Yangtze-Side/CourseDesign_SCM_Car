
#include "user_tim.h"


/**
 * @brief Set 16-bit auto-reload mode timer's ARR frequency.
 * 
 * @param TIMx The timer
 * @param arr  The arr frequency
 */
void User_TIM_SetARR(u8 TIMx, u16 arr)
{
    switch (TIMx)
    {
        case TIM1: TIMER1_SetReload16(arr); break;
        case TIM3: TIMER3_SetReload16(arr); break;
        case TIM4: TIMER3_SetReload16(arr); break;

        default: break;
    }
}


/**
 * @brief Enable or disable TIMx's clock output function.
 * 
 * @param TIMx The timer
 * @param cmd  ENABLE or DISABLE
 */
void User_TIM_CLKOCmd(u8 TIMx, BOOL cmd)
{
    switch (TIMx)
    {
        case TIM1: cmd ? TIMER1_EnableCLKO() : (TIMER1_DisableCLKO(), (TIM1_CLKO_PIN = 1)); break;
        case TIM3: cmd ? TIMER3_EnableCLKO() : (TIMER3_DisableCLKO(), (TIM3_CLKO_PIN = 1)); break;
        case TIM4: cmd ? TIMER4_EnableCLKO() : (TIMER4_DisableCLKO(), (TIM4_CLKO_PIN = 1)); break;

        default: break;
    }
}
