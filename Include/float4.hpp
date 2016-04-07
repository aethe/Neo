#ifndef FLOAT4_HPP
#define FLOAT4_HPP

#include "neo.hpp"

namespace neo {

inline float2 float4::as_float2() const {
    return float2(x, y);
}

inline float3 float4::as_float3() const {
    return float3(x, y, z);
}

inline float float4::length() const {
    return sqrtf(dot(*this, *this));
}

inline float4 float4::normalize() const {
    float inverse_sqrt = 1.0f / length();
    return (*this) * inverse_sqrt;
}

inline float4 float4::proj(const float4& other) const {
    return other * (dot(*this, other) / dot(other, other));
}

inline float4 float4::perp(const float4& other) const {
    return *this - proj(other);
}

inline float4 float4::reflect(const float4& normal) const {
    return *this - normal * dot(*this, normal) * 2.0f;
}

inline float4 float4::refract(const float4& normal, float eta) const {
    float n_dot_i = dot(*this, normal);
    float k = 1.0f - eta * eta * (1.0f - n_dot_i * n_dot_i);
    if (k < 0.0f) {
        return float4(0.0f, 0.0f, 0.0f, 0.0f);
    } else {
        return *this * eta - normal * (eta * n_dot_i + sqrtf(k));
    }
}

inline float4 float4::operator-() const {
    return float4(-x, -y, -z, -w);
}

inline float4 float4::operator+(float scalar) const {
    return float4(x + scalar, y + scalar, z + scalar, w + scalar);
}

inline float4 float4::operator-(float scalar) const {
    return float4(x - scalar, y - scalar, z - scalar, w - scalar);
}

inline float4 float4::operator*(float scalar) const {
    return float4(x * scalar, y * scalar, z * scalar, w * scalar);
}

inline float4 float4::operator/(float scalar) const {
    return (*this) * (1.0f / scalar);
}

inline float4 float4::operator+(const float4& other) const {
    return float4(x + other.x, y + other.y, z + other.z, w + other.w);
}

inline float4 float4::operator-(const float4& other) const {
    return float4(x - other.x, y - other.y, z - other.z, w - other.w);
}

inline float4 float4::operator*(const float4& other) const {
    return float4(x * other.x, y * other.y, z * other.z, w * other.w);
}

inline float4 float4::operator/(const float4& other) const {
    return float4(x / other.x, y / other.y, z / other.z, w / other.w);
}

inline float4& float4::operator+=(float scalar) {
    return *this = *this + scalar;
}

inline float4& float4::operator-=(float scalar) {
    return *this = *this - scalar;
}

inline float4& float4::operator*=(float scalar) {
    return *this = *this * scalar;
}

inline float4& float4::operator/=(float scalar) {
    return *this = *this / scalar;
}

inline float4& float4::operator+=(const float4& other) {
    return *this = *this + other;
}

inline float4& float4::operator-=(const float4& other) {
    return *this = *this - other;
}

inline float4& float4::operator*=(const float4& other) {
    return *this = *this * other;
}

inline float4& float4::operator/=(const float4& other) {
    return *this = *this / other;
}

inline float& float4::operator[](int index) {
    return scalars[index];
}

inline float float4::operator[](int index) const {
    return scalars[index];
}

}

#endif
