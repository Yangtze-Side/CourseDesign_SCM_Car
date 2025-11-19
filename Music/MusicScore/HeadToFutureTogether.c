/**
 * @file HeadToFutureTogether.c
 * @author Zach (2063408575@qq.com)
 * 
 * @brief 《一起去未来吧》- 刘浩存
 * 
 * @version 0.1
 * @date 2025-07-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "HeadToFutureTogether.h"

/*------------------------------------------ 旋律层 ---------------------------------------*/

static code Note_t M1[] =
{
    {PITCH_REST, PULSE_1},
    {PITCH_B5, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1},
    {PITCH_B5, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},

    {PITCH_B5, PULSE_1},
    {PITCH_G5, PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_E5, PULSE_1_2},
    {PITCH_G5, PULSE_1_2},

    {PITCH_A5, PULSE_1},
    {PITCH_G5, PULSE_1_2},
    {PITCH_G5, PULSE_1_2 + PULSE_1},
    {PITCH_F5, PULSE_1_2},
    {PITCH_G5, PULSE_1_2 + PULSE_1},

    {PITCH_C5, PULSE_1},
    {PITCH_C5, PULSE_1_2},
    {PITCH_C5, PULSE_1_2},
    {PITCH_D5, PULSE_1_2},
    {PITCH_C5, PULSE_1_2},
};

static code Note_t M2[] =
{
    {PITCH_E5, PULSE_2},
    {PITCH_REST, PULSE_1},
    {PITCH_G5, PULSE_1_2},
    {PITCH_D5, PULSE_2},

    {PITCH_REST, PULSE_1},
    {PITCH_D5, PULSE_1},
    {PITCH_C5, PULSE_1_2},

    {PITCH_D5, PULSE_1_2},
    {PITCH_C5, PULSE_2},
    {PITCH_REST, PULSE_1 + PULSE_1_2},
};

static code Note_t M3[] =
{
    {PITCH_REST, PULSE_4},
};

static code Note_t M4[] =
{
    {PITCH_E5, PULSE_2},
    {PITCH_REST, PULSE_1},
    {PITCH_G5, PULSE_1_2},
    {PITCH_A5, PULSE_1},

    {PITCH_G5, PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_G5, PULSE_1},
    {PITCH_C5, PULSE_1_2},

    {PITCH_D5, PULSE_1_2},
    {PITCH_C5, PULSE_2},
    {PITCH_REST, PULSE_1_2 + PULSE_1},
};

static code Note_t M5[] =
{
    {PITCH_REST, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},

    {PITCH_E6, PULSE_1},
    {PITCH_E6, PULSE_1},
    {PITCH_E6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2 + PULSE_1},

    {PITCH_REST, PULSE_1},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
};

