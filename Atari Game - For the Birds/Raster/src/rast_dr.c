#include <stdio.h>
#include <stdlib.h>
#include <osbind.h>
#include "raster.h"

const UINT8 letter_e_bits[8] =
{
    0x00,
    0x7e,
    0x40,
    0x40,
    0x7c,
    0x40,
    0x40,
    0x7e
};

const UINT16 num_0_bits[32] = 
{
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0fe0,
    0x3018,
    0x4004,
    0x4004,
    0x8002,
    0x8382,
    0x87c2,
    0x86c2,
    0x8442,
    0x8442,
    0x8442,
    0x8442,
    0x8442,
    0x8442,
    0x8442,
    0x8442,
    0x8442,
    0x8442,
    0x8442,
    0x8382,
    0x8002,
    0xc006,
    0xc006,
    0x701c,
    0x3ff8,
    0x0fe0       
};

const UINT32 bird_bits[32] =
{
    0x00000000,  
    0x00000000,  
    0x00000000,  
    0x00000000, 
    0x00000000,  
    0x01fe0000,  
    0x07ffe000,  
    0x0703f800,  
    0x0e003e00,  
    0x0c000f00,  
    0x0e000380,  
    0x07800180,
    0x0f0005c0,
    0x0c0004c0,
    0x180004f0,
    0x180004fc,
    0x7f40411e,
    0xfc00a207,
    0xe2009c03,
    0x7c4181ff,
    0x3f8e403e,
    0x0ff040f0,
    0x01c027e0,
    0x00f83f80,
    0x007ffc00,
    0x000fe000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000    
};

const Bitmap8 letter_e = {&letter_e_bits, 8};

const Bitmap16 num_0 = {&num_0_bits, 32};

const Bitmap32 bird = {&bird_bits, 32};


int main()
{
    UINT8* base = (UINT8*)Physbase();
    Point location = {35, 35};
    
    clear_screen((UINT32*)base);
    plot_bitmap_8((UINT8*)base, &letter_e, location.x, location.y);
    getchar();
    
    clear_screen((UINT32*)base);
    plot_bitmap_16((UINT16*)base, &num_0, location.x, location.y);
    getchar();
    
    clear_screen((UINT32*)base);
    plot_bitmap_32((UINT32*)base, &bird, location.x, location.y);
    getchar();
    
    return 0;
}