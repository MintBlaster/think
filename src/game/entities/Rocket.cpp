//
// Created by manish on 03-06-2024.
//

#include "Rocket.h"

#include "ResourceManager.h"
#include "UTime.h"
#include "components/EntityRenderer.h"
#include "components/Transform.h"
#include "think-lib.h"

// ----------------------------------------
// Constructor & Destructor
// ----------------------------------------

Rocket::Rocket() {
  // Add Transform and EntityRenderer components
  Rocket::addComponent(std::make_unique<Transform>());
  Rocket::addComponent(std::make_unique<EntityRenderer>());

  // Get pointers to the Transform and EntityRenderer components
  transform_ = getComponent<Transform>();
  entityRenderer_ = getComponent<EntityRenderer>();

  // Load the rocket texture
  ResourceManager::getInstance().loadTexture("rocket_Texture", "gfx/idle_0.png");
  entityRenderer_->setTexture("rocket_Texture");

  transform_->setPosition(50, 50);
}


// ----------------------------------------
// Update
// ----------------------------------------

void Rocket::physicsUpdate() {
  transform_->setPosition(position_);
  if (fuelAmount_ > 0) {
  }
  applyThrust(Vector2(1, 1));
  position_ = position_ + velocity_;
  LOG_TRACE(velocity_.toString().c_str());
}

void Rocket::update() {
  // noop
}

// ----------------------------------------
// Apply Thrust
// ----------------------------------------

void Rocket::applyThrust(const Vector2& direction) {
  // Apply thrust in the given direction
  velocity_.x += direction.x * engineThrust_;
  velocity_.y += direction.y * engineThrust_;
  fuelAmount_ -= 0.1f; // Consume fuel
}

