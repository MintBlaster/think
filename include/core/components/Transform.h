//
// Created by manish on 04-06-2024.
//

#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H
#include "Component.h"
#include "UMath.h"

// #############################################################################
//                       Transform Componenet Implementation
// #############################################################################

class Transform : public Component {
public:
  explicit Transform() = default;

  // Getters and Setters
  void setPosition(float posX, float posY) { position_ = {posX, posY}; }
  [[nodiscard]] Vector2 getPosition() const { return position_; }

private:
  // Position vector
  Vector2 position_ = Vector2(0, 0);
};


#endif //TRANSFORMCOMPONENT_H
