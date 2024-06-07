//
// Created by manish on 04-06-2024.
//

#include "Component.h"
#include "UDebug.h"

// #############################################################################
//                           Component Class Implementation
// #############################################################################

/// <summary> Set the entity as owner of this component </summary>
void Component::setOwner(Entity* owner) {
  if (owner_ != nullptr) {
    CHECK(false, "Setting the owner is not allowed for components that already have an owner.");
  } else {
    owner_ = owner;
  }

  satisfyDependencies();
}