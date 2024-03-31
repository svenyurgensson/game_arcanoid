#pragma once
#include <Arduino.h>

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

    void intro_music();
    void win_music();
    void lose_music();
    

private:
    void tone(unsigned int frequency_hz, unsigned long duration_ms, unsigned long post_play_delay_ms);
};
