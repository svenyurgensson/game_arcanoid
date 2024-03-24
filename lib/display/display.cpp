#include "display.h"

void init_display() {
  oled.init();
  Wire.setClock(SPI_SPEED);

  oled.clear();
  oled.update();
}