//
// Created by manish on 04-06-2024.
//

#include "components/TextureRenderer.h"

#include "ResourceManager.h"
#include "ServiceLocator.h"
#include "components/Transform2D.h"

// #############################################################################
//                       EntityRenderer Class Implementation
// #############################################################################

// -----------------------------------------------------------------------------
// Constructor
// -----------------------------------------------------------------------------

TextureRenderer::TextureRenderer() : transform2d_(nullptr), width(64), height(64) {}

// -----------------------------------------------------------------------------
// Dependencies Satisfaction
// -----------------------------------------------------------------------------

// Gets Transform2d to get the location, rotation and scale to render the texture.
void TextureRenderer::satisfyDependencies()
{
    if (owner_->getComponent<Transform2D>() == nullptr)
    {
        owner_->addComponent<Transform2D>();
    }
    transform2d_ = owner_->getComponent<Transform2D>();
}

// -----------------------------------------------------------------------------
// Rendering
// -----------------------------------------------------------------------------

// It retrieves texture from the resource manager and renders it.
void TextureRenderer::render()
{
    GLuint texture = ResourceManager::getInstance().getTexture(textureName_);
    if (!texture)
        return;
    Vector2 position = transform2d_->getPosition();
    ServiceLocator::getWindow()->renderTexture(texture, position.x, position.y, width, height);
}
