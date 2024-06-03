//
// Created by manish on 03-06-2024.
//

#pragma once

#include "../utils/Transform.h"
#include <SDL.h>

class EntityManager; // Forward declaration of EntityManager class

class Entity {
public:
  explicit Entity(const Vector2 &pos = Vector2(0, 0));
  virtual ~Entity();

  virtual void update() {}
  void render(SDL_Renderer *sdl_renderer) const;

  virtual void setPosition(float posX, float posY) { transform_.setPosition(posX, posY); }
  virtual void setPosition(Vector2 newPos) { transform_.setPosition(newPos.x, newPos.y); }
  [[nodiscard]] virtual  Vector2 getPosition() const { return transform_.getPosition(); }

  virtual void setTexture(SDL_Texture* texture) { texture_ = texture; }
  [[nodiscard]] virtual SDL_Texture * getTexture() const { return texture_; }

protected:
  Transform transform_;
  SDL_Texture* texture_;
};
