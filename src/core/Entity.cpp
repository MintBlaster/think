//
// Created by manish on 03-06-2024.
//

#include "think-lib.h"
#include "Entity.h"
#include "EntityManager.h"

// #############################################################################
//                        Entity Class Implementation
// #############################################################################

// ----------------------------------------
// Constructor & Destructor
// ----------------------------------------

Entity::Entity(const Vector2& pos)
    : transform_(pos), texture_(nullptr) {
  // Add entity to the entity manager
  EntityManager::getInstance().addEntity(this);
}

Entity::~Entity() {
  // Remove entity from the entity manager
  EntityManager::getInstance().removeEntity(this);
}

// ----------------------------------------
// Rendering
// ----------------------------------------

void Entity::render(SDL_Renderer* sdl_renderer) const {
  if (texture_) {
    // Destination rectangle for rendering
    SDL_Rect dstRect = {
      static_cast<int>(transform_.getPosition().x),
      static_cast<int>(transform_.getPosition().y),
      64, 64
    };

    // Render the texture
    if (SDL_RenderCopy(sdl_renderer, texture_, nullptr, &dstRect) != 0) {
      LOG_ERROR("SDL_RenderCopy Error: %s", SDL_GetError());
    }
  } else {
    LOG_ERROR("Texture is nullptr");
  }
}
