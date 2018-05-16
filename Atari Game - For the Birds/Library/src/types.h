#ifndef LIBRARY_TYPES_H
#define LIBRARY_TYPES_H

#define true 1
#define false 0

typedef unsigned char UINT8;
typedef unsigned int UINT16;
typedef unsigned long UINT32;

typedef int bool;

typedef struct Point
{
    int x;
    int y;
} Point;

typedef struct Size
{
    unsigned int height;
    unsigned int width;
} Size;

#endif