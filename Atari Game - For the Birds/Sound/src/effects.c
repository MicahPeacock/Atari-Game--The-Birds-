#include "effects.h"
#include "sound.h"

void play_effect(Effect* effect)
{
    effect->index = 0;
    effect->playing = true;
    set_tone(CHANNEL_C, effect->sounds[effect->index].tone);
    
    if(effect->tone_or_noise == 0)
        enable_channel(CHANNEL_C, 1, 0);
    else
        enable_channel(CHANNEL_C, 0, 1);
    
    set_volume(CHANNEL_C, effect->sounds[effect->index].volume);
}


void update_effect(Effect* effect)
{
    if(effect->playing)
    {
        effect->index++;
        if((effect->index > -1) && (effect->index < effect->size))
        {
            set_tone(CHANNEL_C, effect->sounds[effect->index].tone);
            set_volume(CHANNEL_C, effect->sounds[effect->index].volume);
        }
        else
        {
            stop_effect(effect);
            effect->index = -1;
        }
    }
}


void stop_effect(Effect* effect)
{
    stop_sound(CHANNEL_C);
    effect->playing = false;
}