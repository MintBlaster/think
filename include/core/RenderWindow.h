//
// Created by manish on 02-06-2024.
//

#pragma once

#include <SDL.h>

// #############################################################################
//                           RenderWindow Class Declaration
// #############################################################################

class RenderWindow {
public:
  RenderWindow(const char *title, int width, int height);
  SDL_Texture* loadTexture(const char *filePath) const;
  void cleanUp() const;
  void clear() const;
  void render(SDL_Texture* texture) const;
  void display() const;

private:
  SDL_Window *window_;
  SDL_Renderer *renderer_;
};

