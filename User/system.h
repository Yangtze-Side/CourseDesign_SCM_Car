#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "config.h"
#include "user_driver.h"

#define UART1_SendBuf_SIZE		128
#define UART1_RecvBuf_SIZE		128

extern u8 xdata UART_RecvBuf[UART1_RecvBuf_SIZE];
extern u8 xdata UART1_RecvBuf[UART1_RecvBuf_SIZE];

extern UART_Send_t uart1_tx;
extern UART_Recv_t uart1_rx;

void proj_init(void);
void user_printf(const char *f, ...);

#endif // !__SYSTEM_H
