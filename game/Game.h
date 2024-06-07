//
// Created by manish on 07-06-2024.
//

#pragma once
#include <Rocket.h>

// #############################################################################
//                           Game Implementation
// #############################################################################

inline void GameInit() {

  // ---------------------------------------------------------------------------
  //   Game Initialization
  // ---------------------------------------------------------------------------

  // SceneManager
  // ---------------------------------------------------------------------------
  SceneManager & SceneManager = SceneManager::getInstance();


  // Scenes
  // ---------------------------------------------------------------------------
  Scene* testScene = SceneManager.getCurrentScene();
  Scene* anotherTestScene = SceneManager.createScene("TestScene 2");

  // Entities
  // ---------------------------------------------------------------------------

  auto* rocket1 = testScene->addEntity<Rocket>("Rocket 1");

  rocket1->setFuelAmount(5);
  rocket1->setEngineThrust(2);

  auto* rocket2 = testScene->addEntity<Rocket>("Rocket 2");

  rocket2->setFuelAmount(3);
  rocket2->setEngineThrust(1);

}