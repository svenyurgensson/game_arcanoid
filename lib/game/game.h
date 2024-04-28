#pragma once
#include "resources.h"
#include "display.h"
#include "joystick.h"
#include "renderer.h"
#include "level.h"
#include "ball.h"
#include "paddle.h"
#include "psg.h"

#include "bitmap_arcanoid2.h"
#include "bitmap_fail.h"
#include "bitmap_win.h"

class Level;
class Ball;
class Paddle;
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
    void draw_press_fire();
    void game_loop();
    void draw_win();
    void draw_fault();
    void check_fault();
    bool is_start_pressed();
    void check_for_start_pressed();
private:
    int blink_counter = 0;
    void wait_until_start_pressed();
};