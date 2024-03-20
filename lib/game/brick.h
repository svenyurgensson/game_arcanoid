#pragma once
#include "display.h"
#include "resources.h"

#define BRICKS_HEIGHT 8
#define BRICKS_WIDTH 24

// Должны быть повернуты на 90 из за особенностей SH1106
const static uint8_t bricks1[24] PROGMEM = {
  0B00000000, 0B01111110, 0B01111110, 
  0B01111110, 0B01111110, 0B01111110, 
  0B01111110, 0B01111110, 0B01111110, 
  0B01111110, 0B01111110, 0B01111110, 
  0B01111110, 0B01111110, 0B01111110, 
  0B01111110, 0B01111110, 0B01111110, 
  0B01111110, 0B01111110, 0B01111110, 
  0B01111110, 0B01111110, 0B00000000, 
};
const static uint8_t bricks2[24] PROGMEM = {
  0B00000000, 0B01111110, 0B01110010, 
  0B01011010, 0B01001110, 0B01100110, 
  0B01110010, 0B01011010, 0B01101110, 
  0B01110110, 0B01011010, 0B01101110, 
  0B01110110, 0B01011010, 0B01101110, 
  0B01110110, 0B01011010, 0B01001110, 
  0B01100110, 0B01110010, 0B01011010, 
  0B01001110, 0B01111110, 0B00000000, 
};
const static uint8_t bricks3[24] PROGMEM = {
  0B00000000, 0B01101110, 0B01101110, 
  0B01101110, 0B01101110, 0B01100000, 
  0B01101110, 0B01101110, 0B00001110, 
  0B01101110, 0B01101110, 0B01101110, 
  0B01101110, 0B01101110, 0B01101110, 
  0B00001110, 0B01101110, 0B01101110, 
  0B01100000, 0B01101110, 0B01101110, 
  0B01101110, 0B01101110, 0B00000000
};

class Brick
{
public:
    uint8_t pos_x, pos_y;
    Bricks_type brick_kind;

    Brick() : pos_x(0), pos_y(0), brick_kind(EMP) {};
    Brick(uint8_t x, uint8_t y, Bricks_type kind)
    {
        brick_kind = kind;
        if (kind == EMP) {
            pos_x = x * BRICKS_WIDTH / 2;
        } else {
            pos_x = x * BRICKS_WIDTH;
        }
        pos_y = y * 8;        
        draw();
    }

    void draw() 
    {
        const uint8_t *frame;        
        switch (brick_kind)
        {
        case EMP:
            return;
        case SIM:
            frame = &bricks1[0];
            break;
        case MID:
            frame = &bricks2[0];
            break;
        case HRD:
            frame = &bricks3[0];
            break;
        default:
            return;
        }

        // invert - BITMAP_NORMAL/BITMAP_INVERT инвертировать
        // mode BUF_ADD / BUF_SUBTRACT / BUF_REPLACE
        oled.drawBitmap(pos_x, pos_y, frame, BRICKS_WIDTH, BRICKS_HEIGHT, 0, BUF_ADD);
    }
};