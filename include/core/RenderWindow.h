//
// Created by manish on 02-06-2024.
//

#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#pragma once

#include <SDL.h>

// #############################################################################
//                       RenderWindow Class Declaration
// #############################################################################

class RenderWindow {
public:
  // Constructor
  RenderWindow(const char *title, int width, int height);

  // Member Functions
  SDL_Texture* loadTexture(const char *filePath) const;
  void cleanUp() const;
  void clear() const;
  void display() const;

private:
  // Attributes
  SDL_Window *window_;
  SDL_Renderer *renderer_;
};

#endif // RENDERWINDOW_H
