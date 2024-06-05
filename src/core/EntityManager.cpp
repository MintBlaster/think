//
// Created by manish on 03-06-2024.
//

#include "EntityManager.h"
#include "Entity.h"
#include "think-lib.h"
#include <algorithm>
#include <iostream>

// #############################################################################
//                    EntityManager Class Implementation
// #############################################################################

// ----------------------------------------
// Singleton Instance
// ----------------------------------------

EntityManager &EntityManager::getInstance() {
  static EntityManager instance;
  return instance;
}

// ----------------------------------------
// Entity Management
// ----------------------------------------

void EntityManager::addEntity(Entity* entity) {
  entities_.push_back(entity);
  LOG_TRACE("Entity added. Total entities: %d", entities_.size());
}

void EntityManager::removeEntity(Entity* entity) {
  // Remove the entity from the vector
  entities_.erase(std::remove_if(entities_.begin(), entities_.end(), [entity](const Entity * e) {
      return e == entity;
  }), entities_.end());
  LOG_TRACE("Entity removed. Total entities: %d", entities_.size());
}

// ----------------------------------------
// Update and Render
// ----------------------------------------

void EntityManager::updateEntities() {
  // Update all entities
  for (Entity *entity: entities_) {
    entity->update();
  }
}
void EntityManager::renderEntities() {
  // Update all entities
  for (Entity *entity: entities_) {
    entity->render();
  }
}
