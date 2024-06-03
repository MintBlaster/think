//
// Created by manish on 03-06-2024.
//

#include "Rocket.h"

// #############################################################################
//                           Rocket Class Implementation
// #############################################################################

// ----------------------------------------
// Constructor & Destructor
// ----------------------------------------

Rocket::Rocket(float posX, float posY, float fuelAmount, float engineThrust)
    : posX_(posX), posY_(posY), velocityX_(0), velocityY_(0),
      fuelAmount_(fuelAmount), engineThrust_(engineThrust), texture_(nullptr) {
  // TODO -> Load a rocket texture
}

// ----------------------------------------
// Update
// ----------------------------------------

void Rocket::update() {
  if (fuelAmount_ > 0) {
    applyThrust();
  }
  posX_ += velocityX_;
  posY_ += velocityY_;
}

// ----------------------------------------
// Rendering
// ----------------------------------------

void Rocket::render(SDL_Renderer* renderer) const {
  SDL_Rect dst = { static_cast<int>(posX_), static_cast<int>(posY_), 64, 64 }; // Example size
  SDL_RenderCopy(renderer, texture_, nullptr, &dst);
}

// ----------------------------------------
// Apply Thrust
// ----------------------------------------

void Rocket::applyThrust() {
  // Simple physics calculation (this should be more complex)
  velocityX_ += engineThrust_;
  velocityY_ += engineThrust_;
  fuelAmount_ -= 1.0f; // Consume fuel
}
