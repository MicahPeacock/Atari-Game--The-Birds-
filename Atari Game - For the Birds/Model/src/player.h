#ifndef MODEL_PLAYER_H
#define MODEL_PLAYER_H

#include "..\..\Raster\src\raster.h"

typedef struct Player
{
    const Bitmap32* bitmap[2];
    
    Size size;
    Point location;
    int velocity;
    int acceleration;
    
    bool alive;
} Player;

void player_setup(struct Player* player);

void player_flap(struct Player* player);

void player_fall(struct Player* player);

void player_move(struct Player* player);

void player_die(struct Player* player);

void player_update(struct Player* player);

#endif