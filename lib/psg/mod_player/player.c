#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include "pico/stdlib.h"
#include <stdio.h>

#include "mod_play.h"
#include "player.h"
#include "sound.h"

// #include "the_softliner.h"
// #include "twelve.h"
// #include "berry.h"
// #include "germz2.h"
// #include "megamix.h"
// #include "again.h"
#include "music_arkanoid.h"
#include "music_killer_tomato.h"
#include "music_toytitle.h"

#define SOUND_PIN 16 // sound output

// frequency of the output wave (samples/second)
#define SOUND_OUTPUT_FREQUENCY 22050

void init_mod_player(int theme) 
{
  audio_init(SOUND_PIN, SOUND_OUTPUT_FREQUENCY);

  switch (theme) 
  {
    case 0:
        mod_play_start(&mod_arkanoid, SOUND_OUTPUT_FREQUENCY, 1);
        break;
    case 1:
        mod_play_start(&mod_killer_tomato, SOUND_OUTPUT_FREQUENCY, 0);
        break;
    case 2:
        mod_play_start(&mod_toytitle, SOUND_OUTPUT_FREQUENCY, 0);
        break;
    default:
        break;
  }
}

// Call the MOD player to fill the output audio buffer.
// This must be called every 20 miliseconds or so, or more
// often if SOUND_OUTPUT_FREQUENCY is increased.
void update_mod_player(void) 
{
  uint8_t *audio_buffer = audio_get_buffer();
  if (audio_buffer) {
    mod_play_step(audio_buffer, AUDIO_BUFFER_SIZE);
  }
}
