//
// Created by manish on 03-06-2024.
//

#include <SDL_image.h>
#include "Engine.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "ServiceLocator.h"
#include "UDebug.h"
#include "UTime.h"
#include "Game.h"

// #############################################################################
//                             Game Class Implementation
// #############################################################################

// -----------------------------------------------------------------------------
// Constructor and Destructors
// -----------------------------------------------------------------------------

Engine::Engine() : isRunning_(false), event_(), window_("Think", 1280, 720) {}

Engine::~Engine() { cleanUp(); }

// -----------------------------------------------------------------------------
// Initialization
// -----------------------------------------------------------------------------

bool Engine::init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    PANIC("SDL_Init Error: %s", SDL_GetError());
    return false;
  }
  if (IMG_Init(IMG_INIT_PNG) == 0) {
    PANIC("IMG_Init Error: %s", IMG_GetError());
    return false;
  }

  ServiceLocator::provideWindow(&window_);

  isRunning_ = true;
  WHISPER("Game initialization successful");

  SceneManager::getInstance().getCurrentScene()->init();

  // --- >
  GameInit();
  return true;
}

// -----------------------------------------------------------------------------
// Engine Loop
// -----------------------------------------------------------------------------

void Engine::run() {
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

void Engine::processEvents() {
  while (SDL_PollEvent(&event_)) {
    if (event_.type == SDL_QUIT) {
      isRunning_ = false;
    }
  }
}

// -----------------------------------------------------------------------------
// Engine State Update
// -----------------------------------------------------------------------------

void Engine::physicsUpdate() {
  SceneManager::getInstance().getCurrentScene()->physicsUpdateEntities();
}


void Engine::update() {
  SceneManager::getInstance().getCurrentScene()->updateEntities();
}

// -----------------------------------------------------------------------------
// Rendering
// -----------------------------------------------------------------------------

void Engine::render() const {
  window_.clear();
  SceneManager::getInstance().getCurrentScene()->renderEntities();
  window_.display();
}

// -----------------------------------------------------------------------------
// Clean Up
// -----------------------------------------------------------------------------

void Engine::cleanUp() const {
  window_.cleanUp();
  SDL_Quit();
  IMG_Quit();
}