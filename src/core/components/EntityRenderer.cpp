//
// Created by manish on 04-06-2024.
//

#include "components/EntityRenderer.h"
#include "ResourceManager.h"
#include "ServiceLocator.h"
#include "think-lib.h"

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

void EntityRenderer::satisfyDependencies() {
  if (owner_->getComponent<Transform>() == nullptr) {
    owner_->addComponent(std::make_unique<Transform>());
  }
  transform_ = owner_->getComponent<Transform>();
}

// -----------------------------------------------------------------------------
// Rendering
// -----------------------------------------------------------------------------

void EntityRenderer::render() {
    SDL_Texture* texture = ResourceManager::getInstance().getTexture(textureName_);
    if (texture == nullptr) return;
    const SDL_Rect dstRect = {static_cast<int>(transform_->getPosition().x),
                              static_cast<int>(transform_->getPosition().y), 64, 64};

    // Render the texture
    if (SDL_RenderCopy(ServiceLocator::getRenderer(), texture, nullptr, &dstRect) != 0) {
      LOG_ERROR("SDL_RenderCopy Error: %s", SDL_GetError());
    } else {
      LOG_TRACE("Texture %s rendered at : %s", textureName_.c_str(), transform_->getPosition().toString().c_str());
    }
}
