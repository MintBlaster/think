//
// Created by manish on 03-06-2024.
//

#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "RenderWindow.h"

// -------------------------------------------------------------------
// Game Class
// -------------------------------------------------------------------

class Game {
public:
  Game();
  ~Game();
  void run();

private:
  void processEvents();
  static void update();
  void render() const;
  bool init();
  void cleanUp() const;

  bool isRunning_;
  SDL_Event event_;
  RenderWindow window_;
  SDL_Texture *imageTexture_;
};

#endif // GAME_H

