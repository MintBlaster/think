//
// Created by manish on 03-06-2024.
//

#include <iostream>
#include <SDL_image.h>
#include "Game.h"
#include "think-lib.h"
// #############################################################################
//                           Game Class Implementation
// #############################################################################

// ----------------------------------------
// Constructor & Destructor
// ----------------------------------------

Game::Game()
    : isRunning_(false), event_(), window_("Think", 1280, 720),
      imageTexture_(nullptr) {}

Game::~Game() {
  cleanUp();
}

// ----------------------------------------
// Initialization
// ----------------------------------------

bool Game::init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    ASSERT(false, SDL_GetError());
    return false;
  }

  if (IMG_Init(IMG_INIT_PNG) == 0) {
    ASSERT(false, IMG_GetError());
    return false;
  }

  imageTexture_ = window_.loadTexture("../res/gfx/idle_0.png");

  isRunning_ = true;
  return true;
}

// ----------------------------------------
// Game Loop
// ----------------------------------------

void Game::run() {
  if (!init()) {
    return;
  }

  while (isRunning_) {
    processEvents();
    update();
    render();
  }
}

// ----------------------------------------
// Event Processing
// ----------------------------------------

void Game::processEvents() {
  while (SDL_PollEvent(&event_)) {
    if (event_.type == SDL_QUIT) {
      isRunning_ = false;
    }
  }
}

// ----------------------------------------
// Game State Update
// ----------------------------------------

void Game::update() {
  // Update game state here
}

// ----------------------------------------
// Rendering
// ----------------------------------------

void Game::render() const {
  window_.clear();
  window_.render(imageTexture_);
  window_.display();
}

// ----------------------------------------
// CleanupWW
// ----------------------------------------

void Game::cleanUp() const {
  SDL_DestroyTexture(imageTexture_);
  window_.cleanUp();
  SDL_Quit();
  IMG_Quit();
}
