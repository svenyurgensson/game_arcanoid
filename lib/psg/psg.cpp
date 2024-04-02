#include "psg.h"
#include "hardware/pwm.h"
#include "notes.h"

void Psg::init()
{
     digitalWrite(AUDIO_OUT, 0);
}

void Psg::ball_hit_paddle()
{
     pinMode(AUDIO_OUT, OUTPUT);

     tone(NOTE_D1, 12, 0);
}

void Psg::ball_hit_brick1()
{
     pinMode(AUDIO_OUT, OUTPUT);

     tone(NOTE_C5, 12, 0);
}

void Psg::ball_hit_brick2()
{
     pinMode(AUDIO_OUT, OUTPUT);

     tone(NOTE_C3, 12, 0);
}

void Psg::ball_hit_brick3()
{
     pinMode(AUDIO_OUT, OUTPUT);

     tone(NOTE_C1, 12, 0);
}

void Psg::intro_music()
{
     // Tell GPIO PWM
     gpio_set_function(AUDIO_OUT, GPIO_FUNC_PWM);
}

void Psg::win_music()
{
     // Tell GPIO PWM
     gpio_set_function(AUDIO_OUT, GPIO_FUNC_PWM);

}

void Psg::lose_music()
{

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
          digitalWrite(AUDIO_OUT, 1);
          sleep_us(0.5 * period);
          digitalWrite(AUDIO_OUT, 0);
          sleep_us(0.5 * period);
     };

     // Apply a post-tone delay
     if (post_play_delay_ms > 0)
          sleep_ms(post_play_delay_ms);
}