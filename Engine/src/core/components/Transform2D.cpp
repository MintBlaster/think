#include "components/Transform2D.h"

// #############################################################################
//                          Transform 2D Implementation
// #############################################################################

void Transform2D::setPosition(float posX, float posY)
{
    position_ = {posX, posY};
}

void Transform2D::setPosition(Vector2 position)
{
    position_ = position;
}

Vector2 Transform2D::getPosition() const
{
    return position_;
}
