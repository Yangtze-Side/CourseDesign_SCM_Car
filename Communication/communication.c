
#include "communication.h"
#include "contract.h"
#include "motion_control.h"
#include "user_driver.h"
#include "us.h"
#include "system.h"
#include "dht11.h"
#include "algorithm.h"

#define COMM_DATBUF_SIZE        64

static bit Comm_ParseFlag = FALSE;
static u8  Comm_DatBuf[64];

Comm_JoysModeData_t Comm_JoysModeData = { 0.0f, 0.0f, 0.0f };
Comm_GravModeData_t Comm_GravModeData = { 0.0f, 0.0f, 0.0f };
u8 Comm_MotorMode = Motor_State_OFF;

/**
 * @brief Start parse uart data
 * 
 * @param DatBuf uart receive buffer
 * @param len    length of data received
 */
void Comm_StartParse(u8 DatBuf[64], u8 len)
{
    memcpy(Comm_DatBuf, DatBuf, len);
    Comm_ParseFlag = 1;
}


/**
 * @brief Data parse task. Executed in the infinite loop in main().
 * 
 */
void Comm_ParseTask(void)
{
    if (Comm_ParseFlag)
    {
        Comm_ParseFlag = 0;
        if (COMM_IsFrameHeadCorrect(Comm_DatBuf))
        {
            switch (Comm_DatBuf[2])
            {
                case COMM_CMD_JoysMode:
                {
                    Comm_MotorMode = Motor_State_JOYSTICK;
                    Comm_JoysModeData.vx = *(float*)(Comm_DatBuf + 3);
                    Comm_JoysModeData.vy = *(float*)(Comm_DatBuf + 7);
                    Comm_JoysModeData.vw = *(float*)(Comm_DatBuf + 11);
                } break;
                
                case COMM_CMD_GravMode:
                {
                    Comm_MotorMode = Motor_State_GRAVITY;
                    Comm_GravModeData.vx = *(float*)(Comm_DatBuf + 3);
                    Comm_GravModeData.vy = *(float*)(Comm_DatBuf + 7);
                    Comm_GravModeData.target_yaw = *(float*)(Comm_DatBuf + 11);
                    Motion_Control_GravPIClear();
                } break;

                case COMM_CMD_ACMode:
                {
                    Comm_MotorMode = Motor_State_AUTOCRUISE;
                } break;

                case COMM_CMD_AFMode:
                {
                    Comm_MotorMode = Motor_State_AUTOFOLLOW;
                    Motion_Control_AFPIDClear();
                } break;
            }
        }
    }
}


/**
 * @brief Data transmission task, T = 60ms.
 * 
 */
void Comm_SendTask(void)
{
    u8 dat[23] = { COMM_BYTE0, COMM_BYTE1, COMM_CMD_DHT11Data };
    dat[3] = DHT11_Data.temp_int;
    dat[4] = DHT11_Data.temp_deci;
    dat[5] = DHT11_Data.humi_int;
    dat[6] = DHT11_Data.humi_deci;
    *(float*)(dat + 7) = US_Data.F;
    *(float*)(dat + 11) = US_Data.B;
    *(float*)(dat + 15) = US_Data.L;
    *(float*)(dat + 19) = US_Data.R;
    UART_Send_Start(&uart1_tx, dat, sizeof(dat));
}
