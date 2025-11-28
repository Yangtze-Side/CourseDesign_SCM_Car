
#include "GrainInEar.h"

static code Note_t M1[] =
{
    PITCH_C5, PULSE_1,
    PITCH_REST, PULSE_1_2,
    PITCH_C5, PULSE_1_4,
    PITCH_C5, PULSE_1_4,
    PITCH_REST, PULSE_1_4,
    PITCH_C5, PULSE_1_4,
    PITCH_C5, PULSE_1_2,
    PITCH_C5, PULSE_1_2,
    PITCH_C5, PULSE_1_2,

    PITCH_D5, PULSE_1,
    PITCH_REST, PULSE_1_2,
    PITCH_D5, PULSE_1_4,
    PITCH_D5, PULSE_1_4,
    PITCH_REST, PULSE_1_4,
    PITCH_D5, PULSE_1_4,
    PITCH_D5, PULSE_1_2,
    PITCH_D5, PULSE_1_2,
    PITCH_D5, PULSE_1_2,

    PITCH_G5, PULSE_1,
    PITCH_REST, PULSE_1_2,
    PITCH_G5, PULSE_1_4,
    PITCH_G5, PULSE_1_4,
    PITCH_REST, PULSE_1_4,
    PITCH_G5, PULSE_1_4,
    PITCH_G5, PULSE_1_2,
    PITCH_G5, PULSE_1_2,
    PITCH_E5, PULSE_1_2,

    PITCH_F5, PULSE_1 + PULSE_1_2,
    PITCH_E5, PULSE_1_4,
    PITCH_F5, PULSE_1_4,
    PITCH_G5, PULSE_1,
    PITCH_B5, PULSE_1
};

static code Note_t M2[] =
{
    PITCH_G5, PULSE_1_4,
    PITCH_E5, PULSE_1_4,
    PITCH_E5, PULSE_1_4,
    PITCH_G5, PULSE_1_4,

    PITCH_E5, PULSE_1_4,
    PITCH_E5, PULSE_1_4,
    PITCH_G5, PULSE_1_4,
    PITCH_E5, PULSE_1_4,

    PITCH_E5, PULSE_1_4,
    PITCH_G5, PULSE_1_4,
    PITCH_E5, PULSE_1_4,
    PITCH_E5, PULSE_1_4,

    PITCH_G5, PULSE_1_4,
    PITCH_E5, PULSE_1_4,
    PITCH_G5, PULSE_1_4,
    PITCH_A5, PULSE_1_4,

    PITCH_C6, PULSE_1_4,
    PITCH_C6, PULSE_1_4,
    PITCH_G5, PULSE_1_4,
    PITCH_C6, PULSE_1_4,

    PITCH_C6, PULSE_1_4,
    PITCH_G5, PULSE_1_4,
    PITCH_C6, PULSE_1_4,
    PITCH_C6, PULSE_1_4,

    PITCH_G5, PULSE_1_4,
    PITCH_C6, PULSE_1_4,
    PITCH_C6, PULSE_1_4,
    PITCH_G5, PULSE_1_4,

    PITCH_C6, PULSE_1_4,
    PITCH_G5, PULSE_1_4,
    PITCH_C6, PULSE_1_4,
    PITCH_E6, PULSE_1_4,

    PITCH_D6, PULSE_1_4,
    PITCH_D6, PULSE_1_4,
    PITCH_G5, PULSE_1_4,
    PITCH_E6, PULSE_1_4,

    PITCH_E6, PULSE_1_4,
    PITCH_G5, PULSE_1_4,
    PITCH_D6, PULSE_1_4,
    PITCH_D6, PULSE_1_4,

    PITCH_G5, PULSE_1_4,
    PITCH_E6, PULSE_1_4,
    PITCH_E6, PULSE_1_4,
    PITCH_G5, PULSE_1_4,

    PITCH_D6, PULSE_1_4,
    PITCH_G5, PULSE_1_4,
    PITCH_E6, PULSE_1_4,
    PITCH_G5, PULSE_1_4,

    PITCH_D6, PULSE_1_4,
    PITCH_C6, PULSE_1_4,
    PITCH_B5, PULSE_1_4,
    PITCH_A5, PULSE_1_4,

    PITCH_B5, PULSE_1_4,
    PITCH_A5, PULSE_1_4,
    PITCH_G5, PULSE_1_4,
    PITCH_D5, PULSE_1_4,
};

static code Note_t M3[] =
{
    PITCH_G5, PULSE_1_4,
    PITCH_D5, PULSE_1_4,
    PITCH_B4, PULSE_1_4,
    PITCH_A4, PULSE_1_4,

    PITCH_B4, PULSE_1_2,
    PITCH_B4, PULSE_1_4,
    PITCH_D5, PULSE_1_4,

    PITCH_C5, PULSE_1_4,
    PITCH_REST, PULSE_1_4,
    PITCH_G5, PULSE_1_4,
    PITCH_G5, PULSE_1_8,
    PITCH_G5, PULSE_1_8,
};

static code Note_t M4[] =
{
    PITCH_E5, PULSE_1_4,
    PITCH_REST, PULSE_1_4,
    PITCH_G5, PULSE_1_4,
    PITCH_G5, PULSE_1_8,
    PITCH_G5, PULSE_1_8
};

static code Note_t M5[] =
{
    PITCH_F5, PULSE_1_4,
    PITCH_REST, PULSE_1_4,
    PITCH_G5, PULSE_1_4,
    PITCH_G5, PULSE_1_8,
    PITCH_G5, PULSE_1_8,
};

static code Note_t M6[] =
{
    PITCH_C6, PULSE_1_2,
    PITCH_G5, PULSE_1_2,
    PITCH_C6, PULSE_1_2,
    PITCH_G5, PULSE_1_2,

    PITCH_D6, PULSE_1_2,
    PITCH_G5, PULSE_1_2,
    PITCH_E6, PULSE_1_2,
    PITCH_G5, PULSE_1_2,

    PITCH_F6, PULSE_1_2,
    PITCH_G5, PULSE_1_2,
    PITCH_G6, PULSE_1_2,
    PITCH_G5, PULSE_1_2,

    PITCH_F6, 3,
    PITCH_G6, 3,
    PITCH_F6, 2,
    PITCH_E6, 3,
    PITCH_F6, 3,
    PITCH_E6, 2,
    PITCH_D6, 3,
    PITCH_E6, 3,
    PITCH_D6, 2,
    PITCH_C6, PULSE_1_4,
    PITCH_REST, PULSE_1_4,
};

static code Note_t M7[] =
{
    {PITCH_A4, PULSE_2},
};

static code Melody_t Music1[] =
{
    { M1, sizeof(M1)/sizeof(Note_t) },
    { M2, sizeof(M2)/sizeof(Note_t) },
    { M3, sizeof(M3)/sizeof(Note_t) },
    { M4, sizeof(M4)/sizeof(Note_t) },
    { M4, sizeof(M4)/sizeof(Note_t) },
    { M4, sizeof(M4)/sizeof(Note_t) },
    { M5, sizeof(M5)/sizeof(Note_t) },
    { M5, sizeof(M5)/sizeof(Note_t) },
    { M5, sizeof(M5)/sizeof(Note_t) },
    { M5, sizeof(M5)/sizeof(Note_t) },
    { M6, sizeof(M6)/sizeof(Note_t) },
    { M2, sizeof(M2)/sizeof(Note_t) },
    { M7, sizeof(M7)/sizeof(Note_t) },
};


Music_t code Music_GrainInEar =
{
    Music1,
    sizeof(Music1) / sizeof(Melody_t)
};
