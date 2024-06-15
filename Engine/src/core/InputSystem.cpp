//
// Created by manish on 12-06-2024
//

#include "InputSystem.h"

#include "SDL_events.h"
#include "SDL_keyboard.h"
#include "ServiceLocator.h"
#include "UDebug.h"

#include <string>

// #############################################################################
//                        Input System Declaration
// #############################################################################

// -----------------------------------------------------------------------------
//   Constructor
// -----------------------------------------------------------------------------
InputSystem::InputSystem()
{
    keyPressedLastFrame.fill(false);
}

// -----------------------------------------------------------------------------
//   Singleton Instance
// -----------------------------------------------------------------------------

InputSystem& InputSystem::getInstance()
{
    static InputSystem instance;
    return instance;
}

// -----------------------------------------------------------------------------
//   Process Events
// -----------------------------------------------------------------------------

void InputSystem::processEvents()
{
    SDL_PollEvent(&event_);
}

// -----------------------------------------------------------------------------
//   Return User Actions
// -----------------------------------------------------------------------------

//  Keyboard
// ----------------------------------------

// Will return true or 1 if key is pressed each frame.
float InputSystem::keyDown(std::string keyName)
{
    int scanCode = SDL_GetScancodeFromName(keyName.c_str());
    if (event_.type == SDL_KEYDOWN)
    {
        if (event_.key.keysym.scancode == scanCode)
        {
            return 1;
        }
    }
    return 0;
}

// Will return false of 0 if key is released each frame.
float InputSystem::keyUp(std::string keyName)
{
    int scanCode = SDL_GetScancodeFromName(keyName.c_str());
    if (event_.type == SDL_KEYUP)
    {
        if (event_.key.keysym.scancode == scanCode)
        {
            return 1;
        }
    }
    return 0;
}

// Will return true once when key is pressed until the key is pressed again.
bool InputSystem::keyPressed(std::string keyName)
{
    int scanCode = SDL_GetScancodeFromName(keyName.c_str());
    if (keyDown(keyName) > 0 && keyPressedLastFrame[scanCode] == false)
    {
        keyPressedLastFrame[scanCode] = true;
        return true;
    }
    return false;
}

// Will return true once when key is released until the key is pressed and released again.
bool InputSystem::keyReleased(std::string keyName)
{
    int scanCode = SDL_GetScancodeFromName(keyName.c_str());
    if (keyUp(keyName) > 0 && keyPressedLastFrame[scanCode] == true)
    {
        keyPressedLastFrame[scanCode] = false;
        return true;
    }
    return false;
}

//  Get Axis
// ----------------------------------------
float InputSystem::getAxis(std::string up, std::string down)
{
    return keyDown(up) - keyDown(down);
}

Vector2 InputSystem::getAxis2D(std::string up, std::string left, std::string down, std::string right)
{

    // --> Vertical axis [ Y ]
    float y = getAxis(up, down);

    // --> Horizontal Axis [ X ]
    float x = getAxis(right, left);

    return Vector2(x, y);
}

//  Mouse
// ----------------------------------------
Vector2 InputSystem::getMousePos()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    // For SDL 0,0 is top left while for opengl it is top right.
    // So to invert the y axis we have to do this.
    // We can do this by subtracting it from screen height.
    int screenHeight = ServiceLocator::getWindow()->getScreenSize().y;

    y = (screenHeight - y);
    return Vector2(x, y);
}

//  Helper Functions
// ----------------------------------------
bool InputSystem::hasQuit()
{
    if (event_.type == SDL_QUIT)
    {
        WHISPER("Probably quit");
        return true;
    }
    return false;
}
