#include "..\assets\p_sprit.h"
#include "player.h"

void player_setup(struct Player* player)
{
    player->bitmap[BITMAP] = &herbie_normal_1;
    player->bitmap[ALPHAMASK] = &herbie_normal_1_alpha;
    
    player->size.height = 32;
    player->size.width  = 32;
    player->location.x  = 160;
    player->location.y  = 160;
    
    player->velocity = 0;
    player->acceleration = 2;
    
    player->alive = true;
}


void player_flap(struct Player* player)
{
    player->velocity = -30;
}


void player_fall(struct Player* player)
{
    return;
}


void player_move(struct Player* player)
{
    if(player->alive)
    {
        player->velocity += player->acceleration;
        player->location.y += player->velocity >> 2;
    }
}


void player_die(struct Player* player)
{
    player->alive = false;
    player->velocity = 0;
}


void player_update(struct Player* player)
{
    return;
}
