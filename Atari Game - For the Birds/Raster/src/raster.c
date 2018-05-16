#include "raster.h"

#define SCREEN_HEIGHT 640
#define SCREEN_WIDTH 400

#define BYTES_PER_ROW 80
#define WORDS_PER_ROW 40
#define LONGS_PER_ROW 20

const UINT32 zeroes[400];


void clear_region(UINT32* base, struct Size size, struct Point location)
{
    int index_x;
    int index_y;
    int longs = (size.width >> 5);
    int offset = (size.width & 31);
    
    bool long_aligned = (bool)((location.x & 31) == 0);
    
    UINT32* address;
    
    if(long_aligned)
    {
        for(index_y = 0; index_y < size.height; index_y++)
        {
            for(index_x = 0; index_x < longs; index_x++)
            {
                address = (base + ((location.y + index_y) * LONGS_PER_ROW) + (location.x >> 5));
                *(address + index_x) &= 0x00000000;
            }
        }
    }
    else
    {
        for(index_y = 0; index_y < size.height; index_y++)
        {
            for(index_x = 0; index_x < longs; index_x++)
            {
                address = (base + ((location.y + index_y) * LONGS_PER_ROW) + (location.x >> 5));
                *(address + index_x)     &= 0xFFFFFFFF << (32 - (location.x & 31));
                *(address + index_x + 1) &= 0xFFFFFFFF >> (location.x & 31);
            }
        }
    }
    
    if(offset > 0)
    {
        for(index_y = 0; index_y < size.height; index_y++)
        {
            address = (base + ((location.y + index_y) * LONGS_PER_ROW) + (location.x >> 5));
            *(address + longs) &= 0xFFFFFFFF >> offset;
        }
    }
}

void clear_column_32(UINT32* base, int x, int y, unsigned int height)
{
    UINT32* address;
    UINT32* data = (UINT32*)&zeroes;
    int row;
    
    for(row = 0; row < height; row++)
    {
        address = (base + ((y + row) * LONGS_PER_ROW) + (x >> 5));
        *address &= zeroes[row];
    }
}

