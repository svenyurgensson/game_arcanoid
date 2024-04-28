#pragma once
#include <GyverOLED.h>

// https://github.com/GyverLibs/GyverOLED
/*
     *  @param mosi SPI Master Out, Slave In pin.
     *  @param miso SPI Master In, Slave Out pin.
     *  @param sclk SPI Clock pin.
     *  @param ssel SPI Chip Select pin.
GND –> Display GND 
3V3(OUT) -> Display VCC 
*/

//      SCK    18
// MOSI SDA    19 
#define RST    20
// MISO
#define DC     21 
#define CS     22 

#define SPI_PORT spi0_hw
#define SPI_SPEED 400000ul

static GyverOLED<SSH1106_128x64, OLED_BUFFER, OLED_SPI, CS, DC, RST> oled;

void init_display();