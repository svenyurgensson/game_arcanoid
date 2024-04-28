#include "psg.h"
#include "hardware/pwm.h"
#include "notes.h"

void Psg::init()
{
     // Устаравливаем режим пина подключенного к выводу звука
     pinMode(AUDIO_OUT, OUTPUT_12MA);
     pinMode(BEEP_OUT, OUTPUT_12MA);
     digitalWrite(AUDIO_OUT, 0);
     digitalWrite(BEEP_OUT, 0);
}

void Psg::ball_hit_paddle()
{
     pinMode(BEEP_OUT, OUTPUT_12MA);

     tone(NOTE_D1, 12, 0);
}

void Psg::ball_hit_brick1()
{
     pinMode(BEEP_OUT, OUTPUT_12MA);

     tone(NOTE_C5, 12, 0);
}

void Psg::ball_hit_brick2()
{
     pinMode(BEEP_OUT, OUTPUT_12MA);

     tone(NOTE_C3, 12, 0);
}

void Psg::ball_hit_brick3()
{
     pinMode(BEEP_OUT, OUTPUT_12MA);

     tone(NOTE_C1, 12, 0);
}

void Psg::title_music_init()
{
     init_mod_player(0);
}

void Psg::win_music_init()
{
     init_mod_player(1);
}

void Psg::fail_music_init()
{
     init_mod_player(2);
}

void Psg::next_music_tick()
{
     update_mod_player();
}

void Psg::stop_music()
{
     // update_mod_player();
}

void Psg::tone(unsigned int frequency_hz, unsigned long duration_ms, unsigned long post_play_delay_ms)
{
     // Play the required tone on the pizeo speaker pin

     // Get the cycle period in microseconds
     // NOTE Input is in Hz
     float period = 1000000 / (float)frequency_hz;

     // Get the microsecond timer now
     unsigned long start = time_us_64();

     // Loop until duration (milliseconds) in microseconds has elapsed
     while (time_us_64() < start + duration_ms * 1000)
     {
          digitalWrite(BEEP_OUT, 1);
          sleep_us(0.5 * period);
          digitalWrite(BEEP_OUT, 0);
          sleep_us(0.5 * period);
     };

     // Apply a post-tone delay
     if (post_play_delay_ms > 0)
          sleep_ms(post_play_delay_ms);
}