#ifndef __COMMUNICATION_H
#define __COMMUNICATION_H

#include "config.h"

#define Comm_LinkStatus_PIN             P32
#define Comm_GetLinkStatusPinLevel()    (Comm_LinkStatus_PIN)

typedef struct Comm_JoysModeData_t
{
    float vx;
    float vy;
    float vw;
} Comm_JoysModeData_t;

typedef struct Comm_GravModeData_t
{
    float vx;
    float vy;
    float target_yaw;
} Comm_GravModeData_t;

extern Comm_JoysModeData_t Comm_JoysModeData;
extern Comm_GravModeData_t Comm_GravModeData;
extern u8 Comm_MotorMode;

void Comm_Init(void);

void Comm_StartParse(u8 DatBuf[64], u8 len);
void Comm_ParseTask(void);
void Comm_SendTask(void);

void Comm_DetectLinkStatusTask(void);
BOOL Comm_GetLinkStatus(void);

#endif // !__COMMUNICATION_H
