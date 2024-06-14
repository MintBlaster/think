//
// Created by manish on 03-06-2024.
//

#include "Rocket.h"

#include "ResourceManager.h"
#include "components/TextureRenderer.h"
#include "components/Transform2D.h"

// ----------------------------------------
// Constructor & Destructor
// ----------------------------------------

class TextureRenderer;
Rocket::Rocket(const std::string& name) : Entity(name)
{
    // Add Transform and EntityRenderer components
    transform2d_    = addComponent<Transform2D>();
    entityRenderer_ = addComponent<TextureRenderer>();

    // Load the rocket texture
    ResourceManager& resourceManager = ResourceManager::getInstance();

    resourceManager.loadTexture("rocket_Texture", "gfx/idle_0.png");
    entityRenderer_->setTexture("rocket_Texture");

    transform2d_->setPosition(50, 50);
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
}

void Rocket::update()
{
    // Maybe one day something will be here.
}

// ----------------------------------------
// Apply Thrust
// ----------------------------------------

void Rocket::applyThrust(const Vector2& direction)
{
    // Apply thrust in the given direction
    velocity_.x += direction.x * engineThrust_;
    velocity_.y += direction.y * engineThrust_;
    fuelAmount_ -= 0.1f; // Consume fuel
}
