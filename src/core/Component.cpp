// Created by manish on 04-06-2024.

#include "Component.h"
#include "think-lib.h"

// #############################################################################
//                           Component Class Implementation
// #############################################################################

void Component::setOwner(Entity* owner) {
  if (owner_ != nullptr) {
    ASSERT(false, "Setting the owner is not allowed for components that already have an owner.");
  } else {
    owner_ = owner;
  }
}