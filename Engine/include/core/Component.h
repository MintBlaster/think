//
// Created by manish on 04-06-2024.
//

#ifndef COMPONENT_H
#define COMPONENT_H

#pragma once

#include "Entity.h"

#include <string>

class Entity;

// #############################################################################
//                           Component Class Declaration
// #############################################################################

class Component
{
public:
    // Constructor & Destructor
    explicit Component() = default;
    virtual ~Component() = default;

    // Member Functions
    virtual void update() {}
    virtual void render() {}

    // Getters and Setters
    virtual void                      setOwner(Entity* owner);
    virtual bool                      haveOwner() { return owner_ != nullptr; }
    [[nodiscard]] Entity&             getOwner() const { return *owner_; }
    virtual void                      setName(std::string& name) { name_ = name; }
    [[nodiscard]] virtual std::string getName() { return name_; }

    virtual void satisfyDependencies() {}

protected:
    // Attributes
    std::string name_;
    Entity*     owner_ = nullptr;
};

#endif // COMPONENT_H
