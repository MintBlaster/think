//
// Created by manish on 04-06-2024.
//

#ifndef TEXTURE_H
#define TEXTURE_H

#include "RenderWindow.h"
#include "Resource.h"

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
  [[nodiscard]] GLuint getTexture() const { return textureID_; }

private:
  // Helper Function
  void loadTexture();

protected:
  // Attributes
  int width_ = 64, height_ = 64, nrChannels_ = 1;
  GLuint textureID_{};
  RenderWindow* renderWindow_;
public:
 };

#endif //TEXTURE_H
