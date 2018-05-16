#ifndef RASTER_RASTER_H
#define RASTER_RASTER_H

#include "..\..\Library\src\types.h"

#define BITMAP 0
#define ALPHAMASK 1

typedef struct Bitmap8
{
    UINT8* bitmap;
    unsigned int height;
} Bitmap8;

typedef struct Bitmap16
{
    UINT16* bitmap;
    unsigned int height;
} Bitmap16;

typedef struct Bitmap32
{
    UINT32* bitmap;
    unsigned int height;
} Bitmap32;


/* Assembly functions */
void clear_screen(UINT32* base); /* This is Mark's clear_screen (quick). It works fastest, so I had to steal it (hehehe...) */

/* Set Alpha masks */
void clear_8(UINT8* address, const UINT8* data, unsigned int height);

void clear_16(UINT16* address, const UINT16* data, unsigned int height);

void clear_32(UINT32* address, const UINT32* data, unsigned int height);

/* Set Bitmaps */
void set_8(UINT8* address, const UINT8* data, unsigned int height);

void set_16(UINT16* address, const UINT16* data, unsigned int height);

void set_32(UINT32* address, const UINT32* data, unsigned int height);



void clear_region(UINT32* base, struct Size size, struct Point location);

void clear_column_32(UINT32* base, int x, int y, unsigned int height);

void plot_pixel(UINT8* base, int x, int y);

void plot_line(UINT8* base, int x1, int y1, int x2, int y2);

void plot_bitmap_8(UINT8* base, struct Bitmap8* bitmap, int x, int y);

void plot_bitmap_16(UINT16* base, struct Bitmap16* bitmap, int x, int y);

void plot_bitmap_32(UINT32* base, struct Bitmap32* bitmap, int x, int y);

void clear_alpha_mask_8(UINT8* base, struct Bitmap8* alphamask, int x, int y);

void clear_alpha_mask_16(UINT16* base, struct Bitmap16* alphamask, int x, int y);

void clear_alpha_mask_32(UINT32* base, struct Bitmap32* alphamask, int x, int y);

UINT8* swap_buffers(UINT8* base, UINT8* back);
#endif