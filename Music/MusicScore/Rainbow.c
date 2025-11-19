
#include "Rainbow.h"

#define MAIN_FIELD                  ( 6 )
#define CHORD1_FIELD                ( 7 )

#if (MAIN_FIELD == 6)

/*---------------------------------------- Main Melody - Field 6 ------------------------------------*/

static code Note_t M1[] =
{
    {PITCH_REST, PULSE_2 + PULSE_1 + PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1 + PULSE_1_2},
    {PITCH_E6, PULSE_1_2 + PULSE_4},

    {PITCH_REST, PULSE_1 + PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_B5, PULSE_1 + PULSE_1_2},
    {PITCH_E6, PULSE_1_2 + PULSE_1},
    {PITCH_D6, PULSE_1 + PULSE_2},

    {PITCH_REST, PULSE_1 + PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1 + PULSE_1_2},
    {PITCH_E6, PULSE_2},

    {PITCH_REST, PULSE_1_2},
};

static code Note_t M2[] =
{
    {PITCH_D6, PULSE_1},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1},
    {PITCH_G5, PULSE_1},
    {PITCH_F5, PULSE_1 + PULSE_2 + PULSE_1_2},
    {PITCH_REST, PULSE_1},
};

static code Note_t M3[] =
{
    {PITCH_D6, PULSE_1},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2 + PULSE_1},
    {PITCH_B5, PULSE_1_2},
    {PITCH_C6, PULSE_1_2 + PULSE_1 + PULSE_2},
    {PITCH_REST, PULSE_1},
};

static code Note_t M4[] =
{
    {PITCH_REST, PULSE_1},
    {PITCH_G5, PULSE_1},
    {PITCH_B5, PULSE_1},
    {PITCH_C6, PULSE_1},

    {PITCH_C6, PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_C6, PULSE_1},
    {PITCH_REST, PULSE_1},

    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_REST, PULSE_1_2},
    {PITCH_E6, PULSE_1},
    {PITCH_D6, PULSE_1_2},

    {PITCH_C6, PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_C6, PULSE_1},
    {PITCH_REST, PULSE_1},

    {PITCH_G6, PULSE_1_2},
    {PITCH_F6, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_REST, PULSE_1_2},
    {PITCH_E6, PULSE_1},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1 + PULSE_2},
    {PITCH_REST, PULSE_2 + PULSE_1_2},

    {PITCH_F6, PULSE_1},
    {PITCH_E6, PULSE_1},
    {PITCH_D6, PULSE_1_2},
    {PITCH_D6, PULSE_4},

    {PITCH_REST, PULSE_4},
};

static code Note_t M5[] =
{
    {PITCH_REST, PULSE_2},
    {PITCH_G5, PULSE_1_2},
    {PITCH_G5, PULSE_1},
    {PITCH_E6 , PULSE_1_2},
};

static code Note_t M6[] =
{
    {PITCH_E6, PULSE_1_2},
    {PITCH_D6, PULSE_1},
    {PITCH_D6, PULSE_1},
    {PITCH_C6, PULSE_1},
    {PITCH_D6, PULSE_1_2 + PULSE_1},
    {PITCH_REST, PULSE_1},

    {PITCH_G5, PULSE_1_2},
    {PITCH_G5, PULSE_1},
    {PITCH_F6, PULSE_1},
    {PITCH_E6, PULSE_1},
    {PITCH_E6, PULSE_1},
    {PITCH_D6, PULSE_1},
    {PITCH_E6, PULSE_1_2 + PULSE_2},
    {PITCH_REST, PULSE_2},

    {PITCH_E6, PULSE_1_2},
    {PITCH_D6, PULSE_1},
    {PITCH_D6, PULSE_1},
    {PITCH_C6, PULSE_1},
    {PITCH_C6, PULSE_1_2 + PULSE_2},
    {PITCH_REST, PULSE_2},
    
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_C6, PULSE_1},
    {PITCH_B5, PULSE_1},
    {PITCH_C6, PULSE_1_2},
};

static code Note_t M7[] =
{
    {PITCH_C6, PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_G5, PULSE_1_2},
    {PITCH_G5, PULSE_1},
    {PITCH_E6, PULSE_1_2},
};

static code Note_t M8[] =
{
    {PITCH_C6, PULSE_1 + PULSE_2},
    {PITCH_REST, PULSE_1}
};

