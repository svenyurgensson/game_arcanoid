#pragma once
#include <Arduino.h>
#include "display.h"
#include "game.h"

static Game * game;

void sound_driver(void);
void blocked_music_tick(void);