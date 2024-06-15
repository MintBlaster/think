//
// Created by manish on 04-06-2024.
//

#ifndef ENTITYRENDERER_H
#define ENTITYRENDERER_H

#include "sol.hpp"
#pragma once

#include "Component.h"
#include "Transform2D.h"

#include <string>

// #############################################################################
//                       EntityRenderer Class Declaration
// #############################################################################

class TextureRenderer : public Component
{
public:
    // Constructor
    explicit TextureRenderer();

    // Setter
    void setTexture(const std::string& name) { textureName_ = name; }

private:
    // Member Functions
    void init() override;
    void render() override;

    // Attributes
    std::string  textureName_;
    Transform2D* transform2d_ = nullptr;

public:
    float width = 64;
    float height = 64;
};

#endif // ENTITYRENDERER_H
