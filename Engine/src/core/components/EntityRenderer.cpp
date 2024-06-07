//
// Created by manish on 04-06-2024.
//

#include "components/EntityRenderer.h"
#include "ResourceManager.h"
#include "ServiceLocator.h"
#include "UDebug.h"

#include <iostream>

// #############################################################################
//                       EntityRenderer Class Implementation
// #############################################################################

// -----------------------------------------------------------------------------
// Constructor
// -----------------------------------------------------------------------------

EntityRenderer::EntityRenderer() : transform_(nullptr) {}

// -----------------------------------------------------------------------------
// Dependencies Satisfaction
// -----------------------------------------------------------------------------

// Gets transform to get the location, rotation and scale to render the texture.
void EntityRenderer::satisfyDependencies() {
  if (owner_->getComponent<Transform>() == nullptr) {
    owner_->addComponent<Transform>();
  }
  transform_ = owner_->getComponent<Transform>();
}

// -----------------------------------------------------------------------------
// Rendering
// -----------------------------------------------------------------------------

// It retrieves texture from the resource manager and renders it.
void EntityRenderer::render() {
    SDL_Texture* texture = ResourceManager::getInstance().getTexture(textureName_);
    if (texture == nullptr) return;
    const SDL_Rect dstRect = {static_cast<int>(transform_->getPosition().x),
                              static_cast<int>(transform_->getPosition().y), 64, 64};

    // Render the texture
    if (SDL_RenderCopy(ServiceLocator::getRenderer(), texture, nullptr, &dstRect) != 0) {
      PANIC("SDL_RenderCopy Error: %s", SDL_GetError());
    }
}
