//
// Created by manish on 02-06-2024.
//

#include "RenderWindow.h"
#include <SDL_image.h>

#include "ServiceLocator.h"
#include "UDebug.h"

// #############################################################################
//                           RenderWindow Class Implementation
// #############################################################################

// ----------------------------------------
// Constructor & Destructor
// ----------------------------------------

RenderWindow::RenderWindow(const char *title, int width, int height)
    : window_(nullptr), renderer_(nullptr) {
  window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
  if (window_ == nullptr) {
    PANIC("SDL_CreateWindow Error: %s", SDL_GetError());
  }

  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
  ServiceLocator::provideRenderer(renderer_);

  if (renderer_ == nullptr) {
    PANIC("SDL_CreateRenderer Error: %s", SDL_GetError());
  }
}

// ----------------------------------------
// Texture Loading
// ----------------------------------------

/// <summary> It will laod a texture with given path and will return it. </summary>
SDL_Texture* RenderWindow::loadTexture(const char *filePath) const {
  SDL_Texture* texture = IMG_LoadTexture(renderer_, filePath);
  if (texture == nullptr) {
    CHECK("IMG_LoadTexture Error: %s", IMG_GetError());
  }
  return texture;
}

// ----------------------------------------
// Cleanup
// ----------------------------------------

/// <summary> Clean up the rendered window. </summary>
void RenderWindow::cleanUp() const {
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
}

// ----------------------------------------
// Rendering Functions
// ----------------------------------------

/// <summary> Clears the rendered window. </summary>
void RenderWindow::clear() const {
  SDL_RenderClear(renderer_);
}

/// <summary> Display the rendered window. </summary
void RenderWindow::display() const { SDL_RenderPresent(renderer_); }
