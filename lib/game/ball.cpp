#include "ball.h"

Ball::Ball(int16_t x, int16_t y, Game *g) : pos_x(x), pos_y(y), game(g)
{
    dx = 0;
    dy = 0;
    ball_state = INIT;
}

void Ball::draw_and_check_collisions()
{
    calculate_move();

    renderer.draw_ball(pos_x, pos_y);
    
    if (JOYPAD_UP_PRESSED && ball_state == INIT) // стартуем мяч клавишей вверх
    {
        ball_state = MOVE;
        while(JOYPAD_UP_PRESSED) delay(1); // ждем отжатия клавиши
    } 
}

/* 
  Расчитываем новые координаты мяча
  Обрабатываем столкновение с битой  
 */
void Ball::calculate_move()
{
    uint8_t pad_pos_x = game->paddle->pos_x,
            pad_pos_y = game->paddle->pos_y;

    if (ball_state == INIT)
    {
        pos_x = pad_pos_x + 8;
        pos_y = pad_pos_y - 6;
        dx = speed;
        dy = -speed;
    }

    if (ball_state == MOVE)
    {
        // Проверяем, ударился ли мяч об биту
        if ((pos_x >= (pad_pos_x - 4) && pos_x <= (pad_pos_x + PADDLE_WIDTH + 4)) &&
            pos_y >= (pad_pos_y - 5) && pos_y <= (pad_pos_y - 2))
        {
            dy = -dy;
            float diff = pad_pos_x + PADDLE_WIDTH - pos_x - PADDLE_WIDTH / 2;
            dx -= diff * 0.5 + (5 - random(0, 10) / 30.0); // немного добавим случайности
            // TODO: click sound
        }
        if (pos_y < (pad_pos_y - 5))
        {
            if (dx > 0)
                dx = speed;
            else
                dx = -speed;
        }
        // TODO: click sound

        pos_x = pos_x + dx;
        pos_y = pos_y + dy;

        if (pos_x > 125)
        {
            dx = -dx;
            pos_x = 125;
        }
        if (pos_x < 1)
        {
            dx = -dx;
            pos_x = 0;
        }
        if (pos_y >= 60)
        {
            ball_state = DIE; // если мяч опустился ниже биты, значит конец игры
        }
        if (pos_y < 1)
        {
            dy = -dy;
            pos_y = 0;
        }  
    }              
}
