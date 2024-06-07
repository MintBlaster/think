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
  texture_ = renderWindow_->loadTexture((std::string(RESOURCE_DIR) + path_).c_str());
}
