//
// Created by manish on 02-06-2024.
//

#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include "UMath.h"

#include <GL/glew.h>
#include <SDL.h>

class RenderWindow
{
public:
    RenderWindow(const char* title, int width, int height);
    ~RenderWindow();

    void                  init();
    void                  clear() const;
    void                  display() const;
    void                  renderTexture(GLuint textureID, float x, float y, float width, float height) const;
    void                  loadShaders(const char* vertexShaderPath, const char* fragShaderPath);
    static GLuint         loadGLTexture(const char* filepath);
    [[nodiscard]] Vector2 getScreenSize();

private:
    void setupRenderData();

    SDL_Window*   window_;
    SDL_GLContext glContext_;
    GLuint        shaderProgram;
    GLuint        VAO, VBO, EBO;
    int           screenWidth, screenHeight;
    GLuint        texture;
};

#endif // RENDERWINDOW_H
