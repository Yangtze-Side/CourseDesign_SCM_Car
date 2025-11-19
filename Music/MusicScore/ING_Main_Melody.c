
#include "ING_Main_Melody.h"

static code Note_t M1[] =
{
    {PITCH_E7, PULSE_1},
    {PITCH_C7, PULSE_1_2},
    {PITCH_REST, PULSE_1_2},
    {PITCH_G7, PULSE_1_2 + PULSE_1_4},
    {PITCH_F7, PULSE_1_4},
    {PITCH_E7, PULSE_1_2 + PULSE_1_4},
    {PITCH_F7, PULSE_1_4},

    {PITCH_E7, PULSE_2},
    {PITCH_D7, PULSE_1},
    {PITCH_REST, PULSE_1}
};

static code Note_t M1_2[] =
{
    {PITCH_E7,PULSE_1},
    {PITCH_C7,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},

    {PITCH_G7, PULSE_1_2 + PULSE_1_4},
    {PITCH_F7, PULSE_1_4},
    {PITCH_E7, PULSE_1_2 + PULSE_1_4},
    {PITCH_F7, PULSE_1_4},

    {PITCH_E7,PULSE_2},
    {PITCH_D7,PULSE_1},
    {PITCH_REST,PULSE_1},

    {PITCH_D7,PULSE_1_2 + PULSE_1_4},
    {PITCH_E7,PULSE_1_4},
    {PITCH_F7,PULSE_1_2 + PULSE_1_4},
    {PITCH_G7,PULSE_1_4},

    {PITCH_A7,PULSE_1_2},
    {PITCH_REST,PULSE_1_4},
    {PITCH_G7,PULSE_1_4},
    {PITCH_F7,PULSE_1_2 + PULSE_1_4},
    {PITCH_E7,PULSE_1_4},

    {PITCH_E7,PULSE_2},
    {PITCH_D7,PULSE_1},
    {PITCH_REST,PULSE_1}
};

/* 然后重复 1 */

static code Note_t M4[] =
{
    {PITCH_D7,PULSE_1_2 + PULSE_1_4},
    {PITCH_E7,PULSE_1_4},
    {PITCH_F7,PULSE_1_2 + PULSE_1_4},
    {PITCH_G7,PULSE_1_4},

    {PITCH_A7,PULSE_1_2},
    {PITCH_REST,PULSE_1_4},
    {PITCH_G7,PULSE_1_4},
    {PITCH_A7,PULSE_1_2 + PULSE_1_4},
    {PITCH_B7,PULSE_1_4},

    {PITCH_C8,PULSE_1},
    {PITCH_REST,PULSE_1 + PULSE_2}
};
// 装饰音（第2、3拍，刮奏 PITCH_G7~PITCH_C8~HE7, PITCH_C8~HE7~HH5.


/* 重复 1 2 1 */

static code Note_t M8[] =
{
    {PITCH_D7,PULSE_1_2 + PULSE_1_4},
    {PITCH_E7,PULSE_1_4}, 
    {PITCH_F7,PULSE_1_2 + PULSE_1_4},
    {PITCH_G7,PULSE_1_4}, 

    {PITCH_A7,PULSE_1_2 + PULSE_1_4},
    {PITCH_G7,PULSE_1_4}, 
    {PITCH_A7,PULSE_1_2 + PULSE_1_4},
    {PITCH_B7,PULSE_1_4},

    {PITCH_C8,PULSE_2 + PULSE_1 + PULSE_1_2},
    {PITCH_REST, PULSE_1_2}
};

static code Note_t M9_12[] =
{
    {PITCH_C7,PULSE_1},
    {PITCH_C7,PULSE_1_2 + PULSE_1_4},
    {PITCH_E7,PULSE_1_4},
    {PITCH_D7,PULSE_1},
    {PITCH_C7,PULSE_1},

    {PITCH_B6,PULSE_1},
    {PITCH_B6,PULSE_1_2 + PULSE_1_4},
    {PITCH_D7,PULSE_1_4},
    {PITCH_C7,PULSE_1},
    {PITCH_B6,PULSE_1},

    {PITCH_A6,PULSE_1},
    {PITCH_A6,PULSE_1_2 + PULSE_1_4},
    {PITCH_B6,PULSE_1_4},
    {PITCH_C7,PULSE_1},
    {PITCH_A6,PULSE_1},

    {PITCH_B6,PULSE_1},
    {PITCH_B6,PULSE_1_2 + PULSE_1_4},
    {PITCH_C7,PULSE_1_4},
    {PITCH_D7,PULSE_1},
    {PITCH_G6,PULSE_1},

    {PITCH_E7,PULSE_1},
    {PITCH_E7,PULSE_1_2 + PULSE_1_4},
    {PITCH_G7,PULSE_1_4},
    {PITCH_D7,PULSE_1},
    {PITCH_C7,PULSE_1},

    {PITCH_D7,PULSE_1},
    {PITCH_D7,PULSE_1},
    {PITCH_G6,PULSE_1},
    {PITCH_B6,PULSE_1},

    {PITCH_F7,PULSE_1},
    {PITCH_F7,PULSE_1_2 + PULSE_1_4},
    {PITCH_D7,PULSE_1_4},
    {PITCH_G6,PULSE_1},
    {PITCH_G7,PULSE_1},

    {PITCH_E7,PULSE_4 - PULSE_1_2},
    {PITCH_REST, PULSE_1_2}
};

/* 重复 1 2 1 4 */
/* End */


static code Melody_t Music1[] =
{
    {M1_2, sizeof(M1_2) / sizeof(Note_t)},
    {M1, sizeof(M1) / sizeof(Note_t)},
    {M4, sizeof(M4) / sizeof(Note_t)},

    {M1_2, sizeof(M1_2) / sizeof(Note_t)},
    {M1, sizeof(M1) / sizeof(Note_t)},
    {M8, sizeof(M8) / sizeof(Note_t)},

    {M9_12, sizeof(M9_12) / sizeof(Note_t)},

    {M1_2, sizeof(M1_2) / sizeof(Note_t)},
    {M1, sizeof(M1) / sizeof(Note_t)},
    {M4, sizeof(M4) / sizeof(Note_t)},
};


code Music_t Music_ING_Main =
{
    Music1,
    sizeof(Music1) / sizeof(Melody_t),
};
