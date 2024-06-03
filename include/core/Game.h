//
// Created by manish on 03-06-2024.
//

#ifndef GAME_H
#define GAME_H

#include "RenderWindow.h"
#include "Rocket.h"
#include <SDL.h>

class EntityManager;

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
  void update() const;
  void render() const;
  bool init();
  void cleanUp() const;

  bool isRunning_;
  SDL_Event event_;
  RenderWindow window_;
  SDL_Texture* rocketTexture_;

  Rocket* rocket1_;
  Rocket* rocket2_;
};

#endif // GAME_H
