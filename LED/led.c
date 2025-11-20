
#include "led.h"
#include "motion.h"
#include "communication.h"
#include "user_pwm.h"
#include "user_lib.h"


static u8 sine_index = 0;
static u8 led1_flash_cnt1 = 0;
static u8 led1_flash_cnt2 = 0;


/**
 * @brief 电机和连接状态灯。(PWME)
 * @note  电机关闭，灯关闭。电机打开，遥控器未连接，灯呼吸；遥控器连接，灯常亮。
 * 
 */
static void led_1_task(void)
{
    if (led1_flash_cnt1)
    {
        if (--led1_flash_cnt2 == 0)
        {
            --led1_flash_cnt1;
            led1_flash_cnt2 = 6;
            LED1 ^= 1;
        }
    }
    else
    {
        if (Motor_IsEnabled())
        {
            if (Comm_GetLinkStatus())
            {
                User_PWME_SetWidth(PWM_PulseWidth_MAX);
            }
            else
            {
                User_PWME_SetWidth(SineTable[sine_index]);
            }
        }
        else
        {
            User_PWME_SetWidth(0);
        }
    }
}


/**
 * @brief 模式指示灯。(PWMF)
 * @note  遥控模式，灯关闭；自动避障或自动跟随模式，灯呼吸；当小车四面楚歌或茕茕孑立时，灯常亮。
 * 
 */
static void led_2_task(void)
{
    if (Motor_GetState() == Motor_State_AUTOCRUISE)
    {
        if (Motion_IsACStucked()) User_PWMF_SetWidth(PWM_PulseWidth_MAX);
        else User_PWMF_SetWidth(SineTable[sine_index]);
    }
    else if (Motor_GetState() == Motor_State_AUTOFOLLOW)
    {
        if (Motion_IsAFAlone()) User_PWMF_SetWidth(PWM_PulseWidth_MAX);
        else User_PWMF_SetWidth(SineTable[sine_index]);
    }
    else
    {
        User_PWMF_SetWidth(0);
    }
}

/**
 * @brief Starts led1 flash process.
 * 
 */
void LED1_Flash(void)
{
    led1_flash_cnt1 = 5;
    led1_flash_cnt2 = 6;
    User_PWME_SetWidth(0);
}

void led_task_25ms(void)
{
    led_1_task();
    led_2_task();
    ++sine_index >= SINETABLE_LEN ? sine_index = 0 : (void)0;
}
