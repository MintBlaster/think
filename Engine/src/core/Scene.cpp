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

/// <summary> Removes an entity from the scene. </summary>

// ----------------------------------------
// Update and Render
// ----------------------------------------

/// <summary> Gets an enity by its name </summary>
Entity *Scene::getEntityByName(std::string &name) {
  auto it =
      std::find_if(entities_.begin(), entities_.end(),
                   [&name](const auto &pair) { return pair.first == name; });
  if (it != entities_.end()) {
    return it->second.get();
  }
  return nullptr;
}
void Scene::init() {
  for (const auto& entity : entities_) {
    entity.second->satisfyDependencies();
  }
}

/// <summary> Updates all entities within this scene in a fixed
/// timestep.</summary>
void Scene::physicsUpdateEntities() {
  for (const auto& entity : entities_) {
    entity.second->physicsUpdate();
  }
}

/// <summary> Updates all entities within this scene. </summary>
void Scene::updateEntities() {
  for (const auto& entity : entities_) {
    entity.second->update();
  }
}

/// <summary> Render all entities within this scene. </summary>
void Scene::renderEntities() {
  for (const auto& entity : entities_) {
    entity.second->render();
  }
}
