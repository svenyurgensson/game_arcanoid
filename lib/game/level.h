#pragma once
#include "resources.h"
#include "ball.h"
#include "brick.h"

class Ball;
class Brick;

class Level
{
public:
    uint8_t level = 0;
    Brick * scene[BRICKS_IN_ROW * BRICKS_ROWS];

    Level(uint8_t level);
    ~Level();

    void init_scene();
    void draw();    
    const static uint8_t brick_margin = 6;

    uint8_t handle_collisions(Ball * ball);
    bool is_fault();
};