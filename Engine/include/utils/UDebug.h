//
// Created by manish on 02-06-2024.
//

#pragma once

#include <cstdio>

// #############################################################################
//                           Defines
// #############################################################################

#ifdef _WIN32
#    define DEBUG_BREAK() __debugbreak()
#elif __linux__
#    define DEBUG_BREAK() __builtin_debugtrap()
#elif __APPLE__
#    define DEBUG_BREAK() __builtin_trap()
#endif

// #############################################################################
//                           Logging
// #############################################################################

// Enum for text colors
enum TextColor
{
    TEXT_COLOR_BLACK,
    TEXT_COLOR_RED,
    TEXT_COLOR_GREEN,
    TEXT_COLOR_YELLOW,
    TEXT_COLOR_BLUE,
    TEXT_COLOR_MAGENTA,
    TEXT_COLOR_CYAN,
    TEXT_COLOR_WHITE,
    TEXT_COLOR_BRIGHT_BLACK,
    TEXT_COLOR_BRIGHT_RED,
    TEXT_COLOR_BRIGHT_GREEN,
    TEXT_COLOR_BRIGHT_YELLOW,
    TEXT_COLOR_BRIGHT_BLUE,
    TEXT_COLOR_BRIGHT_MAGENTA,
    TEXT_COLOR_BRIGHT_CYAN,
    TEXT_COLOR_BRIGHT_WHITE,
    TEXT_COLOR_COUNT
};

// Utility function for logging
template <typename... Args>
void log(const char* prefix, const char* msg, const TextColor textColor, Args... args)
{
    static const char* TextColorTable[TEXT_COLOR_COUNT] = {
        "\x1b[30m", // TEXT_COLOR_BLACK
        "\x1b[31m", // TEXT_COLOR_RED
        "\x1b[32m", // TEXT_COLOR_GREEN
        "\x1b[33m", // TEXT_COLOR_YELLOW
        "\x1b[34m", // TEXT_COLOR_BLUE
        "\x1b[35m", // TEXT_COLOR_MAGENTA
        "\x1b[36m", // TEXT_COLOR_CYAN
        "\x1b[37m", // TEXT_COLOR_WHITE
        "\x1b[90m", // TEXT_COLOR_BRIGHT_BLACK
        "\x1b[91m", // TEXT_COLOR_BRIGHT_RED
        "\x1b[92m", // TEXT_COLOR_BRIGHT_GREEN
        "\x1b[93m", // TEXT_COLOR_BRIGHT_YELLOW
        "\x1b[94m", // TEXT_COLOR_BRIGHT_BLUE
        "\x1b[95m", // TEXT_COLOR_BRIGHT_MAGENTA
        "\x1b[96m", // TEXT_COLOR_BRIGHT_CYAN
        "\x1b[97m", // TEXT_COLOR_BRIGHT_WHITE
    };

    char formatBuffer[8192];
    snprintf(formatBuffer, sizeof(formatBuffer), "%s %s %s \x1b[0m", TextColorTable[textColor], prefix, msg);

    char textBuffer[8912];
    snprintf(textBuffer, sizeof(textBuffer), formatBuffer, args...);

    puts(textBuffer);
}

// Macros for different log levels
#define WHISPER(msg, ...) log("TRACE: ", msg, TEXT_COLOR_GREEN, ##__VA_ARGS__)
#define CAUTION(msg, ...) log("WARN: ", msg, TEXT_COLOR_YELLOW, ##__VA_ARGS__)
#define PANIC(msg, ...) log("ERROR: ", msg, TEXT_COLOR_RED, ##__VA_ARGS__)
#define CHECK(x, msg, ...)             \
    {                                  \
        if (!(x))                      \
        {                              \
            PANIC(msg, ##__VA_ARGS__); \
            DEBUG_BREAK();             \
        }                              \
    }
