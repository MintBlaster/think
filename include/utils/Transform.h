//
// Created by manish on 03-06-2024.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "UMath.h"

// #############################################################################
//                           Transform Class Declaration
// #############################################################################

class Transform {
public:
  // Constructor with default position
  explicit Transform(const Vector2& pos = Vector2(0, 0))
    : position_(pos) {}

  // Set position function
  void setPosition(float posX, float posY) { position_ = {posX, posY}; }

  // Get position function
  [[nodiscard]] Vector2 getPosition() const { return position_; }

private:
  // Position vector
  Vector2 position_;
};

#endif // TRANSFORM_H
