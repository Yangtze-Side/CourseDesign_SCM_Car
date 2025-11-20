
#include "system.h"
#include <stdarg.h>
#include "imu_app.h"
#include "motion.h"
#include "communication.h"

/*---------------------------------------- System Variables --------------------------------------*/

static volatile u32 sys_tick;          	// System tick variable, increases in SysTick interrupt.
                                    	// And the increase frequency is 1 KHz.

u8 UART2_SendBuf[UART2_SendBuf_SIZE];
u8 UART2_RecvBuf[UART2_RecvBuf_SIZE];

UART_Send_t uart2_tx = { UART2, FALSE, UART2_SendBuf, UART2_SendBuf_SIZE, 0, 0 };
UART_Recv_t uart2_rx = { UART2, FALSE, UART2_RecvBuf, UART2_RecvBuf_SIZE, 0, 0 };


/*---------------------------------------- User Determine --------------------------------------*/

/**
 * @brief Project init.
 * 
 */
void proj_init(void)
{
	Comm_Init();
	User_PCA_Init();
	Motion_Control_Init();
	User_PWM_Init();
	IMU_Init();
}

/**
 * @brief UART receive handler, when a frame of data has received.
 * 
 * @param recv the handle
 */
void uart_recv_handler(UART_Recv_t *recv)
{
	if (recv->Index == UART1)
	{
		Comm_StartParse(UART2_RecvBuf, recv->Cnt);
	}
}

void sys_uart_recv_task_5ms(void)
{
	UART_Recv_Task_5ms(&uart2_rx);
}


/*---------------------------------------- System Functions --------------------------------------*/

/*---------------------- User Printf ---------------------*/

#define PRINTF_BUF                      UART2_SendBuf
#define PRINTF_HANDLE                   uart2_tx

/**
 * @brief User-defined printf function, whose usage is the same as printf.
 * 
 * @param f 	format stirng
 * @param ... 	args
 */
void user_printf(const char *f, ...)
{
	va_list args;
	if (PRINTF_HANDLE.Busy == TRUE) return;
	
	va_start(args, f);
	vsprintf((char*)PRINTF_BUF, f, args);
	va_end(args);
	UART_Send_Start(&PRINTF_HANDLE, NULL, strlen((char*)PRINTF_BUF));
}


/*---------------------- SysTick ---------------------*/

/**
 * @brief System delay function.
 * 
 * @param ms time in millisecond
 */
void Sys_Delay(u32 ms)
{
    u32 tick_start = Sys_GetTick();
    if (ms < Sys_MAX_DELAY) ms++;
    while (Sys_GetTick() - tick_start < ms);
}

/**
 * @brief Increase sys_tick by 1.
 * 
 */
void Sys_IncTick(void)
{
    ++sys_tick;
}

/**
 * @brief Get sys_tick.
 * 
 * @return u32 sys_tick
 */
u32 Sys_GetTick(void)
{
    return sys_tick;
}
