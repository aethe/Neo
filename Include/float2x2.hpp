#ifndef FLOAT2X2_HPP
#define FLOAT2X2_HPP

#include "neo.hpp"

namespace neo {

inline float3x3 float2x2::as_float3x3() const {
    return float3x3(v1.as_float3(), v2.as_float3(), float3(0.0f, 0.0f, 1.0f));
}

inline float4x4 float2x2::as_float4x4() const {
    return float4x4(v1.as_float4(), v2.as_float4(), float4(0.0f, 0.0f, 1.0f, 0.0f), float4(0.0f, 0.0f, 0.0f, 1.0f));
}

inline float2x2 float2x2::transpose() const {
    return float2x2(
        float2(v1.x, v2.x),
        float2(v1.y, v2.y)
    );
}

inline float2x2 float2x2::inverse() const {
    float2x2 inv;

    inv.v1.x = v2.y;
    inv.v1.y = -v1.y;
    inv.v2.x = -v2.x;
    inv.v2.y = v1.x;

    float det = v1.x * inv.v1.x + v1.y * inv.v2.x;

    return inv / det;
}

inline float float2x2::det() const {
    return v1.x * v2.y - v1.y * v2.x;
}

inline float2x2 float2x2::operator-() const {
    return float2x2(-v1, -v2);
}

inline float2x2 float2x2::operator+(float scalar) const {
    return float2x2(v1 + scalar, v2 + scalar);
}

inline float2x2 float2x2::operator-(float scalar) const {
    return float2x2(v1 - scalar, v2 - scalar);
}

inline float2x2 float2x2::operator*(float scalar) const {
    return float2x2(v1 * scalar, v2 * scalar);
}

inline float2x2 float2x2::operator/(float scalar) const {
    return (*this) * (1.0f / scalar);
}

inline float2 float2x2::operator*(const float2& vector) const {
    return float2(
        v1.x * vector.x + v2.x * vector.y,
        v1.y * vector.x + v2.y * vector.y
    );
}

inline float2x2 float2x2::operator+(const float2x2& other) const {
    return float2x2(v1 + other.v1, v2 + other.v2);
}

inline float2x2 float2x2::operator-(const float2x2& other) const {
    return float2x2(v1 - other.v1, v2 - other.v2);
}

inline float2x2 float2x2::operator*(const float2x2& other) const {
    return float2x2(
        float2(
            v1.x * other.v1.x + v2.x * other.v1.y,
            v1.y * other.v1.x + v2.y * other.v1.y
        ),
        float2(
            v1.x * other.v2.x + v2.x * other.v2.y,
            v1.y * other.v2.x + v2.y * other.v2.y
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
