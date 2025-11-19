
#include "ING_Chord1_Melody.h"


static code Note_t M1[] =
{
    {PITCH_C6,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_E6,PULSE_1_4},
    {PITCH_G6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},

    {PITCH_C6,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_E6,PULSE_1_4},
    {PITCH_G6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},

    {PITCH_B5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_F6,PULSE_1_4},
    {PITCH_G6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},

    {PITCH_B5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_D6,PULSE_1_4},
    {PITCH_G6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},
};

static code Note_t M2[] =
{
    {PITCH_A5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_C6,PULSE_1_4},
    {PITCH_F6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},
    {PITCH_A5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_C6,PULSE_1_4},
    {PITCH_F6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},
    {PITCH_C6,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_E6,PULSE_1_4},
    {PITCH_G6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},
    {PITCH_C6,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_E6,PULSE_1_4},
    {PITCH_G6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},
};

static code Note_t M4[] =
{
    {PITCH_A5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_C6,PULSE_1_4},
    {PITCH_F6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},

    {PITCH_G5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_B5,PULSE_1_4},
    {PITCH_F6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},

    {PITCH_REST,PULSE_1},
    {PITCH_G7,2},
    {PITCH_A7,2},
    {PITCH_B7,2},
    {PITCH_C8,2},
    {PITCH_E8,2},
    {PITCH_REST,6},

    {PITCH_C8,2},
    {PITCH_D8,2},
    {PITCH_E8,2},
    {PITCH_F8,2},
    {PITCH_G8,2},
    {PITCH_REST,6},

    {PITCH_REST,PULSE_1},
};


static code Note_t M5_8[] =
{
    {PITCH_C6,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_E6,PULSE_1_4},
    {PITCH_G6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},
    {PITCH_C6,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_E6,PULSE_1_4},
    {PITCH_G6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},

    {PITCH_G5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_D6,PULSE_1_4},
    {PITCH_F6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},
    {PITCH_G5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_B5,PULSE_1_4},
    {PITCH_E6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},


    {PITCH_D5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_F5,3},
    {PITCH_A5,3},
    {PITCH_C6,3},
    {PITCH_REST,7},

    {PITCH_F5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_F5,3},
    {PITCH_A5,3},
    {PITCH_D6,3},
    {PITCH_REST,7},


    {PITCH_G5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_D5,PULSE_1_4},
    {PITCH_G5,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},
    {PITCH_C5,PULSE_1_4},
    {PITCH_A5,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},
    {PITCH_D5,PULSE_1_4},
    {PITCH_B5,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},


    {PITCH_C6,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_E6,PULSE_1_4},
    {PITCH_G6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},
    {PITCH_C6,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_E6,PULSE_1_4},
    {PITCH_G6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},

    {PITCH_G5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_B5,PULSE_1_4},
    {PITCH_D6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},
    {PITCH_G5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_D6,PULSE_1_4},
    {PITCH_F6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},

    {PITCH_D5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_F5,PULSE_1_4},
    {PITCH_C6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},
    {PITCH_G5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_B5,PULSE_1_4},
    {PITCH_F6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},

    {PITCH_C6,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_C6,PULSE_1_4},
    {PITCH_E6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},
    {PITCH_B5,PULSE_1_4},
    {PITCH_D6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},
    {PITCH_C6,PULSE_1_4},
    {PITCH_F6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2}
};

static code Note_t M9_12[] =
{
    {PITCH_C5,PULSE_1},
    {PITCH_C6,PULSE_1},
    {PITCH_E6,PULSE_2},

    {PITCH_G6,PULSE_1},
    {PITCH_G6,PULSE_1},
    {PITCH_G5,PULSE_2},

    {PITCH_D5,PULSE_1},
    {PITCH_F5,PULSE_1},
    {PITCH_A5,PULSE_1},
    {PITCH_C6,PULSE_1},

    {PITCH_B5,PULSE_1},
    {PITCH_G5,PULSE_1},
    {PITCH_A5,PULSE_1},
    {PITCH_B5,PULSE_1},

    {PITCH_C5,PULSE_1_2},
    {PITCH_G5,PULSE_1_2},
    {PITCH_C6,PULSE_1_2},
    {PITCH_G5,PULSE_1_2},
    {PITCH_E6,PULSE_1_2},
    {PITCH_G5,PULSE_1_2},
    {PITCH_C6,PULSE_1_2},
    {PITCH_G5,PULSE_1_2},

    {PITCH_B5,PULSE_1_2},
    {PITCH_D5,PULSE_1_2},
    {PITCH_G5,PULSE_1_2},
    {PITCH_D5,PULSE_1_2},
    {PITCH_D5,PULSE_1_2},
    {PITCH_G5,PULSE_1_2},
    {PITCH_A5,PULSE_1_2},
    {PITCH_B5,PULSE_1_2},

    {PITCH_A5,PULSE_1_2},
    {PITCH_C6,PULSE_1_2},
    {PITCH_D6,PULSE_1_2},
    {PITCH_A5,PULSE_1_2},
    {PITCH_G5,PULSE_1_2},
    {PITCH_B5,PULSE_1_2},
    {PITCH_D6,PULSE_1_2},
    {PITCH_G5,PULSE_1_2},

    {PITCH_E5,PULSE_1_2},
    {PITCH_G5,PULSE_1_2},
    {PITCH_C6,PULSE_1_2},
    {PITCH_E6,PULSE_1_2},
    {PITCH_G5,3},
    {PITCH_A5,3},
    {PITCH_B5,3},
    {PITCH_C6,3},
    {PITCH_D6,3},
    {PITCH_E6,3},
    {PITCH_REST,14}
};


static code Note_t M14[] = 
{
    {PITCH_A5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_C6,PULSE_1_4},
    {PITCH_F6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},

    {PITCH_A5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_C6,PULSE_1_4},
    {PITCH_F6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},

    {PITCH_G5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_C6,PULSE_1_4},
    {PITCH_F6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},

    {PITCH_G5,PULSE_1_2},
    {PITCH_REST,PULSE_1_2},
    {PITCH_B5,PULSE_1_4},
    {PITCH_G6,PULSE_1_4},
    {PITCH_REST,PULSE_1_2},
};

/* End */


code Melody_t Music1[] =
{
    {M1, sizeof(M1) / sizeof(Note_t)},
    {M2, sizeof(M2) / sizeof(Note_t)},
    {M1, sizeof(M1) / sizeof(Note_t)},
    {M4, sizeof(M4) / sizeof(Note_t)},
    {M5_8, sizeof(M5_8) / sizeof(Note_t)},
    {M9_12, sizeof(M9_12) / sizeof(Note_t)},
    {M1, sizeof(M1) / sizeof(Note_t)},
    {M14, sizeof(M14) / sizeof(Note_t)},
    {M1, sizeof(M1) / sizeof(Note_t)},
};


code Music_t Music_ING_1 =
{
    Music1,
    sizeof(Music1) / sizeof(Melody_t),
};
