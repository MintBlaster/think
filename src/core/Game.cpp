//
// Created by manish on 03-06-2024.
//

#include <SDL_image.h>
#include "EntityManager.h"
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
      rocketTexture_(nullptr) {}

Game::~Game() {
  cleanUp();
}

// ----------------------------------------
// Initialization
// ----------------------------------------

bool Game::init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    LOG_ERROR("SDL_Init Error: %s", SDL_GetError());
    return false;
  }

  if (IMG_Init(IMG_INIT_PNG) == 0) {
    LOG_ERROR("IMG_Init Error: %s", IMG_GetError());
    return false;
  }

  SDL_Texture* rocketTexture = window_.loadTexture("../res/gfx/idle_0.png");
  if (!rocketTexture) {
    LOG_ERROR("Failed to load rocket texture.");
    return false;
  }

  rocket1_ = new Rocket(0, 0, .7, 1);
  rocket2_ = new Rocket(0, 0, 1.2, 1.5);

  rocket1_->setTexture(rocketTexture);
  rocket2_->setTexture(rocketTexture);

  isRunning_ = true;
  LOG_TRACE("Game initialization successful");

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

void Game::update() const {
  EntityManager::getInstance().updateEntities();
}



// ----------------------------------------
// Rendering
// ----------------------------------------

void Game::render() const {
  window_.clear();
  window_.render();
  window_.display();
}

// ----------------------------------------
// Cleanup
// ----------------------------------------

void Game::cleanUp() const {
  window_.cleanUp();
  SDL_Quit();
  IMG_Quit();
}
