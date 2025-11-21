
#include "communication.h"
#include "contract.h"
#include "motion.h"
#include "user_driver.h"
#include "us.h"
#include "system.h"
#include "dht11.h"
#include "algorithm.h"
#include "music_header.h"

#define COMM_DATBUF_SIZE        64

static BOOL Comm_ParseFlag = FALSE;
static u8  Comm_DatBuf[64];
static BOOL Comm_Linked = FALSE;

Comm_JoysModeData_t Comm_JoysModeData = { 0.0f, 0.0f, 0.0f };
Comm_GravModeData_t Comm_GravModeData = { 0.0f, 0.0f, 0.0f };
u8 Comm_MotorMode = Motor_State_OFF;


void Comm_Init(void)
{
    Comm_Linked = Comm_GetLinkStatusPinLevel();
}

/**
 * @brief Change BT link status when the LINKED pin level changes.
 * 
 * @param status new satus (TRUE/FALSE)
 */
void Comm_SetLinkStatus(BOOL status)
{
    Comm_Linked = status;
}


/**
 * @brief Get BT link status.
 * 
 * @return BOOL status (TRUE for linked and FALSE vice versa).
 */
BOOL Comm_GetLinkStatus(void)
{
    return Comm_Linked;
}

/**
 * @brief Start parse uart data
 * 
 * @param DatBuf uart receive buffer
 * @param len    length of data received
 */
void Comm_StartParse(u8 DatBuf[64], u8 len)
{
    memcpy(Comm_DatBuf, DatBuf, min(len, 64));
    Comm_ParseFlag = 1;
}


/**
 * @brief Data parse task. Executed in the infinite loop in main().
 * 
 */
void Comm_ParseTask(void)
{
    if (Comm_Linked == FALSE) return;

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
                } break;

                case COMM_CMD_ACMode:
                {
                    Comm_MotorMode = Motor_State_AUTOCRUISE;
                } break;

                case COMM_CMD_AFMode:
                {
                    Comm_MotorMode = Motor_State_AUTOFOLLOW;
                } break;

                // case COMM_CMD_Music:
                // {
                //     app_music_start(Comm_DatBuf[3]);
                // } break;
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
	u8 dat[COMM_CMD_DHT11Data_LEN];
    if (Comm_Linked == FALSE) return;

	dat[0] = COMM_HEAD_BYTE0;
	dat[1] = COMM_HEAD_BYTE1;
	dat[2] = COMM_CMD_DHT11Data;
    dat[3] = DHT11_Data.temp_int;
    dat[4] = DHT11_Data.temp_deci;
    dat[5] = DHT11_Data.humi_int;
    dat[6] = DHT11_Data.humi_deci;
    *(float*)(dat + 7)  = US_Data.F;
    *(float*)(dat + 11) = US_Data.B;
    *(float*)(dat + 15) = US_Data.L;
    *(float*)(dat + 19) = US_Data.R;
    dat[23] = COMM_TAIL_BYTE0;
    dat[24] = COMM_TAIL_BYTE1;
    UART_Send_Start(&uart2_tx, dat, sizeof(dat));
}
