//
// Created by manish on 03-06-2024.
//

#include "EntityManager.h"
#include "Entity.h"
#include "think-lib.h"

#include <algorithm>
#include <iostream>

EntityManager& EntityManager::getInstance() {
  static EntityManager instance;
  return instance;
}

void EntityManager::addEntity(Entity* entity) {
  entities_.push_back(entity);
  LOG_TRACE("Entity added. Total entities: %d", entities_.size());
}

void EntityManager::removeEntity(Entity* entity) {
  entities_.erase(std::remove_if(entities_.begin(), entities_.end(), [entity](Entity* e) {
      return e == entity;
  }), entities_.end());
  LOG_TRACE("Entity removed. Total entities: %d", entities_.size());
}

void EntityManager::updateEntities() {
  for (Entity* entity : entities_) {
    entity->update();
  }
}

void EntityManager::renderEntities(SDL_Renderer* renderer) {
  for (Entity* entity : entities_) {
    entity->render(renderer);
  }
}
