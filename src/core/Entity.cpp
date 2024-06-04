//
// Created by manish on 03-06-2024.
//

#include "Entity.h"
#include "EntityManager.h"
#include <algorithm>

// #############################################################################
//                        Entity Class Implementation
// #############################################################################

// ----------------------------------------
// Constructor & Destructor
// ----------------------------------------

Entity::Entity() {
  // Add entity to the entity manager
  EntityManager::getInstance().addEntity(this);
}

Entity::~Entity() {
  // Remove entity from the entity manager
  EntityManager::getInstance().removeEntity(this);
}

// -----------------------------------------------------------------------------
// Components
// -----------------------------------------------------------------------------

void Entity::addComponent(std::unique_ptr<Component> component) {
  component->setOwner(this);
  components_.push_back(std::move(component));
}

void Entity::removeComponent(Component *component) {
  if (const auto it =
          std::remove_if(components_.begin(), components_.end(),
                         [component](const std::unique_ptr<Component> &e) {
                           return e.get() == component;
                         });
      it != components_.end()) {
    components_.erase(it, components_.end());
  }
}
void Entity::updateComponents() {
  for (const std::unique_ptr<Component> component : components_) {
      component->update();
  }
}

template <typename T>
T* Entity::getComponent() {
  for (const auto& component : components_) {
    if (T* castedComponent = dynamic_cast<T*>(component.get())) {
      return castedComponent;
    }
  }
  return nullptr;
}
