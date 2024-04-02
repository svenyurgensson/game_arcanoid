#include "main.h"
#include "bitmap_arcanoid1.h"
#include "pico/binary_info.h"

Psg psg;

// the setup routine runs once when you press reset:
// cppcheck-suppress unusedFunction
void setup()
{
    bi_decl(bi_program_description("Arkanoid Game"));

    Serial.begin(115200);
    init_display();
    pinMode(AUDIO_OUT, OUTPUT);
    digitalWrite(AUDIO_OUT, 0);

    multicore_fifo_drain();
    multicore_launch_core1(sound_driver);
    delay(1);
    oled.drawBitmap(0, 0, arcanoid1, 128, 64);
    oled.update();    
    audio_command_play(START);
    delay(3000);

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
        case WIN: // while !multicore_fifo_rvalid() play_music
            psg.win_music_init();
            blocked_music_tick();
            break;
        case FAIL:
            psg.fail_music_init();
            blocked_music_tick();
            break;
        case START:            
        case TITLE:   
            psg.title_music_init();               
            blocked_music_tick();
            break;
        default:
            break;
        }
    }
}

void blocked_music_tick(void)
{
    // играем музыку, пока процессору не пришла другая команда в CPU FIFO
    while (!multicore_fifo_rvalid())
    {
        sleep_ms(20);
        psg.next_music_tick();
    }  
}