//
// Created by manish on 02-06-2024.
//

#pragma once

#include <SDL.h>

class RenderWindow {
public:
  RenderWindow(const char *title, int width, int height);
  SDL_Texture *load_texture(const char *file_path);
  void clean_up() const;
  void clear();
  void render(SDL_Texture* texture);
  void display();

private:
  SDL_Window *window_;
  SDL_Renderer *renderer_;
};