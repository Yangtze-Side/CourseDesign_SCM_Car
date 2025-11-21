
#include "motor.h"
#include "user_pwm.h"
#include "user_lib.h"
#include "motion_control.h"

/*--------------------------------- Private Defines & TypeDefs ------------------------------*/

#define Motor_Speed_MIN                     -100.0f
#define Motor_Speed_MAX                     100.0f

typedef struct MotorSpeed_t
{
    float A;        // Motor speed value, range [ Motor_Speed_MIN, Motor_Speed_MAX ]
    float B;        // Motor speed value, range [ Motor_Speed_MIN, Motor_Speed_MAX ]
    float C;        // Motor speed value, range [ Motor_Speed_MIN, Motor_Speed_MAX ]
    float D;        // Motor speed value, range [ Motor_Speed_MIN, Motor_Speed_MAX ]
} MotorSpeed_t;

// transform motor_speed into pulse width
#define Speed2Width(x)          ( (u16) ((x) / Motor_Speed_MAX * (float)PWM_PERIOD) )

/*--------------------------------- Variables & Funcs ------------------------------*/

// Motor control state, indicate which mode is taken control of motors.
static u8   MotorState   = Motor_State_OFF;
static BOOL Motor_Enable = FALSE;

static void Car_SpeedTransform(CarSpeed_t *cs, MotorSpeed_t *ms);
static void Motor_SpeedUpdate(MotorSpeed_t *ms);


/*--------------------------------- Function Definitions ------------------------------*/

BOOL Motor_IsEnabled(void) { return Motor_Enable; }
void Motor_Cmd(BOOL cmd) { Motor_Enable = cmd; }


/**
 * @brief Get motion state.
 * 
 * @return u8 
 */
u8 Motor_GetState(void)
{
    return MotorState;
}


/**
 * @brief Set motion state.
 * 
 */
void Motor_SetState(u8 NewState)
{
    MotorState = NewState;
}


/**
 * @brief Update motor speed according to MotorState every 10ms.
 * 
 */
void Motor_Task(void)
{
    MotorSpeed_t MotorSpeed = { 0.0f, 0.0f, 0.0f, 0.0f };
    CarSpeed_t CarSpeed = { 0.0f, 0.0f, 0.0f };

    Motion_Control_SetState();

    // Assign MotorSpeed
    switch (MotorState)
    {
        case Motor_State_OFF: break;    // Keep motor speed at 0

        case Motor_State_JOYSTICK:
        {
            Motion_Control_ByJoystick(&CarSpeed);
            Car_SpeedTransform(&CarSpeed, &MotorSpeed);
        } break;
        
        case Motor_State_GRAVITY:
        {
            Motion_Control_ByGravity(&CarSpeed);
            Car_SpeedTransform(&CarSpeed, &MotorSpeed);
        } break;
        
        case Motor_State_AUTOCRUISE:
        {
            Motion_Control_AutoCruise(&CarSpeed);
            Car_SpeedTransform(&CarSpeed, &MotorSpeed);
        } break;

        case Motor_State_AUTOFOLLOW:
        {
            Motion_Control_AutoFollow(&CarSpeed);
            Car_SpeedTransform(&CarSpeed, &MotorSpeed);
        } break;
    }

    Motor_SpeedUpdate(&MotorSpeed);
}


/**
 * @brief Transform car_speed to motor_speed.
 * @note  When motor speed is determined by car speed.
 * 
 * @param cs Car speed
 * @param ms Motor speed
 */
static void Car_SpeedTransform(CarSpeed_t *cs, MotorSpeed_t *ms)
{
    // Ensure that cs.x + cs.y <= 80
    if ( ABS(cs->x) + ABS(cs->y) > 80.0f )
    {
        cs->x = (int16_t)(cs->x / (ABS(cs->x) + ABS(cs->y)) * 80.0f );
        cs->y = ( cs->y < 0.0f ? (ABS(cs->x) - 80.0f) : (80.0f - ABS(cs->x)) );
    }

    // Ensure that cs.x + cs.y + cs.w < 100
    if (ABS(cs->w) > 20.0f)
    {
        float temp = 100.0f - ABS(cs->x) - ABS(cs->y);
        if (ABS(cs->w) > temp)
        {
            if (cs->w < 0) temp = -temp;
            cs->w = temp;
        }
    }

    ms->A = cs->y - cs->x - cs->w;
    ms->B = cs->y + cs->x + cs->w;
    ms->C = cs->y + cs->x - cs->w;
    ms->D = cs->y - cs->x + cs->w;
}


/**
 * @brief Update motor speed from MotorSpeed variable.
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
