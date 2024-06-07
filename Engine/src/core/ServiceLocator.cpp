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

/// <summary> It provides the SDL_Renderer to the service locator </summary>
void ServiceLocator::provideRenderer(SDL_Renderer* renderer) {
  rendererService_ = renderer;
}

/// <summary> It returns the SDL_Renderer from the service locator. </summary>
SDL_Renderer* ServiceLocator::getRenderer() {
  return rendererService_;
}

/// <summary> It provides the RenderWindow to the service locator </summary>
void ServiceLocator::provideWindow(RenderWindow* window) {
  windowService_ = window;
}

/// <summary> It returns the RenderWindow from the service locator. </summary>
RenderWindow* ServiceLocator::getWindow() {
  return windowService_;
}
