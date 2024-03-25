#include "brick.h"

Brick::Brick(uint8_t x, uint8_t y, BricksType kind)
{
    brick_kind = kind;
    pos_x = x * BRICKS_WIDTH;

    pos_y = y * 8;
    draw();
}

void Brick::draw()
{
    renderer.draw_bricks(pos_x, pos_y, brick_kind);
}
