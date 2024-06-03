//
// Created by manish on 03-06-2024.
//

// Rocket.h

#ifndef ROCKET_H
#define ROCKET_H

#include "Entity.h"
#include <SDL.h>

class Rocket final : public Entity {
public:
  Rocket(float posX, float posY, float fuelAmount, float engineThrust);

private:
  void update() override;
  void applyThrust(const Vector2& direction);

public:
  float fuelAmount_;
  float engineThrust_;

private:
  Vector2 velocity_;
  Vector2 position_;
  SDL_Texture* texture_;
};

#endif // ROCKET_H


