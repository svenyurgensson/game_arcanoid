#pragma once
#include "display.h"
#include "resources.h"
#include "control.h"

#define PADDLE_HEIGHT 8
#define PADDLE_WIDTH 24

const static uint8_t paddle[24] PROGMEM = {
  0B00000100, 0B00011000, 0B00111000, 
  0B00111000, 0B00111000, 0B00111000, 
  0B01111000, 0B01111000, 0B00111000, 
  0B00111000, 0B00111000, 0B01111000, 
  0B01111000, 0B01111000, 0B00111000, 
  0B00111000, 0B00111000, 0B01111000, 
  0B01111000, 0B00111000, 0B00111000, 
  0B00111000, 0B00011000, 0B00000100
};

class Paddle
{
public:
    int16_t pos_x, pos_y;
    uint16_t r_step_idx=0, l_step_idx=0;
    int8_t last_direction = 0; // 0 - still, 1 +x, -1 -x

    Paddle(int16_t x, int16_t y) : pos_x(x), pos_y(y) {};

    void draw()
    {
        // invert - BITMAP_NORMAL/BITMAP_INVERT инвертировать
        // mode BUF_ADD / BUF_SUBTRACT / BUF_REPLACE        
        oled.drawBitmap(pos_x, pos_y, &paddle[0], PADDLE_WIDTH, PADDLE_HEIGHT, 0, BUF_ADD);
    }

    const uint8_t steps[12] = {1, 1, 2, 2, 4, 4, 4, 6, 6, 8, 10, 12};
    static constexpr uint8_t steps_count { sizeof(steps) };
    static constexpr uint8_t max_right_x_pos = (127 - 24);    

    void move(Joystick control)
    {
         if (control.read())
         {
            if (control.left == 0 && pos_x > 0) {
                last_direction = -1;
                r_step_idx = 0;
                pos_x -= steps[l_step_idx];
                if (pos_x < 0) pos_x = 0;
                l_step_idx++;
                if (l_step_idx >= steps_count) { l_step_idx = steps_count - 1; }
            } 

            if (control.right == 0 && pos_x < max_right_x_pos) {
                last_direction = 1;
                l_step_idx = 0;
                pos_x += steps[r_step_idx];
                if (pos_x > max_right_x_pos) pos_x = max_right_x_pos;
                r_step_idx++;
                if (r_step_idx >= steps_count) { r_step_idx  = steps_count - 1; }
            }
         } 
         else 
         {
            l_step_idx = 0;
            r_step_idx = 0;
            last_direction = 0;
        }            
    }
};