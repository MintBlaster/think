// Created by manish on 04-06-2024.

#ifndef COMPONENT_H
#define COMPONENT_H

#include "Entity.h"
class Entity;

// #############################################################################
//                           Component Class Declaration
// #############################################################################

class Component {
public:
  // Constructor & Destructor
  explicit Component() = default;
  virtual ~Component() = default;

  // Member Functions
  virtual void update() {}
  static std::unique_ptr<Component> createInstance() { return std::make_unique<Component>(); }

  // Getters and Setters
  virtual void setOwner(Entity* owner);
  virtual bool haveOwner() { return owner_ != nullptr; }
  [[nodiscard]] Entity& getOwner() const { return *owner_; }

protected:
  // Attributes
  Entity* owner_ = nullptr;
};

#endif // COMPONENT_H
