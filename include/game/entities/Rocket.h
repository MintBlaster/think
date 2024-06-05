//
// Created by manish on 03-06-2024.
//

#ifndef ROCKET_H
#define ROCKET_H

#pragma once

#include <SDL_render.h>
#include "Entity.h"
#include "UMath.h"
#include "components/EntityRenderer.h"
#include "components/Transform.h"

// #############################################################################
//                            Rocket Class Declaration
// #############################################################################

class Rocket final : public Entity {
public:
  // Constructor
  Rocket();

  // Setters
  void setFuelAmount(float amount) { fuelAmount_ = amount; }
  void setEngineThrust(float thrust) { engineThrust_ = thrust; }

private:
  // Physics update function override
  void physicsUpdate() override;
  // Update function override
  void update() override;
  // Apply thrust function
  void applyThrust(const Vector2& direction);

  // Attributes
  float fuelAmount_ = 0;
  float engineThrust_ = 0;
  Vector2 velocity_;
  Vector2 position_;
  SDL_Texture* texture_{};
  Transform* transform_{};
  EntityRenderer* entityRenderer_{};
};

#endif // ROCKET_H
