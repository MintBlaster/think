//
// Created by manish on 02-06-2024.
//

#include "RenderWindow.h"
#include "think-lib.h"

RenderWindow::RenderWindow(const char *title, int width, int height) :window_(nullptr), renderer_(nullptr)
{
    window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (window_ == nullptr) {
        SM_ASSERT(false, SDL_GetError());
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::clean_up()
{
    SDL_DestroyWindow(window_);
}
