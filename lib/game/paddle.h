#pragma once
#include "resources.h"
#include "renderer.h"
#include "joystick.h"

class Joystick;

class Paddle
{
public:
    int16_t pos_x, pos_y;
    uint16_t r_step_idx=0, l_step_idx=0;
    int8_t last_direction = 0; // 0 - still, 1 +x, -1 -x

    Paddle(int16_t x, int16_t y) : pos_x(x), pos_y(y) {};

    void draw();   
    void move(Joystick control);
};