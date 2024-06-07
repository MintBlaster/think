//
// Created by manish on 04-06-2024.
//

#ifndef ENTITYRENDERER_H
#define ENTITYRENDERER_H

#pragma once

#include "Component.h"
#include "components/Transform.h"
#include <string>

// #############################################################################
//                       EntityRenderer Class Declaration
// #############################################################################

class EntityRenderer : public Component {
public:
  // Constructor
  explicit EntityRenderer();

  // Setter
  void setTexture(const std::string& name) { textureName_ = name; }

private:
  // Member Functions
  void satisfyDependencies() override;
  void render() override;

  // Attributes
  std::string textureName_;
  Transform* transform_;
};

#endif // ENTITYRENDERER_H
