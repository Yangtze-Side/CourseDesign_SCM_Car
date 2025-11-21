
#include "user_pca.h"
#include "music_app.h"

static volatile u16 CCPA0_Period = User_PCA_CCPA0_PERIOD_DEFAULT_5MS;

#define User_PCA_SetCnReload(n, v)      { CCAP##n##L = LOBYTE(v); CCAP##n##H = HIBYTE(v); }
#define User_PCA_SetC0Reload(v)         User_PCA_SetCnReload(0, (v))

/**
 * @brief PCA counter initialization.
 * @note  CLK: SYSCLK / 12 = 2M
 *        PCA INTERRUPT: Off
 *        PCA M0 INTERRUPT: On
 * 
 */
void User_PCA_Init(void)
{
    PCA_Stop();

    PCA_DisableC0();                // 失能 PCA 模块 0
    PCA_SetCnAs16BitTimerMode(0);   // 设置 PCA 模块 0 为软件定时器模式
    User_PCA_SetC0Reload(CCPA0_Period);  // 设置 PCA 模块 0 装载值
    PCA_EnableCCF0Int();            // 使能 PCA 模块 0 中断

    PCA_IdleContinue();             // 空闲模式仍然计数
    PCA_CLK_SYSCLKD12();            // PCA 时钟源选择 SYSCLK / 12
    PCA_InitCounter();              // 初始化 CH,CL 为 0
    PCA_Run();
}


/**
 * @brief Get PCA 16-bit counter value.
 * 
 * @return u16 Counter value.
 */
u16 User_PCA_GetCounter(void)
{
    return MAKEWORD(CL, CH);
}


/**
 * @brief Set CCPA0_Period
 * 
 * @param period New period
 */
void User_PCA_M0_SetPeriod(u16 period)
{
    CCPA0_Period = period;
}


/**
 * @brief Get CCPA0_Period
 * 
 * @return u16 The period of ccap module 0
 */
u16 User_PCA_M0_GetPeriod(void)
{
    return CCPA0_Period;
}


/**
 * @brief Interrupt handler of PCA module 0.
 * 
 */
void User_PCA_M0_ITHandler(void)
{
    u16 tmpreload = MAKEWORD(CL, CH) + CCPA0_Period;
    User_PCA_SetC0Reload(tmpreload);      // 设置 PCA 模块 0 装载值

    // TODO
    app_music_task();
}


/**
 * @brief Interrupt service routine of PCA.
 * 
 */
void PCA_Isr(void) interrupt PCA_VECTOR
{
    if (PCA_CheckCCF0Flag())
    {
        PCA_ClearCCF0Flag();
        User_PCA_M0_ITHandler();
    }
}