void plot_pixel(UINT8* base, int x, int y)
{
    UINT8* address;
    
    if(x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
    {
        address = (base + (y * BYTES_PER_ROW) + (x >> 3));
        *address |= (1 << (7 - (x & 7)));
    }
}


void plot_line(UINT8* base, int x1, int y1, int x2, int y2)
{
    
}


void plot_bitmap_8(UINT8* base, struct Bitmap8* bitmap8, int x, int y)
{
    UINT8* address;
    UINT8* data = (UINT8*)bitmap8->bitmap;
    
    int row;
    bool byte_aligned = (bool)((x & 7) == 0);
    
    if(byte_aligned)
    {
        for(row = 0; row < bitmap8->height; row++)
        {
            address = (base + ((y + row) * BYTES_PER_ROW) + (x >> 3));
            *address |= data[row];
        }
    }
    else
    {
        for(row = 0; row < bitmap8->height; row++)
        {
            address = (base + ((y + row) * BYTES_PER_ROW) + (x >> 3));
            *(address)     |= data[row] >> (x & 7);
            *(address + 1) |= data[row] << (8 - (x & 7));
        }
    }
}


void plot_bitmap_16(UINT16* base, struct Bitmap16* bitmap16, int x, int y)
{
    UINT16* address;
    UINT16* data = (UINT16*)bitmap16->bitmap;
    
    int row;
    bool word_aligned = (bool)((x & 15) == 0);
    
    if(word_aligned)
    {
        for(row = 0; row < bitmap16->height; row++)
        {
            address = (base + ((y + row) * WORDS_PER_ROW) + (x >> 4)); 
            *address |= data[row];
        }
    }
    else
    {
        for(row = 0; row < bitmap16->height; row++)
        {
            address = (base + ((y + row) * WORDS_PER_ROW) + (x >> 4));
            *(address)     |= data[row] >> (x & 15);
            *(address + 1) |= data[row] << (16 - (x & 15));
        }
    }
}

void plot_bitmap_32(UINT32* base, struct Bitmap32* bitmap32, int x, int y)
{
    UINT32* address;
    UINT32* data = (UINT32*)bitmap32->bitmap;
    
    int row;
    long bitshift_mask;
    bool long_aligned = (bool)((x & 31) == 0);
    /*
    if((32 - x) < 16)
    {
        return;
    }
    else if(x < 16)
    {
        bitshift_mask = 0xFFFFFFFF >> (16 - x);
        for(row = 0; row < bitmap32->height; row++)
        {
            address = (base + ((y + row) * LONGS_PER_ROW) + (x >> 5));
            *address |= (data[row] & bitshift_mask);
        }
    }
    else */if(long_aligned)
    {
        for(row = 0; row < bitmap32->height; row++)
        {
            address = (base + ((y + row) * LONGS_PER_ROW) + (x >> 5));
            *address |= data[row];
        }
    }
    else
    {
        for(row = 0; row < bitmap32->height; row++)
        {
            address = (base + ((y + row) * LONGS_PER_ROW) + (x >> 5));
            *(address)     |= data[row] >> (x & 31);
            *(address + 1) |= data[row] << (32 - (x & 31));
        }
    }
}


void clear_alpha_mask_8(UINT8* base, struct Bitmap8* alphamask8, int x, int y)
{
    UINT8* address;
    UINT8* data = (UINT8*)alphamask8->bitmap;
    
    int row;
    bool byte_aligned = (bool)((x & 7) == 0);
    
    if(byte_aligned)
    {
        for(row = 0; row < alphamask8->height; row++)
        {
            address = (base + ((y + row) * BYTES_PER_ROW) + (x >> 3));
            *address &= data[row];
        }
    }
    else
    {
        for(row = 0; row < alphamask8->height; row++)
        {
            address = (base + ((y + row) * BYTES_PER_ROW) + (x >> 3));
            *(address)     &= data[row] >> (x & 7);
            *(address + 1) &= data[row] << (8 - (x & 7));
        }
    }
}


void clear_alpha_mask_16(UINT16* base, struct Bitmap16* alphamask16, int x, int y)
{
    UINT16* address;
    UINT16* data = (UINT16*)alphamask16->bitmap;
    
    int row;
    bool word_aligned = (bool)((x & 15) == 0);
    
    if(word_aligned)
    {
        for(row = 0; row < alphamask16->height; row++)
        {
            address = (base + ((y + row) * WORDS_PER_ROW) + (x >> 4));
            *address &= data[row];
        }
    }
    else
    {
        for(row = 0; row < alphamask16->height; row++)
        {
            address = (base + ((y + row) * WORDS_PER_ROW) + (x >> 4));
            *(address)     &= data[row] >> (x & 15);
            *(address + 1) &= data[row] << (16 - (x & 15));
        }
    }
}


void clear_alpha_mask_32(UINT32* base, struct Bitmap32* alphamask32, int x, int y)
{
    UINT32* address;
    UINT32* data = (UINT32*)alphamask32->bitmap;
    
    int row;
    bool long_aligned = (bool)((x & 31) == 0);
    
    if(long_aligned)
    {
        for(row = 0; row < alphamask32->height; row++)
        {
            address = (base + ((y + row) * LONGS_PER_ROW) + (x >> 5));
            *address &= data[row];
        }
    }
    else
    {
        for(row = 0; row < alphamask32->height; row++)
        {
            address = (base + ((y + row) * LONGS_PER_ROW) + (x >> 5));
            *(address)     &= data[row] >> (x & 31);
            *(address + 1) &= data[row] << (32 - (x & 31));
        }
    }
}

UINT8* swap_buffers(UINT8* base, UINT8* back)
{
    UINT8* old_buffer = (UINT8*)base;
    base = back;
    return old_buffer;
}