//
// Created by manish on 03-06-2024.
//

#ifndef ROCKET_H
#define ROCKET_H

#include "Entity.h"
#include "UMath.h"

// #############################################################################
//                            Rocket Class Declaration
// #############################################################################

class Rocket final : public Entity {
public:
  Rocket();
private:
  // Update function override
  void update() override;

  // Apply thrust function
  void applyThrust(const Vector2& direction);

private:
  // Velocity, position, and texture variables
  float fuelAmount_ = 0;
  float engineThrust_ = 0;
  Vector2 velocity_;
  Vector2 position_;

  SDL_Texture* texture_;
};

#endif // ROCKET_H
