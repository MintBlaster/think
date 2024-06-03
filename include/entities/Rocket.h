//
// Created by manish on 03-06-2024.
//

#ifndef ROCKET_H
#define ROCKET_H

#include "Entity.h"
#include <SDL.h>

class Rocket : public Entity {
public:
  Rocket(float posX, float posY, float fuelAmount, float engineThrust);
  void update() override;
  void render(SDL_Renderer* renderer) override;

  void setTexture(SDL_Texture* texture) { texture_ = texture; }
  [[nodiscard]] SDL_Texture* getTexture() const { return texture_; }

  void applyThrust(const Vector2& direction);

private:
  float velocityX_;
  float velocityY_;
  float fuelAmount_;
  float engineThrust_;
  Vector2 position_;
  SDL_Texture* texture_;
};

#endif // ROCKET_H


