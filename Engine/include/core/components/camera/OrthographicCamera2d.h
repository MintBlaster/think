//
// Created by manish on 07-06-2024.
//

#ifndef CAMERA_H
#define CAMERA_H

#pragma once

#include <Component.h>
#include <SDL.h>
#include <UMath.h>

// #############################################################################
//                 Orthographic Camera2D Declaration
// #############################################################################

class OrthographicCamera2D : public Component {
public:
  // Constructor
  OrthographicCamera2D(float screenWidth, float screenHeight);

  // Getters
  Matrix4 getViewMatrix() const;
  SDL_Rect getViewRect() const;

  // Setters
  void setPosition(const Vector2& newPosition);
  void setZoom(float newZoom);

  // Member Functions
  void move(const Vector2& delta);
  void update(const SDL_Rect& target);

private:
  // Attributes
  float zoom;
  Vector2 dimensions;
  Vector2 position;
};

#endif // CAMERA_H
