
#include "music.h"
#include "freq_table.h"

#include "user_driver.h"

/*------------------------------------------- User Determine ---------------------------------------*/

#define Tim_ForceHigh(c)                    User_TIM_CLKOCmd(c->timIndex, DISABLE)
#define Tim_Compare(c)                      User_TIM_CLKOCmd(c->timIndex, ENABLE)

#define TIM_SetAutoReload(timx, arr)        User_TIM_SetARR(timx, arr)


#define CurrNote(_pm, _pc)       (_pm->melodies[_pc->pmelody].notes[_pc->pnote])
#define CurrMelody(_pm, _pc)     (_pm->melodies[_pc->pmelody])


/**
 * @brief 根据 MusicControl 中的指针，加载当前音符的时长和音调。
 * 
 * @param m 音乐结构体
 */
static void MusicNoteSet(const Music_t *m, MusicControl_t *c) reentrant
{
    c->curr_note_time = CurrNote(m, c).pulse * Pulse_To_Period_FACTOR;

    if (c->curr_note_time == 0)
    {
        // An Exception Occured.
        MusicStop(c);
        return;
    }

    if (CurrNote(m, c).pitch == PITCH_REST)
    {
        Tim_ForceHigh(c);
    }
    else
    {
        TIM_SetAutoReload(c->timIndex, Get_Freq(CurrNote(m, c).pitch));
        Tim_Compare(c);
    }
}


/**
 * @brief 音乐播放任务。
 * @note  放在基准时间片的中断服务函数里。
 * 
 * @param m     音乐
 */
void MusicTask(const Music_t *m, MusicControl_t *c)
{
    if (c->state != Music_PLAY) return;
    if (m == NULL) return;

    if (c->curr_note_time == 0)
    {
        // Next Note.
        if (++c->pnote >= CurrMelody(m, c).NumOfNotes)
        {
            c->pnote = 0;
            // Next Melody.
            if (++c->pmelody >= m->NumOfMelody)
            {
                c->pmelody = 0;
                // The Music Ends.
                c->state = Music_STOP;
                Tim_ForceHigh(c);
                return;
            }
        }

        MusicNoteSet(m, c);
    }

    // Pulse PULSE_1_4 and longer rests at the last time period.
    else if (c->curr_note_time == 1 && CurrNote(m, c).pulse >= PULSE_1_4)
    {
        // REST
        Tim_ForceHigh(c);
    }

    c->curr_note_time--;
}


// 开始播放
void MusicStart(const Music_t *m, MusicControl_t *c)
{
    if (m == NULL) return;

    c->pnote = 0;
    c->pmelody = 0;
    MusicNoteSet(m, c);
    c->state = Music_PLAY;
}

// 继续播放
void MusicResume(const Music_t *m, MusicControl_t *c)
{
    if (c->state != Music_PAUSE || m == NULL) return;

    if (CurrNote(m, c).pitch != PITCH_REST)
    {
        TIM_SetAutoReload(c->timIndex, Get_Freq(CurrNote(m, c).pitch));
        Tim_Compare(c);
    }
    else
    {
        Tim_ForceHigh(c);
    }
    c->state = Music_PLAY;
}

// 暂停
void MusicPause(MusicControl_t *c)
{
    if (c->state == Music_PLAY)
    {
        c->state = Music_PAUSE;
        Tim_ForceHigh(c);
    }
}

// 停止
void MusicStop(MusicControl_t *c)
{
    c->pnote = 0;
    c->pmelody = 0;
    c->curr_note_time = 0;
    c->state = Music_STOP;
    Tim_ForceHigh(c);
}
