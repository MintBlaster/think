//
// Created by manish on 05-06-2024.
//

#ifndef SERVICELOCATOR_H
#define SERVICELOCATOR_H

#pragma once

#include "RenderWindow.h"

#include <SDL.h>

// #############################################################################
//                           ServiceLocator Class Declaration
// #############################################################################

class ServiceLocator
{
public:
    // Static Member Functions
    static void          provideRenderer(SDL_Renderer* renderer);
    static SDL_Renderer* getRenderer();
    static void          provideWindow(RenderWindow* window);
    static RenderWindow* getWindow();

private:
    // Static Attributes
    static SDL_Renderer* rendererService_;
    static RenderWindow* windowService_;
};

#endif // SERVICELOCATOR_H
