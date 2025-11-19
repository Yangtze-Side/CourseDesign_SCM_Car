#ifndef __MUSIC_H
#define __MUSIC_H

#include "config.h"

/*------------------------------------------- Library ---------------------------------------*/

// 音符，不可相加
typedef enum Pitch_t
{
    PITCH_C4, PITCH_bD4, PITCH_D4, PITCH_bE4, PITCH_E4, PITCH_F4, PITCH_bG4, PITCH_G4, PITCH_bA4, PITCH_A4, PITCH_bB4, PITCH_B4,
    PITCH_C5, PITCH_bD5, PITCH_D5, PITCH_bE5, PITCH_E5, PITCH_F5, PITCH_bG5, PITCH_G5, PITCH_bA5, PITCH_A5, PITCH_bB5, PITCH_B5,
    PITCH_C6, PITCH_bD6, PITCH_D6, PITCH_bE6, PITCH_E6, PITCH_F6, PITCH_bG6, PITCH_G6, PITCH_bA6, PITCH_A6, PITCH_bB6, PITCH_B6,
    PITCH_C7, PITCH_bD7, PITCH_D7, PITCH_bE7, PITCH_E7, PITCH_F7, PITCH_bG7, PITCH_G7, PITCH_bA7, PITCH_A7, PITCH_bB7, PITCH_B7,
    PITCH_C8, PITCH_bD8, PITCH_D8, PITCH_bE8, PITCH_E8, PITCH_F8, PITCH_bG8, PITCH_G8, PITCH_bA8, PITCH_A8, PITCH_bB8, PITCH_B8,
    PITCH_C9, PITCH_bD9, PITCH_D9, PITCH_bE9, PITCH_E9, PITCH_F9, PITCH_bG9, PITCH_G9, PITCH_bA9, PITCH_A9, PITCH_bB9, PITCH_B9,
    PITCH_REST,
} Pitch_t;


#define Pulse_To_Period_FACTOR      8      // Pulse 转换到基准时间片个数的因子

// 音符时长记号，可以相加，转换到周期重装值需要乘以 Pulse_To_Period_FACTOR
typedef enum Pulse_t
{
    PULSE_1_16  = (u8)1,
    PULSE_1_8   = (u8)2,
    PULSE_1_4   = (u8)4,
    PULSE_1_2   = (u8)8,
    PULSE_1     = (u8)16,
    PULSE_2     = (u8)32,
    PULSE_3     = (u8)48,
    PULSE_4     = (u8)64,
    PULSE_8     = (u8)128,
} Pulse_t;


typedef struct Note_t
{
    u8 pitch;
    u8 pulse;
} Note_t;

typedef struct Melody_t
{
    const Note_t *notes;
    u16 NumOfNotes;
} Melody_t;

typedef struct Music_t
{
    const Melody_t *melodies;
    u8 NumOfMelody;
} Music_t;


typedef enum music_state_t
{
    Music_STOP,
    Music_PAUSE,
    Music_PLAY
} music_state_t;


typedef struct MusicControl_t
{
    u8  timIndex;

    u8  pmelody;
    u16 pnote;
    u16 curr_note_time;
    u8  state;
} MusicControl_t;


void MusicTask(const Music_t *m, MusicControl_t *c);

void MusicStart(const Music_t *m, MusicControl_t *c);
void MusicResume(const Music_t *m, MusicControl_t *c);
void MusicPause(MusicControl_t *c);
void MusicStop(MusicControl_t *c);

#endif // !__MUSIC_H
