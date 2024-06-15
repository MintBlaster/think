// /src/math/Math.h

#ifndef MATH_H
#define MATH_H

#include <UDebug.h>
#include <array>
#include <cmath>
#include <optional>
#include <stdexcept>
#include <string>

// #############################################################################
//                               Vector Implementations
// #############################################################################

// -----------------------------------------------------------------------------
// Vector2 Implementations
// -----------------------------------------------------------------------------

constexpr double PI = 22.0f / 7.0f;

struct Vector2
{
    float x = 0;
    float y = 0;

    // Constructors
    Vector2() = default;
    Vector2(const float x, const float y) : x(x), y(y) {}

    // Operator Overloads
    Vector2  operator/(const float scalar) const { return {x / scalar, y / scalar}; }
    Vector2  operator*(const float scalar) const { return {x * scalar, y * scalar}; }
    Vector2  operator-(const Vector2& other) const { return {x - other.x, y - other.y}; }
    Vector2  operator+(const Vector2& other) const { return {x + other.x, y + other.y}; }
    explicit operator bool() const { return x != 0.0f && y != 0.0f; }

    // Member Functions
    [[nodiscard]] float   magnitude() const { return std::hypot(x, y); }
    [[nodiscard]] Vector2 normalize() const
    {
        const float mag = magnitude();
        return {x / mag, y / mag};
    }

    // 'with' and 'add' functions
    [[nodiscard]] Vector2 with(const std::optional<float>& newX = std::nullopt,
                               const std::optional<float>& newY = std::nullopt) const
    {
        return {newX.value_or(x), newY.value_or(y)};
    }

    [[nodiscard]] Vector2 withX(float newX) const { return {newX, y}; }
    [[nodiscard]] Vector2 withY(float newY) const { return {x, newY}; }

    [[nodiscard]] Vector2 add(const std::optional<float>& toX = std::nullopt,
                              const std::optional<float>& toY = std::nullopt) const
    {
        return {x + toX.value_or(0), y + toY.value_or(0)};
    }

    [[nodiscard]] Vector2 addX(const float value) const { return {x + value, y}; }
    [[nodiscard]] Vector2 addY(const float value) const { return {x, y + value}; }

    // String Representation
    [[nodiscard]] std::string toString() const
    {
        char buffer[50];
        snprintf(buffer, sizeof(buffer), "(%f, %f)", x, y);
        return {buffer};
    }
};

// -----------------------------------------------------------------------------
// Vector3 Implementations
// -----------------------------------------------------------------------------

struct Vector3
{
    float x = 0;
    float y = 0;
    float z = 0;

    // Constructors
    Vector3() = default;
    Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) {}

    // Operator Overloads
    Vector3  operator/(const float scalar) const { return {x / scalar, y / scalar, z / scalar}; }
    Vector3  operator*(const float scalar) const { return {x * scalar, y * scalar, z * scalar}; }
    Vector3  operator-(const Vector3& other) const { return {x - other.x, y - other.y, z - other.z}; }
    Vector3  operator+(const Vector3& other) const { return {x + other.x, y + other.y, z + other.z}; }
    explicit operator bool() const { return x != 0.0f && y != 0.0f && z != 0.0f; }

    // Member Functions
    [[nodiscard]] float   magnitude() const { return std::sqrt(x * x + y * y + z * z); }
    [[nodiscard]] Vector3 normalize() const
    {
        const float mag = magnitude();
        return {x / mag, y / mag, z / mag};
    }

    // 'with' and 'add' functions
    [[nodiscard]] Vector3 with(const std::optional<float>& newX = std::nullopt,
                               const std::optional<float>& newY = std::nullopt,
                               const std::optional<float>& newZ = std::nullopt) const
    {
        return {newX.value_or(x), newY.value_or(y), newZ.value_or(z)};
    }

    [[nodiscard]] Vector3 withX(float newX) const { return {newX, y, z}; }
    [[nodiscard]] Vector3 withY(float newY) const { return {x, newY, z}; }
    [[nodiscard]] Vector3 withZ(float newZ) const { return {x, y, newZ}; }

    [[nodiscard]] Vector3 add(const std::optional<float>& toX = std::nullopt,
                              const std::optional<float>& toY = std::nullopt,
                              const std::optional<float>& toZ = std::nullopt) const
    {
        return {x + toX.value_or(0), y + toY.value_or(0), z + toZ.value_or(0)};
    }
    [[nodiscard]] Vector3 addX(const float value) const { return {x + value, y, z}; }
    [[nodiscard]] Vector3 addY(const float value) const { return {x, y + value, z}; }
    [[nodiscard]] Vector3 addZ(const float value) const { return {x, y, z + value}; }

    // String Representation
    [[nodiscard]] std::string toString() const
    {
        char buffer[50];
        snprintf(buffer, sizeof(buffer), "(%f, %f, %f)", x, y, z);
        return {buffer};
    }
};

