#include "delay.h"

void delay(unsigned int frameLimit)
{
    // Gestion des 60 fps (images/seconde)
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + FPS)
    {
        SDL_Delay(FPS);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}
