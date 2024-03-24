#pragma once
#include "resources.h"
#include "renderer.h"

class Brick
{
public:
    uint8_t pos_x, pos_y;
    BricksType brick_kind;

    Brick() : pos_x(0), pos_y(0), brick_kind(EMP) {};
    Brick(uint8_t x, uint8_t y, BricksType kind);
    void draw();
};