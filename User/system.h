#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "config.h"
#include "user_driver.h"

/*---------------------------------- System Defines ---------------------------------*/

#define Sys_MAX_DELAY                       ( 0xffffffff )

#define UART2_SendBuf_SIZE		            128
#define UART2_RecvBuf_SIZE		            64

#define IAP_CONTR_SWBS_MSK                  BIT6
#define IAP_CONTR_SWRST_MSK                 BIT5
#define Software_ResetToISP()              SET_REG_BIT(IAP_CONTR, IAP_CONTR_SWBS_MSK | IAP_CONTR_SWRST_MSK)

/*-------------------------------- Exported Variables -------------------------------*/

extern u8 UART2_SendBuf[UART2_SendBuf_SIZE];
extern u8 UART2_RecvBuf[UART2_RecvBuf_SIZE];

extern UART_Send_t uart2_tx;
extern UART_Recv_t uart2_rx;


/*-------------------------------- Exported Functions -------------------------------*/

void proj_init(void);
void user_printf(const char *f, ...);

void sys_uart_recv_task_5ms(void);
void uart_recv_handler(UART_Recv_t *recv);

void Sys_Delay(u32 ms);
void Sys_IncTick(void);
u32  Sys_GetTick(void);

#endif // !__SYSTEM_H
