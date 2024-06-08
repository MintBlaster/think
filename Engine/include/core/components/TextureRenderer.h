//
// Created by manish on 04-06-2024.
//

#ifndef ENTITYRENDERER_H
#define ENTITYRENDERER_H

#pragma once

#include "Component.h"
#include "Transform2D.h"
#include <string>

// #############################################################################
//                       EntityRenderer Class Declaration
// #############################################################################

class TextureRenderer : public Component {
public:
  // Constructor
  explicit TextureRenderer();

  // Setter
  void setTexture(const std::string& name) {textureName_ = name;}

private:
  // Member Functions
  void satisfyDependencies() override;
  void render() override;

  // Attributes
  std::string textureName_;
  Transform2D* transform2d_;

public:
	float width;
    float height;
};

#endif // ENTITYRENDERER_H
