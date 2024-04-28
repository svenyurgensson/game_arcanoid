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
    Serial.println(F("\nStarting\n"));
    
    // Инициализируем дисплей
    init_display();

    // Очищаем  FIFO буффер обмена между ядрами процессора
    multicore_fifo_drain();
    // Стартуем драйвер звука на втором ядре процессора
    multicore_launch_core1(sound_driver);
    delay(1);

    // Рисуем заставку, стартуем интро музыку и небольшая задержка перед переходом в игру
    oled.drawBitmap(0, 0, arcanoid1, 128, 64);
    oled.update();    
    audio_command_play(START);
    delay(3000);

    game = new Game();
}

// Основной цикл игры, обновляемся каждые 20мс
//cppcheck-suppress unusedFunction
void loop()
{
    log_joystick_state();
    game->refresh();
    delay(20);
}

// Звуковой драйвер, работает в бесконечном цикле, запускается на втором ядре процессора
// Ожидает команды от первого ядра процессора при помощи чтения из своего входного FIFO буфера
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
        case WIN: 
            psg.win_music_init();
            play_music_until_break();
            break;
        case FAIL:
            //psg.fail_music_init();
            //play_music_until_break();
            break;
        case START:            
        case TITLE:   
            //psg.title_music_init();               
            //play_music_until_break();
            break;
        default:
            break;
        }
    }
}

// играем музыку, пока процессору не пришла другая команда в FIFO второго ядра
void play_music_until_break(void)
{    
    while (!multicore_fifo_rvalid())
    {
        psg.next_music_tick();
        sleep_ms(20);
    } 
    psg.stop_music();
}