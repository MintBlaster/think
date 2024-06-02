#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "think-lib.h"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SM_ASSERT(false, SDL_GetError());
    }

    if (IMG_Init(IMG_INIT_PNG) == 0)
    {
        SM_ASSERT(false, IMG_GetError());
    }

    IMG_Quit();
    SDL_Quit();
    return 0;
}
