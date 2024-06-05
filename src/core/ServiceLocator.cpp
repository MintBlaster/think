//
// Created by manish on 05-06-2024.
//

#include "ServiceLocator.h"

// #############################################################################
//                       ServiceLocator Class Implementation
// #############################################################################

// -----------------------------------------------------------------------------
// Static Attributes Initialization
// -----------------------------------------------------------------------------

SDL_Renderer* ServiceLocator::rendererService_ = nullptr;
RenderWindow* ServiceLocator::windowService_ = nullptr;

// -----------------------------------------------------------------------------
// Static Member Functions
// -----------------------------------------------------------------------------

void ServiceLocator::provideRenderer(SDL_Renderer* renderer) {
  rendererService_ = renderer;
}

SDL_Renderer* ServiceLocator::getRenderer() {
  return rendererService_;
}

void ServiceLocator::provideWindow(RenderWindow* window) {
  windowService_ = window;
}

RenderWindow* ServiceLocator::getWindow() {
  return windowService_;
}
