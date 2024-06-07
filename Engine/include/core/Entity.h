//
// Created by manish on 03-06-2024.
//

#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include "Component.h"
#include <memory>
#include <string>
#include <vector>

class Component;

// #############################################################################
//                               Entity Class Declaration
// #############################################################################

class Entity {
public:
  // Constructor & Destructor
  explicit Entity();
  virtual ~Entity();

  // Member Functions
  virtual void physicsUpdate() {}
  virtual void update() { updateComponents(); }
  virtual void render() { renderComponents(); }

  // Name
  virtual void setName(const std::string& name) { name_ = name; }
  virtual std::string getName() { return name_; }

  // Components
  virtual void addComponent(std::unique_ptr<Component> component);
  virtual void removeComponent(Component* component);
  void updateComponents();
  void renderComponents();

  template<typename T>
  T* getComponent();

protected:
  // Attributes
  std::string name_;
  std::vector<std::unique_ptr<Component>> components_;
};

// #############################################################################
//                               Templates Implementation
// #############################################################################

template <typename T>
T* Entity::getComponent() {
  for (const auto& component : components_) {
    if (T* castedComponent = dynamic_cast<T*>(component.get())) {
      return castedComponent;
    }
  }
  return nullptr;
}

#endif // ENTITY_H
