//
// Created by manish on 03-06-2024.
//

#include "../include/Game.h"
#include <SDL_image.h>
#include "../include/core/EntityManager.h"
#include "../include/utils/think-lib.h"
#include "ResourceManager.h"
#include "ServiceLocator.h"

// #############################################################################
//                           Game Class Implementation
// #############################################################################

// ----------------------------------------
// Constructor & Destructor
// ----------------------------------------

Game::Game() :
    isRunning_(false), event_(), window_("Think", 1280, 720) {}

Game::~Game() { cleanUp(); }

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
    ServiceLocator::provideWindow(&window_);

    ResourceManager::getInstance().loadTexture("Rocket Texture", "../res/gfx/idle_0.png");

    rocket1 = std::make_unique<Rocket>();
    rocket2 = std::make_unique<Rocket>();

    rocket1->setName("Rocket 1");
    rocket2->setName("Rocket 2");

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

void Game::update() { EntityManager::getInstance().updateEntities(); }

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
