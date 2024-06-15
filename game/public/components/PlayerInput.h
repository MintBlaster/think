
#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include "Component.h"
#include "UMath.h"
#include "components/Transform2D.h"
#pragma once

// #############################################################################
//                        PlayerInput Declaration
// #############################################################################

class PlayerInput : public Component
{

public:
    Vector2 getMoveInput();

private:
    virtual void update() override;

    virtual void satisfyDependencies() override;

    Transform2D* transform_ {};
    Vector2      position_ {};
    Vector2      moveInput_ {};
};

#endif
