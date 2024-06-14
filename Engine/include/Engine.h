//
// Created by manish on 03-06-2024.
//

#ifndef GAME_H
#define GAME_H

#pragma once

#include "core/RenderWindow.h"

class EntityManager;
class ResourceManager;
class Component;

// #############################################################################
//                           Game Class Declaration
// #############################################################################

class Engine
{
public:
    // Constructor & Destructor
    Engine();
    ~Engine();

    // Member Functions
    void run();

private:
    // Helper Functions
    void physicsUpdate();
    void processEvents();
    void update();
    void render() const;
    bool init();
    void cleanUp() const;

    // constants
    const float FIXED_UPDATE_PER_SECONDS = 30.0f;

    // Attributes
    bool         isRunning_ {};
    RenderWindow window_ {"Think", 1280, 720};
};

#endif // GAME_H
