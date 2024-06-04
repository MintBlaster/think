// Created by manish on 04-06-2024.

#include "components/EntityRenderer.h"

#include "ResourceManager.h"
#include "ServiceLocator.h"
#include "think-lib.h"

// #############################################################################
//                       EntityRenderer Class Implementation
// #############################################################################

EntityRenderer::EntityRenderer() {
  if (owner_->getComponent<Transform>()) {
    owner_->addComponent(Transform::createInstance());
  }
  transform_ = owner_->getComponent<Transform>();
}

void EntityRenderer::render() const {

    SDL_Texture* texture = ResourceManager::getInstance().getTexture(textureName_);
    // Destination rectangle for rendering
    const SDL_Rect dstRect = {static_cast<int>(transform_->getPosition().x),
                              static_cast<int>(transform_->getPosition().y), 64, 64};

    // Render the texture
    if (SDL_RenderCopy(ServiceLocator::getRenderer(), texture, nullptr, &dstRect) != 0) {
      LOG_ERROR("SDL_RenderCopy Error: %s", SDL_GetError());
    }
}