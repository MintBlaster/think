//
// Created by manish on 02-06-2024.
//

#include <SDL_image.h>
#include "RenderWindow.h"
#include "think-lib.h"

RenderWindow::RenderWindow(const char *title, int width, int height)
    : window_(nullptr), renderer_(nullptr) {
  window_ =
      SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                       width, height, SDL_WINDOW_SHOWN);

  if (window_ == nullptr) {
    SM_ASSERT(false, SDL_GetError());
  }

  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture *RenderWindow::load_texture(const char *file_path) {
  SDL_Texture* texture = nullptr;
  texture = IMG_LoadTexture(renderer_, file_path);

  if (texture == nullptr) {
    SM_ASSERT(false, "Failed to laod Texture : %s\n", SDL_GetError());
  }

  return texture;
}


void RenderWindow::clean_up() const { SDL_DestroyWindow(window_); }

void RenderWindow::clear() {
  SDL_RenderClear(renderer_);
}

void RenderWindow::render(SDL_Texture *texture) {
  SDL_RenderCopy(renderer_, texture, nullptr, nullptr);
}

void RenderWindow::display() {
  SDL_RenderPresent(renderer_);
}
