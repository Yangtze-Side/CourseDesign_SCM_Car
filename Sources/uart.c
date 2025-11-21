//<<AICUBE_USER_HEADER_REMARK_BEGIN>>
////////////////////////////////////////
// 在此添加用户文件头说明信息  
// 文件名称: uart.c
// 文件描述: 
// 文件版本: V1.0
// 修改记录:
//   1. (2025-11-11) 创建文件
////////////////////////////////////////
//<<AICUBE_USER_HEADER_REMARK_END>>


#include "config.h"


//<<AICUBE_USER_INCLUDE_BEGIN>>
// 在此添加用户头文件包含  
#include "user_driver.h"
#include "system.h"
//<<AICUBE_USER_INCLUDE_END>>


//<<AICUBE_USER_GLOBAL_DEFINE_BEGIN>>
// 在此添加用户全局变量定义、用户宏定义以及函数声明  
//<<AICUBE_USER_GLOBAL_DEFINE_END>>



////////////////////////////////////////
// 串口2初始化函数
// 入口参数: 无
// 函数返回: 无
////////////////////////////////////////
void UART2_Init(void)
{
    UART2_SwitchP1011();                //设置串口数据端口: RxD2 (P1.0), TxD2 (P1.1)

//  UART2_Timer2BRT();                  //串口2固定选择定时器2作为波特率发生器

    UART2_EnableRx();                   //使能串口2接收数据
    UART2_Mode0();                      //设置串口2为模式0 (8位数据可变波特率)
    UART2_SetIntPriority(1);            //设置中断为高优先级
    UART2_EnableInt();                  //使能串口2中断

    //<<AICUBE_USER_UART2_INITIAL_BEGIN>>
    // 在此添加用户初始化代码  
    //<<AICUBE_USER_UART2_INITIAL_END>>
}


////////////////////////////////////////
// 串口2中断服务程序
// 入口参数: 无
// 函数返回: 无
////////////////////////////////////////
void UART2_ISR(void) interrupt UART2_VECTOR
{
    //<<AICUBE_USER_UART2_ISR_CODE1_BEGIN>>
    // 在此添加中断函数用户代码  
    if (UART2_CheckTxFlag())            //判断串口发送中断
    {
        UART2_ClearTxFlag();            //清除串口发送中断标志
        UART_Send_ITHandler(&uart2_tx);
    }

    if (UART2_CheckRxFlag())            //判断串口接收中断
    {
        UART2_ClearRxFlag();            //清除串口接收中断标志
        UART_Recv_ITHandler(&uart2_rx);
    }
    //<<AICUBE_USER_UART2_ISR_CODE1_END>>
}


//<<AICUBE_USER_FUNCTION_IMPLEMENT_BEGIN>>
// 在此添加用户函数实现代码  
//<<AICUBE_USER_FUNCTION_IMPLEMENT_END>>