static code Note_t M9[] =
{
    {PITCH_C6, PULSE_1_2},
    {PITCH_B5, PULSE_1},
    {PITCH_A5, PULSE_1},
    {PITCH_G5, PULSE_1},
    {PITCH_D6, PULSE_1_2 + PULSE_2},
    {PITCH_REST, PULSE_2},

    {PITCH_C6, PULSE_1_2},
    {PITCH_D6, PULSE_1},
    {PITCH_E6, PULSE_1},
    {PITCH_C6, PULSE_1},
    {PITCH_B5, PULSE_1_2 + PULSE_2 + PULSE_1},
    {PITCH_REST, PULSE_1 + PULSE_2},
    {PITCH_B5, PULSE_1},
    {PITCH_C6, PULSE_4},
    {PITCH_REST, PULSE_1},

    {PITCH_B5, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_B5, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_B5, PULSE_1},
    {PITCH_G5, PULSE_1_2},
    {PITCH_F5, PULSE_1_2},
    {PITCH_F5, PULSE_2},
    {PITCH_REST, PULSE_2},
    
    {PITCH_B5, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_B5, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_B5, PULSE_1},
    {PITCH_G5, PULSE_1_2},
    {PITCH_F5, PULSE_1_2},
    {PITCH_F5, PULSE_4},

    {PITCH_REST, PULSE_4},
};

#elif (MAIN_FIELD == 7)

/*---------------------------------------- Main Melody - Field 7 ------------------------------------*/

static code Note_t M1[] =
{
    {PITCH_REST, PULSE_2 + PULSE_1 + PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1 + PULSE_1_2},
    {PITCH_E7, PULSE_1_2 + PULSE_4},

    {PITCH_REST, PULSE_1 + PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1 + PULSE_1_2},
    {PITCH_E7, PULSE_1_2 + PULSE_1},
    {PITCH_D7, PULSE_1 + PULSE_2},

    {PITCH_REST, PULSE_1 + PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1 + PULSE_1_2},
    {PITCH_E7, PULSE_2},

    {PITCH_REST, PULSE_1_2},
};

static code Note_t M2[] =
{
    {PITCH_D7, PULSE_1},
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1},
    {PITCH_G6, PULSE_1},
    {PITCH_F6, PULSE_1 + PULSE_2 + PULSE_1_2},
    {PITCH_REST, PULSE_1},
};

static code Note_t M3[] =
{
    {PITCH_D7, PULSE_1},
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2 + PULSE_1},
    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_2 + PULSE_1 + PULSE_2},
    {PITCH_REST, PULSE_1},
};

static code Note_t M4[] =
{
    {PITCH_REST, PULSE_1},
    {PITCH_G6, PULSE_1},
    {PITCH_B6, PULSE_1},
    {PITCH_C7, PULSE_1},

    {PITCH_C7, PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_C7, PULSE_1},
    {PITCH_REST, PULSE_1},

    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    {PITCH_REST, PULSE_1_2},
    {PITCH_E7, PULSE_1},
    {PITCH_D7, PULSE_1_2},

    {PITCH_C7, PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_C7, PULSE_1},
    {PITCH_REST, PULSE_1},

    {PITCH_G7, PULSE_1_2},
    {PITCH_F7, PULSE_1_2},
    {PITCH_E7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    {PITCH_REST, PULSE_1_2},
    {PITCH_E7, PULSE_1},
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1 + PULSE_2},
    {PITCH_REST, PULSE_2 + PULSE_1_2},

    {PITCH_F7, PULSE_1},
    {PITCH_E7, PULSE_1},
    {PITCH_D7, PULSE_1_2},
    {PITCH_D7, PULSE_4},

    {PITCH_REST, PULSE_4},
};

static code Note_t M5[] =
{
    {PITCH_REST, PULSE_2},
    {PITCH_G6, PULSE_1_2},
    {PITCH_G6, PULSE_1},
    {PITCH_E7 , PULSE_1_2},
};

