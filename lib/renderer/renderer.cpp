#include "renderer.h"

void Renderer::draw_paddle(uint8_t x, uint8_t y)
{
    // invert - BITMAP_NORMAL/BITMAP_INVERT инвертировать
    // mode BUF_ADD / BUF_SUBTRACT / BUF_REPLACE        
    oled.drawBitmap(x, y, &paddle[0], PADDLE_WIDTH, PADDLE_HEIGHT, 0, BUF_ADD);    
}

void Renderer::draw_ball(uint8_t x, uint8_t y)
{
    oled.setCursorXY(x, y);
    
    for (uint8_t i = 0; i < 8; i++)
    {
        oled.drawByte(ball_data[i]);        
    }    
}

void Renderer::draw_bricks(uint8_t x, uint8_t y, uint8_t kind)
{
    const uint8_t *frame;
    switch (kind)
    {
    case 0: // EMP
        return;
    case 1: // SIM
        frame = &bricks1[0];
        break;
    case 2: // MID
        frame = &bricks2[0];
        break;
    case 3: // HRD
        frame = &bricks3[0];
        break;
    default:
        return;
    }

    // invert - BITMAP_NORMAL/BITMAP_INVERT инвертировать
    // mode BUF_ADD / BUF_SUBTRACT / BUF_REPLACE
    oled.drawBitmap(x, y, frame, BRICKS_WIDTH, BRICKS_HEIGHT, 0, BUF_ADD);
}

void Renderer::start()
{
    oled.clear();
}

void Renderer::render()
{
    oled.update();
}