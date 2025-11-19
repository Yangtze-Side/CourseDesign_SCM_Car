
#include "music_app.h"
#include "MusicScore.h"
#include "system.h"

#include "user_driver.h"

/*---------------------------------------- Exported Defines --------------------------------------*/

#define MUSIC1_TIM          TIM1
#define MUSIC2_TIM          TIM3
#define MUSIC3_TIM          TIM4

#define MUSIC_MIN_NO        1
#define MUSIC_MAX_NO        4


#define Set_BeatTimer_Period(bpm)           \
    User_PCA_M0_SetPeriod( User_PCA_Freq2Period((bpm) * PULSE_1 * Pulse_To_Period_FACTOR / 60.0f) )

static u16 beat_cnt = 0;        // used to count the rythm and identify a beat

// Music list
const app_music_list_t app_music_list[] =
{
    {
        /* .num = */ 1,
        /* .m1 = */ &Music_HeadToFutureTogether,
        /* .m2 = */ NULL,
        /* .m3 = */ NULL,
        /* .bpm = */ 124
    },
    {
        /* .num = */ 2,
        /* .m1 = */ &Music_ING_Main,
        /* .m2 = */ &Music_ING_1,
        /* .m3 = */ &Music_ING_2,
        /* .bpm = */ 128
    },
    {
        /* .num = */ 3,
        /* .m1 = */ &Music_Rainbow_Main,
        /* .m2 = */ &Music_Rainbow_C1,
        /* .m3 = */ NULL,
        /* .bpm = */ 144
    },
    {
        /* .num = */ 4,
        /* .m1 = */ &Music_ShanhuHai_Main1,
        /* .m2 = */ &Music_ShanhuHai_Main2,
        /* .m3 = */ NULL,
        /* .bpm = */ 74
    }
};

static MusicControl_t music_ctrl[3] = {
    {
        /* .timIndex = */ MUSIC1_TIM,
        /* .pmelody = */ 0,
        /* .pnote = */ 0,
        /* .curr_note_time = */ 0,
        /* .state = */ Music_PAUSE,
    },
    {
        /* .timIndex = */ MUSIC2_TIM,
        /* .pmelody = */ 0,
        /* .pnote = */ 0,
        /* .curr_note_time = */ 0,
        /* .state = */ Music_PAUSE,
    },
    {
        /* .timIndex = */ MUSIC3_TIM,
        /* .pmelody = */ 0,
        /* .pnote = */ 0,
        /* .curr_note_time = */ 0,
        /* .state = */ Music_PAUSE,
    },
};

app_music_control_t app_music_control =
{
    /* .list = */ app_music_list,
    /* .list_size = */ sizeof(app_music_list) / sizeof(app_music_list_t),
    /* .pnum = */ 0,
    /* .ctrl = */ music_ctrl,
    /* .state = */ APP_MUSIC_STOP
};

#define Curr_List()                     (app_music_control.list[app_music_control.pnum])


/**
 * @brief Run upon the music time period.
 * 
 */
void app_music_task(void)
{
    if (app_music_control.state == APP_MUSIC_PLAY)
    {
        if (++beat_cnt >= PULSE_1 * Pulse_To_Period_FACTOR * 2)
        {
            beat_cnt = 0;
            // One beat is over and you can do something alnog the beat.
        }
    }

    MusicTask(app_music_control.list[app_music_control.pnum].m1, &app_music_control.ctrl[0]);
    MusicTask(app_music_control.list[app_music_control.pnum].m2, &app_music_control.ctrl[1]);
    MusicTask(app_music_control.list[app_music_control.pnum].m3, &app_music_control.ctrl[2]);

    // Determine the condition of termination
    if (app_music_control.ctrl[0].state == Music_STOP &&
        app_music_control.ctrl[1].state == Music_STOP &&
        app_music_control.ctrl[2].state == Music_STOP)
    {
        app_music_control.state = APP_MUSIC_STOP;
        Set_BeatTimer_Period(120);
    }
}


/**
 * @brief Starts the music according the numbering.
 * 
 * @param number music numbering
 * @return app_music_start_status_t start status
 */
app_music_start_status_t app_music_start(u8 number)
{
    u8 i = 0;
    u8 is_searched = FALSE;
	
    beat_cnt = 0;

    for (; i < app_music_control.list_size; i++)
    {
        if (app_music_control.list[i].num == number)
        {
            is_searched = TRUE;
            break;
        }
    }

    if (is_searched == TRUE)
    {
        // Start the music
        app_music_control.pnum = i;

        // Set bps
        Set_BeatTimer_Period(Curr_List().bpm);

        MusicStop(&app_music_control.ctrl[0]);
        MusicStop(&app_music_control.ctrl[1]);
        MusicStop(&app_music_control.ctrl[2]);

        if (Curr_List().m1 != NULL) MusicStart(Curr_List().m1, &app_music_control.ctrl[0]);
        if (Curr_List().m2 != NULL) MusicStart(Curr_List().m2, &app_music_control.ctrl[1]);
        if (Curr_List().m3 != NULL) MusicStart(Curr_List().m3, &app_music_control.ctrl[2]);
        
        app_music_control.state = APP_MUSIC_PLAY;
    }

    return (is_searched == TRUE ? APP_Music_Start_OK : APP_Music_Start_ERROR_NUM);
}


/**
 * @brief Stops the music.
 * 
 */
void app_music_stop(void)
{
    MusicStop(&app_music_control.ctrl[0]);
    MusicStop(&app_music_control.ctrl[1]);
    MusicStop(&app_music_control.ctrl[2]);

    app_music_control.state = APP_MUSIC_STOP;
}


/**
 * @brief Pauses the music.
 * 
 * @return BOOL if success or not
 */
BOOL app_music_pause(void)
{
    if (app_music_control.state != APP_MUSIC_PLAY) return FALSE;

    MusicPause(&app_music_control.ctrl[0]);
    MusicPause(&app_music_control.ctrl[1]);
    MusicPause(&app_music_control.ctrl[2]);

    app_music_control.state = APP_MUSIC_PAUSE;

    return TRUE;
}


/**
 * @brief Let the music resume.
 * 
 * @return BOOL if success or not
 */
BOOL app_music_resume(void)
{
    if (app_music_control.state != APP_MUSIC_PAUSE) return FALSE;

    MusicResume(Curr_List().m1, &app_music_control.ctrl[0]);
    MusicResume(Curr_List().m2, &app_music_control.ctrl[1]);
    MusicResume(Curr_List().m3, &app_music_control.ctrl[2]);
    
    app_music_control.state = APP_MUSIC_PLAY;
    return TRUE;
}
