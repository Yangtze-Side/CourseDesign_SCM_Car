#ifndef __MOTOR_H
#define __MOTOR_H

#include "config.h"

/*--------------------------------- Exported Defines ------------------------------*/

#define Car_Speed_MIN                       -100.0f
#define Car_Speed_MAX                       100.0f

#define MOTORA_DIR1_Pin                     P00
#define MOTORA_DIR2_Pin                     P00
#define MOTORB_DIR1_Pin                     P00
#define MOTORB_DIR2_Pin                     P00
#define MOTORC_DIR1_Pin                     P00
#define MOTORC_DIR2_Pin                     P00
#define MOTORD_DIR1_Pin                     P00
#define MOTORD_DIR2_Pin                     P00

#define Motor_State_OFF                     0


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

void Motor_Init(void);
void Motor_Task(void);
u8   Motor_GetState(void);
void Motor_SetState(u8 NewState);

#endif // !__MOTOR_H
