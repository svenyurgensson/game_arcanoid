#pragma once


const static BallWidth = 6;
const static BallHeight = 6;

#define BRICKS_IN_ROW 5
#define BRICKS_ROWS 3
#define TOTAL_BRICKS (BRICKS_IN_ROW * BRICKS_ROWS)

/* 
    EMP - пустой блок
    SIM - простой блок крепость 1 удар
    MID - средний блок крепость 2 удара
    HRD - крепкий блок крепость 4 удара 
 */
typedef enum { EMP, SIM, MID, HRD } Bricks_type;

/* 
    Поле 9 на 6 блоков
    один блок = 3( 4b + 16b + 4b) на 1(*8)
 */
const uint8_t LEVEL_SIZE = TOTAL_BRICKS;

const static Bricks_type levels[] PROGMEM = {
    EMP, SIM, SIM, SIM, EMP, // level 0
    MID, SIM, HRD, SIM, MID,
    EMP, SIM, SIM, SIM, EMP, // emd of level 0
};
