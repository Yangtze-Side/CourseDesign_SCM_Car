#ifndef __MOTOR_H
#define __MOTOR_H

#include "config.h"

/*--------------------------------- Exported Defines ------------------------------*/

#define Car_Speed_MIN                       -100.0f
#define Car_Speed_MAX                       100.0f

#define MotorPin(x, y)                      Motor_##x##_In##y

#define Motor_A_In1                         MT0
#define Motor_A_In2                         MT1
#define Motor_B_In1                         MT2
#define Motor_B_In2                         MT3
#define Motor_C_In1                         MT4
#define Motor_C_In2                         MT5
#define Motor_D_In1                         MT6
#define Motor_D_In2                         MT7

#define Motor_State_OFF                     0       // Motor is off
#define Motor_State_JOYSTICK                1       // Control by joystick (user implement)
#define Motor_State_GRAVITY                 2       // Control by gravity  (user implement)
#define Motor_State_AUTOCRUISE              3       // Auto cruise mode    (user implement)
#define Motor_State_AUTOFOLLOW              4       // Auto follow mode    (user implement)


/*--------------------------------- Exported TypeDefs ------------------------------*/

/**
 * @brief Car speed is determined by 3 parameters:
 *        Vx, Vy and Vw(angle ratio).
 * @note  Export the type as an interface to set the car speed.
 * 
 */
typedef struct CarSpeed_t
{
    float x;
    float y;
    float w;
} CarSpeed_t;


/*--------------------------------- Exported Vars & Fnucs ------------------------------*/

void Motor_Task(void);

u8   Motor_GetState(void);
void Motor_SetState(u8 NewState);

BOOL Motor_IsEnabled(void);
void Motor_Cmd(BOOL cmd);

#endif // !__MOTOR_H