static code Note_t M6[] =
{
    {PITCH_E7, PULSE_1_2},
    {PITCH_D7, PULSE_1},
    {PITCH_D7, PULSE_1},
    {PITCH_C7, PULSE_1},
    {PITCH_D7, PULSE_1_2 + PULSE_1},
    {PITCH_REST, PULSE_1},

    {PITCH_G6, PULSE_1_2},
    {PITCH_G6, PULSE_1},
    {PITCH_F7, PULSE_1},
    {PITCH_E7, PULSE_1},
    {PITCH_E7, PULSE_1},
    {PITCH_D7, PULSE_1},
    {PITCH_E7, PULSE_1_2 + PULSE_2},
    {PITCH_REST, PULSE_2},

    {PITCH_E7, PULSE_1_2},
    {PITCH_D7, PULSE_1},
    {PITCH_D7, PULSE_1},
    {PITCH_C7, PULSE_1},
    {PITCH_C7, PULSE_1_2 + PULSE_2},
    {PITCH_REST, PULSE_2},
    
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_C7, PULSE_1},
    {PITCH_B6, PULSE_1},
    {PITCH_C7, PULSE_1_2},
};

static code Note_t M7[] =
{
    {PITCH_C7, PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_G6, PULSE_1_2},
    {PITCH_G6, PULSE_1},
    {PITCH_E7, PULSE_1_2},
};

static code Note_t M8[] =
{
    {PITCH_C7, PULSE_1 + PULSE_2},
    {PITCH_REST, PULSE_1}
};

static code Note_t M9[] =
{
    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1},
    {PITCH_A6, PULSE_1},
    {PITCH_G6, PULSE_1},
    {PITCH_D7, PULSE_1_2 + PULSE_2},
    {PITCH_REST, PULSE_2},

    {PITCH_C7, PULSE_1_2},
    {PITCH_D7, PULSE_1},
    {PITCH_E7, PULSE_1},
    {PITCH_C7, PULSE_1},
    {PITCH_B6, PULSE_1_2 + PULSE_2 + PULSE_1},
    {PITCH_REST, PULSE_1 + PULSE_2},
    {PITCH_B6, PULSE_1},
    {PITCH_C7, PULSE_4},
    {PITCH_REST, PULSE_1},

    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1},
    {PITCH_G6, PULSE_1_2},
    {PITCH_F6, PULSE_1_2},
    {PITCH_F6, PULSE_2},
    {PITCH_REST, PULSE_2},
    
    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_B6, PULSE_1},
    {PITCH_G6, PULSE_1_2},
    {PITCH_F6, PULSE_1_2},
    {PITCH_F6, PULSE_4},

    {PITCH_REST, PULSE_4},
};

#else
    #error Please assign the definition 'MAIN_FIELD' 6 or 7.
#endif


static code Melody_t Music1[] =
{
    {M1, sizeof(M1) / sizeof(Note_t)},
    {M2, sizeof(M2) / sizeof(Note_t)},
    {M1, sizeof(M1) / sizeof(Note_t)},
    {M3, sizeof(M3) / sizeof(Note_t)},
    {M4, sizeof(M4) / sizeof(Note_t)},
    {M5, sizeof(M5) / sizeof(Note_t)},
    {M6, sizeof(M6) / sizeof(Note_t)},
    {M7, sizeof(M7) / sizeof(Note_t)},
    {M6, sizeof(M6) / sizeof(Note_t)},
    {M8, sizeof(M8) / sizeof(Note_t)},
    {M9, sizeof(M9) / sizeof(Note_t)},
    {M5, sizeof(M5) / sizeof(Note_t)},
    {M6, sizeof(M6) / sizeof(Note_t)},
    {M7, sizeof(M7) / sizeof(Note_t)},
    {M6, sizeof(M6) / sizeof(Note_t)},
    {M8, sizeof(M8) / sizeof(Note_t)},
};

code Music_t Music_Rainbow_Main =
{
    /* .melodies = */ Music1,
    /* .NumOfMelody = */ sizeof(Music1) / sizeof(Melody_t)
};


#if (CHORD1_FIELD == 7)

/*---------------------------------------- Chord PULSE_1 ------------------------------------*/

static code Note_t c1m1[] =
{
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_4},
};

static code Note_t c1m2[] =
{
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_4},
    {PITCH_REST, PULSE_2},
    {PITCH_C7, PULSE_1},
    {PITCH_C7, PULSE_1_8},
    {PITCH_D7, PULSE_1_8},
    {PITCH_E7, PULSE_1_8},
    {PITCH_F7, PULSE_1_8},
    {PITCH_G7, PULSE_1_8},
    {PITCH_A7, PULSE_1_8},
    {PITCH_B7, PULSE_1_8},
};

static code Note_t c1m2_1[] =
{
    {PITCH_C8, PULSE_1_8 + PULSE_1 + PULSE_2},
    {PITCH_REST, PULSE_1},
};

