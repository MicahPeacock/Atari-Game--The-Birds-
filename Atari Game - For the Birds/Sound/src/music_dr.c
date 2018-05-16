#include <osbind.h>
#include "music.h"
#include "sound.h"

unsigned long get_time();

int main()
{
    return 0;
}

unsigned long get_time()
{
    unsigned long* system_clock = 0x462;
    unsigned long current_time;
    
    unsigned long system_stack_pointer = Super(0);
    current_time = *system_clock;
    Super(system_stack_pointer);
    
    return current_time;
}