// -----------------------------------------------------------------------------
// Vector4 Implementations
// -----------------------------------------------------------------------------

struct Vector4
{
    float x = 0;
    float y = 0;
    float z = 0;
    float w = 0;

    // Constructors
    Vector4() = default;
    Vector4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) {}

    // Operator Overloads
    Vector4 operator/(const float scalar) const { return {x / scalar, y / scalar, z / scalar, w / scalar}; }
    Vector4 operator*(const float scalar) const { return {x * scalar, y * scalar, z * scalar, w * scalar}; }

    Vector4 operator*(const Vector4 other) const { return {x * other.x, y * other.y, z * other.z, w * other.w}; }

    Vector4  operator-(const Vector4& other) const { return {x - other.x, y - other.y, z - other.z, w - other.w}; }
    Vector4  operator+(const Vector4& other) const { return {x + other.x, y + other.y, z + other.z, w + other.w}; }
    explicit operator bool() const { return x != 0.0f && y != 0.0f && z != 0.0f && w != 0.0f; }
    // Accessor
    float& operator[](int index)
    {
        switch (index)
        {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        case 3:
            return w;
        default:
            throw std::out_of_range("Index out of bounds");
        }
    }

    const float& operator[](int index) const
    {
        switch (index)
        {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        case 3:
            return w;
        default:
            throw std::out_of_range("Index out of bounds");
        }
    }

    // Member Functions
    [[nodiscard]] float   magnitude() const { return std::sqrt(x * x + y * y + z * z + w * w); }
    [[nodiscard]] Vector4 normalize() const
    {
        const float mag = magnitude();
        return {x / mag, y / mag, z / mag, w / mag};
    }

    // 'with' and 'add' functions
    [[nodiscard]] Vector4 with(const std::optional<float>& newX = std::nullopt,
                               const std::optional<float>& newY = std::nullopt,
                               const std::optional<float>& newZ = std::nullopt,
                               const std::optional<float>& newW = std::nullopt) const
    {
        return {newX.value_or(x), newY.value_or(y), newZ.value_or(z), newW.value_or(w)};
    }

    [[nodiscard]] Vector4 withX(float newX) const { return {newX, y, z, w}; }
    [[nodiscard]] Vector4 withY(float newY) const { return {x, newY, z, w}; }
    [[nodiscard]] Vector4 withZ(float newZ) const { return {x, y, newZ, w}; }
    [[nodiscard]] Vector4 withW(float newW) const { return {x, y, z, newW}; }

    [[nodiscard]] Vector4 add(const std::optional<float>& toX = std::nullopt,
                              const std::optional<float>& toY = std::nullopt,
                              const std::optional<float>& toZ = std::nullopt,
                              const std::optional<float>& toW = std::nullopt) const
    {
        return {x + toX.value_or(0), y + toY.value_or(0), z + toZ.value_or(0), w + toW.value_or(0)};
    }
    [[nodiscard]] Vector4 addX(const float value) const { return {x + value, y, z, w}; }
    [[nodiscard]] Vector4 addY(const float value) const { return {x, y + value, z, w}; }
    [[nodiscard]] Vector4 addZ(const float value) const { return {x, y, z + value, w}; }
    [[nodiscard]] Vector4 addW(const float value) const { return {x, y, z, w + value}; }

    // String Representation
    [[nodiscard]] std::string toString() const
    {
        char buffer[80];
        snprintf(buffer, sizeof(buffer), "(%f, %f, %f, %f)", x, y, z, w);
        return {buffer};
    }
};

// #############################################################################
//                               Matrix Implementations
// #############################################################################

