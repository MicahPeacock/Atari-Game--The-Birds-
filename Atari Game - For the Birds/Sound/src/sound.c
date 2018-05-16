#include <osbind.h>
#include "sound.h"

volatile UINT8 *PSG_reg_select = 0xFF8800;
volatile UINT8 *PSG_reg_write = 0xFF8802;

void write_psg(UINT8 reg, UINT8 val)
{
    long old_ssp = Super(0);
    
    *PSG_reg_select = reg;
    *PSG_reg_write = val;
    
    Super(old_ssp);
}

UINT8 read_psg(UINT8 reg)
{
    UINT8 val;
    long old_ssp = Super(0);
    
    *PSG_reg_select = reg;
    val = *PSG_reg_select;

    Super(old_ssp);
    
    return val;
}

void set_tone(int channel, int tuning)
{
    UINT8 fine_tuning = (tuning & 0x0FF);
    UINT8 coarse_tuning = ((tuning & 0xF00) >> 8);

    write_psg((channel << 1), fine_tuning);
    write_psg((channel << 1) + 1, coarse_tuning);
}

void set_noise(int tuning)
{
    write_psg(NOISE_CHANNEL, tuning);
}

void enable_channel(int channel, int tone_on, int noise_on)
{
    UINT8 code = read_psg(ENABLE_CHANNEL);
    code = (code ^ (tone_on << channel));
    code = (code ^ ((noise_on << channel) << 3));
    write_psg(ENABLE_CHANNEL, code);
}

void set_volume(int channel, int volume)
{
    write_psg(channel + VOLUME_CHANNEL, volume);
}

void set_envelope(int shape, UINT16 sustain)
{

}

void stop_sound(int channel)
{
    UINT8 code = read_psg(ENABLE_CHANNEL);
    code = (code | (1 << channel));
    code = (code | (( 1 << channel) << 3 ));

    write_psg(channel + VOLUME_CHANNEL, VOLUME_OFF);
    write_psg(ENABLE_CHANNEL, code);
}

void stop_all_sound()
{
    write_psg(CHANNEL_A + VOLUME_CHANNEL, VOLUME_OFF);
    write_psg(CHANNEL_B + VOLUME_CHANNEL, VOLUME_OFF);
    write_psg(CHANNEL_C + VOLUME_CHANNEL, VOLUME_OFF);
    write_psg(ENABLE_CHANNEL, 0x3F);
}