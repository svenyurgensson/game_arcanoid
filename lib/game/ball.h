#pragma once
#include "display.h"
#include "game.h"

const static uint8_t ball[8] PROGMEM = {
  0B00111100, 
  0B01111110, 
  0B11111111, 
  0B11111111, 
  0B11111111, 
  0B11111111, 
  0B01111110, 
  0B00111100
};

enum Ball_State {INIT, MOVE};

class Ball
{
public:
    int16_t pos_x, pos_y;
    Ball_State ball_state = INIT;
    Game * game; 

    Ball(int16_t x, int16_t y, Game * g) : pos_x(x), pos_y(y), game(g) {};

    void draw()
    {
        calculate_move();

        oled.setCursorXY(pos_x, pos_y);
        for (uint8_t i = 0; i < 8; i++)
        {
            oled.drawByte(ball[i]);
        }
    }

    void calculate_move()
    {
        if (ball_state == INIT) {
            pos_x = game->paddle->pos_x + 8;
            pos_y = game->paddle->pos_x - 6;
            return;
        }

        if (ball_state == MOVE) {

        }
    }
};
