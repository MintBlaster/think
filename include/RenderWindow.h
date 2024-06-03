//
// Created by manish on 02-06-2024.
//

#pragma once

#include <SDL.h>
#include <SDL_image.h>

class RenderWindow
{
public:
    RenderWindow(const char* title, int width, int height);
    void clean_up();
private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
};