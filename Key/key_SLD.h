/**
 * @file key.h
 * @author Zach (2063408575@qq.com)
 * 
 * @brief 按键模板，区分长短按和双击。适用单个按键的情况。
 * 
 *        一些细节，如按键电平极性和长短按阈值等，在 .c 文件开头的宏定义处设置。
 * 
 * @version 0.1
 * @date 2025-07-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef __KEY_SLD_H
#define __KEY_SLD_H

#include "config.h"

#define GET_KEY_NOW()               (P20)     // 当前按键的值

void KeySLD_Task(void);

#endif // !__KEY_SLD_H
