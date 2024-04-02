#pragma once
#include <Arduino.h>
#include "mod_player/player.h"

// sound out
#define AUDIO_OUT 16

class Psg 
{
public:
    Psg() 
    {
        init();
    }

    void init();
    void ball_hit_paddle();
    void ball_hit_brick1();
    void ball_hit_brick2();
    void ball_hit_brick3();

    void title_music_init();
    void win_music_init();
    void fail_music_init();
    void next_music_tick();
    

private:
    void tone(unsigned int frequency_hz, unsigned long duration_ms, unsigned long post_play_delay_ms);
};
