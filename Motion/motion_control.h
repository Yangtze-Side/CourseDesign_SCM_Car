#ifndef __MOTION_CONTROL_H
#define __MOTION_CONTROL_H

#include "motor.h"
#include "algorithm.h"

extern PosPI_t g_pi;
extern PosPID_t af_pid;

void Motion_Control_Init(void);
void Motion_Control_SetState(void);

void Motion_Control_ByJoystick(CarSpeed_t *cs);
void Motion_Control_ByGravity(CarSpeed_t *cs);
void Motion_Control_AutoCruise(CarSpeed_t *cs);
void Motion_Control_AutoFollow(CarSpeed_t *cs);

void Motion_Control_GravPIClear(void);
void Motion_Control_AFPIDClear(void);

BOOL Motion_IsACStucked(void);
BOOL Motion_IsAFAlone(void);

#endif // !__MOTION_CONTROL_H
