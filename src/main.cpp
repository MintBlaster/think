#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "think-lib.h"
#include "RenderWindow.h"

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

    RenderWindow window("Think", 1280, 720);

    bool gameRunning = true;
    SDL_Event event;

    while(gameRunning) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                gameRunning = false;
            }
        }
    }

    window.clean_up();
    SDL_Quit();
    return 0;
}
