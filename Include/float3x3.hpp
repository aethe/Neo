#ifndef FLOAT3X3_HPP
#define FLOAT3X3_HPP

#include "neo.hpp"

namespace neo {

inline float2x2 float3x3::as_float2x2() const {
    return float2x2(v1.as_float2(), v2.as_float2());
}

inline float4x4 float3x3::as_float4x4() const {
    return float4x4(v1.as_float4(), v2.as_float4(), v3.as_float4(), float4(0.0f, 0.0f, 0.0f, 1.0f));
}

inline float3x3 float3x3::transpose() const {
    return float3x3(
        float3(v1.x, v2.x, v3.x),
        float3(v1.y, v2.y, v3.y),
        float3(v1.z, v2.z, v3.z)
    );
}

inline float3x3 float3x3::inverse() const {
    float3x3 inv;

    inv.v1.x = v2.y * v3.z - v2.z * v3.y;
    inv.v1.y = v1.z * v3.y - v1.y * v3.z;
    inv.v1.z = v1.y * v2.z - v1.z * v2.y;

    inv.v2.x = v2.z * v3.x - v2.x * v3.z;
    inv.v2.y = v1.x * v3.z - v1.z * v3.x;
    inv.v2.z = v1.z * v2.x - v1.x * v2.z;

    inv.v3.x = v2.x * v3.y - v2.y * v3.x;
    inv.v3.y = v1.y * v3.x - v1.x * v3.y;
    inv.v3.z = v1.x * v2.y - v1.y * v2.x;

    float det = v1.x * inv.v1.x + v1.y * inv.v2.x + v1.z * inv.v3.x;

    return inv / det;
}

inline float float3x3::det() const {
    return v1.x * (v2.y * v3.z - v2.z * v3.y) + v1.y * (v2.z * v3.x - v2.x * v3.z) + v1.z * (v2.x * v3.y - v2.y * v3.x);
}

inline float3x3 float3x3::operator-() const {
    return float3x3(-v1, -v2, -v3);
}

inline float3x3 float3x3::operator+(float scalar) const {
    return float3x3(v1 + scalar, v2 + scalar, v3 + scalar);
}

inline float3x3 float3x3::operator-(float scalar) const {
    return float3x3(v1 - scalar, v2 - scalar, v3 - scalar);
}

inline float3x3 float3x3::operator*(float scalar) const {
    return float3x3(v1 * scalar, v2 * scalar, v3 * scalar);
}

inline float3x3 float3x3::operator/(float scalar) const {
    return (*this) * (1.0f / scalar);
}

inline float3 float3x3::operator*(const float3& vector) const {
    return float3(
        v1.x * vector.x + v2.x * vector.y + v3.x * vector.z,
        v1.y * vector.x + v2.y * vector.y + v3.y * vector.z,
        v1.z * vector.x + v2.z * vector.y + v3.z * vector.z
    );
}

inline float3x3 float3x3::operator+(const float3x3& other) const {
    return float3x3(v1 + other.v1, v2 + other.v2, v3 + other.v3);
}

inline float3x3 float3x3::operator-(const float3x3& other) const {
    return float3x3(v1 - other.v1, v2 - other.v2, v3 - other.v3);
}

inline float3x3 float3x3::operator*(const float3x3& other) const {
    return float3x3(
        float3(
            v1.x * other.v1.x + v2.x * other.v1.y + v3.x * other.v1.z,
            v1.y * other.v1.x + v2.y * other.v1.y + v3.y * other.v1.z,
            v1.z * other.v1.x + v2.z * other.v1.y + v3.z * other.v1.z
        ),
        float3(
            v1.x * other.v2.x + v2.x * other.v2.y + v3.x * other.v2.z,
            v1.y * other.v2.x + v2.y * other.v2.y + v3.y * other.v2.z,
            v1.z * other.v2.x + v2.z * other.v2.y + v3.z * other.v2.z
        ),
        float3(
            v1.x * other.v3.x + v2.x * other.v3.y + v3.x * other.v3.z,
            v1.y * other.v3.x + v2.y * other.v3.y + v3.y * other.v3.z,
            v1.z * other.v3.x + v2.z * other.v3.y + v3.z * other.v3.z
        )
    );
}

inline float3x3& float3x3::operator+=(float scalar) {
    return *this = *this + scalar;
}

inline float3x3& float3x3::operator-=(float scalar) {
    return *this = *this - scalar;
}

inline float3x3& float3x3::operator*=(float scalar) {
    return *this = *this * scalar;
}

inline float3x3& float3x3::operator/=(float scalar) {
    return *this = *this / scalar;
}

inline float3x3& float3x3::operator+=(const float3x3& other) {
    return *this = *this + other;
}

inline float3x3& float3x3::operator-=(const float3x3& other) {
    return *this = *this - other;
}

inline float3x3& float3x3::operator*=(const float3x3& other) {
    return *this = *this * other;
}

}

#endif
