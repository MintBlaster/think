//
// Created by manish on 03-06-2024.
//

#include "Rocket.h"
#include <SDL.h>

// ----------------------------------------
// Constructor & Destructor
// ----------------------------------------

Rocket::Rocket(float posX, float posY, float fuelAmount, float engineThrust)
    : Entity(Vector2(posX, posY)), velocity_(),
      fuelAmount_(fuelAmount), engineThrust_(engineThrust / 100.0f), texture_(nullptr) {}


// ----------------------------------------
// Update
// ----------------------------------------

void Rocket::update() {
  if (fuelAmount_ > 0) {
  }
  applyThrust(Vector2(1, 1));
  applyThrust(Vector2(1, 1));
  position_ = position_ + velocity_;
  this->setPosition(position_);
}

// ----------------------------------------
// Apply Thrust
// ----------------------------------------

void Rocket::applyThrust(const Vector2& direction) {
  // Apply thrust in the given direction
  velocity_.x += direction.x * engineThrust_;
  velocity_.y += direction.y * engineThrust_;
  fuelAmount_ -= 0.1f; // Consume fuel
}

