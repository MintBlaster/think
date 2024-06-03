//
// Created by manish on 02-06-2024.
//

// RenderWindow.h

#pragma once

#include <SDL.h>

class RenderWindow {
public:
  RenderWindow(const char *title, int width, int height);
  SDL_Texture* loadTexture(const char *filePath) const;
  void cleanUp() const;
  void clear() const;
  void render() const;
  void display() const;
  [[nodiscard]] SDL_Renderer* getRenderer() const { return renderer_; } // Getter for renderer

private:
  SDL_Window *window_;
  SDL_Renderer *renderer_;
};