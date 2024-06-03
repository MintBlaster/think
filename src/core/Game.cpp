//
// Created by manish on 03-06-2024.
//

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
      imageTexture_(nullptr), rocket_(nullptr) {}

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

  imageTexture_ = window_.loadTexture("../res/gfx/idle_0.png");
  if (!imageTexture_) {
    LOG_ERROR("Failed to load imageTexture_");
    return false;
  }

  SDL_Texture* rocketTexture = window_.loadTexture("../res/gfx/idle_0.png");
  if (!rocketTexture) {
    LOG_ERROR("Failed to load rocket texture.");
    return false;
  }

  rocket_ = new Rocket(0, 0, 100, 5); // Reduced thrust value
  rocket_->setTexture(rocketTexture);

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
    if (event_.type == SDL_KEYDOWN) {
      switch (event_.key.keysym.sym) {
      case SDLK_UP:
        rocket_->applyThrust(Vector2(0, -1)); // Thrust up
        break;
      case SDLK_DOWN:
        rocket_->applyThrust(Vector2(0, 1)); // Thrust down
        break;
      case SDLK_LEFT:
        rocket_->applyThrust(Vector2(-1, 0)); // Thrust left
        break;
      case SDLK_RIGHT:
        rocket_->applyThrust(Vector2(1, 0)); // Thrust right
        break;
      default:
        break;
      }
    }
  }
}

// ----------------------------------------
// Game State Update
// ----------------------------------------

void Game::update() const {
  rocket_->update(); // Update the rocket
}


// ----------------------------------------
// Rendering
// ----------------------------------------

void Game::render() const {
  window_.clear();
  window_.render(imageTexture_);
  rocket_->render(window_.getRenderer()); // Render the rocket
  window_.display();
}

// ----------------------------------------
// Cleanup
// ----------------------------------------

void Game::cleanUp() const {
  SDL_DestroyTexture(imageTexture_);
  SDL_DestroyTexture(rocket_->getTexture());
  delete rocket_;
  window_.cleanUp();
  SDL_Quit();
  IMG_Quit();
}
