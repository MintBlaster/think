//
// Created by manish on 02-06-2024.
//

#include "RenderWindow.h"
#include <SDL_image.h>
#include "EntityManager.h"
#include "ServiceLocator.h"
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
    LOG_ERROR("SDL_CreateWindow Error: %s", SDL_GetError());
  }

  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
  ServiceLocator::provideRenderer(renderer_);

  if (renderer_ == nullptr) {
    LOG_ERROR("SDL_CreateRenderer Error: %s", SDL_GetError());
  }
}

// ----------------------------------------
// Texture Loading
// ----------------------------------------

SDL_Texture* RenderWindow::loadTexture(const char *filePath) const {
  SDL_Texture* texture = IMG_LoadTexture(renderer_, filePath);
  if (texture == nullptr) {
    ASSERT("IMG_LoadTexture Error: %s", IMG_GetError());
  } else {
    LOG_TRACE("Texture loaded: %s", filePath);
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

void RenderWindow::render() const {
  EntityManager::getInstance().renderEntities(renderer_);
}

void RenderWindow::display() const {
  SDL_RenderPresent(renderer_);
}
