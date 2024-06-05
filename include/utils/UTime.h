//
// Created by manish on 05-06-2024.
//

#ifndef UTIME_H
#define UTIME_H

#pragma once

#include <chrono>

// #############################################################################
//                               UTime Implementations
// #############################################################################

class UTime {
public:
  // Returns the current time in seconds
  static float getTime() {
    using namespace std::chrono;

    static high_resolution_clock::time_point startTime = high_resolution_clock::now();
    const high_resolution_clock::time_point currentTime = high_resolution_clock::now();
    const auto timeSpan = duration_cast<duration<float>>(currentTime - startTime);
    return timeSpan.count();
  }

  // Returns the time that has been elapsed between current and previous frame.
  static float getDeltaTime() {
    static float lastTime = getTime();
    float currentTime = getTime();
    float deltaTime = currentTime - lastTime;
    lastTime = currentTime;
    return deltaTime;
  }
};

#endif //UTIME_H
