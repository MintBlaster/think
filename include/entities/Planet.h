//
// Created by manish on 03-06-2024.
//

#ifndef PLANET_H
#define PLANET_H

#include <SDL.h>

// #############################################################################
//                           Planet Class Declaration
// #############################################################################

class Planet {
public:
  Planet(float posX, float posY, float gravityForce);
  void render(SDL_Renderer* renderer) const;

private:
  float posX_;
  float posY_;
  float gravityForce_;
  SDL_Texture* texture_;
};

#endif // PLANET_H
