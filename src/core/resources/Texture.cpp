//
// Created by manish on 04-06-2024.
//

#include "../../../include/core/resources/Texture.h"
#include "RenderWindow.h"

Texture::Texture(const std::string &name, const std::string &path,RenderWindow &renderWindow): Resource(name, path), texture_(nullptr), renderWindow_(renderWindow) {
  loadTexture();
}
void Texture::setPath(const std::string &path) {
  Resource::setPath(path);
  loadTexture();
}
void Texture::loadTexture() {
  texture_ = renderWindow_.loadTexture(path_.c_str());
}

