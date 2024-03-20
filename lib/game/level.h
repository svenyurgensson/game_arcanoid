#pragma once
#include <Arduino.h>
#include "display.h"
#include "resources.h"
#include "paddle.h"
#include "brick.h"

class Level
{
public:
    uint8_t level = 0;
    Brick * scene[TOTAL_BRICKS];

    Level(uint8_t level)  
    {
        level = level;
        init_scene(); 
    }

    ~Level()
    {
        delete scene[TOTAL_BRICKS];
    }

    /*
        Копируем из начального состояния поля из флеша в память
     */
    void init_scene()
    {
        for (uint8_t y = 0; y < BRICKS_ROWS; y++)
        {
            for (uint8_t x = 0; x < BRICKS_IN_ROW; x++)
            {
                uint8_t offset = (y * BRICKS_IN_ROW) + x;
                Bricks_type kind = levels[level * LEVEL_SIZE + offset];
                scene[offset] = new Brick(x, y, kind);
            }
        }        
    }

    void draw()
    {
        for (uint8_t i = 0; i < TOTAL_BRICKS; i++)
        {
            scene[i]->draw();
        }
    }
    /* 
        Проверяем, попадает ли мяч в какой-нибудь кирпич
     */
    bool check_brick_collision(uint8_t x, uint8_t y)
    {
        uint8_t t_x = x / BRICKS_WIDTH, t_y = y / BRICKS_HEIGHT;
        return true;
    }

    bool is_fault() 
    {
        return false;
    }
};