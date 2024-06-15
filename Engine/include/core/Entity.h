//
// Created by manish on 03-06-2024.
//

#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include "Component.h"

#include <memory>
#include <string>
#include <vector>

class Component;

// #############################################################################
//                               Entity Class Declaration
// #############################################################################

class Entity
{
public:
    // Constructor & Destructor
    explicit Entity(std::string name);
    virtual ~Entity();

    // Member Functions
    virtual void init() {};
    virtual void physicsUpdate() {}
    virtual void update() { updateComponents(); }
    virtual void render() { renderComponents(); }

    // Name
    virtual void        setName(const std::string& name) { name_ = name; }
    virtual std::string getName() { return name_; }

    // Components
    virtual void removeComponent(Component* component);
    void         satisfyDependencies();
    void         updateComponents();
    void         renderComponents();

    template <typename T>
    T* addComponent();
    template <typename T>
    T* getComponent();
    template <typename T>
    T* getOrAddComponent();

protected:
    // Attributes
    std::string                             name_;
    std::vector<std::unique_ptr<Component>> components_;
};

// #############################################################################
//                               Templates Implementation
// #############################################################################

// Implementation of getComponent method
template <typename T>
T* Entity::getComponent()
{
    for (const auto& component : components_)
    {
        if (T* castedComponent = dynamic_cast<T*>(component.get()))
        {
            return castedComponent;
        }
    }
    return nullptr;
}

// Implementation of addComponent method
template <typename T>
T* Entity::addComponent()
{
    // Ensure T is derived from Component
    static_assert(std::is_base_of<Component, T>::value, "T must be derived from Component");

    // Create a new component and add it to the vector
    std::unique_ptr<T> component       = std::make_unique<T>();
    T*                 castedComponent = component.get();
    castedComponent->setOwner(this);             // Set the owner of the component
    components_.push_back(std::move(component)); // Add the component to the vector

    return castedComponent;
}

template <typename T>
T* Entity::getOrAddComponent()
{

    T* component = getComponent<T>();
    if (component == nullptr)
    {
        component = addComponent<T>();
    }
    return component;
}

#endif // ENTITY_H
