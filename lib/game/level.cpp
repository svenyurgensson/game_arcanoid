#include "level.h"

Level::Level(uint8_t level)
{
    level = level;
    init_scene();
}

Level::~Level()
{
    delete scene[TOTAL_BRICKS];
}

/*
    Копируем из начального состояния поля из флеша в память
 */
void Level::init_scene()
{
    for (uint8_t y = 0; y < BRICKS_ROWS; y++)
    {
        for (uint8_t x = 0; x < BRICKS_IN_ROW; x++)
        {
            uint8_t offset = (y * BRICKS_IN_ROW) + x;
            BricksType kind = levels[level * LEVEL_SIZE + offset];
            scene[offset] = new Brick(x, y, kind);
        }
    }
}

void Level::draw()
{
    for (uint8_t i = 0; i < TOTAL_BRICKS; i++)
    {
        scene[i]->draw();
    }
}

const static uint8_t brick_margin = 6;
/*
    Проверяем, попадает ли мяч в какой-нибудь кирпич
 */
uint8_t Level::handle_collisions(Ball *ball)
{
    float ball_x = ball->pos_x;
    float ball_y = ball->pos_y;
    uint8_t remain_bricks = 0;

    for (uint8_t i = 0; i < TOTAL_BRICKS; i++)
    {
        if (scene[i]->brick_kind == EMP)
        {
            continue;
        }
        uint8_t x1 = scene[i]->pos_x - brick_margin,
                y1 = scene[i]->pos_y - brick_margin,
                x2 = scene[i]->pos_x + BRICKS_WIDTH - 4,
                y2 = scene[i]->pos_y + BRICKS_HEIGHT - 2;

        if (ball_x >= x1 && ball_x <= x2 && ball_y >= y1 && ball_y <= y2)
        {
            scene[i]->brick_kind = EMP;
            // TODO: другие типы кирпичей обработать

            // при отражение мяча рассчитать и изменить его координаты
            if (ball_x >= x1 || ball_x <= x2) { ball->dx *= -1; }
            if (ball_y >= y1 || ball_y <= y2) { ball->dy *= -1; }
        }
        else
        {
            remain_bricks++;
        }
    }
    return remain_bricks;
}

bool Level::is_fault()
{
    return false;
}