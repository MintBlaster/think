//
// Created by manish on 04-06-2024.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H

#pragma once

#include "Component.h"
#include "UMath.h"

// #############################################################################
//                        Transform Class Declaration
// #############################################################################

class Transform2D : public Component
{
public:
    // Constructor
    explicit Transform2D() = default;

    // Getters and Setters
    void                  setPosition(float posX, float posY) { position_ = {posX, posY}; }
    void                  setPosition(Vector2 position) { position_ = position; }
    [[nodiscard]] Vector2 getPosition() const { return position_; }

    std::string getName() override { return "Transform"; }

private:
    // Attributes
    Vector2 position_ = Vector2(0, 0);
};

#endif // TRANSFORM_H
