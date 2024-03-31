#pragma once
#include <Arduino.h>
#include "pico/multicore.h"

const uint8_t BRICKS_IN_ROW = 5;
const uint8_t BRICKS_ROWS = 3;
static constexpr uint8_t TOTAL_BRICKS{BRICKS_IN_ROW * BRICKS_ROWS};
const uint8_t BRICKS_HEIGHT = 8;
const uint8_t BRICKS_WIDTH = 24;
const uint8_t PADDLE_HEIGHT = 8;
const uint8_t PADDLE_WIDTH = 24;

/* 
    EMP - пустой блок
    SIM - простой блок крепость 1 удар
    MID - средний блок крепость 2 удара
    HRD - крепкий блок крепость 4 удара 
 */
typedef enum BricksType { EMP, SIM, MID, HRD } BricksType;

/* 
    Поле 9 на 6 блоков
    один блок = 3( 4b + 16b + 4b) на 1(*8)
 */
const uint8_t LEVELS_COUNT = 1;
const uint8_t LEVEL_SIZE = (LEVELS_COUNT * TOTAL_BRICKS);

const static BricksType levels[] PROGMEM = {
    EMP, SIM, SIM, SIM, EMP, // level 0
    MID, SIM, HRD, SIM, MID,
    EMP, SIM, SIM, SIM, EMP, // end of level 0

    SIM, SIM, SIM, SIM, SIM, // level 1
    EMP, MID, MID, MID, EMP,
    EMP, HRD, EMP, HRD, EMP,

    MID, HRD, HRD, HRD, MID, // level 2
    MID, SIM, HRD, SIM, MID,
    MID, SIM, SIM, SIM, MID,

    MID, HRD, EMP, HRD, MID, // level 3
    SIM, SIM, MID, SIM, SIM,
    MID, HRD, EMP, HRD, MID,

    HRD, MID, HRD, MID, HRD, // level 4
    SIM, HRD, HRD, HRD, SIM,
    MID, MID, SIM, MID, MID,

    HRD, HRD, MID, HRD, HRD, // level 5
    MID, MID, HRD, MID, MID,
    HRD, HRD, MID, HRD, HRD,
};

constexpr uint8_t levels_count = (sizeof(levels) / LEVEL_SIZE);

class Renderer;

enum SOUND { NO, BR1, BR2, BR3, PAD, FALL, WIN, FAIL, TITLE };