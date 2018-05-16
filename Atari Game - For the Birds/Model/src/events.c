#include <osbind.h>
#include <stdio.h>
#include "events.h"

void handle_input(struct Model *model)
{
    long result;

    if (Cconis())               /* Check for keypress */
    {
        result = Cnecin();      /* Read keypress */
        
        if(model->state == Start)
        {
            if ((result & KEYCODE_MASK) == FLAP_BUTTON)
            {
                player_flap(&model->player);
                model->state = Play;
            }                
        }
        else if(model->state == Pause)
        {
            if ((result & KEYCODE_MASK) == FLAP_BUTTON)
            {
                player_flap(&model->player);
                model->state = Play; 
            }      
            else if((result & KEYCODE_MASK) == QUIT_BUTTON)
            {
                player_die(&model->player);
            }
        }
        else if(model->state == Play)
        {
            if ((result & KEYCODE_MASK) == FLAP_BUTTON)
                player_flap(&model->player);
            else if((result & KEYCODE_MASK) == PAUSE_BUTTON)
                model->state = Pause;
        }
    }
}

void handle_movement(struct Model *model)
{
    int index;

    /* Player Movement */
    player_move(&model->player);
    
    /* Obstacle Movement */
    for (index = 0; index < MAX_OBSTACLES; index++)
    {
        if(model->obstacles[index].alive)
        {
            obstacle_move(&model->obstacles[index]);
            if (model->obstacles[index].location.x < -64)
            {
                obstacle_destroy(&model->obstacles[index]);
            }
        }
    }
}

void handle_obstacle_generation(struct Model *model)
{
    int index;
    int count = 1;
    
    for (index = 0; index < count; index++)
    {
        if(!model->obstacles[index].alive)
        {
            obstacle_generate(&model->obstacles[index]);
        }
    }
}

void handle_score_increment(struct Model *model)
{
    int index;

    for(index = 0; index < MAX_OBSTACLES; index++)
    {
        if (model->obstacles[index].alive)
        {
            if (model->obstacles[index].location.x < model->player.location.x)
            {
                if (!model->obstacles[index].passed)
                {
                    scoreboard_increment(&model->score);
                    model->obstacles[index].passed = true;
                }
            }
        }
    }
}