static code Note_t c1m2_2[] =
{
    {PITCH_C8, PULSE_1_8 + PULSE_4},
};

static code Note_t c1m3[] =
{
    {PITCH_REST, PULSE_2 + PULSE_1_2},
    
    {PITCH_C7, PULSE_1_2 + PULSE_1},
    {PITCH_D7, PULSE_3},
    {PITCH_REST, PULSE_1 + PULSE_2 + PULSE_1_2,},
    {PITCH_B6, PULSE_1_2 + PULSE_1},
    {PITCH_C7, PULSE_3},
    {PITCH_C8, PULSE_3 + PULSE_1_2},

    {PITCH_B7, PULSE_1_2},
    {PITCH_C8, PULSE_1_2},
    {PITCH_G7, PULSE_1_2},
    {PITCH_F7, PULSE_2},
    {PITCH_REST, PULSE_1},

    {PITCH_E7, PULSE_1_2},
    {PITCH_F7, PULSE_1_2},
    {PITCH_G7, PULSE_1},
    {PITCH_G6, PULSE_1},
    {PITCH_E7, PULSE_1},
    {PITCH_F7, PULSE_1},
    {PITCH_E7, PULSE_3},
    {PITCH_REST, PULSE_1},

    {PITCH_REST, PULSE_2 + PULSE_1_2},
    {PITCH_G7, PULSE_1},
    {PITCH_F7, PULSE_1_4},
    {PITCH_E7, PULSE_1_4},
    {PITCH_D7, PULSE_2,},
    {PITCH_REST, PULSE_2},

    {PITCH_G7, PULSE_2 + PULSE_1_2},
    {PITCH_D8, PULSE_1 + PULSE_1_2},

    {PITCH_C8, PULSE_4},

    {PITCH_REST, PULSE_2},
    {PITCH_C8, PULSE_1_2},
    {PITCH_G7, PULSE_1_2},
    {PITCH_E7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_F7, PULSE_2},
    {PITCH_E7, PULSE_1_2},
    {PITCH_F7, PULSE_1_2 + PULSE_1},
    
    {PITCH_G7, PULSE_2},
    {PITCH_F7, PULSE_1_2},
    {PITCH_G7, PULSE_1_2 + PULSE_1},
    {PITCH_E7, PULSE_4},
};

static code Note_t c1m4[] =
{
    // 当大雨模糊
    {PITCH_REST, PULSE_1 + PULSE_1_2},
    {PITCH_E7, PULSE_1},
    {PITCH_D7, PULSE_1},
    {PITCH_C7, PULSE_1_2},

    {PITCH_G7, PULSE_1 + PULSE_1_2},
    {PITCH_F7, PULSE_1_4},
    {PITCH_E7, PULSE_1_4},
    {PITCH_D7, PULSE_2},
    
    {PITCH_REST, PULSE_2 + PULSE_1_2},
    {PITCH_A7, PULSE_1_2 + PULSE_1},
    {PITCH_G7, PULSE_3},
    {PITCH_D8, PULSE_3},
    {PITCH_A7, PULSE_1_2},
    {PITCH_G7, PULSE_1_2},
    {PITCH_E7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},

    {PITCH_C7, PULSE_3},
    {PITCH_C8, PULSE_3},
    {PITCH_A7, PULSE_1_2},
    {PITCH_G7, PULSE_1_2},
    {PITCH_E7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},

    {PITCH_F7, PULSE_4},
    {PITCH_REST, PULSE_2},
    {PITCH_F7, PULSE_1_2},
    {PITCH_E7, PULSE_1_2},
    {PITCH_D7, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},

    {PITCH_F7, PULSE_2},
    {PITCH_G7, PULSE_2},
    {PITCH_bA7, PULSE_4},
};

static code Note_t c1m6_1[] =
{
    {PITCH_C8, PULSE_2 + PULSE_1_2},

    {PITCH_B7, PULSE_1_2},
    {PITCH_C8, PULSE_1_2},
    {PITCH_G7, PULSE_1_2},
};

static code Note_t c1m6_1_1[] =
{
    {PITCH_E7, PULSE_1_4},
    {PITCH_D7, PULSE_1_4},
    {PITCH_C7, PULSE_1_2},
    {PITCH_E7, PULSE_1_2},
    {PITCH_F7, PULSE_1_2},
    
    {PITCH_F7, PULSE_1_4},
    {PITCH_E7, PULSE_1_4},
    {PITCH_D7, PULSE_1_2},
    {PITCH_E7, PULSE_1_2},
    {PITCH_F7, PULSE_1_2},
};

