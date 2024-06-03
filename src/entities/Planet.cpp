//
// Created by manish on 03-06-2024.
//

#include "Planet.h"

// #############################################################################
//                           Planet Class Implementation
// #############################################################################

// ----------------------------------------
// Constructor & Destructor
// ----------------------------------------

Planet::Planet(const float posX, const float posY, const float gravityForce)
    : posX_(posX), posY_(posY), gravityForce_(gravityForce), texture_(nullptr) {
  // TODO -> Load a planet texture
}

// ----------------------------------------
// Rendering
// ----------------------------------------

void Planet::render(SDL_Renderer* renderer) const {
  const SDL_Rect dst = { static_cast<int>(posX_), static_cast<int>(posY_), 128, 128 };
  SDL_RenderCopy(renderer, texture_, nullptr, &dst);
}
