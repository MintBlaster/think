//
// Created by manish on 03-06-2024.
//

#include <algorithm>
#include "Scene.h"

// #############################################################################
//                    Scene Class Implementation
// #############################################################################

// ----------------------------------------
// Constructor
// ----------------------------------------

Scene::Scene(std::string name) : name_(std::move(name)) {}

/// <summary> Adds an entity to the scene. </summary>
void Scene::addEntity(std::unique_ptr<Entity> entity) {
  entities_.push_back(std::move(entity));
}

/// <summary> Removes an entity from the scene. </summary>
void Scene::removeEntity(Entity* entity) {
  auto it = std::remove_if(entities_.begin(), entities_.end(),
                           [entity](const std::unique_ptr<Entity>& e) {
                               return e.get() == entity;
                           });
  if (it != entities_.end()) {
    entities_.erase(it, entities_.end());
  }
}

// ----------------------------------------
// Update and Render
// ----------------------------------------

/// <summary> Updates all entities within this scene in a fixed timestep. </summary>
void Scene::physicsUpdateEntities() {
  for (const auto& entity : entities_) {
    entity->physicsUpdate();
  }
}

/// <summary> Updates all entities within this scene. </summary>
void Scene::updateEntities() {
  for (const auto& entity : entities_) {
    entity->update();
  }
}

/// <summary> Render all entities within this scene. </summary>
void Scene::renderEntities() {
  for (const auto& entity : entities_) {
    entity->render();
  }
}
