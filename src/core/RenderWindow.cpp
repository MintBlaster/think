//
// Created by manish on 02-06-2024.
//

#include <SDL_image.h>
#include "RenderWindow.h"
#include "think-lib.h"

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
    ASSERT(false, SDL_GetError());
  }

  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
  if (renderer_ == nullptr) {
    ASSERT(false, SDL_GetError());
  }
}

// ----------------------------------------
// Texture Loading
// ----------------------------------------

SDL_Texture* RenderWindow::loadTexture(const char *filePath) const {
  SDL_Texture* texture = IMG_LoadTexture(renderer_, filePath);
  if (texture == nullptr) {
    ASSERT(false, "Failed to load Texture");
  }
  return texture;
}

// ----------------------------------------
// Cleanup
// ----------------------------------------

void RenderWindow::cleanUp() const {
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
}

// ----------------------------------------
// Rendering Functions
// ----------------------------------------

void RenderWindow::clear() const {
  SDL_RenderClear(renderer_);
}

void RenderWindow::render(SDL_Texture *texture) const {
  SDL_RenderCopy(renderer_, texture, nullptr, nullptr);
}

void RenderWindow::display() const {
  SDL_RenderPresent(renderer_);
}
