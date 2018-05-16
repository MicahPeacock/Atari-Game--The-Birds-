#include <stdio.h>
#include <osbind.h>

#include "..\..\Model\src\model.h"
#include "..\..\Renderer\src\render.h"

long get_time();
void restore();
UINT8* back_buffer();


UINT8 buffer[32256]; 
void* old_system_interrupt;

int main()
{
    UINT8* base = (UINT8*)Physbase();
    UINT8* back = back_buffer();
    
    
    Model model;
    Model old;
    
    long current_time = 0;
    long previous_time = 0;
    
    bool quit = false;
    
    clear_screen((UINT32*)base);
    
    old_system_interrupt = Setexc(0x102, &restore);
    
    model_setup(&model);
    render(base, &model);
    
    model_copy(&model, &old);
    
    previous_time = get_time();
    
    while(!quit)
    {
        current_time = get_time();

        do
        {
            model_update_async(&model); 
            current_time = get_time();
        } while(current_time == previous_time);

        clear_model(back, &old);
        render(back, &model);
        
        back = swap_buffers(base, back);
        Setscreen(-1, back, -1);
        
        model_copy(&model, &old);
        
        if(model.state == Play)
        {
            model_update(&model);
        }
        
        if(!model.player.alive)
        {
            quit = true;
        }
        previous_time = current_time;
    }
    
    restore();
    
    return 0;
}

void restore()
{
    Setscreen(-1, Physbase(), -1);
    Setexc(0x102, old_system_interrupt);
}

long get_time()
{
    const long* timer = 0x462;
    const long old_ssp = Super(0);
    long time;
    time = *timer;
    Super(old_ssp);
    return time;
}

UINT8* back_buffer()
{
    long address;
    address = (long)&buffer;
    return (UINT8*)&buffer[(256 - (address % 256))];
}