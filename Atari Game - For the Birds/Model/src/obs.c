#include "..\assets\o_sprit.h"
#include "obs.h"

void obstacles_setup(struct Obstacle* obstacles)
{
    int index;
    
    for(index = 0; index < MAX_OBSTACLES; index++)
    {
        obstacle_setup(&obstacles[index]);
    }
}


void obstacle_setup(struct Obstacle* obstacle)
{
    obstacle->bitmaps[HEAD][BITMAP] = &goose_head;
    obstacle->bitmaps[HEAD][ALPHAMASK] = &goose_head_alpha;
    obstacle->bitmaps[BODY][BITMAP] = &goose_body;
    obstacle->bitmaps[BODY][ALPHAMASK] = &goose_body_alpha;
    
    obstacle->speed = 0;
    
    obstacle->size.height = 32;
    obstacle->size.width = 64;
    obstacle->location.x = 704;
    obstacle->location.y = 160;
    
    obstacle->alive = false;
    obstacle->passed = true;
}


void obstacle_generate(struct Obstacle* obstacle)
{
    obstacle->speed = -3;
    obstacle->location.x = 704;
    obstacle->location.y = 160;
    
    obstacle->alive = true;
    obstacle->passed = false;
}


void obstacle_destroy(struct Obstacle* obstacle)
{
    obstacle->speed = 0;
    obstacle->alive = false;
}


void obstacle_move(struct Obstacle* obstacle)
{
    obstacle->location.x += obstacle->speed;
}


void obstacle_update(struct Obstacle* obstacle)
{
    
}