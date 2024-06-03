//
// Created by manish on 03-06-2024.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H

// Transform.h
#pragma once

#include "Math.h"

class Transform {
public:
  explicit Transform(const Vector2& pos = Vector2(0, 0))
    : position(pos) {}

  void setPosition(float posX, float posY) { position = {posX, posY}; }
  [[nodiscard]] Vector2 getPosition() const { return position; }

private:
  Vector2 position;
};


#endif //TRANSFORM_H
