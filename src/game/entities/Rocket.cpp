//
// Created by manish on 03-06-2024.
//

#include "Rocket.h"
#include <SDL.h>

// ----------------------------------------
// Constructor & Destructor
// ----------------------------------------

Rocket::Rocket() {

  SDL_Texture* texture_ = window_.loadTexture("../res/gfx/idle_0.png");
  if (!rocketTexture) {
    LOG_ERROR("Failed to load rocket texture.");
    return false;
  }

  texture_ = window::load_texture

  Rocket::addComponent(Transform::createInstance());
  Rocket::addComponent(EntityRenderer::createInstance());
}

// ----------------------------------------
// Update
// ----------------------------------------

void Rocket::update() {
  if (fuelAmount_ > 0) {
  }
  applyThrust(Vector2(1, 1));
  applyThrust(Vector2(1, 1));
  position_ = position_ + velocity_;
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

