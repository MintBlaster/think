// Created by manish on 05-06-2024.

#include "../../include/core/SceneManager.h"

#include "UDebug.h"

#include <algorithm>
#include <sol.hpp>

// #############################################################################
//                         Scene Manager Implementation
// #############################################################################

// ----------------------------------------
//  Constructor
// ----------------------------------------

// Constructor will create a default test scene.
SceneManager::SceneManager() : currentScene_(nullptr)
{
    createScene("Test");
    currentScene_ = scenes_.front().second.get();
}

/// <summary> Singleton instance getter for scene manager. </summary>
SceneManager& SceneManager::getInstance()
{
    static SceneManager instance;
    return instance;
}

// -----------------------------------------------------------------------------
//  Scenes
// -----------------------------------------------------------------------------

/// <summary> Creates a new scene with the given name. </summary>
Scene* SceneManager::createScene(const std::string& name)
{
    auto newScene = std::make_unique<Scene>(name);
    scenes_.emplace_back(name, std::move(newScene));
    return getScene(name);
}

/// <summary> Removes the specified scene from the SceneManager by name. </summary>
void SceneManager::removeScene(const std::string& name)
{
    auto it = std::remove_if(
        scenes_.begin(),
        scenes_.end(),
        [&name](const std::pair<std::string, std::unique_ptr<Scene>>& pair) { return pair.first == name; });
    if (it != scenes_.end())
    {
        if (currentScene_ == it->second.get())
        {
            currentScene_ = nullptr; // Reset currentScene_ if it was the one being removed
        }
        scenes_.erase(it, scenes_.end());
    }
}

/// <summary> Sets the current scene by name. </summary>
void SceneManager::setCurrentScene(const std::string& name)
{
    auto it = std::find_if(
        scenes_.begin(),
        scenes_.end(),
        [&name](const std::pair<std::string, std::unique_ptr<Scene>>& pair) { return pair.first == name; });
    if (it != scenes_.end())
    {
        currentScene_ = it->second.get();
    }
    else
    {
        CHECK(false, "Scene does not exist in the SceneManager.");
    }
}

/// <summary> Returns a pointer to the current scene. </summary>
Scene* SceneManager::getCurrentScene() const
{
    if (currentScene_ == nullptr)
        PANIC("No available current scene");
    return currentScene_;
}

/// <summary> Returns a pointer to the scene with the specified name. </summary>
Scene* SceneManager::getScene(const std::string& name) const
{
    auto it = std::find_if(
        scenes_.begin(),
        scenes_.end(),
        [&name](const std::pair<std::string, std::unique_ptr<Scene>>& pair) { return pair.first == name; });
    if (it != scenes_.end())
    {
        return it->second.get();
    }
    return nullptr;
}