static code Note_t c1m6_2[] =
{
    {PITCH_G7, PULSE_2},
    {PITCH_REST, PULSE_2 + PULSE_1_2},
    {PITCH_E8, PULSE_1},
    {PITCH_D8, PULSE_1},
    {PITCH_C8, PULSE_1_2 + PULSE_1},

    {PITCH_D8, PULSE_3 + PULSE_1_2},
    {PITCH_G7, PULSE_1_2 + PULSE_1},
    {PITCH_C8, PULSE_2},
    {PITCH_B7, PULSE_1},

    {PITCH_C8, PULSE_4},
    {PITCH_REST, PULSE_1 + PULSE_1_2},

    {PITCH_B7, PULSE_1_4},
    {PITCH_C8, PULSE_1_4},

    {PITCH_C8, PULSE_1_4},
    {PITCH_B7, PULSE_1_4},
    {PITCH_A7, PULSE_1_4},
    {PITCH_G7, PULSE_1_4},
    {PITCH_A7, PULSE_1_4},
    {PITCH_G7, PULSE_1_4},
    {PITCH_D7, PULSE_1_4},
    {PITCH_C7, PULSE_1_4},

    {PITCH_F7, PULSE_4},
    {PITCH_G7, PULSE_4},
};

#elif (CHORD1_FIELD == 6)

/*---------------------------------------- Chord PULSE_1 - Fd 6------------------------------------*/

static code Note_t c1m1[] =
{
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_4},
};

static code Note_t c1m2[] =
{
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_4},
    {PITCH_REST, PULSE_2},
    {PITCH_C6, PULSE_1},
    {PITCH_C6, PULSE_1_8},
    {PITCH_D6, PULSE_1_8},
    {PITCH_E6, PULSE_1_8},
    {PITCH_F6, PULSE_1_8},
    {PITCH_G6, PULSE_1_8},
    {PITCH_A6, PULSE_1_8},
    {PITCH_B6, PULSE_1_8},
};

static code Note_t c1m2_1[] =
{
    {PITCH_C7, PULSE_1_8 + PULSE_1 + PULSE_2},
    {PITCH_REST, PULSE_1},
};

static code Note_t c1m2_2[] =
{
    {PITCH_C7, PULSE_1_8 + PULSE_4},
};

static code Note_t c1m3[] =
{
    {PITCH_REST, PULSE_2 + PULSE_1_2},
    
    {PITCH_C6, PULSE_1_2 + PULSE_1},
    {PITCH_D6, PULSE_3},
    {PITCH_REST, PULSE_1 + PULSE_2 + PULSE_1_2,},
    {PITCH_B5, PULSE_1_2 + PULSE_1},
    {PITCH_C6, PULSE_3},
    {PITCH_C7, PULSE_3 + PULSE_1_2},

    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_G6, PULSE_1_2},
    {PITCH_F6, PULSE_2},
    {PITCH_REST, PULSE_1},

    {PITCH_E6, PULSE_1_2},
    {PITCH_F6, PULSE_1_2},
    {PITCH_G6, PULSE_1},
    {PITCH_G5, PULSE_1},
    {PITCH_E6, PULSE_1},
    {PITCH_F6, PULSE_1},
    {PITCH_E6, PULSE_3},
    {PITCH_REST, PULSE_1},

    {PITCH_REST, PULSE_2 + PULSE_1_2},
    {PITCH_G6, PULSE_1},
    {PITCH_F6, PULSE_1_4},
    {PITCH_E6, PULSE_1_4},
    {PITCH_D6, PULSE_2,},
    {PITCH_REST, PULSE_2},

    {PITCH_G6, PULSE_2 + PULSE_1_2},
    {PITCH_D7, PULSE_1 + PULSE_1_2},

    {PITCH_C7, PULSE_4},

    {PITCH_REST, PULSE_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_G6, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},
    {PITCH_F6, PULSE_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_F6, PULSE_1_2 + PULSE_1},
    
    {PITCH_G6, PULSE_2},
    {PITCH_F6, PULSE_1_2},
    {PITCH_G6, PULSE_1_2 + PULSE_1},
    {PITCH_E6, PULSE_4},
};

