//
// Created by manish on 04-06-2024.
//

#include "../../../include/core/resources/Texture.h"
#include "RenderWindow.h"

#include <UDebug.h>
#include <ext/matrix_clip_space.hpp>
#include <ext/matrix_transform.hpp>
#include <gtc/type_ptr.inl>
#include <stb_image.h>

// #############################################################################
//                             Texture Class Implementation
// #############################################################################

// -----------------------------------------------------------------------------
// Constructor
// -----------------------------------------------------------------------------

Texture::Texture(const std::string &name, const std::string &path, RenderWindow *renderWindow)
    : Resource(name, path), renderWindow_(renderWindow) {
  loadTexture();
}

// -----------------------------------------------------------------------------
// Set Path
// -----------------------------------------------------------------------------

/// <summary> Sets path for the texture </summary>
void Texture::setPath(const std::string &path) {
  Resource::setPath(path);
  loadTexture();
}

// -----------------------------------------------------------------------------
// Load Texture
// -----------------------------------------------------------------------------

/// <summary> It loads the texture. </summary>
void Texture::loadTexture() {
  stbi_set_flip_vertically_on_load(1);
  std::string newPath = "C:/Projects/cpp/think/res/" + path_;
  unsigned char *data = stbi_load(newPath.c_str(), &width_, &height_, &nrChannels_, 4);
  if (!data) {
    PANIC("Failed to load texture: %s", newPath.c_str());
  } else {
    WHISPER("Loaded texture: %s width: %i, height: %i, channels: %i", newPath, width_, height_, nrChannels_);
  }

  glGenTextures(1, &textureID_);
  glBindTexture(GL_TEXTURE_2D, textureID_);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  GLenum format = GL_RGBA;
  glTexImage2D(GL_TEXTURE_2D, 0, format, width_, height_, 0, format, GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glBindTexture(GL_TEXTURE_2D, 0);
  stbi_image_free(data);
}