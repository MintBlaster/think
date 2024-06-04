//
// Created by manish on 05-06-2024.
//

#ifndef SERVICELOCATOR_H
#define SERVICELOCATOR_H

#include "RenderWindow.h"
#include <SDL.h>

class ServiceLocator {
public:
  static void provideRenderer(SDL_Renderer* renderer) {
    rendererService_ = renderer;
  }

  static SDL_Renderer* getRenderer() {
    return rendererService_;
  }

  static void provideWindow(const RenderWindow & window) {
    windowService_ = window;
  }

  static RenderWindow& getWindow() {
    return windowService_;
  }

private:
  static SDL_Renderer* rendererService_;
  static RenderWindow& windowService_;
};

#endif // SERVICELOCATOR_H
