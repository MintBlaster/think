// Created by manish on 03-06-2024.

// Entity.h
#pragma once

#include "Transform.h"
#include <SDL.h>

class Entity {
public:
  explicit Entity(const Vector2& pos = Vector2(0, 0))
    : transform(pos) {}
  virtual ~Entity() = default;

  virtual void update() = 0;
  virtual void render(SDL_Renderer* sdl_renderer) = 0;

  void setPosition(float posX, float posY) { transform.setPosition(posX, posY); }
  [[nodiscard]] Vector2 getPosition() const { return transform.getPosition(); }

protected:
  Transform transform;
};

