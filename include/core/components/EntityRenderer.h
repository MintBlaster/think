//
// Created by manish on 04-06-2024.
//

#ifndef ENTITYRENDERER_H
#define ENTITYRENDERER_H

#include "Component.h"
#include "Transform.h"

// #############################################################################
//                    Entity Renderer Implementation
// #############################################################################

class EntityRenderer : public Component {

public:
  explicit EntityRenderer();

  void setTexture(const std::string& name) {textureName_ = name;}

private:
  void render() const;

private:
  std::string textureName_;
  Transform* transform_;
};

#endif //ENTITYRENDERER_H
