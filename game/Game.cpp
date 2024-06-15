
//
// Created by manish on 07-06-2024.
//

#include "PlayerInput.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "SceneManager.h"
#include "components/TextureRenderer.h"

#include <Rocket.h>

// #############################################################################
//                           Game Loop Implementation
// #############################################################################

//  Variables
// ----------------------------------------
constexpr const char* PLAYER_TEXTURE_KEY  = "Player Rocket Texture";
constexpr const char* ENEMY_TEXTURE_KEY   = "Enemy Rocket Texture";
constexpr const char* PLAYER_TEXTURE_PATH = "gfx/ShipsPNG/ship1.png";
constexpr const char* ENEMY_TEXTURE_PATH  = "gfx/ShipsPNG/ship2.png";

// Function to initialize resources
inline void InitializeResources(ResourceManager& resourceManager)
{
    resourceManager.loadTexture(PLAYER_TEXTURE_KEY, PLAYER_TEXTURE_PATH);
    resourceManager.loadTexture(ENEMY_TEXTURE_KEY, ENEMY_TEXTURE_PATH);
}

// Function to create and configure rockets
inline void CreateRockets(Scene* scene)
{
    // Create Player Rocket
    auto playerRocket = scene->addEntity<Rocket>("Player Rocket");

    playerRocket->addComponent<PlayerInput>();
    if (auto* playerRenderer = playerRocket->getComponent<TextureRenderer>())
    {
        playerRenderer->setTexture(PLAYER_TEXTURE_KEY);
    }
    playerRocket->setFuelAmount(400);
    playerRocket->setEngineThrust(.5);
    // Create Enemy Rocket
    auto enemyRocket = scene->addEntity<Rocket>("Enemy Rocket");

    if (auto* enemyRenderer = enemyRocket->getComponent<TextureRenderer>())
    {
        enemyRenderer->setTexture(ENEMY_TEXTURE_KEY);
    }
    enemyRocket->setFuelAmount(20);
    enemyRocket->setEngineThrust(.3);
}
// Main game initialization function

inline void GameInit()
{
    // Get manager instances
    auto& sceneManager    = SceneManager::getInstance();
    auto& resourceManager = ResourceManager::getInstance();

    // Get the current scene
    Scene* testScene = sceneManager.getCurrentScene();

    // Initialize resources
    InitializeResources(resourceManager);
    // Create and configure rockets
    CreateRockets(testScene);
}
