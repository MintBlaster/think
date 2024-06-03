// Created by manish on 03-06-2024.

#pragma once

#include "Math.h"
#include <SDL.h>

class Entity {
public:
  explicit Entity(const float x = 0, const float y = 0) : position(x, y) {}
  virtual ~Entity() = default;

  virtual void update() = 0;
  virtual void render(SDL_Renderer* sdl_renderer) = 0;

  void setPosition(float x, float y) { position = {x, y}; }
  [[nodiscard]] Vector2 getPosition() const { return position; }

protected:
  Vector2 position;
};
