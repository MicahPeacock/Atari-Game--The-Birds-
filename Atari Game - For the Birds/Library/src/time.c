#include "time.h"

#include <osbind.h>

unsigned long get_time()
{
    const unsigned long* system_clock = 0x462;
    unsigned long current_time;
    
    long system_stack_pointer = Super(0);
    current_time = *system_clock;
    Super(system_stack_pointer);
    
    return current_time;
}