
#include "communication.h"
#include "contract.h"
#include "motion_control.h"

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
                } break;

                case COMM_CMD_ACMode:
                {
                    Comm_MotorMode = Motor_State_AUTOCRUISE;
                    ;
                } break;

                case COMM_CMD_AFMode:
                {
                    Comm_MotorMode = Motor_State_AUTOFOLLOW;
                    ;
                } break;
            }
        }
    }
}
