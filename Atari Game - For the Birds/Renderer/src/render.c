#include "render.h"
#include "..\..\Raster\src\raster.h"

void clear_model(UINT8* base, struct Model* model)
{
    int index;
    
    clear_column_32((UINT32*)base, model->player.location.x, model->player.location.y, model->player.size.height);
    for(index = 0; index < MAX_OBSTACLES; index++)
    {
        if(model->obstacles[index].alive)
        {
            clear_region((UINT32*)base, model->obstacles[index].size, model->obstacles[index].location);
        }
    }
}


void render(UINT8* base, struct Model* model)
{
    int index;
/*    
    for(index = 0; index < MAX_OBSTACLES; index++)
    {
        render_decoration(base);
    }
*/   
    for(index = 0; index < MAX_OBSTACLES; index++)
    {
        if(model->obstacles[index].alive)
        {
            render_obstacle((UINT8*)base, &model->obstacles[index]);
        }
    }

    render_player((UINT8*)base, &model->player);
    
    render_score((UINT8*)base, &model->score);
    
    /* render_border((UINT8*) base, model); */
}


void render_player(UINT8* base, struct Player* player)
{
    clear_alpha_mask_32((UINT32*)base, player->bitmap[ALPHAMASK], player->location.x, player->location.y);
    plot_bitmap_32((UINT32*)base, player->bitmap[BITMAP], player->location.x, player->location.y);
}


void render_obstacle(UINT8* base, struct Obstacle* obstacle)
{
    clear_alpha_mask_32((UINT32*)base, obstacle->bitmaps[HEAD][ALPHAMASK], obstacle->location.x, obstacle->location.y);
    clear_alpha_mask_32((UINT32*)base, obstacle->bitmaps[BODY][ALPHAMASK], obstacle->location.x + 32, obstacle->location.y);
    
    plot_bitmap_32((UINT32*)base, obstacle->bitmaps[HEAD][BITMAP], obstacle->location.x, obstacle->location.y);
    plot_bitmap_32((UINT32*)base, obstacle->bitmaps[BODY][BITMAP], obstacle->location.x + 32, obstacle->location.y);
}


void render_decoration(UINT8* base, struct Decoration* decor, int index)
{
    plot_bitmap_32((UINT32*)base, decor->bitmaps[index][0], decor->location.x, decor->location.y);
    plot_bitmap_32((UINT32*)base, decor->bitmaps[index][1], decor->location.x + 32, decor->location.y);
    plot_bitmap_32((UINT32*)base, decor->bitmaps[index][2], decor->location.x, decor->location.y + 32);
    plot_bitmap_32((UINT32*)base, decor->bitmaps[index][3], decor->location.x + 32, decor->location.y + 32);
}


void render_score(UINT8* base, struct Scoreboard* scoreboard)
{
    int index;
    int x;
    int y; 
    
    
    x = scoreboard->board_location.x;
    y = scoreboard->board_location.y;
    
    for(index = 0; index < 6; index++)
    {
        plot_bitmap_32((UINT32*)base, scoreboard->scoreboard[index], x, y);
        x+= 32;
    }
    
    x = scoreboard->score_location.x;
    y = scoreboard->score_location.y;
    
    for(index = 3; index >= 0; index--)
    {
        plot_bitmap_16((UINT16*)base, scoreboard->score[index], x, y);
        x += 16;
    }
}


void render_border(UINT8* base, struct Model* model)
{
    int index;
    int x = 0;
    int y = 0;
    
    for(index = 0; index < 20; index++)
    {
        plot_bitmap_32((UINT32*)base, model->border[index], x, y);
        x+= 32;
    }
}