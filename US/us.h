#ifndef __US_H
#define __US_H

#include "config.h"

#define US_F_StartSignal()              { P00 = 0; delay_us(10); P00 = 1; }
#define US_B_StartSignal()              { P00 = 0; delay_us(10); P00 = 1; }
#define US_L_StartSignal()              { P00 = 0; delay_us(10); P00 = 1; }
#define US_R_StartSignal()              { P00 = 0; delay_us(10); P00 = 1; }

#define US_Timer_Start()                TIMER3_Run()
#define US_Timer_Stop()                 TIMER3_Stop()
#define US_Timer_Clear()                (T3H = 0, T3L = 0)
#define US_Timer_ReadCounter()          MAKEWORD(T3L, T3H)

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
