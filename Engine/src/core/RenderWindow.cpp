//
// Created by manish on 02-06-2024.
//

#include "RenderWindow.h"

#include "UDebug.h"
#include "UMath.h"

#include <GL/glew.h>
#include <UShader.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>

// #############################################################################
//                           RenderWindow Class Implementation
// #############################################################################

// ----------------------------------------
// Constructor & Destructor
// ----------------------------------------

RenderWindow::RenderWindow(const char* title, int width, int height)
    : window_(nullptr),
      glContext_(nullptr),
      shaderProgram(0),
      VAO(0),
      VBO(0),
      EBO(0),
      screenWidth(width),
      screenHeight(height),
      texture(0)
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        PANIC("SDL_Init Error: %s", SDL_GetError());
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    window_ = SDL_CreateWindow(title,
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               width,
                               height,
                               SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (window_ == nullptr)
    {
        PANIC("SDL_CreateWindow Error: %s", SDL_GetError());
    }

    glContext_ = SDL_GL_CreateContext(window_);
    if (glContext_ == nullptr)
    {
        PANIC("SDL_GL_CreateContext Error: %s", SDL_GetError());
    }

    SDL_GL_MakeCurrent(window_, glContext_);

    glewExperimental = GL_TRUE;
    GLenum err       = glewInit();
    if (err != GLEW_OK)
    {
        PANIC("GLEW Init Error: %s", glewGetErrorString(err));
    }

    SDL_GL_SetSwapInterval(1);

    // Set up viewport
    glViewport(0, 0, width, height);
    glEnable(GL_DEPTH_TEST);
}

RenderWindow::~RenderWindow()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    if (glContext_)
    {
        SDL_GL_DeleteContext(glContext_);
    }
    if (window_)
    {
        SDL_DestroyWindow(window_);
    }
    SDL_Quit();
}

void RenderWindow::init()
{
    setupRenderData();
    glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
}

void RenderWindow::setupRenderData()
{
    float vertices[] = {
        // positions       // texture coords
        -0.5f,
        -0.5f,
        0.0f,
        0.0f, // bottom left
        0.5f,
        -0.5f,
        1.0f,
        0.0f, // bottom right
        0.5f,
        0.5f,
        1.0f,
        1.0f, // top right
        -0.5f,
        0.5f,
        0.0f,
        1.0f // top left
    };
    unsigned int indices[] = {
        0,
        1,
        2, // first triangle
        2,
        3,
        0 // second triangle
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*) (2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

// ----------------------------------------
// Shader Management
// ----------------------------------------

// Load shaders
void RenderWindow::loadShaders(const char* vertexShaderPath, const char* fragShaderPath)
{
    std::string BASE_RES_DIR = "C:/Projects/cpp/think/res/";
    shaderProgram =
        createShaderProgram((BASE_RES_DIR + vertexShaderPath).c_str(), (BASE_RES_DIR + fragShaderPath).c_str());
}

// ----------------------------------------
// Rendering Functions
// ----------------------------------------

/// <summary> Clears the rendered window. </summary>
void RenderWindow::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/// <summary> Display the rendered window. </summary
void RenderWindow::display() const
{
    SDL_GL_SwapWindow(window_);
}

// ----------------------------------------
// Rendering Textures
// ----------------------------------------

void RenderWindow::renderTexture(GLuint textureID, float x, float y, float width, float height) const
{
    glUseProgram(shaderProgram);

    // Create projection matrix (orthographic)
    glm::mat4 projection = glm::ortho(0.0f, (float) screenWidth, 0.0f, (float) screenHeight);

    // Create model matrix
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f)) *
                      glm::scale(glm::mat4(1.0f), glm::vec3(width, height, 1.0f));

    // Combine model and projection matrices
    glm::mat4 mvp = projection * model;

    // Send MVP matrix to the shader
    GLint mvpLocation = glGetUniformLocation(shaderProgram, "mvp");
    if (mvpLocation != -1)
    {
        glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));
    }
    else
    {
        std::cerr << "Failed to set uniform 'mvp'" << std::endl;
    }

    // Bind texture and set uniform
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
    GLint textureLocation = glGetUniformLocation(shaderProgram, "texture1");
    if (textureLocation != -1)
    {
        glUniform1i(textureLocation, 0);
    }
    else
    {
        std::cerr << "Failed to set uniform 'texture1'" << std::endl;
    }

    // Draw
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}

// -----------------------------------------------------------------------------
//   Setters and Getters
// -----------------------------------------------------------------------------

Vector2 RenderWindow::getScreenSize()
{
    return Vector2(screenWidth, screenHeight);
}
