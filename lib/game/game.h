#pragma once
#include <Arduino.h>
#include "level.h"
#include "display.h"
#include "control.h"
//#include "ball.h"
class Ball;

static Joystick control;

typedef enum { Menu, PlayGame, Win, Fault } GameState;

class Game 
{
    uint8_t current_level = 0;
public:
    Level * level_builder;
    Paddle * paddle;
    Ball * ball;    
    GameState state;

    Game();
    void init();
    void refresh();
    void draw_menu();
    void game_loop();
    void draw_win();
    void draw_fault();
    void handle_fault();
    void wait_for_start();
};

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

enum Ball_State {INIT, MOVE, DIE};

class Ball
{
public:
    float pos_x, pos_y;
    float dx = 0, dy = 0;
    Ball_State ball_state = INIT;
    Game * game; 

    Ball(int16_t x, int16_t y, Game * g) : pos_x(x), pos_y(y), game(g) 
    { 
        dx = 0; dy = 0; ball_state = INIT; 
    };

    void handle()
    {
        calculate_move();

        oled.setCursorXY(pos_x, pos_y);
        for (uint8_t i = 0; i < 8; i++)
        {
            if (pos_y + i > 63) break; // не рисуем ниже пола
            oled.drawByte(ball[i]);
        }

        if (JOYPAD_UP_PRESSED) { ball_state = MOVE; } // стартуем игру клавишей вверх
    }

    void calculate_move()
    {
        uint8_t pad_pos_x = game->paddle->pos_x, 
                pad_pos_y = game->paddle->pos_y;

        if (ball_state == INIT) {
            pos_x = pad_pos_x + 8;
            pos_y = pad_pos_y - 6;
            dx = 3;
            dy = -3;
        }

        if (ball_state == MOVE) {
            pos_x = pos_x + dx;
            pos_y = pos_y + dy;
            // TODO: check scene collision

            if ((pos_x >= (pad_pos_x - 4) && pos_x <= (pad_pos_x + PADDLE_WIDTH + 4)) &&
                pos_y >= (pad_pos_y - 5) && pos_y <= (pad_pos_y - 2)) 
            {
                dy = -dy;
                float diff = pad_pos_x + PADDLE_WIDTH - pos_x - PADDLE_WIDTH/2; 
                Serial.println(diff*0.4);
                dx -= diff * 0.5 + (5 - random(0, 10) / 30.0);
                // TODO: click sound
            }
            if (pos_y < (pad_pos_y - 5)) {
                if (dx > 0) dx = 3;
                else dx = -3;
            }
                // TODO: click sound

            if (pos_x > 123) { dx = -dx; pos_x = 123; }
            if (pos_x < 1) { dx = -dx; pos_x = 0; }
            if (pos_y >= 60) { ball_state = DIE; } 
            if (pos_y < 2) { dy = -dy; pos_y = 2; }
        }        
    }
};
