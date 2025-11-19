
#include "ShanhuHai.h"

/*----------------------------------- Main1 ------------------------------------*/

static code Note_t M1[] =
{
    {PITCH_REST, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_B5, PULSE_1_2},
    {PITCH_A5, PULSE_1_2},
    {PITCH_B5, PULSE_1_2},

    {PITCH_A5, PULSE_1_4},
    {PITCH_G5, PULSE_1_4},
    {PITCH_G5, PULSE_1_2 + PULSE_1},
    {PITCH_REST, PULSE_2},

    {PITCH_REST, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_G5, PULSE_1_2},

    {PITCH_F6, PULSE_1_2},
    {PITCH_E6, PULSE_1_2 + PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_E6, PULSE_1_2},
    {PITCH_G6, PULSE_1_2},

    {PITCH_G6, PULSE_1_4},
    {PITCH_C6, PULSE_1_4},
    {PITCH_C6, PULSE_1 + PULSE_1_2},
    {PITCH_REST, PULSE_1},
    {PITCH_C6, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},

    {PITCH_E6, PULSE_1_4},
    {PITCH_A5, PULSE_1_4},
    {PITCH_A5, PULSE_1_2 + PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_A5, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},

    {PITCH_D6, PULSE_1 + PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_F6, PULSE_1 + PULSE_1_2},
    {PITCH_E6, PULSE_1_4},
    {PITCH_D6, PULSE_1_4},

    {PITCH_D6, PULSE_3},

    {PITCH_REST, PULSE_1 + PULSE_4},

    {PITCH_REST, PULSE_1 + PULSE_1_2},
    {PITCH_G5, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_E6, PULSE_1_4},
    {PITCH_E6, PULSE_1_4 + PULSE_1},

    {PITCH_REST, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},

    {PITCH_D6, PULSE_1_2},
    {PITCH_F6, PULSE_1_4},
    {PITCH_E6, PULSE_1_4 + PULSE_1},
    {PITCH_REST, PULSE_2},

    {PITCH_REST, PULSE_1},
    {PITCH_C6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_G6, PULSE_1_2 + PULSE_1},

    {PITCH_REST, PULSE_1},
    {PITCH_C6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_G5, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},

    {PITCH_E6, PULSE_1 + PULSE_1_2},
    {PITCH_F6, PULSE_1_2},
    {PITCH_G6, PULSE_1 + PULSE_1_2},
    {PITCH_E6, PULSE_1_2},

    {PITCH_F6, PULSE_2},
    {PITCH_REST, PULSE_1},
    {PITCH_G5, PULSE_1_2},  // 转身离开
    {PITCH_D6, PULSE_1_2},

    {PITCH_D6, PULSE_1_2},
    {PITCH_E6, PULSE_1},
    {PITCH_REST, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_F6, PULSE_1_2},
    {PITCH_F6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},

    {PITCH_A6, PULSE_1_2},
    {PITCH_G6, PULSE_1},
    {PITCH_REST, PULSE_1_2},
    {PITCH_G6, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},

    {PITCH_D7, PULSE_1_2},
    {PITCH_C7, PULSE_1},
    {PITCH_REST, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},

    {PITCH_A6, PULSE_1_2},
    {PITCH_G6, PULSE_1 + PULSE_1_2},
    {PITCH_REST, PULSE_1},
    {PITCH_G6, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    
    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1},
    {PITCH_REST, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},

    {PITCH_A6, PULSE_1_2},
    {PITCH_G6, PULSE_1 + PULSE_1_2},
    {PITCH_REST, PULSE_1},
    {PITCH_E6, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},

    {PITCH_A6, PULSE_1_4},
    {PITCH_C6, PULSE_1_4},
    {PITCH_C6, PULSE_1},
    {PITCH_REST, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},
    {PITCH_G6, PULSE_1_2},
    {PITCH_F6, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},

    {PITCH_A6, PULSE_1},
    {PITCH_REST, PULSE_1_2},
    {PITCH_G6, PULSE_1_2},
    {PITCH_G6, PULSE_1_2},
    {PITCH_REST, PULSE_1_2},
    {PITCH_G5, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},

    {PITCH_D6, PULSE_1_2},
    {PITCH_E6, PULSE_1},
    {PITCH_REST, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_F6, PULSE_1_2},
    {PITCH_F6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},

    {PITCH_A6, PULSE_1_2},
    {PITCH_G6, PULSE_1},
    {PITCH_REST, PULSE_1_2},
    {PITCH_G6, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},

    {PITCH_D7, PULSE_1_2},
    {PITCH_C7, PULSE_1},
    {PITCH_REST, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},

    {PITCH_A6, PULSE_1_2},
    {PITCH_G6, PULSE_1_2 + PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_G6, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},

    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1},
    {PITCH_REST, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},

    {PITCH_A6, PULSE_1_2},
    {PITCH_G6, PULSE_1_2 + PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_E6, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},

    {PITCH_A6, PULSE_1_4},
    {PITCH_C6, PULSE_1_4},
    {PITCH_C6, PULSE_1},
    {PITCH_REST, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},
    {PITCH_G6, PULSE_1_2},
    {PITCH_F6, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    
    {PITCH_E6, PULSE_1_4},
    {PITCH_D6, PULSE_1_2},
    {PITCH_D6, PULSE_1_4 + PULSE_1},
    {PITCH_E6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},

    {PITCH_D6, PULSE_1_4},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_4 + PULSE_2},
    {PITCH_REST, PULSE_1}
};

