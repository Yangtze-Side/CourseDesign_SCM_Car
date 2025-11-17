
#include "dht11.h"
#include "system.h"

#define DHT11_HIGH	            1
#define DHT11_LOW		        0

#define DHT11_TIMEOUT_ms        5


DHT11_Data_t DHT11_Data;


/**
 * @brief DTH读取一个字节
 * 
 * @return u8 读到的字节(u8)
 */
u8 Dht11_ReadByte(void)
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
	delay_us(50);
	
	if(DHT11_R() == DHT11_LOW)
    {
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

		DHT11_Data.humi_int = Dht11_ReadByte();
		DHT11_Data.humi_deci = Dht11_ReadByte();
		DHT11_Data.temp_int = Dht11_ReadByte();
		DHT11_Data.temp_deci = Dht11_ReadByte();
		DHT11_Data.check = Dht11_ReadByte();
		
        DHT11_Data.data_OK =
            (DHT11_Data.check == (u8)(DHT11_Data.humi_int + DHT11_Data.humi_deci + DHT11_Data.temp_int + DHT11_Data.temp_deci));
	}
	else
    {
		DHT11_Data.data_OK = FALSE;
	}

    DHT11_W(0);
    P10 ^= 1;
}
