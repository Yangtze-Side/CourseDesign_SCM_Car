
#include "motor.h"
#include "user_pwm.h"
#include "user_lib.h"

// transform motor_speed into pulse width
#define Speed2Width(x)          ( (u16) ((x) / Motor_Speed_MAX * (float)PWM_PERIOD) )

// speed of four motors
static MotorSpeed_t MotorSpeed = { 0.0f, 0.0f, 0.0f, 0.0f };

// Motor control state, indicate which process is take control of motors.
static u8 MotorState = Motor_State_OFF;

/**
 * @brief Motor device initialization.
 * 
 */
void Motor_Init(void)
{
    User_PWM_Init();
}

/**
 * @brief Update the speed from MotorSpeed variable.
 * 
 */
static void Motor_SpeedUpdate(MotorSpeed_t *ms)
{
    float spdtmp;
    
    LimAsgn(ms->A, Motor_Speed_MIN, Motor_Speed_MAX);
    LimAsgn(ms->B, Motor_Speed_MIN, Motor_Speed_MAX);
    LimAsgn(ms->C, Motor_Speed_MIN, Motor_Speed_MAX);
    LimAsgn(ms->D, Motor_Speed_MIN, Motor_Speed_MAX);

    if (ms->A < 0.0f)
    {
        MOTORA_DIR1_Pin = 0;
        MOTORA_DIR2_Pin = 1;
    }
    else if (ms->A > 0.0f)
    {
        MOTORA_DIR1_Pin = 1;
        MOTORA_DIR2_Pin = 0;
    }
    else
    {
        MOTORA_DIR1_Pin = 0;
        MOTORA_DIR2_Pin = 0;
    }
    spdtmp = ABS(ms->A);
    User_PWMA_SetWidth(Speed2Width(spdtmp));

    if (ms->B < 0.0f)
    {
        MOTORB_DIR1_Pin = 0;
        MOTORB_DIR2_Pin = 1;
    }
    else if (ms->B > 0.0f)
    {
        MOTORB_DIR1_Pin = 1;
        MOTORB_DIR2_Pin = 0;
    }
    else
    {
        MOTORB_DIR1_Pin = 0;
        MOTORB_DIR2_Pin = 0;
    }
    spdtmp = ABS(ms->B);
    User_PWMB_SetWidth(Speed2Width(spdtmp));

    if (ms->C < 0.0f)
    {
        MOTORC_DIR1_Pin = 0;
        MOTORC_DIR2_Pin = 1;
    }
    else if (ms->C > 0.0f)
    {
        MOTORC_DIR1_Pin = 1;
        MOTORC_DIR2_Pin = 0;
    }
    else
    {
        MOTORC_DIR1_Pin = 0;
        MOTORC_DIR2_Pin = 0;
    }
    spdtmp = ABS(ms->C);
    User_PWMC_SetWidth(Speed2Width(spdtmp));

    if (ms->D < 0.0f)
    {
        MOTORD_DIR1_Pin = 0;
        MOTORD_DIR2_Pin = 1;
    }
    else if (ms->D > 0.0f)
    {
        MOTORD_DIR1_Pin = 1;
        MOTORD_DIR2_Pin = 0;
    }
    else
    {
        MOTORD_DIR1_Pin = 0;
        MOTORD_DIR2_Pin = 0;
    }
    spdtmp = ABS(ms->D);
    User_PWMD_SetWidth(Speed2Width(spdtmp));
}


void Motor_Task(void)
{
    // Assign MotorSpeed
    switch (MotorState)
    {
        case Motor_State_OFF:
        {
            MotorSpeed.A = 0.0f;
            MotorSpeed.B = 0.0f;
            MotorSpeed.C = 0.0f;
            MotorSpeed.D = 0.0f;
        } break;

        ;
    }
    Motor_SpeedUpdate(&MotorSpeed);
}

u8 MotorGetState(void)
{
    return MotorState;
}