static code Melody_t Music1[] =
{
    { M1, sizeof(M1) / sizeof(Note_t) },
};

code Music_t Music_ShanhuHai_Main1 =
{
    Music1,
    sizeof(Music1) / sizeof(Melody_t)
};

/*----------------------------------- Main2 ------------------------------------*/

static code Note_t M2[] =
{
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},

    {PITCH_REST, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},

    {PITCH_A6, PULSE_1_2},
    {PITCH_G6, PULSE_1_2 + PULSE_1},
    {PITCH_REST, PULSE_2},

    {PITCH_REST, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},

    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_4},
    {PITCH_C7, PULSE_1_4 + PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},

    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_2 + PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},

    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_4},
    {PITCH_C7, PULSE_1_4 + PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_G6, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},

    {PITCH_C7, PULSE_1 + PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    {PITCH_E7, PULSE_1 + PULSE_1_2},
    {PITCH_C7, PULSE_1_2},

    {PITCH_D7, PULSE_2},
    {PITCH_REST, PULSE_2},

    {PITCH_REST, PULSE_1},
    {PITCH_C7, PULSE_1},
    {PITCH_C7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},

    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1_2 + PULSE_1},
    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    {PITCH_F7, PULSE_1_2},

    {PITCH_F7, PULSE_1_2},
    {PITCH_E7, PULSE_1_2 + PULSE_1},
    {PITCH_E7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},

    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1_2 + PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_D7, PULSE_1},
    
    {PITCH_C7, PULSE_1_2},
    {PITCH_E7, PULSE_1 + PULSE_1_2},
    {PITCH_E7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},

    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1},
    {PITCH_G6, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_4},
    {PITCH_C7, PULSE_1_4 + PULSE_1},

    {PITCH_REST, PULSE_1},
    {PITCH_E6, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},

    {PITCH_C7, PULSE_1 + PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_REST, PULSE_1_2},
    {PITCH_G6, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},

    {PITCH_D7, PULSE_1_2},
    {PITCH_C7, PULSE_1 + PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},

    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1_2 + PULSE_1},
    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    {PITCH_F7, PULSE_1_2},

    {PITCH_F7, PULSE_1_2},
    {PITCH_E7, PULSE_1_2 + PULSE_1},
    {PITCH_E7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    
    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1 + PULSE_1_2},
    {PITCH_REST, PULSE_1},
    {PITCH_D7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},

    {PITCH_D7, PULSE_1_2},
    {PITCH_E7, PULSE_1 + PULSE_1_2},
    {PITCH_E7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},

    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1},
    {PITCH_G6, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_4},
    {PITCH_C7, PULSE_1_4 + PULSE_1},

    {PITCH_REST, PULSE_1},
    {PITCH_E6, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},
    {PITCH_A6, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    
    {PITCH_C7, PULSE_1_4},
    {PITCH_B6, PULSE_1_2},
    {PITCH_B6, PULSE_1_4 + PULSE_1},
    {PITCH_E7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},

    {PITCH_D7, PULSE_1_4},
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1_4 + PULSE_2},
    {PITCH_REST, PULSE_1}
};

static code Melody_t Music2[] =
{
    { M2, sizeof(M2) / sizeof(Note_t) },
};

code Music_t Music_ShanhuHai_Main2 =
{
    Music2,
    sizeof(Music2) / sizeof(Melody_t)
};
