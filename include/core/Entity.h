//
// Created by manish on 03-06-2024.
//

#pragma once

#include "../utils/Transform.h"
#include <SDL.h>

class EntityManager; // Forward declaration of EntityManager class

// #############################################################################
//                           Entity Class Declaration
// #############################################################################

class Entity {
public:
  // Constructor & Destructor
  explicit Entity(const Vector2 &pos = Vector2(0, 0));
  virtual ~Entity();

  // Member Functions
  virtual void update() {}
  void render(SDL_Renderer *sdl_renderer) const;

  // Position
  virtual void setPosition(float posX, float posY) { transform_.setPosition(posX, posY); }
  virtual void setPosition(Vector2 newPos) { transform_.setPosition(newPos.x, newPos.y); }
  [[nodiscard]] virtual Vector2 getPosition() const { return transform_.getPosition(); }

  // Texture
  virtual void setTexture(SDL_Texture* texture) { texture_ = texture; }
  [[nodiscard]] virtual SDL_Texture * getTexture() const { return texture_; }

protected:
  // Attributes
  Transform transform_;
  SDL_Texture* texture_;
};