struct Matrix4
{
    std::array<Vector4, 4> rows {};

    // Constructors
    // Constructors
    Matrix4() : rows {Vector4(), Vector4(), Vector4(), Vector4()} {}
    Matrix4(const Vector4& row0, const Vector4& row1, const Vector4& row2, const Vector4& row3)
        : rows {row0, row1, row2, row3}
    {
    }

    // Static Methods for Special matrices
    static Matrix4 identity()
    {
        return {
            Vector4(1, 0, 0, 0),
            Vector4(0, 1, 0, 0),
            Vector4(0, 0, 1, 0),
            Vector4(0, 0, 0, 1),
        };
    }

    static Matrix4 translation(const float tx, const float ty, const float tz)
    {
        return {
            Vector4(1, 0, 0, tx),
            Vector4(0, 1, 0, ty),
            Vector4(0, 0, 1, tz),
            Vector4(0, 0, 0, 1),
        };
    }

    static Matrix4 scaling(const float sx, const float sy, const float sz)
    {
        return {
            Vector4(sx, 0, 0, 0),
            Vector4(1, sy, 0, 0),
            Vector4(1, 0, sz, 0),
            Vector4(1, 0, 0, 1),
        };
    }

    static Matrix4 rotationX(const float angle)
    {
        const float c = std::cos(angle);
        const float s = std::sin(angle);
        return {
            Vector4(1, 0, 0, 0),
            Vector4(0, c, -s, 0),
            Vector4(0, s, c, 0),
            Vector4(0, 0, 0, 1),
        };
    }

    static Matrix4 rotationY(const float angle)
    {
        const float c = std::cos(angle);
        const float s = std::sin(angle);
        return {
            Vector4(c, 0, s, 0),
            Vector4(0, 0, 0, 0),
            Vector4(-s, 0, c, 0),
            Vector4(0, 0, 0, 1),
        };
    }

    static Matrix4 rotationZ(const float angle)
    {
        const float c = std::cos(angle);
        const float s = std::sin(angle);
        return {
            Vector4(c, -s, 0, 0),
            Vector4(s, c, 0, 0),
            Vector4(0, 0, 0, 0),
            Vector4(0, 0, 0, 1),
        };
    }

    static Matrix4 orthographic(const float left, float right, float bottom, float top, float near, float far)
    {
        return {Vector4(2 / (right - left), 0, 0, -(right + left) / (right - left)),
                Vector4(0, 2 / (top - bottom), 0, -(top + bottom) / (top - bottom)),
                Vector4(0, 0, -2 / (far - near), -(far + near) / (far - near)),
                Vector4(0, 0, 0, 1)};
    }

    // Operator Overloads
    Matrix4 operator*(const Matrix4& other) const
    {
        Matrix4 result;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                result[i][j] = rows[i].x * other.rows[0][j] + rows[i].y * other.rows[1][j] +
                               rows[i].z * other.rows[2][j] + rows[i].w * other.rows[3][j];
            }
        }
        return result;
    }

    Matrix4 operator*(float scalar) const
    {
        Matrix4 result;
        for (int i = 0; i < 4; ++i)
        {
            result.rows[i] = rows[i] * scalar;
        }
        return result;
    }

    Matrix4 operator+(const Matrix4& other) const
    {
        Matrix4 result;
        for (int i = 0; i < 4; ++i)
        {
            result.rows[i] = rows[i] + other.rows[i];
        }
        return result;
    }

    // Accessor
    Vector4& operator[](int index) { return rows[index]; }

    const Vector4& operator[](int index) const { return rows[index]; }

    // Convert to float array for OpenGL
    std::array<float, 16> toFloatArray() const
    {
        std::array<float, 16> result;
        for (int i = 0; i < 4; ++i)
        {
            result[i * 4]     = rows[i].x;
            result[i * 4 + 1] = rows[i].y;
            result[i * 4 + 2] = rows[i].z;
            result[i * 4 + 3] = rows[i].w;
        }
        return result;
    }

    // String Representation
    [[nodiscard]] std::string toString() const
    {
        return "[\n" + rows[0].toString() + "\n" + rows[1].toString() + "\n" + rows[2].toString() + "\n" +
               rows[3].toString() + "\n]";
    }
};

#endif // MATH_H
