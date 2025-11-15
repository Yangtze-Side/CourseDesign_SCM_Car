#ifndef __DHT11_H
#define __DHT11_H

#include "config.h"

#define DHT11_PIN		        P26
#define DHT11_W(x)              (DHT11_PIN = (x))
#define DHT11_R(x)              (DHT11_PIN)


typedef struct DHT11_Data_t
{
	u8 humi_int;
	u8 humi_deci;
	u8 temp_int;
	u8 temp_deci;
	u8 check;
	u8 data_OK;
} DHT11_Data_t;

extern DHT11_Data_t DHT11_Data;

void Dht11_Task(void);

#endif
