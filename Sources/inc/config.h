//<<AICUBE_USER_HEADER_REMARK_BEGIN>>
////////////////////////////////////////
// 在此添加用户文件头说明信息  
// 文件名称: config.h
////////////////////////////////////////
//<<AICUBE_USER_HEADER_REMARK_END>>


#ifndef __CONFIG_H__
#define __CONFIG_H__


//<<AICUBE_USER_DEFINE_BEGIN>>
// 在此添加用户宏定义  
#define USE_MPU6500             1

#define __INDIRECT_CALL_PARAMETER_TYPE
//<<AICUBE_USER_DEFINE_END>>


#define __ENCODING              "UTF-8" //DO NOT DELETE or MODIFY


#define FOSC                    24000000UL
#define SYSCLK                  FOSC
#define MAIN_Fosc               FOSC

#include <stc15.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <intrins.h>

#include "def.h"
#include "stc15w_def.h"


//<<AICUBE_USER_INCLUDE_BEGIN>>
// 在此添加用户头文件包含  
#include "user_def.h"
//<<AICUBE_USER_INCLUDE_END>>


#define MT5                     P05
#define UST0                    P41
#define UST1                    P42
#define UST2                    P44
#define KEY                     P20
#define MT6                     P24
#define MT7                     P25
#define DHT11                   P26
#define UST3                    P45
#define MT0                     P00
#define MT1                     P01
#define MT2                     P02
#define MT3                     P03
#define MT4                     P04


#include "port.h"
#include "timer.h"
#include "uart.h"
#include "exti.h"
#include "spi.h"

void SYS_Init(void);
void delay_us(uint16_t us);
void delay_ms(uint16_t ms);



//<<AICUBE_USER_EXTERNAL_DECLARE_BEGIN>>
// 在此添加用户外部函数和外部变量声明  
//<<AICUBE_USER_EXTERNAL_DECLARE_END>>


#endif
