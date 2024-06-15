//
// Created by manish on 08-06-2024.
//

#ifndef USHADER_H
#define USHADER_H

#include "UDebug.h"

#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

inline std::string loadShaderSource(const char* filePath)
{
    std::ifstream shaderFile(filePath);
    if (!shaderFile.is_open())
    {
        CHECK(false, "Failed to laod shader file : %s", filePath);
        exit(EXIT_FAILURE);
    }

    std::stringstream shaderStream;
    shaderStream << shaderFile.rdbuf();
    return shaderStream.str();
}

inline GLuint compileShader(const char* source, GLenum shaderType)
{
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        PANIC("Shader compilation error: %s", infoLog);
        exit(EXIT_FAILURE);
    }
    return shader;
}

inline GLuint createShaderProgram(const char* vertexShaderPath, const char* fragShaderPath)
{
    std::string vertexCode   = loadShaderSource(vertexShaderPath);
    std::string fragmentCode = loadShaderSource(fragShaderPath);

    GLuint vertexShader   = compileShader(vertexCode.c_str(), GL_VERTEX_SHADER);
    GLuint fragmentShader = compileShader(fragmentCode.c_str(), GL_FRAGMENT_SHADER);

    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        CHECK(false, "Shader compilation error: %s", infoLog);
        exit(EXIT_FAILURE);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}

#endif // USHADER_H
