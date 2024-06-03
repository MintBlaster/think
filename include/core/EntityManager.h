//
// Created by manish on 03-06-2024.
//

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "RenderWindow.h"
#include "EntityManager.h"
#include <SDL.h>
#include <vector>

class Entity; // Forward declaration of Entity class

class EntityManager {
public:
  static EntityManager& getInstance();
  void addEntity(Entity* entity);
  void removeEntity(Entity* entity);
  void updateEntities();
  void renderEntities(SDL_Renderer* renderer);

  EntityManager(const EntityManager&) = delete;
  EntityManager& operator=(const EntityManager&) = delete;

private:
  EntityManager() = default;
  std::vector<Entity*> entities_;
};

#endif // ENTITYMANAGER_H
