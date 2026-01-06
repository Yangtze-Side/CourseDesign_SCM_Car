/**
 * @file key.c
 * @author Zach (2063408575@qq.com)
 * 
 * @brief 按键模板，区分长短按和双击。适用单个按键的情况。
 * 
 *        一些细节，如按键电平极性和长短按阈值等，在 .c 文件开头的宏定义处设置。
 * 
 * @version 0.1
 * @date 2025-07-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "key_SLD.h"
#include "motion.h"
#include "system.h"

/*------------------------------------------- User Determine -------------------------------------------*/

#define Key_IsPressed(__key__)      ((__key__) == Bit_RESET)
#define Key_IsReleased(__key__)     ((__key__) == Bit_SET)

#define Key_TaskPeriod              (20)    // KeyTask 20 ms 执行一次
#define Key_LP_THRES                (600 / Key_TaskPeriod)      // 长按阈值 ms
#define Key_DP_THRES                (300 / Key_TaskPeriod)      // 双击阈值 ms
#define Key_DP_DELAY                (150 / Key_TaskPeriod)      // 双击反应延迟时间（为了操控更舒适）ms


/**
 * @brief 短按改变电机使能状态。
 * 
 */
static void Key_ShortPress(void)
{
    if (Motor_IsEnabled()) Motor_Cmd(DISABLE);
    else Motor_Cmd(ENABLE);
}


static void Key_LongPress(void)
{
    // 直接复位，准备下载程序
    Software_ResetToISP();
}

static void Key_DoublePress(void)
{
    ;
}


/*---------------------------------------------- Library ----------------------------------------------*/

/**
 * @brief 按键周期性任务，20 ms 执行一次。
 * @note  区分长按、短按、双击。
 * 
 */
void KeySLD_Task(void)
{
    static BOOL keyLast = Bit_SET;
    static u8 keyState = 0, keyCount = 0;
    BOOL keyNow = GET_KEY_NOW();

    switch (keyState)
    {
        case 0:
        {
            if (Key_IsPressed(keyNow) && Key_IsReleased(keyLast))
            {
                keyState = 1;
                keyCount = 0;
            }
        } break;

        case 1:
        {
            if (Key_IsPressed(keyNow))
            {
                if (++keyCount >= Key_LP_THRES)
                {
                    keyState = 0;
                    Key_LongPress();
                }
            }
            else
            {
                keyState = 2;
                keyCount = 0;
            }
        } break;

        case 2:
        {
            if (Key_IsReleased(keyNow))
            {
                if (++keyCount >= Key_DP_THRES)
                {
                    keyState = 0;
                    Key_ShortPress();
                }
            }
            else
            {
                // 注：
                // 如果是双击，那么不立即执行，延迟一定时间再执行
                // 因为一般识别为单击需要延迟 300 ms 左右，如果双击是立即执行的。
                // 那么操控效果和单击相差比较大，不太舒适。
                keyState = 3;
                keyCount = 0;
            }
        } break;

        case 3:
        {
            if (++keyCount >= Key_DP_DELAY)
            {
                keyState = 0;
                Key_DoublePress();
            }
        } break;
    }

    keyLast = keyNow;
}
