#ifndef MODEL_SCOREBOARD_H
#define MODEL_SCOREBOARD_H

#include "..\..\Raster\src\raster.h"

typedef struct Scoreboard
{
    const Bitmap32* scoreboard[6];
    
    Size board_size;
    Point board_location;
    
    const Bitmap16* digits[10];
    const Bitmap16* score[4];
    
    Size score_size;
    Point score_location;
    
    int value;
} Scoreboard;

void scoreboard_setup(struct Scoreboard* score);

void scoreboard_increment(struct Scoreboard* score);

#endif