//
// Created by manish on 03-06-2024.
//

#ifndef ROCKET_H
#define ROCKET_H

#include <SDL.h>

// #############################################################################
//                           Rocket Class Declaration
// #############################################################################

class Rocket {
public:
  Rocket(float posX, float posY, float fuelAmount, float engineThrust);
  void update();
  void render(SDL_Renderer* renderer) const;
  void applyThrust();

private:
  float posX_;
  float posY_;
  float velocityX_;
  float velocityY_;
  float fuelAmount_;
  float engineThrust_;
  SDL_Texture* texture_;
};

#endif // ROCKET_H
