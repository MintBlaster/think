//
// Created by manish on 03-06-2024.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H

// Transform.h
#pragma once

#include "UMath.h"

class Transform {
public:
  explicit Transform(const Vector2& pos = Vector2(0, 0))
    : position_(pos) {}

  void setPosition(float posX, float posY) { position_ = {posX, posY}; }
  [[nodiscard]] Vector2 getPosition() const { return position_; }

private:
  Vector2 position_;
};


#endif //TRANSFORM_H
