//
// Created by manish on 04-06-2024.
//

#include "Entity.h"
#include <algorithm>
#include "Component.h"

// #############################################################################
//                             Entity Class Implementation
// #############################################################################

// -----------------------------------------------------------------------------
// Constructor & Destructor
// -----------------------------------------------------------------------------

Entity::Entity() = default;

Entity::~Entity() = default;

// -----------------------------------------------------------------------------
// Components
// -----------------------------------------------------------------------------

/// <summary> Adds a component to the entity. </summary>
void Entity::addComponent(std::unique_ptr<Component> component) {
  component->setOwner(this);
  components_.push_back(std::move(component));
}

/// <summary> Removes a component from the entity. </summary>
void Entity::removeComponent(Component* component) {
  auto it = std::remove_if(components_.begin(), components_.end(),
                           [component](const std::unique_ptr<Component>& e) {
                               return e.get() == component;
                           });
  if (it != components_.end()) {
    components_.erase(it, components_.end());
  }
}

/// <summary> Update all components within this entity. </summary>
void Entity::updateComponents() {
  for (const auto& component : components_) {
    component->update();
  }
}

/// <summary> Render all components within this entity. </summary>
void Entity::renderComponents() {
  for (const auto& component : components_) {
    component->render();
  }
}
