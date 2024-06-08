//
// Created by manish on 03-06-2024.
//

#ifndef ROCKET_H
#define ROCKET_H

#pragma once

#include "../../include/core/Entity.h"
#include "../../include/core/components/TextureRenderer.h"
#include "../../include/core/components/Transform2D.h"
#include "../../include/utils/UMath.h"

// #############################################################################
//                            Rocket Class Declaration
// #############################################################################

class Rocket final : public Entity {
public:
  // Constructor
  explicit Rocket(const std::string& name);

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
  Transform2D* transform2d_{};
  TextureRenderer* entityRenderer_{};
};

#endif // ROCKET_H
