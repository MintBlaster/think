//
// Created by manish on 03-06-2024.
//

#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <memory>
#include "core/RenderWindow.h"
#include "game/entities/Rocket.h"

class EntityManager;
class ResourceManager;
class Component;

// #############################################################################
//                           Game Class Declaration
// #############################################################################

class Game {
public:
  // Constructor & Destructor
  Game();
  ~Game();

  // Member Functions
  void run();

private:
  // Helper Functions
  void processEvents();
  void update();
  void render() const;
  bool init();
  void cleanUp() const;

  // Attributes
  bool isRunning_;
  SDL_Event event_;
  RenderWindow window_;

  // testing
  std::unique_ptr<Rocket>rocket1;
  std::unique_ptr<Rocket> rocket2;
};

#endif // GAME_H
