#ifndef __MOTOR_H
#define __MOTOR_H

#include "config.h"

#define Motor_Speed_MIN                     -100.0f
#define Motor_Speed_MAX                     100.0f

#define MOTORA_DIR1_Pin                     P00
#define MOTORA_DIR2_Pin                     P00
#define MOTORB_DIR1_Pin                     P00
#define MOTORB_DIR2_Pin                     P00
#define MOTORC_DIR1_Pin                     P00
#define MOTORC_DIR2_Pin                     P00
#define MOTORD_DIR1_Pin                     P00
#define MOTORD_DIR2_Pin                     P00

#define Motor_State_OFF                     0

typedef struct MotorSpeed_t
{
    float A;        // Motor speed value, range [ Motor_Speed_MIN, Motor_Speed_MAX ]
    float B;        // Motor speed value, range [ Motor_Speed_MIN, Motor_Speed_MAX ]
    float C;        // Motor speed value, range [ Motor_Speed_MIN, Motor_Speed_MAX ]
    float D;        // Motor speed value, range [ Motor_Speed_MIN, Motor_Speed_MAX ]
} MotorSpeed_t;

void Motor_Init(void);
void Motor_Task(void);
u8   MotorGetState(void);

#endif // !__MOTOR_H
