#ifndef MODEL_EVENTS_H
#define MODEL_EVENTS_H

#define KEYCODE_MASK 0x00ff0000
#define FLAP_BUTTON 0x00390000 /* Space bar... */
#define PAUSE_BUTTON 0x00190000 /* 'P' key */
#define QUIT_BUTTON 0x00100000 /* 'Q' key */

#include "model.h"

void handle_input(struct Model *model);

void handle_movement(struct Model *model);

void handle_obstacle_generation(struct Model *model);

void handle_score_increment(struct Model *model);

#endif