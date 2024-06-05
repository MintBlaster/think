//
// Created by manish on 04-06-2024.
//

#include "../../include/core/ResourceManager.h"
#include "ServiceLocator.h"

// #############################################################################
//                       ResourceManager Class Implementation
// #############################################################################

// -----------------------------------------------------------------------------
// Singleton Instance
// -----------------------------------------------------------------------------

ResourceManager& ResourceManager::getInstance() {
  static ResourceManager instance;
  return instance;
}

// -----------------------------------------------------------------------------
// Texture Management
// -----------------------------------------------------------------------------

void ResourceManager::loadTexture(const std::string &name, const std::string &path) {
  // Check if the texture is already loaded
  auto it = textures_.find(name);
  if (it != textures_.end()) {
    return;
  }
  // If the texture is not loaded, create a new texture and store it in the map
  auto texture = std::make_unique<Texture>(name, path, ServiceLocator::getWindow());
  textures_.emplace(name, std::move(texture));
}

SDL_Texture *ResourceManager::getTexture(const std::string &name) {
  if (const auto it = textures_.find(name); it != textures_.end()) {
    return it->second->getTexture();
  }
  return nullptr;
}

SDL_Texture *ResourceManager::loadAndGetTexture(const std::string &name, const std::string &path) {
  loadTexture(name, path);
  return getTexture(name);
}

void ResourceManager::unloadTexture(const std::string &name) {
  auto it = textures_.find(name);
  if (it != textures_.end()) {
    SDL_DestroyTexture(it->second->getTexture());
    textures_.erase(it);
  }
}