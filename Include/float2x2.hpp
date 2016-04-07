#ifndef FLOAT2X2_HPP
#define FLOAT2X2_HPP

#include "neo.hpp"

namespace neo {

inline float3x3 float2x2::as_float3x3() const {
    return float3x3(c0.as_float3(), c1.as_float3(), float3(0.0f, 0.0f, 1.0f));
}

inline float4x4 float2x2::as_float4x4() const {
    return float4x4(c0.as_float4(), c1.as_float4(), float4(0.0f, 0.0f, 1.0f, 0.0f), float4(0.0f, 0.0f, 0.0f, 1.0f));
}

inline float2x2 float2x2::transpose() const {
    return float2x2(
        float2(c0.x, c1.x),
        float2(c0.y, c1.y)
    );
}

inline float2x2 float2x2::inverse() const {
    float2x2 inv;

    inv.c0.x = c1.y;
    inv.c0.y = -c0.y;
    inv.c1.x = -c1.x;
    inv.c1.y = c0.x;

    float det = c0.x * inv.c0.x + c0.y * inv.c1.x;

    return inv / det;
}

inline float float2x2::det() const {
    return c0.x * c1.y - c0.y * c1.x;
}

inline float2x2 float2x2::operator-() const {
    return float2x2(-c0, -c1);
}

inline float2x2 float2x2::operator+(float scalar) const {
    return float2x2(c0 + scalar, c1 + scalar);
}

inline float2x2 float2x2::operator-(float scalar) const {
    return float2x2(c0 - scalar, c1 - scalar);
}

inline float2x2 float2x2::operator*(float scalar) const {
    return float2x2(c0 * scalar, c1 * scalar);
}

inline float2x2 float2x2::operator/(float scalar) const {
    return (*this) * (1.0f / scalar);
}

inline float2 float2x2::operator*(const float2& vector) const {
    return float2(
        c0.x * vector.x + c1.x * vector.y,
        c0.y * vector.x + c1.y * vector.y
    );
}

inline float2x2 float2x2::operator+(const float2x2& other) const {
    return float2x2(c0 + other.c0, c1 + other.c1);
}

inline float2x2 float2x2::operator-(const float2x2& other) const {
    return float2x2(c0 - other.c0, c1 - other.c1);
}

inline float2x2 float2x2::operator*(const float2x2& other) const {
    return float2x2(
        float2(
            c0.x * other.c0.x + c1.x * other.c0.y,
            c0.y * other.c0.x + c1.y * other.c0.y
        ),
        float2(
            c0.x * other.c1.x + c1.x * other.c1.y,
            c0.y * other.c1.x + c1.y * other.c1.y
        )
    );
}

inline float2x2& float2x2::operator+=(float scalar) {
    return *this = *this + scalar;
}

inline float2x2& float2x2::operator-=(float scalar) {
    return *this = *this - scalar;
}

inline float2x2& float2x2::operator*=(float scalar) {
    return *this = *this * scalar;
}

inline float2x2& float2x2::operator/=(float scalar) {
    return *this = *this / scalar;
}

inline float2x2& float2x2::operator+=(const float2x2& other) {
    return *this = *this + other;
}

inline float2x2& float2x2::operator-=(const float2x2& other) {
    return *this = *this - other;
}

inline float2x2& float2x2::operator*=(const float2x2& other) {
    return *this = *this * other;
}

}

#endif
