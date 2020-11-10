


#include "Delay.h"

void Fn_DELAY_Short (unsigned int _vrui_Time)
{
    while(_vrui_Time--);
}

void Fn_DELAY_Long  (unsigned int _vrui_Time)
{
    unsigned int vrui_i;
    
    while(_vrui_Time--)
    {
        for(vrui_i = 0; vrui_i < 1000; vrui_i++);
    }
}
