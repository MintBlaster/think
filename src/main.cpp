#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        return -1;
    }

    if (IMG_Init(IMG_INIT_PNG) == 0)
    {
        return -1;
    }

    // Your code here

    IMG_Quit();
    SDL_Quit();
    return 0;
}
