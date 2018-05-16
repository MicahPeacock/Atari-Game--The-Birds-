#include "..\assets\nums.h"
#include "score.h"

void scoreboard_setup(struct Scoreboard* score)
{
    int index;

    score->scoreboard[0] = &scoreboard_1;
    score->scoreboard[1] = &scoreboard_2;
    score->scoreboard[2] = &scoreboard_3;
    score->scoreboard[3] = &scoreboard_4;
    score->scoreboard[4] = &scoreboard_5;
    score->scoreboard[5] = &scoreboard_6;
    
    score->digits[0] = &number_0;
    score->digits[1] = &number_1;
    score->digits[2] = &number_2;
    score->digits[3] = &number_3;
    score->digits[4] = &number_4;
    score->digits[5] = &number_5;
    score->digits[6] = &number_6;
    score->digits[7] = &number_7;
    score->digits[8] = &number_8;
    score->digits[9] = &number_9;
    
    for(index = 0; index < 4; index++)
    {
        score->score[index] = score->digits[0];
    }
    
    score->value = 0;
    
    score->board_size.height = 48;
    score->board_size.width = 192;
    
    score->board_location.x = 14;
    score->board_location.y = 338;
    
    score->score_size.height = 32;
    score->score_size.width  = 64;
    
    score->score_location.x = 128;
    score->score_location.y = 346;
}

void scoreboard_increment(struct Scoreboard* score)
{
    int index;
    int currentValue;
    int digitValue;

    score->value += 1;
    currentValue = score->value;

    for(index = 0; index < 4; index++)
    {
        digitValue = currentValue % 10;
        currentValue = currentValue / 10;

        score->score[index] = score->digits[digitValue];
    }
}