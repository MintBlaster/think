//
// Created by manish on 12-06-2024
//

#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "UMath.h"

#pragma once

#include "SDL_events.h"

#include <string>

// #############################################################################
//                             Input System Declaration
// #############################################################################

class InputSystem
{
public:
    // Singleton Instance
    static InputSystem& getInstance();

    // Member functions
    void processEvents();

    // keyboard
    [[nodiscard]] float keyDown(std::string keyName);
    [[nodiscard]] float keyUp(std::string keyName);

    [[nodiscard]] bool keyPressed(std::string keyName);
    [[nodiscard]] bool keyReleased(std::string keyName);

    // Mouse
    [[nodiscard]] Vector2 getMousePos();

    // helper
    [[nodiscard]] bool hasQuit();

private:
    // constructors and destructors
    InputSystem();
    ~InputSystem() = default;
    SDL_Event event_;

    // -> becuase there are 282 scanCode keys in SDL2.
    std::array<bool, 282> keyPressedLastFrame;
};

#endif // !INPUTSYSTEM_H
