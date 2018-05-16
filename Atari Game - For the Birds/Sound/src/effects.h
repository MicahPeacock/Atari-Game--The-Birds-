#ifndef SOUND_EFFECTS_H
#define SOUND_EFFECTS_H

#include "..\..\Library\src\types.h"

typedef struct Sound
{
    int tone;
    int volume;
} Sound;

typedef struct Effect
{
    Sound* sounds;
    int tone_or_noise; /* 0 for tone, 1 for noise */
    int index;
    int size;
    bool playing;
} Effect;

void play_effect(struct Effect* effect);

void update_effect(struct Effect* effect);

void stop_effect(struct Effect* effect);

#endif