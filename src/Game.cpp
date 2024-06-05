//
// Created by manish on 03-06-2024.
//

#include "Game.h"
#include <SDL_image.h>
#include <chrono>
#include "EntityManager.h"
#include "ResourceManager.h"
#include "ServiceLocator.h"
#include "components/Transform.h"
#include "think-lib.h"

#include "UTime.h"

// #############################################################################
//                             Game Class Implementation
// #############################################################################

// -----------------------------------------------------------------------------
// Constructor and Destructors
// -----------------------------------------------------------------------------

Game::Game() : isRunning_(false), event_(), window_("Think", 1280, 720), rocket1(nullptr), rocket2(nullptr) {}

Game::~Game() { cleanUp(); }

// -----------------------------------------------------------------------------
// Initialization
// -----------------------------------------------------------------------------

bool Game::init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    LOG_ERROR("SDL_Init Error: %s", SDL_GetError());
    return false;
  }
  if (IMG_Init(IMG_INIT_PNG) == 0) {
    LOG_ERROR("IMG_Init Error: %s", IMG_GetError());
    return false;
  }

  ServiceLocator::provideWindow(&window_);

  rocket1 = std::make_unique<Rocket>();
  rocket2 = std::make_unique<Rocket>();

  rocket1->setFuelAmount(.5);
  rocket1->setEngineThrust(.5);

  rocket2->setFuelAmount(.0002);
  rocket2->setEngineThrust(.00978);

  isRunning_ = true;
  LOG_TRACE("Game initialization successful");

  return true;
}

// -----------------------------------------------------------------------------
// Game Loop
// -----------------------------------------------------------------------------

void Game::run() {
  if (!init()) {
    return;
  }
  float accumulator = 0.0f;
  float currentTime = UTime::getTime();

  while (isRunning_) {

    float newTime = UTime::getTime();
    float frameRateTime = newTime - currentTime;
    currentTime = newTime;

    accumulator += frameRateTime;
    while (accumulator >= (1 / FIXED_UPDATE_PER_SECONDS)) {
      physicsUpdate();
      accumulator -= (1 / FIXED_UPDATE_PER_SECONDS);
    }

    processEvents();
    update();
    render();
  }
}

// -----------------------------------------------------------------------------
// Event Processing
// -----------------------------------------------------------------------------

void Game::processEvents() {
  while (SDL_PollEvent(&event_)) {
    if (event_.type == SDL_QUIT) {
      isRunning_ = false;
    }
  }
}

// -----------------------------------------------------------------------------
// Game State Update
// -----------------------------------------------------------------------------

void Game::physicsUpdate() {
  EntityManager::getInstance().physicsUpdateEntities();
}


void Game::update() {
  EntityManager::getInstance().updateEntities();
}

// -----------------------------------------------------------------------------
// Rendering
// -----------------------------------------------------------------------------

void Game::render() const {
  window_.clear();
  EntityManager::getInstance().renderEntities();
  window_.display();
}

// -----------------------------------------------------------------------------
// Clean Up
// -----------------------------------------------------------------------------

void Game::cleanUp() const {
  window_.cleanUp();
  SDL_Quit();
  IMG_Quit();
}