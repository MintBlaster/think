//
// Created by manish on 03-06-2024.
//

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <SDL.h>
#include <vector>

class Entity; // Forward declaration of Entity class

// #############################################################################
//                        EntityManager Class Declaration
// #############################################################################

class EntityManager {
public:
  // Singleton
  static EntityManager& getInstance();

  // Member Functions
  void addEntity(Entity* entity);
  void removeEntity(Entity* entity);
  void updateEntities();
  void renderEntities(SDL_Renderer* renderer);

  // Deleted Constructors
  EntityManager(const EntityManager&) = delete;
  EntityManager& operator=(const EntityManager&) = delete;

private:
  // Constructor
  EntityManager() = default;

  // Attributes
  std::vector<Entity*> entities_;
};

#endif // ENTITYMANAGER_H
