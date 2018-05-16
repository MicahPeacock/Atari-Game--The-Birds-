#ifndef RENDERER_RENDER_H
#define RENDERER_RENDER_H

#include "..\..\Raster\src\raster.h"
#include "..\..\Model\src\model.h"

void clear_model(UINT8* base, struct Model* model);

void render(UINT8* base, struct Model* model);

void render_player(UINT8* base, struct Player* player);

void render_obstacle(UINT8* base, struct Obstacle* obstacle);

void render_decoration(UINT8* base, struct Decoration* decor, int index);

void render_score(UINT8* base, struct Scoreboard* scoreboard);

void render_border(UINT8* base, struct Model* model);

#endif