//
// Created by manish on 04-06-2024.
//

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "RenderWindow.h"
#include "resources/Texture.h"
#include <memory>
#include <unordered_map>

// #############################################################################
//                       ResourceManager Class Declaration
// #############################################################################

class ResourceManager {
public:
  // singleton
  static ResourceManager& getInstance();

  // Deleted Constructors
  ResourceManager(const ResourceManager&) = delete;
  ResourceManager& operator=(const ResourceManager&) = delete;

  // Member Functions
  void loadTexture(const std::string &name, const std::string &path);
  [[nodiscard]] SDL_Texture *getTexture(const std::string &name);
  [[nodiscard]] SDL_Texture *loadAndGetTexture(const std::string &name, const std::string &path);
  void unloadTexture(const std::string &name);

private:
  // constructor
    ResourceManager() = default;
  // Attributes
  std::unordered_map<std::string, std::unique_ptr<Texture>> textures_;
};

#endif // RESOURCEMANAGER_H