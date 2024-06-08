//
// Created by manish on 07-06-2024.
//

#include "components/camera/OrthographicCamera2d.h"

// #############################################################################
//                 Orthographic Camera2D Implementation
// #############################################################################

// -----------------------------------------------------------------------------
// Constructor
// -----------------------------------------------------------------------------

OrthographicCamera2D::OrthographicCamera2D(float screenWidth, float screenHeight)
    : dimensions(screenWidth, screenHeight), position(0, 0), zoom(1.0f) {}

// -----------------------------------------------------------------------------
// Getters
// -----------------------------------------------------------------------------

// Returns the view matrix combining translation and scaling
Matrix4 OrthographicCamera2D::getViewMatrix() const {
    Matrix4 translate = Matrix4::translation(-position.x, -position.y, 0);
    Matrix4 scale = Matrix4::scaling(zoom, zoom, 1);
    return scale * translate;
}

// Returns the view rectangle (area covered by the camera)
SDL_Rect OrthographicCamera2D::getViewRect() const {
    return {
        static_cast<int>(position.x),
        static_cast<int>(position.y),
        static_cast<int>(dimensions.x / zoom),
        static_cast<int>(dimensions.y / zoom)
    };
}

// -----------------------------------------------------------------------------
// Setters
// -----------------------------------------------------------------------------

// Sets the camera position to a new position
void OrthographicCamera2D::setPosition(const Vector2& newPosition) {
    position = newPosition;
}

// Sets the zoom level of the camera
void OrthographicCamera2D::setZoom(float newZoom) {
    zoom = newZoom;
}

// -----------------------------------------------------------------------------
// Member Functions
// -----------------------------------------------------------------------------

// Moves the camera by a given delta
void OrthographicCamera2D::move(const Vector2& delta) {
    position = position + delta;
}

// Updates the camera position to center on the target SDL_Rect
void OrthographicCamera2D::update(const SDL_Rect& target) {
    position.x = target.x + target.w / 2 - dimensions.x / 2 / zoom;
    position.y = target.y + target.h / 2 - dimensions.y / 2 / zoom;
}
