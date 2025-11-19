#ifndef __US_H
#define __US_H

#include "config.h"
#include "user_driver.h"

// 这些引脚初始化的时候要给 0
#define US_F_Pin                        P41
#define US_B_Pin                        P42
#define US_L_Pin                        P44
#define US_R_Pin                        P45

#define US_F_StartSignal()              { US_F_Pin = 1; delay_us(12); US_F_Pin = 0; }
#define US_B_StartSignal()              { US_B_Pin = 1; delay_us(12); US_B_Pin = 0; }
#define US_L_StartSignal()              { US_L_Pin = 1; delay_us(12); US_L_Pin = 0; }
#define US_R_StartSignal()              { US_R_Pin = 1; delay_us(12); US_R_Pin = 0; }

#define US_Timer_ReadCounter()          User_PCA_GetCounter()

#define US_DATA_MAX_cm                  520.0f        // distance max (cm)

typedef struct US_Data_t
{
    float F;                // Front, cm
    float B;                // Back, cm
    float L;                // Left, cm
    float R;                // Right, cm
} US_Data_t;

extern US_Data_t US_Data;

void US_Task_30ms(void);
void US_F_INT_Handler(void);
void US_B_INT_Handler(void);
void US_L_INT_Handler(void);
void US_R_INT_Handler(void);

#endif // !__US_H
