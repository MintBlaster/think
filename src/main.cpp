#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "RenderWindow.h"
#include "think-lib.h"

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SM_ASSERT(false, SDL_GetError());
  }

  if (IMG_Init(IMG_INIT_PNG) == 0) {
    SM_ASSERT(false, IMG_GetError());
  }

  RenderWindow window("Think", 1280, 720);

  SDL_Texture* grass_texture = window.load_texture("../res/gfx/Mossy - FloatingPlatforms.png");

  bool gameRunning = true;
  SDL_Event event;

  while (gameRunning) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        gameRunning = false;
    }
      window.clear();
      window.render(grass_texture);
      window.display();
  }

  window.clean_up();
  SDL_Quit();
  return 0;
}
