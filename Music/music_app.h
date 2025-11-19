#ifndef __MUSIC_APP_H
#define __MUSIC_APP_H

#include "config.h"
#include "music.h"

/*---------------------------------------- Exported Types --------------------------------------*/

typedef enum app_music_state_t
{
    APP_MUSIC_STOP,
    APP_MUSIC_PLAY,
    APP_MUSIC_PAUSE,
} app_music_state_t;

typedef enum app_music_start_status_t
{
    APP_Music_Start_OK,
    APP_Music_Start_ERROR_NUM,
    APP_Music_Start_ERROR_BUSY,
} app_music_start_status_t;

/**
 * @brief Music list elements, provide information of a multi-melody music.
 * 
 */
typedef struct app_music_list_t
{
    u8 num;             // numbering of music
    const Music_t *m1;  // melody 1
    const Music_t *m2;  // melody 2
    const Music_t *m3;  // melody 3
    u8 bpm;       // speed of music
} app_music_list_t;

typedef struct app_music_control_t
{
    const app_music_list_t *list;   // music list
    const u8 list_size;             // number of songs
    u8 pnum;                        // position of current music
    MusicControl_t *ctrl;           // music play control
    u8 state;                       // music state  
} app_music_control_t;


/*---------------------------------------- Exported Variables --------------------------------------*/

extern app_music_control_t app_music_control;


/*---------------------------------------- Exported Functions --------------------------------------*/

void app_music_task(void);

app_music_start_status_t app_music_start(u8 number);
void app_music_stop(void);
BOOL app_music_pause(void);
BOOL app_music_resume(void);

#endif // !__MUSIC_APP_H
