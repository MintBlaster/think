//
// Created by manish on 03-06-2024.
//

#ifndef SCENE_H
#define SCENE_H

#pragma once

#include "Entity.h"
#include <memory>
#include <string>
#include <vector>

// #############################################################################
//                     Scene Class Declaration
// #############################################################################

class Scene {
public:
  explicit Scene(std::string name);
  ~Scene() = default;

  // Member Functions
  void addEntity(std::unique_ptr<Entity> entity);
  void removeEntity(Entity* entity);
  void physicsUpdateEntities();
  void updateEntities();
  void renderEntities();

private:
  // Attributes
  std::string name_;
  std::vector<std::unique_ptr<Entity>> entities_;
};

#endif // SCENE_H
