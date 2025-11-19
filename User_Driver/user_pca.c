
#include "user_pca.h"


/**
 * @brief PCA counter initialization.
 * @note  CLK: SYSCLK / 2 = 2M
 *        INTERRUPT: Off
 * 
 */
void User_PCA_Init(void)
{
    PCA_Stop();
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
