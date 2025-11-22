
#include "dht11.h"
#include "system.h"

#define DHT11_HIGH	            1
#define DHT11_LOW		        0

#define DHT11_TIMEOUT_ms        3


DHT11_Data_t DHT11_Data;


/**
 * @brief DTH读取一个字节
 * 
 * @return u8 读到的字节(u8)
 */
static u8 Dht11_ReadByte(void)
{
	u8 i = 0, Data = 0x00;
    BOOL protocal_error = FALSE;
    u32 tickstart;

	for(; i < 8; i++)
    {
		Data <<= 1;
        tickstart = Sys_GetTick();
		while(DHT11_R() == DHT11_LOW)
        {
            if (Sys_GetTick() - tickstart >= DHT11_TIMEOUT_ms)
            {
                protocal_error = TRUE;
                break;
            }
        }
        if (protocal_error) break;

		delay_us(30);

		if(DHT11_R() == DHT11_HIGH)
        {
			Data |= (u8)0x01;
            tickstart = Sys_GetTick();
			while(DHT11_R() == DHT11_HIGH)
            {
                if (Sys_GetTick() - tickstart >= DHT11_TIMEOUT_ms)
                {
                    protocal_error = TRUE;
                    break;
                }
            }
            if (protocal_error) break;
		}
	}
	return Data;
}


/**
 * @brief DHT11向指定DHT11数据结构体读取数据包并判断数据有效性
 * @note  100ms 执行一次。
 * 
 */
void Dht11_Task(void)
{
	DHT11_W(1);
	delay_us(40);
	
	if(DHT11_R() == DHT11_LOW)
    {
		u8 res[4];
		u8 check;
        BOOL protocal_error = FALSE;
        u32 tickstart = Sys_GetTick();

		while(DHT11_R() == DHT11_LOW)
        {
            if (Sys_GetTick() - tickstart >= DHT11_TIMEOUT_ms)
                protocal_error = TRUE;
        }
        if (protocal_error) return;
		while(DHT11_R() == DHT11_HIGH)
        {
            if (Sys_GetTick() - tickstart >= DHT11_TIMEOUT_ms)
                protocal_error = TRUE;
        }
        if (protocal_error) return;

		res[0] = Dht11_ReadByte();
		res[1] = Dht11_ReadByte();
		res[2] = Dht11_ReadByte();
		res[3] = Dht11_ReadByte();
		check  = Dht11_ReadByte();
		
        if (check == (u8)(res[0] + res[1] + res[2] + res[3]))
		{
			DHT11_Data = *(DHT11_Data_t*)res;
		}
	}
}
