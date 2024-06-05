//
// Created by manish on 04-06-2024.
//

#ifndef TEXTURE_H
#define TEXTURE_H

#include "RenderWindow.h"
#include "Resource.h"
#include <SDL_render.h>

// #############################################################################
//                           Texture Class Declaration
// #############################################################################

class Texture : public Resource {
public:
  // Constructor
  Texture(const std::string &name, const std::string &path, RenderWindow* renderWindow);

  // Override Member Function
  void setPath(const std::string& path) override;

  // Getter
  [[nodiscard]] SDL_Texture* getTexture() const { return texture_; }

private:
  // Helper Function
  void loadTexture();

protected:
  // Attributes
  SDL_Texture* texture_;
  RenderWindow* renderWindow_;

private:
  std::string BASE_TEXTURE_DIR = "../res/";
 };

#endif //TEXTURE_H
