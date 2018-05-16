#ifndef SOUND_SOUND_H
#define SOUND_SOUND_H

#include "..\..\Library\src\types.h"

#define CHANNEL_A 0
#define CHANNEL_B 1
#define CHANNEL_C 2

#define NOISE_CHANNEL 6
#define ENABLE_CHANNEL 7

#define VOLUME_CHANNEL 8
#define VOLUME_OFF 0


void write_psg(UINT8 reg, UINT8 val);

UINT8 read_psg(UINT8 reg);

void set_tone(int channel, int tuning);

void set_noise(int tuning);

void enable_channel(int channel, int tone_on, int noise_on);

void set_volume(int channel, int volume);

void set_envelope(int shape, UINT16 sustain);

void stop_sound(int channel);

void stop_all_sound();

#endif