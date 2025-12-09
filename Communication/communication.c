
#include "communication.h"
#include "contract.h"
#include "motion.h"
#include "user_driver.h"
#include "us.h"
#include "system.h"
#include "dht11.h"
#include "algorithm.h"
#include "music_header.h"
#include "led.h"
#include "motion_control.h"
#include "imu_app.h"

#define COMM_DATBUF_SIZE        64

#define GPID_Kp_STEP            0.02f
#define GPID_Ki_STEP            0.1f
#define GPID_Kd_STEP            0.1f
#define AFPID_Kp_STEP           0.2f
#define AFPID_Ki_STEP           0.1f
#define AFPID_Kd_STEP           0.1f

static BOOL Comm_ParseFlag = FALSE;
static u8  Comm_DatBuf[64];
static BOOL Comm_Linked = FALSE;

Comm_JoysModeData_t Comm_JoysModeData = { 0.0f, 0.0f, 0.0f };
Comm_EncoderModeData_t Comm_EncoderModeData = { 0.0f, 0.0f, 0.0f };
Comm_GravModeData_t Comm_GravModeData = { 0.0f, 0.0f, 0.0f };
u8 Comm_MotorMode = Motor_State_OFF;


void Comm_Init(void)
{
    Comm_Linked = Comm_GetLinkStatusPinLevel();
}


/**
 * @brief Detect bt link status and write it to Comm_Linked.
 * 
 */
void Comm_DetectLinkStatusTask(void)
{
    Comm_Linked = Comm_GetLinkStatusPinLevel();
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

                case COMM_CMD_EncoderMode:
                {
                    Comm_MotorMode = Motor_State_ENCODER;
                    Comm_EncoderModeData.vx = *(float*)(Comm_DatBuf + 3);
                    Comm_EncoderModeData.vy = *(float*)(Comm_DatBuf + 7);
                    Comm_EncoderModeData.target_yaw = *(float*)(Comm_DatBuf + 11);
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

                case COMM_CMD_MusicStart:
                {
                    app_music_start(Comm_DatBuf[3]);
                    LED1_Flash();
                } break;

                case COMM_CMD_MusicPause:
                {
                    app_music_pause();
                    LED1_Flash();
                } break;

                case COMM_CMD_MusicStop:
                {
                    app_music_stop();
                    LED1_Flash();
                } break;

                case COMM_CMD_MusicResume:
                {
                    app_music_resume();
                    LED1_Flash();
                } break;

                case COMM_CMD_GPIDkpAdd: g_pid.Kp += GPID_Kp_STEP; break;
                case COMM_CMD_GPIDkpDec: g_pid.Kp -= GPID_Kp_STEP; break;
                case COMM_CMD_GPIDkiAdd: g_pid.Ki += GPID_Ki_STEP; break;
                case COMM_CMD_GPIDkiDec: g_pid.Ki -= GPID_Ki_STEP; break;
                case COMM_CMD_GPIDkdAdd: g_pid.Kd += GPID_Kd_STEP; break;
                case COMM_CMD_GPIDkdDec: g_pid.Kd -= GPID_Kd_STEP; break;
                case COMM_CMD_AFPIDkpAdd: af_pid.Kp += AFPID_Kp_STEP; break;
                case COMM_CMD_AFPIDkpDec: af_pid.Kp -= AFPID_Kp_STEP; break;
                case COMM_CMD_AFPIDkiAdd: af_pid.Ki += AFPID_Ki_STEP; break;
                case COMM_CMD_AFPIDkiDec: af_pid.Ki -= AFPID_Ki_STEP; break;
                case COMM_CMD_AFPIDkdAdd: af_pid.Kd += AFPID_Kd_STEP; break;
                case COMM_CMD_AFPIDkdDec: af_pid.Kd -= AFPID_Kd_STEP; break;
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
	dat[2] = COMM_CMD_CarData;
    dat[3] = DHT11_Data.temp_int;
    dat[4] = DHT11_Data.temp_deci;
    dat[5] = DHT11_Data.humi_int;
    dat[6] = DHT11_Data.humi_deci;
    *(float*)(dat + 7)  = US_Data.F;
    *(float*)(dat + 11) = US_Data.B;
    *(float*)(dat + 15) = US_Data.L;
    *(float*)(dat + 19) = US_Data.R;
    *(float*)(dat + 23) = g_pid.Kp;
    *(float*)(dat + 27) = g_pid.Ki;
    *(float*)(dat + 31) = g_pid.Kd;
    *(float*)(dat + 35) = af_pid.Kp;
    *(float*)(dat + 39) = af_pid.Ki;
    *(float*)(dat + 43) = af_pid.Kd;
    *(float*)(dat + 47) = EulerAngle.yaw;
    dat[51] = COMM_TAIL_BYTE0;
    dat[52] = COMM_TAIL_BYTE1;
    UART_Send_Start(&uart2_tx, dat, sizeof(dat));
}
