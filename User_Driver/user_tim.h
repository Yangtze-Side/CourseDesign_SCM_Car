#ifndef __USER_TIM_H
#define __USER_TIM_H

#include "config.h"

#define TIM1                1
#define TIM3                3
#define TIM4                4

#define TIM1_CLKO_PIN       P34
#define TIM3_CLKO_PIN       P04
#define TIM4_CLKO_PIN       P06

void User_TIM_SetARR(u8 TIMx, u16 arr);
void User_TIM_CLKOCmd(u8 TIMx, u8 cmd) reentrant;

#endif // !__USER_TIM_H
