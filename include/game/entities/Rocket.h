//
// Created by manish on 03-06-2024.
//

#ifndef ROCKET_H
#define ROCKET_H

#include "Entity.h"
#include <SDL.h>

// #############################################################################
//                            Rocket Class Declaration
// #############################################################################

class Rocket final : public Entity {
public:
  Rocket(float posX, float posY, float fuelAmount, float engineThrust);

private:
  // Update function override
  void update() override;

  // Apply thrust function
  void applyThrust(const Vector2& direction);

public:
  // Fuel amount and engine thrust variables
  float fuelAmount_;
  float engineThrust_;

private:
  // Velocity, position, and texture variables
  Vector2 velocity_;
  Vector2 position_;
  SDL_Texture* texture_;
};

#endif // ROCKET_H
