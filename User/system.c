
#include "system.h"
#include <stdarg.h>

/*---------------------------------------- System Variables --------------------------------------*/

u8 xdata UART1_SendBuf[UART1_SendBuf_SIZE];
u8 xdata UART1_RecvBuf[UART1_RecvBuf_SIZE];

UART_Send_t uart1_tx = { UART1, FALSE, UART1_SendBuf, 0, 0 };
UART_Recv_t uart1_rx = { UART1, FALSE, UART1_RecvBuf, 0, 0 };

static void uart_recv_handler(UART_Recv_t *recv);

/*---------------------------------------- User Determine --------------------------------------*/

void proj_init(void)
{
	UART_Recv_SetCB(uart_recv_handler);
}

static void uart_recv_handler(UART_Recv_t *recv)
{
	if (recv->Index == UART1)
	{
		;
	}
}

/*---------------------------------------- System Functions --------------------------------------*/

#define PRINTF_BUF                      UART1_SendBuf
#define PRINTF_HANDLE                   uart1_tx

void user_printf(const char *f, ...)
{
	va_list args;
	if (PRINTF_HANDLE.Busy == TRUE) return;
	
	va_start(args, f);
	vsprintf((char*)PRINTF_BUF, f, args);
	va_end(args);
	UART_Send_Start(&PRINTF_HANDLE, strlen((char*)PRINTF_BUF));
}
