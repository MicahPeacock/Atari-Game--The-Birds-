#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include "..\..\Raster\src\raster.h"
#include "player.h"
#include "obs.h"
#include "decor.h"
#include "score.h"

#define MAX_OBSTACLES 5
#define MAX_DECORATIONS 3
#define MAX_BOUNDARIES 2

#define CEILING 0
#define FLOOR 1

typedef enum GameState
{
    Start,
    Play,
    Pause,
    Menu
} GameState;

typedef struct Model
{
    GameState state;
    
    Player player;
    
    Obstacle obstacles[MAX_OBSTACLES];
    Decoration decorations[MAX_DECORATIONS];
    int boundaries[MAX_BOUNDARIES];
    
    Scoreboard score;
    
    const Bitmap32* border[20];
} Model;


void model_setup(struct Model* model);

void model_update_async(struct Model* model);

void model_update(struct Model* model);

void model_copy(struct Model* original, struct Model* copy);

void check_for_collision(struct Model* model);

bool check_boundary_collision(struct Player* player, int ceiling, int floor);

bool check_obstacle_collision(struct Player* player, struct Obstacle* obstacle);

#endif