//
// Created by manish on 03-06-2024.
//

#include "Engine.h"

#include "Game.cpp"
#include "InputSystem.h"
#include "SDL.h"
#include "SceneManager.h"
#include "ServiceLocator.h"
#include "UDebug.h"
#include "UTime.h"

#include <SDL_image.h>

// #############################################################################
//                             Game Class Implementation
// #############################################################################

// -----------------------------------------------------------------------------
// Constructor and Destructors
// -----------------------------------------------------------------------------

Engine::Engine() = default;

Engine::~Engine()
{
    cleanUp();
}

// -----------------------------------------------------------------------------
// Initialization
// -----------------------------------------------------------------------------

bool Engine::init()
{
    // SDL ->
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        PANIC("SDL_Init Error: %s", SDL_GetError());
        return false;
    }
    if (IMG_Init(IMG_INIT_PNG) == 0)
    {
        PANIC("IMG_Init Error: %s", IMG_GetError());
        return false;
    }

    ServiceLocator::provideWindow(&window_);
    window_.init();

    window_.loadShaders("shaders/texture_shader.vert", "shaders/texture_shader.frag");

    isRunning_ = true;
    WHISPER("Game initialization successful");

    GameInit();
    SceneManager::getInstance().getCurrentScene()->init();

    return true;
}

// -----------------------------------------------------------------------------
// Engine Loop
// -----------------------------------------------------------------------------

void Engine::run()
{
    if (!init())
    {
        return;
    }
    float accumulator = 0.0f;
    float currentTime = UTime::getTime();

    while (isRunning_)
    {

        float newTime       = UTime::getTime();
        float frameRateTime = newTime - currentTime;
        currentTime         = newTime;

        accumulator += frameRateTime;
        while (accumulator >= (1 / FIXED_UPDATE_PER_SECONDS))
        {
            physicsUpdate();
            accumulator -= (1 / FIXED_UPDATE_PER_SECONDS);
        }

        processEvents();
        update();
        render();
    }

    // If not running QUIT.
    SDL_Quit();
}

// -----------------------------------------------------------------------------
// Event Processing
// -----------------------------------------------------------------------------

void Engine::processEvents()
{
    InputSystem::getInstance().processEvents();

    // if NOT QUIT -> Game is running.
    isRunning_ = !InputSystem::getInstance().hasQuit();
}

// -----------------------------------------------------------------------------
// Engine State Update
// -----------------------------------------------------------------------------

void Engine::physicsUpdate()
{
    SceneManager::getInstance().getCurrentScene()->physicsUpdateEntities();
}

void Engine::update()
{
    SceneManager::getInstance().getCurrentScene()->updateEntities();
}

// -----------------------------------------------------------------------------
// Rendering
// -----------------------------------------------------------------------------

void Engine::render() const
{
    window_.clear();
    SceneManager::getInstance().getCurrentScene()->renderEntities();
    window_.display();
}

// -----------------------------------------------------------------------------
// Clean Up
// -----------------------------------------------------------------------------

void Engine::cleanUp() const
{
    SDL_Quit();
    IMG_Quit();
}
