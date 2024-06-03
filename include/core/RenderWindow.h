//
// Created by manish on 02-06-2024.
//

#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

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
  void render() const;
  void display() const;
  [[nodiscard]] SDL_Renderer* getRenderer() const { return renderer_; } // Getter for renderer

private:
  // Attributes
  SDL_Window *window_;
  SDL_Renderer *renderer_;
};

#endif // RENDERWINDOW_H
