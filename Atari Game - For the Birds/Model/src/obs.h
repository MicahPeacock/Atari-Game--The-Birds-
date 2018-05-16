#ifndef MODEL_OBSTACLE_H
#define MODEL_OBSTACLE_H

#include "..\..\Raster\src\raster.h"

#define MAX_OBSTACLES 5
#define HEAD 0
#define BODY 1

typedef struct Obstacle
{
    const Bitmap32* bitmaps[2][2]; /* 0 for his head, 1 for his body */
    
    int speed;
    
    Size size;
    Point location;
    
    bool alive;
    bool passed;
} Obstacle;

void obstacles_setup(struct Obstacle* obstacle);

void obstacle_setup(struct Obstacle* obstacle);

void obstacle_generate(struct Obstacle* obstacle);

void obstacle_destroy(struct Obstacle* obstacle);

void obstacle_move(struct Obstacle* obstacle);

void obstacle_update(struct Obstacle* obstacle);

#endif