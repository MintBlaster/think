//
// Created by manish on 03-06-2024.
//

#ifndef MATH_H
#define MATH_H

#include <cmath>
#include <optional>
#include <string>

// #############################################################################
//                               Vector Implementations
// #############################################################################

// -----------------------------------------------------------------------------
// Vector2 Implementations
// -----------------------------------------------------------------------------

struct Vector2 {
  float x = 0;
  float y = 0;

  // Constructors
  Vector2() = default;
  Vector2(const float x, const float y) : x(x), y(y) {}

  // Operator Overloads
  Vector2 operator/(const float scalar) const {
    return {x / scalar, y / scalar};
  }
  Vector2 operator*(const float scalar) const {
    return {x * scalar, y * scalar};
  }
  Vector2 operator-(const Vector2 &other) const {
    return {x - other.x, y - other.y};
  }
  Vector2 operator+(const Vector2 &other) const {
    return {x + other.x, y + other.y};
  }
  explicit operator bool() const { return x != 0.0f && y != 0.0f; }

  // Member Functions
  [[nodiscard]] float magnitude() const { return std::hypot(x, y); }
  [[nodiscard]] Vector2 normalize() const {
    const float mag = magnitude();
    return {x / mag, y / mag};
  }

  // 'with' and 'add' functions
  [[nodiscard]] Vector2
  with(const std::optional<float> &newX = std::nullopt,
       const std::optional<float> &newY = std::nullopt) const {
    return {newX.value_or(x), newY.value_or(y)};
  }

  [[nodiscard]] Vector2 withX(float newX) const { return {newX, y}; }
  [[nodiscard]] Vector2 withY(float newY) const { return {x, newY}; }

  [[nodiscard]] Vector2
  add(const std::optional<float> &toX = std::nullopt,
      const std::optional<float> &toY = std::nullopt) const {
    return {x + toX.value_or(0), y + toY.value_or(0)};
  }

  [[nodiscard]] Vector2 addX(const float value) const { return {x + value, y}; }
  [[nodiscard]] Vector2 addY(const float value) const { return {x, y + value}; }

  // String Representation
  [[nodiscard]] std::string toString() const {
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "(%f, %f)", x, y);
    return {buffer};
  }
};

// -----------------------------------------------------------------------------
// Vector3 Implementations
// -----------------------------------------------------------------------------

struct Vector3 {
  float x = 0;
  float y = 0;
  float z = 0;

  // Constructors
  Vector3() = default;
  Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) {}

  // Operator Overloads
  Vector3 operator/(const float scalar) const {
    return {x / scalar, y / scalar, z / scalar};
  }
  Vector3 operator*(const float scalar) const {
    return {x * scalar, y * scalar, z * scalar};
  }
  Vector3 operator-(const Vector3 &other) const {
    return {x - other.x, y - other.y, z - other.z};
  }
  Vector3 operator+(const Vector3 &other) const {
    return {x + other.x, y + other.y, z + other.z};
  }
  explicit operator bool() const { return x != 0.0f && y != 0.0f && z != 0.0f; }

  // Member Functions
  [[nodiscard]] float magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
  }
  [[nodiscard]] Vector3 normalize() const {
    const float mag = magnitude();
    return {x / mag, y / mag, z / mag};
  }

  // 'with' and 'add' functions
  [[nodiscard]] Vector3
  with(const std::optional<float> &newX = std::nullopt,
       const std::optional<float> &newY = std::nullopt,
       const std::optional<float> &newZ = std::nullopt) const {
    return {newX.value_or(x), newY.value_or(y), newZ.value_or(z)};
  }

  [[nodiscard]] Vector3 withX(float newX) const { return {newX, y, z}; }
  [[nodiscard]] Vector3 withY(float newY) const { return {x, newY, z}; }
  [[nodiscard]] Vector3 withZ(float newZ) const { return {x, y, newZ}; }

  [[nodiscard]] Vector3
  add(const std::optional<float> &toX = std::nullopt,
      const std::optional<float> &toY = std::nullopt,
      const std::optional<float> &toZ = std::nullopt) const {
    return {x + toX.value_or(0), y + toY.value_or(0), z + toZ.value_or(0)};
  }
  [[nodiscard]] Vector3 addX(const float value) const {
    return {x + value, y, z};
  }
  [[nodiscard]] Vector3 addY(const float value) const {
    return {x, y + value, z};
  }
  [[nodiscard]] Vector3 addZ(const float value) const {
    return {x, y, z + value};
  }

  // String Representation
  [[nodiscard]] std::string toString() const {
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "(%f, %f, %f)", x, y, z);
    return {buffer};
  }
};

#endif // MATH_H
