//
// Created by manish on 03-06-2024.
//

#include "Rocket.h"

#include "PlayerInput.h"
#include "ResourceManager.h"
#include "components/TextureRenderer.h"
#include "components/Transform2D.h"

class TextureRenderer;

// ----------------------------------------
// Constructor & Destructor
// ----------------------------------------

Rocket::Rocket(const std::string& name) : Entity(name)
{
    // Add Transform and EntityRenderer components
    transform2d_    = getOrAddComponent<Transform2D>();
    entityRenderer_ = getOrAddComponent<TextureRenderer>();

    // Load the rocket texture
    ResourceManager& resourceManager = ResourceManager::getInstance();
    transform2d_->setPosition(50, 50);
}

void Rocket::init()
{

    if (getComponent<PlayerInput>())
    {
        isPlayerInput = true;
    }
    else
        isPlayerInput = false;
}

// ----------------------------------------
// Update
// ----------------------------------------

void Rocket::physicsUpdate()
{
    if (fuelAmount_ > 0)
    {
        applyThrust(Vector2(1, 1));
    }
    else
    {
        velocity_.x = velocity_.x > 0 ? velocity_.x -= 1 : 0;
        velocity_.y = velocity_.y > 0 ? velocity_.y -= 1 : 0;
    }

    transform2d_->setPosition(transform2d_->getPosition() + velocity_);
}

void Rocket::update()
{
    Entity::update();

    if (isPlayerInput)
    {
        moveInput_ = getComponent<PlayerInput>()->getMoveInput();
    }
}

// ----------------------------------------
// Apply Thrust
// ----------------------------------------

void Rocket::applyThrust(const Vector2& direction)
{
    // Apply thrust in the given direction
    velocity_.x += direction.x * engineThrust_ * moveInput_.x;
    velocity_.y += direction.y * engineThrust_ * moveInput_.y;
    fuelAmount_ -= 0.1f; // Consume fuel
}
