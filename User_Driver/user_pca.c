
#include "user_pca.h"
#include "music_app.h"
#include "dht11.h"

/*------------------------------------------- Library -------------------------------------------*/

static volatile u16 CCPA0_Period = User_PCA_CCPA0_PERIOD_DEFAULT_5MS;

#define User_PCA_SetCnReload(n, v)      { CCAP##n##L = LOBYTE(v); CCAP##n##H = HIBYTE(v); }
#define User_PCA_SetC0Reload(v)         User_PCA_SetCnReload(0, (v))
#define User_PCA_SetC1Reload(v)         User_PCA_SetCnReload(1, (v))

/**
 * @brief PCA counter initialization.
 * @note  CLK: SYSCLK / 12 = 2M
 *        PCA CNT INTERRUPT: Off
 *        PCA M0 INTERRUPT: On
 *        PCA M1 INTERRUPT: On T=5ms
 * 
 */
void User_PCA_Init(void)
{
    PCA_Stop();

    PCA_DisableCn(0);                // 失能 PCA 模块 0
    PCA_SetCnAs16BitTimerMode(0);   // 设置 PCA 模块 0 为软件定时器模式
    User_PCA_SetC0Reload(CCPA0_Period);  // 设置 PCA 模块 0 装载值
    PCA_EnableCCF0Int();            // 使能 PCA 模块 0 中断

    PCA_DisableCn(1);                // 失能 PCA 模块 1
    PCA_SetCnAs16BitTimerMode(1);   // 设置 PCA 模块 1 为软件定时器模式
    User_PCA_SetC1Reload(User_PCA_CCPA0_PERIOD_DEFAULT_5MS);  // 设置 PCA 模块 1 装载值
    PCA_EnableCCF1Int();            // 使能 PCA 模块 1 中断

    PCA_IdleContinue();             // 空闲模式仍然计数
    PCA_SetIntPriority(0);          // 中断优先级为低优先级
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


/*----------------------------------------------------------------------------------------------*/

/**
 * @brief Interrupt handler of PCA module 0.
 * 
 */
void User_PCA_M1_ITHandler(void)
{
    static u8 dht11_cnt = 0;
    ++dht11_cnt;
    if (dht11_cnt == 160/5)
    {
        DHT11_W(0);
    }
    else if (dht11_cnt >= 180/5)
    {
        dht11_cnt = 0;
        Dht11_Task();
    }
}

/*----------------------------------------------------------------------------------------------*/

/**
 * @brief Interrupt service routine of PCA.
 * 
 */
void PCA_Isr(void) interrupt PCA_VECTOR
{
    if (PCA_CheckCCF0Flag())
    {
        u16 tmpreload;
        PCA_ClearCCF0Flag();
        tmpreload = MAKEWORD(CL, CH) + CCPA0_Period;
        User_PCA_SetC0Reload(tmpreload);      // 设置 PCA 模块 0 装载值

        // TODO
        app_music_task();
    }
    
    if (PCA_CheckCCF1Flag())
    {
        u16 tmpreload;
        PCA_ClearCCF1Flag();
        tmpreload = MAKEWORD(CL, CH) + User_PCA_CCPA0_PERIOD_DEFAULT_5MS;
        User_PCA_SetC1Reload(tmpreload);      // 设置 PCA 模块 1 装载值

        // TODO
        User_PCA_M1_ITHandler();
    }
}
