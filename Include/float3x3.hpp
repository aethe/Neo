#ifndef FLOAT3X3_HPP
#define FLOAT3X3_HPP

#include "neo.hpp"

namespace neo {

inline float2x2 float3x3::as_float2x2() const {
    return float2x2(c0.as_float2(), c1.as_float2());
}

inline float4x4 float3x3::as_float4x4() const {
    return float4x4(c0.as_float4(), c1.as_float4(), c2.as_float4(), float4(0.0f, 0.0f, 0.0f, 1.0f));
}

inline float3x3 float3x3::transpose() const {
    return float3x3(
        float3(c0.x, c1.x, c2.x),
        float3(c0.y, c1.y, c2.y),
        float3(c0.z, c1.z, c2.z)
    );
}

inline float3x3 float3x3::inverse() const {
    float3x3 inv;

    inv.c0.x = c1.y * c2.z - c1.z * c2.y;
    inv.c0.y = c0.z * c2.y - c0.y * c2.z;
    inv.c0.z = c0.y * c1.z - c0.z * c1.y;

    inv.c1.x = c1.z * c2.x - c1.x * c2.z;
    inv.c1.y = c0.x * c2.z - c0.z * c2.x;
    inv.c1.z = c0.z * c1.x - c0.x * c1.z;

    inv.c2.x = c1.x * c2.y - c1.y * c2.x;
    inv.c2.y = c0.y * c2.x - c0.x * c2.y;
    inv.c2.z = c0.x * c1.y - c0.y * c1.x;

    float det = c0.x * inv.c0.x + c0.y * inv.c1.x + c0.z * inv.c2.x;

    return inv / det;
}

inline float float3x3::det() const {
    return c0.x * (c1.y * c2.z - c1.z * c2.y) + c0.y * (c1.z * c2.x - c1.x * c2.z) + c0.z * (c1.x * c2.y - c1.y * c2.x);
}

inline float3x3 float3x3::operator-() const {
    return float3x3(-c0, -c1, -c2);
}

inline float3x3 float3x3::operator+(float scalar) const {
    return float3x3(c0 + scalar, c1 + scalar, c2 + scalar);
}

inline float3x3 float3x3::operator-(float scalar) const {
    return float3x3(c0 - scalar, c1 - scalar, c2 - scalar);
}

inline float3x3 float3x3::operator*(float scalar) const {
    return float3x3(c0 * scalar, c1 * scalar, c2 * scalar);
}

inline float3x3 float3x3::operator/(float scalar) const {
    return (*this) * (1.0f / scalar);
}

inline float3 float3x3::operator*(const float3& vector) const {
    return float3(
        c0.x * vector.x + c1.x * vector.y + c2.x * vector.z,
        c0.y * vector.x + c1.y * vector.y + c2.y * vector.z,
        c0.z * vector.x + c1.z * vector.y + c2.z * vector.z
    );
}

inline float3x3 float3x3::operator+(const float3x3& other) const {
    return float3x3(c0 + other.c0, c1 + other.c1, c2 + other.c2);
}

inline float3x3 float3x3::operator-(const float3x3& other) const {
    return float3x3(c0 - other.c0, c1 - other.c1, c2 - other.c2);
}

inline float3x3 float3x3::operator*(const float3x3& other) const {
    return float3x3(
        float3(
            c0.x * other.c0.x + c1.x * other.c0.y + c2.x * other.c0.z,
            c0.y * other.c0.x + c1.y * other.c0.y + c2.y * other.c0.z,
            c0.z * other.c0.x + c1.z * other.c0.y + c2.z * other.c0.z
        ),
        float3(
            c0.x * other.c1.x + c1.x * other.c1.y + c2.x * other.c1.z,
            c0.y * other.c1.x + c1.y * other.c1.y + c2.y * other.c1.z,
            c0.z * other.c1.x + c1.z * other.c1.y + c2.z * other.c1.z
        ),
        float3(
            c0.x * other.c2.x + c1.x * other.c2.y + c2.x * other.c2.z,
            c0.y * other.c2.x + c1.y * other.c2.y + c2.y * other.c2.z,
            c0.z * other.c2.x + c1.z * other.c2.y + c2.z * other.c2.z
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
