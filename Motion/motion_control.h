#ifndef __MOTION_CONTROL_H
#define __MOTION_CONTROL_H

#include "motor.h"

void Motion_Control_Init(void);
void Motor_Control_SetState(void);
void Motion_Control_ByJoystick(CarSpeed_t *cs);
void Motion_Control_ByGravity(CarSpeed_t *cs);
void Motion_Control_AutoCruise(CarSpeed_t *cs);

#endif // !__MOTION_CONTROL_H
