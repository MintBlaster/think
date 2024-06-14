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

ResourceManager& ResourceManager::getInstance()
{
    static ResourceManager instance;
    return instance;
}

// -----------------------------------------------------------------------------
// Texture Management
// -----------------------------------------------------------------------------

/// <summary> It loads the texture from the given path into resource manager. </summary>
void ResourceManager::loadTexture(const std::string& name, const std::string& path)
{
    // Check if the texture is already loaded
    auto it = textures_.find(name);
    if (it != textures_.end())
    {
        return;
    }
    // If the texture is not loaded, create a new texture and store it in the map
    auto texture = std::make_unique<Texture>(name, path, ServiceLocator::getWindow());
    textures_.emplace(name, std::move(texture));
}

/// <summary> It returs the texture using texture's name from resource manager. </summary>
GLuint ResourceManager::getTexture(const std::string& name)
{
    if (const auto it = textures_.find(name); it != textures_.end())
    {
        return it->second->getTexture();
    }
    return NULL;
}

/// <summary> It will load and returs the texture from resource manager. </summary>
GLuint ResourceManager::loadAndGetTexture(const std::string& name, const std::string& path)
{
    loadTexture(name, path);
    return getTexture(name);
}

/// <summary> It will destroy the texture. </summary>
/// <summary> It will destroy the texture. </summary>
void ResourceManager::unloadTexture(const std::string& name)
{
    auto it = textures_.find(name);
    if (it != textures_.end())
    {
        if (GLuint textureID = it->second->getTexture())
        {
            glDeleteTextures(1, &textureID);
        }
        textures_.erase(it);
    }
}
