#include "music.h"
#include "sound.h"

void play_music(struct Song* song)
{   
    play_track(song->tracks[CHANNEL_A], CHANNEL_A);
    play_track(song->tracks[CHANNEL_B], CHANNEL_B);
}

void play_track(struct Track* track, int channel)
{
    track->index = 0;
    set_tone(channel, track->notes[track->index].tone);
    enable_channel(channel, 1, 0);
    set_volume(channel, track->notes[track->index].volume);
}


void update_music(struct Song *song)
{
    update_track(song->tracks[CHANNEL_A], CHANNEL_A);
    update_track(song->tracks[CHANNEL_B], CHANNEL_B);
}


void update_track(struct Track *track, int channel)
{
    int previous_index;
    
    track->notes[track->index].counter += 1;
    if(track->notes[track->index].counter >= track->notes[track->index].duration)
    {
        previous_index = track->index; 
        track->index++;
        if(track->index >= track->size) 
        {
            track->index = 0;
        }
        track->notes[track->index].counter = track->notes[previous_index].counter - track->notes[previous_index].duration;
        track->notes[previous_index].counter = 0; 
        
        set_tone(channel, track->notes[track->index].tone);
        set_volume(channel, track->notes[track->index].volume);
    } 
}