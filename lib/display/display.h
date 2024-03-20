#pragma once
#include <SPI.h>
#include <Wire.h>
#include <GyverOLED.h>
#define SPI_PORT spi0_hw

// https://github.com/GyverLibs/GyverOLED
/*
     *  @param mosi SPI Master Out, Slave In pin.
     *  @param miso SPI Master In, Slave Out pin.
     *  @param sclk SPI Clock pin.
     *  @param ssel SPI Chip Select pin.
GND –> Display GND 
3V3(OUT) -> Display VCC 
GP16 -> Display DC (Data Command) 
GP17 -> Display CS (Channel Select) 
GP18 -> Display SCL (Clock) 
GP19 -> Display SDA (MOSI) 
GP20 -> Display RES (Reset)
*/

//      SCK    18
// MOSI SDA    19 
#define RST    20
// MISO
#define DC     21 
#define CS     22 

static GyverOLED<SSH1106_128x64, OLED_BUFFER, OLED_SPI, CS, DC, RST> oled;

void init_display();
void oled_loop();