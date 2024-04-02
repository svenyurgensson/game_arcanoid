#pragma once
#include "mod_data.h"

#ifdef __cplusplus
extern "C" {
#endif

void mod_play_start(const struct MOD_DATA *mod_data, unsigned int out_frequency, int loop);
int  mod_play_step(unsigned char *out, unsigned int len);

#ifdef __cplusplus
}
#endif