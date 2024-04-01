#include "main.h"
#include "bitmap_arcanoid1.h"

Psg psg;
void sound_driver();

// the setup routine runs once when you press reset:
// cppcheck-suppress unusedFunction
void setup()
{
    Serial.begin(115200);
    init_display();
    pinMode(AUDIO_OUT, OUTPUT);
    digitalWrite(AUDIO_OUT, 0);

    oled.drawBitmap(0, 0, arcanoid1, 128, 64);
    oled.update();
    delay(3000);

    multicore_fifo_drain();
    multicore_launch_core1(sound_driver);

    Serial.println(F("\nStarting\n"));
    game = new Game();
}

//cppcheck-suppress unusedFunction
void loop()
{
    // log_joystick_state();
    game->refresh();
    delay(20);
}

void sound_driver()
{
    while (true)
    {
        uint32_t _cmd = multicore_fifo_pop_blocking();
        SOUND _sound_cmd = (SOUND)_cmd;

        switch (_sound_cmd)
        {
        case NO:
            break;
        case BR1:
            psg.ball_hit_brick1();
            break;
        case BR2:
            psg.ball_hit_brick2();
            break;
        case BR3:
            psg.ball_hit_brick3();
            break;
        case PAD:
            psg.ball_hit_paddle();
            break;
        case START:
        case WIN: // while !multicore_fifo_rvalid() play_music
            // psg.win_music();
            break;
        case FAIL:
            // psg.lose_music();
            break;
        case TITLE:
            // psg.intro_music();
            break;
        default:
            break;
        }
    }
}