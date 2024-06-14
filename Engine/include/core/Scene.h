//
// Created by manish on 03-06-2024.
//

#ifndef SCENE_H
#define SCENE_H

#pragma once

#include "Entity.h"

#include <memory>
#include <string>
#include <vector>

// #############################################################################
//                     Scene Class Declaration
// #############################################################################

class Scene
{
public:
    explicit Scene(std::string name);
    ~        Scene() = default;

    // Member Functions
    void    removeEntity(std::string& name);
    Entity* getEntityByName(std::string& name);
    void    init();
    void    physicsUpdateEntities();
    void    updateEntities();
    void    renderEntities();

    // Template Functions
    template <typename T>
    T* addEntity(std::string name);

private:
    // Attributes
    std::string                                                  name_;
    std::vector<std::pair<std::string, std::unique_ptr<Entity>>> entities_;
};

// #############################################################################
//                               Template Implementations
// #############################################################################

// Implementation of addEntity method
template <typename T>
T* Scene::addEntity(std::string name)
{
    // Ensure T is derived from Entity
    static_assert(std::is_base_of_v<Entity, T>, "T must be derived from Component");
    // Create a new Entity
    std::unique_ptr<T> entity       = std::make_unique<T>(name);
    T*                 castedEntity = entity.get();

    // Make pair of entity and its name and add it to vector.
    entities_.push_back(std::make_pair(name, std::move(entity)));

    return castedEntity;
}

#endif // SCENE_H
