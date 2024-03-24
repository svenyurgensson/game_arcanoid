#pragma once
#include "game.h"
#include "renderer.h"

class Game;

enum Ball_State {INIT, MOVE, DIE};

class Ball
{
public:
    float pos_x, pos_y;
    float dx, dy;

    Ball_State ball_state = INIT; 

    Ball(int16_t x, int16_t y, Game * g);

    void draw_and_check_collisions();
private:
    Game * game;

    void calculate_move();
};