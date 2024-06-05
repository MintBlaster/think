//
// Created by manish on 04-06-2024.
//

#include "../../../include/core/resources/Texture.h"
#include "RenderWindow.h"

// #############################################################################
//                             Texture Class Implementation
// #############################################################################

// -----------------------------------------------------------------------------
// Constructor
// -----------------------------------------------------------------------------

Texture::Texture(const std::string &name, const std::string &path, RenderWindow *renderWindow)
    : Resource(name, path), texture_(nullptr), renderWindow_(renderWindow) {
  loadTexture();
}

// -----------------------------------------------------------------------------
// Set Path
// -----------------------------------------------------------------------------

void Texture::setPath(const std::string &path) {
  Resource::setPath(path);
  loadTexture();
}

// -----------------------------------------------------------------------------
// Load Texture
// -----------------------------------------------------------------------------

void Texture::loadTexture() {
  texture_ = renderWindow_->loadTexture((BASE_TEXTURE_DIR + path_).c_str());
}
