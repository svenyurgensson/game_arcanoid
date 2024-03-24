#pragma once
#include "resources.h"
#include "display.h"
#include "joystick.h"
#include "renderer.h"
#include "level.h"
#include "ball.h"
#include "paddle.h"

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
    void draw_menu();
    void game_loop();
    void draw_win();
    void draw_fault();
    void handle_fault();
    void wait_for_start();
};