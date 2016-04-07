#ifndef FLOAT2_HPP
#define FLOAT2_HPP

#include "neo.hpp"

namespace neo {

inline float3 float2::as_float3(float z) const {
    return float3(x, y, z);
}

inline float4 float2::as_float4(float z, float w) const {
    return float4(x, y, z, w);
}

inline float float2::length() const {
    return sqrtf(dot(*this, *this));
}

inline float2 float2::normalize() const {
    float inverse_sqrt = 1.0f / length();
    return (*this) * inverse_sqrt;
}

inline float2 float2::proj(const float2& other) const {
    return other * (dot(*this, other) / dot(other, other));
}

inline float2 float2::perp(const float2& other) const {
    return *this - proj(other);
}

inline float2 float2::reflect(const float2& normal) const {
    return *this - normal * dot(*this, normal) * 2.0f;
}

inline float2 float2::refract(const float2& normal, float eta) const {
    float n_dot_i = dot(*this, normal);
    float k = 1.0f - eta * eta * (1.0f - n_dot_i * n_dot_i);
    if (k < 0.0f) {
        return float2(0.0f, 0.0f);
    } else {
        return *this * eta - normal * (eta * n_dot_i + sqrtf(k));
    }
}

inline float2 float2::operator-() const {
    return float2(-x, -y);
}

inline float2 float2::operator+(float scalar) const {
    return float2(x + scalar, y + scalar);
}

inline float2 float2::operator-(float scalar) const {
    return float2(x - scalar, y - scalar);
}

inline float2 float2::operator*(float scalar) const {
    return float2(x * scalar, y * scalar);
}

inline float2 float2::operator/(float scalar) const {
    return (*this) * (1.0f / scalar);
}

inline float2 float2::operator+(const float2& other) const {
    return float2(x + other.x, y + other.y);
}

inline float2 float2::operator-(const float2& other) const {
    return float2(x - other.x, y - other.y);
}

inline float2 float2::operator*(const float2& other) const {
    return float2(x * other.x, y * other.y);
}

inline float2 float2::operator/(const float2& other) const {
    return float2(x / other.x, y / other.y);
}

inline float2& float2::operator+=(float scalar) {
    return *this = *this + scalar;
}

inline float2& float2::operator-=(float scalar) {
    return *this = *this - scalar;
}

inline float2& float2::operator*=(float scalar) {
    return *this = *this * scalar;
}

inline float2& float2::operator/=(float scalar) {
    return *this = *this / scalar;
}

inline float2& float2::operator+=(const float2& other) {
    return *this = *this + other;
}

inline float2& float2::operator-=(const float2& other) {
    return *this = *this - other;
}

inline float2& float2::operator*=(const float2& other) {
    return *this = *this * other;
}

inline float2& float2::operator/=(const float2& other) {
    return *this = *this / other;
}

}

#endif
