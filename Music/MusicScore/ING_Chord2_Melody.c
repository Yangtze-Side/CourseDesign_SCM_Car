
#include "ING_Chord2_Melody.h"

static Note_t code M1[] =
{
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},
    {PITCH_REST, PULSE_8},

    {PITCH_E6, PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_G6, PULSE_1_2 + PULSE_1_4},
    {PITCH_F6, PULSE_1_4},
    {PITCH_E6, PULSE_1_2 + PULSE_1_4},
    {PITCH_F6, PULSE_1_4},

    {PITCH_E6, PULSE_1 + PULSE_1_2},
    {PITCH_REST, PULSE_2 + PULSE_1_2},

    {PITCH_REST, PULSE_1},
    {PITCH_F6, PULSE_1_2 + PULSE_1_4},
    {PITCH_G6, PULSE_1_4},
    {PITCH_A6, PULSE_1_2},
    {PITCH_REST, PULSE_1_4},
    {PITCH_G6, PULSE_1_4},
    {PITCH_F6, PULSE_1_2 + PULSE_1_4},
    {PITCH_E6, PULSE_1_4},

    {PITCH_E6, PULSE_2},
    {PITCH_REST, PULSE_2},

    {PITCH_E6, PULSE_1},
    {PITCH_REST, PULSE_1},
    {PITCH_G6, PULSE_1_2 + PULSE_1_4},
    {PITCH_F6, PULSE_1_4},
    {PITCH_E6, PULSE_1_2 + PULSE_1_4},
    {PITCH_F6, PULSE_1_4},

    {PITCH_E6, PULSE_2},
    {PITCH_A6, PULSE_2},

    {PITCH_REST, PULSE_2},
    {PITCH_A7, PULSE_1_2 + PULSE_1_4},
    {PITCH_G7, PULSE_1_4},
    {PITCH_A7, PULSE_1_2 + PULSE_1_4},
    {PITCH_B7, PULSE_1_4},

    {PITCH_C8, PULSE_2 + PULSE_1 + PULSE_1_2},
    {PITCH_REST, PULSE_1_2},


    {PITCH_C7, PULSE_1 + PULSE_1_2 + PULSE_1_4},
    {PITCH_E7, PULSE_1_4},
    {PITCH_D7, PULSE_1},
    {PITCH_E7, PULSE_1},
    {PITCH_G7, PULSE_4 - PULSE_1_4},
    {PITCH_REST, PULSE_1_4},

    {PITCH_A7, PULSE_2},
    {PITCH_C8, PULSE_1},
    {PITCH_A7, PULSE_1},
    {PITCH_G7, PULSE_1},
    {PITCH_REST, PULSE_1},

    {PITCH_A7, PULSE_1},
    {PITCH_B7, PULSE_1},
    {PITCH_C8, PULSE_2},
    {PITCH_E8, PULSE_2},
    {PITCH_G8, PULSE_2},

    {PITCH_A8, PULSE_1},
    {PITCH_G8, PULSE_1},
    {PITCH_F8, PULSE_2},
    {PITCH_B7, PULSE_2},
    {PITCH_C8, PULSE_4 - PULSE_1_2},
    {PITCH_REST, PULSE_1_2},
};

static Melody_t code Music1[] =
{
    {
        /* .notes = */ M1,
        /* .NumOfNotes = */ (sizeof(M1) / sizeof(Note_t))
    },
};

code Music_t Music_ING_2 =
{
    Music1,
    1
};
