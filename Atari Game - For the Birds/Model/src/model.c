#include <osbind.h>
#include <stdlib.h>
#include <string.h>
#include "..\assets\backgr.h"
#include "model.h"
#include "events.h"

void model_setup(struct Model* model)
{
    int index;
    
    model->state = Start;
    
    player_setup(&model->player);
    obstacles_setup(model->obstacles);
    decorations_setup(model->decorations);    
    scoreboard_setup(&model->score);
    
    model->boundaries[CEILING] = 16;
    model->boundaries[FLOOR]   = 352;
    
    model->border[0] = &background_front;
    for(index = 1; index < 19; index++)
    {
        model->border[index] = &background_mid;
    }
    model->border[19] = &background_end;
}

void model_update_async(struct Model* model)
{
    handle_input(model);
}

void model_update(struct Model* model)
{
    handle_movement(model);
    check_for_collision(model);
    handle_score_increment(model);
    handle_obstacle_generation(model);
}

void model_copy(struct Model* original, struct Model* copy)
{
    memcpy(copy, original, sizeof(Model));
}

void check_for_collision(struct Model* model)
{
    int index;
    
    if(check_boundary_collision(&model->player, model->boundaries[CEILING], model->boundaries[FLOOR]))
    {
        player_die(&model->player);
    }
    for(index = 0; index < MAX_OBSTACLES && model->player.alive; index++)
    {
        if(model->obstacles[index].alive && check_obstacle_collision(&model->player, &model->obstacles[index]))
        {
            player_die(&model->player);
        }
    }
}

bool check_boundary_collision(struct Player* player, int ceiling, int floor)
{
    if(player->location.y < ceiling)
    {
        return true;
    }
    if((player->location.y + player->size.height) > floor)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_obstacle_collision(struct Player* player, struct Obstacle* obstacle)
{
    if((player->location.x < (obstacle->location.x + obstacle->size.width)) && ((player->location.x + player->size.width) > obstacle->location.x) && 
      (player->location.y < (obstacle->location.y + obstacle->size.height)) && ((player->location.y + player->size.height) > obstacle->location.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}