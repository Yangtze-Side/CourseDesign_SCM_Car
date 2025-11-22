#ifndef __USER_PCA_H
#define __USER_PCA_H

#include "config.h"

#define User_PCA_CCPA0_PERIOD_DEFAULT_5MS           (MAIN_Fosc / 12 / 1000 * 5)
#define User_PCA_Freq2Period(freq_hz)               ((u16)(MAIN_Fosc / 12 / (float)(freq_hz)))


void User_PCA_Init(void);
u16  User_PCA_GetCounter(void);
void User_PCA_M0_SetPeriod(u16 period);
u16  User_PCA_M0_GetPeriod(void);

#endif // !__USER_PCA_H
