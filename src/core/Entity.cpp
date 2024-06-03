//
// Created by manish on 03-06-2024.
//

#include "think-lib.h"
#include "Entity.h"
#include "EntityManager.h"

Entity::Entity(const Vector2& pos)
    : transform_(pos), texture_(nullptr) {
  EntityManager::getInstance().addEntity(this);
}

Entity::~Entity() {
  EntityManager::getInstance().removeEntity(this);
}

void Entity::render(SDL_Renderer* sdl_renderer) const {
  if (texture_) {
    SDL_Rect dstRect = {
      static_cast<int>(transform_.getPosition().x),
      static_cast<int>(transform_.getPosition().y),
      64, 64
  };
    if (SDL_RenderCopy(sdl_renderer, texture_, nullptr, &dstRect) != 0) {
      LOG_ERROR("SDL_RenderCopy Error: %s", SDL_GetError());
    }
  } else {
    LOG_ERROR("Texture is nullptr");
  }
}

