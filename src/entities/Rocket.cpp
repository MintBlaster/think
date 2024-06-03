//
// Created by manish on 03-06-2024.
//

#include "Rocket.h"
#include "think-lib.h"
#include <SDL.h>

// ----------------------------------------
// Constructor & Destructor
// ----------------------------------------

Rocket::Rocket(float posX, float posY, float fuelAmount, float engineThrust)
    : Entity(Vector2(posX, posY)), velocityX_(0), velocityY_(0),
      fuelAmount_(fuelAmount), engineThrust_(engineThrust / 100.0f), texture_(nullptr) {}

// ----------------------------------------
// Update
// ----------------------------------------

void Rocket::update() {
  if (fuelAmount_ > 0) {
    // No automatic thrust
  }
  position_ = position_ + Vector2(velocityX_, velocityY_);
  LOG_TRACE("Rocket position: (%.2f, %.2f)", position_.x, position_.y); // Debug
}

void Rocket::render(SDL_Renderer *renderer) {
  if (texture_) {
    SDL_Rect dstRect = {
      static_cast<int>(position_.x),
      static_cast<int>(position_.y),
      64, // Assuming the width of the rocket texture
      64  // Assuming the height of the rocket texture
    };
    if (SDL_RenderCopy(renderer, texture_, nullptr, &dstRect) != 0) {
      LOG_ERROR("SDL_RenderCopy Error: %s", SDL_GetError());
    } else {
      LOG_TRACE("Rocket rendered at position: (%.2f, %.2f)", position_.x, position_.y);
    }
  } else {
    LOG_ERROR("Texture is nullptr");
  }
}

// ----------------------------------------
// Apply Thrust
// ----------------------------------------

void Rocket::applyThrust(const Vector2& direction) {
  // Apply thrust in the given direction
  velocityX_ += direction.x * engineThrust_;
  velocityY_ += direction.y * engineThrust_;
  fuelAmount_ -= 0.1f; // Consume fuel
  LOG_TRACE("Applying thrust: (%.2f, %.2f)", direction.x, direction.y);
}