static code Note_t M6[] =
{
    {PITCH_D6, PULSE_1},
    {PITCH_D6, PULSE_1},
    {PITCH_D6, PULSE_1},
    {PITCH_D6, PULSE_1_2},
    {PITCH_D6, PULSE_1},

    {PITCH_C6, PULSE_1},
    {PITCH_REST, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    
    {PITCH_E6, PULSE_1},
    {PITCH_E6, PULSE_1},
    {PITCH_E6, PULSE_1},
    {PITCH_G6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2 + PULSE_1},

    {PITCH_REST, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_D6, PULSE_1},
    {PITCH_C6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2 + PULSE_1},

    {PITCH_D6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2 + PULSE_2},
};

static code Note_t M7[] =
{
    {PITCH_REST, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},

    {PITCH_E6, PULSE_1},
    {PITCH_E6, PULSE_1},
    {PITCH_E6, PULSE_1},
    {PITCH_G6, PULSE_1_2},
    {PITCH_A6, PULSE_1},

    {PITCH_G6, PULSE_1},
    {PITCH_REST, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
};

static code Note_t M8[] =
{
    {PITCH_REST, PULSE_1 + PULSE_1_2},
    {PITCH_G5, PULSE_1_2},
    {PITCH_C6, PULSE_1},
    {PITCH_A5, PULSE_1_2},

    {PITCH_G5, PULSE_1},
    {PITCH_C6, PULSE_2 + PULSE_1_2},
    {PITCH_REST, PULSE_1},
};

static code Note_t M9[] =
{
    {PITCH_B5, PULSE_1},
    {PITCH_B5, PULSE_1},
    {PITCH_B5, PULSE_1},
    {PITCH_A5, PULSE_1_2},

    {PITCH_B5, PULSE_1},
    {PITCH_C6, PULSE_1_2 + PULSE_1},
    {PITCH_REST, PULSE_2},

    {PITCH_C6, PULSE_1},
    {PITCH_C6, PULSE_1},
    {PITCH_C6, PULSE_1},
    {PITCH_D6, PULSE_1_2},

    {PITCH_C6, PULSE_1_2 + PULSE_2},
    {PITCH_REST, PULSE_2},

    {PITCH_E6, PULSE_1},
    {PITCH_D6, PULSE_1},
    {PITCH_D6, PULSE_1},
    {PITCH_E6, PULSE_1_2},

    {PITCH_C6, PULSE_1_2 + PULSE_2},
    {PITCH_REST, PULSE_2},

    {PITCH_C6, PULSE_1},
    {PITCH_C6, PULSE_1},
    {PITCH_C6, PULSE_1},
    {PITCH_G5, PULSE_1_2},

    {PITCH_C6, PULSE_1_2 + PULSE_2},
    {PITCH_REST, PULSE_2},
};

static code Note_t M10[] =
{
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
};

static code Note_t M11[] =
{
    {PITCH_REST, PULSE_1 + PULSE_1_2},
    {PITCH_G5, PULSE_1_2},
    {PITCH_C6, PULSE_1},
    {PITCH_A5, PULSE_1},

    {PITCH_G5, PULSE_1},
    {PITCH_C6, PULSE_2 + PULSE_1},
};

/*------------------------------------------ 音乐层 ---------------------------------------*/

static code Melody_t Music1[] =
{
    {M1, sizeof(M1) / sizeof(Note_t)},
    {M2, sizeof(M2) / sizeof(Note_t)},
    {M3, sizeof(M3) / sizeof(Note_t)},
    {M1, sizeof(M1) / sizeof(Note_t)},
    {M4, sizeof(M4) / sizeof(Note_t)},

    {M5, sizeof(M5) / sizeof(Note_t)},
    {M6, sizeof(M6) / sizeof(Note_t)},
    {M7, sizeof(M7) / sizeof(Note_t)},
    {M6, sizeof(M6) / sizeof(Note_t)},
    {M8, sizeof(M8) / sizeof(Note_t)},


    {M10, sizeof(M10) / sizeof(Note_t)},
    {M3, sizeof(M3) / sizeof(Note_t)},


    {M1, sizeof(M1) / sizeof(Note_t)},
    {M2, sizeof(M2) / sizeof(Note_t)},

    {M5, sizeof(M5) / sizeof(Note_t)},
    {M6, sizeof(M6) / sizeof(Note_t)},
    {M7, sizeof(M7) / sizeof(Note_t)},
    {M6, sizeof(M6) / sizeof(Note_t)},
    {M8, sizeof(M8) / sizeof(Note_t)},
    {M9, sizeof(M9) / sizeof(Note_t)},


    {M10, sizeof(M10) / sizeof(Note_t)},

    {M5, sizeof(M5) / sizeof(Note_t)},
    {M6, sizeof(M6) / sizeof(Note_t)},
    {M7, sizeof(M7) / sizeof(Note_t)},
    {M6, sizeof(M6) / sizeof(Note_t)},
    {M11, sizeof(M11) / sizeof(Note_t)},
    {M3, sizeof(M3) / sizeof(Note_t)},
};

Music_t code Music_HeadToFutureTogether =
{
    Music1,
    sizeof(Music1) / sizeof(Melody_t),
};
