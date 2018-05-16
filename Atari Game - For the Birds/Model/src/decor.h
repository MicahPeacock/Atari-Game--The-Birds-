#ifndef MODEL_DECORATION_H
#define MODEL_DECORATION_H

#include "..\..\Raster\src\raster.h"

#define MAX_DECORATIONS 3

typedef struct Decoration
{
    const Bitmap32* bitmaps[MAX_DECORATIONS][4];
    
    int speed;
    Size size;
    Point location;
    
    bool generated;
} Decoration;

void decorations_setup(struct Decoration* decor);

void decoration_setup(struct Decoration* decor);

void decoration_generate(struct Decoration* decor);

void decoration_destroy(struct Decoration* decor);

void decoration_move(struct Decoration* decor);

#endif