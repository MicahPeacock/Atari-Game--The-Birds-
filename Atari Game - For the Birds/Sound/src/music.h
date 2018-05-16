#ifndef SOUND_MUSIC_H
#define SOUND_MUSIC_H

#include "sound.h"

#define c_1 0xD5D
#define C_1 0xC9C
#define d_1 0xBE7
#define D_1 0xB3C
#define e_1 0xA9B
#define f_1 0xA02
#define F_1 0x973
#define g_1 0x8EB
#define G_1 0x86B
#define a_1 0x7F2
#define A_1 0x780
#define b_1 0x714

#define c_2 0x6AE
#define C_2 0x64E
#define d_2 0x5F4
#define D_2 0x59E
#define e_2 0x54D
#define f_2 0x501
#define F_2 0x4B9
#define g_2 0x475
#define G_2 0x435
#define a_2 0x3F9
#define A_2 0x3C0
#define b_2 0x38A

#define c_3 0x357
#define C_3 0x327
#define d_3 0x2FA
#define D_3 0x2CF
#define e_3 0x2A7
#define f_3 0x281
#define F_3 0x25D
#define g_3 0x23B
#define G_3 0x21B
#define a_3 0x1FC
#define A_3 0x1E0
#define b_3 0x1C5

#define c_4 0x1AC
#define C_4 0x194
#define d_4 0x17D
#define D_4 0x168
#define e_4 0x153
#define f_4 0x140
#define F_4 0x12E
#define g_4 0x11D
#define G_4 0x10D
#define a_4 0x0F3
#define A_4 0x0F0
#define b_4 0x0E2

#define c_5 0x0D6
#define C_5 0x0CA
#define d_5 0x0BE
#define D_5 0x0B4
#define e_5 0x0AA
#define f_5 0x0A0
#define F_5 0x097
#define g_5 0x08F
#define G_5 0x087
#define a_5 0x07F
#define A_5 0x078
#define b_5 0x071

#define c_6 0x06B
#define C_6 0x065
#define d_6 0x05F
#define D_6 0x05A
#define e_6 0x055
#define f_6 0x050
#define F_6 0x04C
#define g_6 0x047
#define G_6 0x043
#define a_6 0x040
#define A_6 0x03C
#define b_6 0x039

#define c_7 0x035
#define C_7 0x032
#define d_7 0x030
#define D_7 0x02D
#define e_7 0x02A
#define f_7 0x028
#define F_7 0x026
#define g_7 0x024
#define G_7 0x022
#define a_7 0x020
#define A_7 0x01E
#define b_7 0x01C

#define c_8 0x01B
#define C_8 0x019
#define d_8 0x018
#define D_8 0x016
#define e_8 0x015
#define f_8 0x014
#define F_8 0x013
#define g_8 0x012
#define G_8 0x011
#define a_8 0x010
#define A_8 0x00F
#define b_8 0x00E

#define REST 0x000

#define WHOLE_NOTE 112
#define HALF_NOTE 56
#define QUARTER_NOTE 28
#define EIGHTH_NOTE 14
#define SIXTEENTH_NOTE 7

typedef struct Note
{
    int tone;
    int duration;
    int counter;
    int volume;
} Note;

typedef struct Track
{
    Note* notes;
    int index;
    int size;
} Track;

typedef struct Song
{
    Track* tracks[2];
} Song;

void play_music(struct Song* song);

void play_track(struct Track* track, int channel);

void update_music(struct Song* song);

void update_track(struct Track* track, int channel);

#endif