//
// Created by manish on 03-06-2024.
//

#pragma once

#include "Component.h"
#include "components/EntityRenderer.h"
#include "components/Transform.h"

#include <memory>
#include <string>
#include <vector>

class Component;
class EntityManager; // Forward declaration of EntityManager class

// #############################################################################
//                           Entity Class Declaration
// #############################################################################

class Entity {
public:
  // Constructor & Destructor
  explicit Entity();
  virtual ~Entity();
  // Member Functions
  virtual void update() {}

  // Name
  virtual void setName(const std::string& name) { name_ = name; }
  virtual std::string getName() { return name_; }

  // Components
  virtual void addComponent(std::unique_ptr<Component> component);
  virtual void removeComponent(Component* component);
  void updateComponents();

  template<typename T>
  T* getComponent();

protected:
  // Attributes
  std::string name_;
  std::vector<std::unique_ptr<Component>> components_;
};
