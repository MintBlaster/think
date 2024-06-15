
#include "PlayerInput.h"

#include "InputSystem.h"

// #############################################################################
//                          Player Input Implementation
// #############################################################################

void PlayerInput::init()
{
    transform_ = owner_->getOrAddComponent<Transform2D>();
}

void PlayerInput::update()
{
    moveInput_ = InputSystem::getInstance().getAxis2D("W", "A", "S", "D");
}

Vector2 PlayerInput::getMoveInput()
{
    return moveInput_;
}