static code Note_t c1m4[] =
{
    // 当大雨模糊
    {PITCH_REST, PULSE_1 + PULSE_1_2},
    {PITCH_E6, PULSE_1},
    {PITCH_D6, PULSE_1},
    {PITCH_C6, PULSE_1_2},

    {PITCH_G6, PULSE_1 + PULSE_1_2},
    {PITCH_F6, PULSE_1_4},
    {PITCH_E6, PULSE_1_4},
    {PITCH_D6, PULSE_2},
    
    {PITCH_REST, PULSE_2 + PULSE_1_2},
    {PITCH_A6, PULSE_1_2 + PULSE_1},
    {PITCH_G6, PULSE_3},
    {PITCH_D7, PULSE_3},
    {PITCH_A6, PULSE_1_2},
    {PITCH_G6, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},

    {PITCH_C6, PULSE_3},
    {PITCH_C7, PULSE_3},
    {PITCH_A6, PULSE_1_2},
    {PITCH_G6, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},

    {PITCH_F6, PULSE_4},
    {PITCH_REST, PULSE_2},
    {PITCH_F6, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_D6, PULSE_1_2},
    {PITCH_C6, PULSE_1_2},

    {PITCH_F6, PULSE_2},
    {PITCH_G6, PULSE_2},
    {PITCH_bA6, PULSE_4},
};

static code Note_t c1m6_1[] =
{
    {PITCH_C7, PULSE_2 + PULSE_1_2},

    {PITCH_B6, PULSE_1_2},
    {PITCH_C7, PULSE_1_2},
    {PITCH_G6, PULSE_1_2},
};

static code Note_t c1m6_1_1[] =
{
    {PITCH_E6, PULSE_1_4},
    {PITCH_D6, PULSE_1_4},
    {PITCH_C6, PULSE_1_2},
    {PITCH_E6, PULSE_1_2},
    {PITCH_F6, PULSE_1_2},
};

static code Note_t c1m6_2[] =
{
    {PITCH_G6, PULSE_4 + PULSE_1_2},
    {PITCH_E7, PULSE_1},
    {PITCH_D7, PULSE_1},
    {PITCH_C7, PULSE_1_2 + PULSE_1},

    {PITCH_D7, PULSE_3 + PULSE_1_2},
    {PITCH_G6, PULSE_1_2 + PULSE_1},
    {PITCH_C7, PULSE_2},
    {PITCH_B6, PULSE_1},

    {PITCH_C7, PULSE_4},
    {PITCH_REST, PULSE_1 + PULSE_1_2},

    {PITCH_B6, PULSE_1_4},
    {PITCH_C7, PULSE_1_4},

    {PITCH_C7, PULSE_1_4},
    {PITCH_B6, PULSE_1_4},
    {PITCH_A6, PULSE_1_4},
    {PITCH_G6, PULSE_1_4},
    {PITCH_A6, PULSE_1_4},
    {PITCH_G6, PULSE_1_4},
    {PITCH_D6, PULSE_1_4},
    {PITCH_C6, PULSE_1_4},

    {PITCH_F6, PULSE_4},
    {PITCH_G6, PULSE_4},
    {PITCH_C6, PULSE_4}
};

#else
    #error Please assign the definition 'CHORD1_FIELD' 6 or 7.
#endif


static code Melody_t Chord1[] =
{
    { c1m1, sizeof(c1m1) / sizeof(Note_t) },
    { c1m2, sizeof(c1m2) / sizeof(Note_t) },
    { c1m2_1, sizeof(c1m2_1) / sizeof(Note_t) },
    { c1m3, sizeof(c1m3) / sizeof(Note_t) },
    { c1m4, sizeof(c1m4) / sizeof(Note_t) },
    { c1m2, sizeof(c1m2) / sizeof(Note_t) },
    { c1m2_2, sizeof(c1m2_2) / sizeof(Note_t) },
    { c1m6_1, sizeof(c1m6_1) / sizeof(Note_t) },
    { c1m6_1_1, sizeof(c1m6_1_1) / sizeof(Note_t) },
    { c1m6_1_1, sizeof(c1m6_1_1) / sizeof(Note_t) },
    { c1m6_2, sizeof(c1m6_2) / sizeof(Note_t) },
};

code Music_t Music_Rainbow_C1 =
{
    Chord1,
    sizeof(Chord1) / sizeof(Melody_t)
};
