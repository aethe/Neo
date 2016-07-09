#ifndef FLOAT2_HPP
#define FLOAT2_HPP

#include "neo.hpp"

namespace neo {

NEO_FUNC_DEF float3 float2::as_float3(float z) const {
    return float3(x, y, z);
}

NEO_FUNC_DEF float4 float2::as_float4(float z, float w) const {
    return float4(x, y, z, w);
}

NEO_FUNC_DEF float float2::length() const {
    return sqrtf(dot(*this, *this));
}

NEO_FUNC_DEF float2 float2::normalize() const {
    float inverse_sqrt = 1.0f / length();
    return (*this) * inverse_sqrt;
}

NEO_FUNC_DEF float2 float2::proj(const float2& other) const {
    return other * (dot(*this, other) / dot(other, other));
}

NEO_FUNC_DEF float2 float2::perp(const float2& other) const {
    return *this - proj(other);
}

NEO_FUNC_DEF float2 float2::reflect(const float2& normal) const {
    return *this - normal * dot(*this, normal) * 2.0f;
}

NEO_FUNC_DEF float2 float2::refract(const float2& normal, float eta) const {
    float n_dot_i = dot(*this, normal);
    float k = 1.0f - eta * eta * (1.0f - n_dot_i * n_dot_i);
    if (k < 0.0f) {
        return float2(0.0f, 0.0f);
    } else {
        return *this * eta - normal * (eta * n_dot_i + sqrtf(k));
    }
}

NEO_FUNC_DEF float2 float2::operator-() const {
    return float2(-x, -y);
}

NEO_FUNC_DEF float2 float2::operator+(float scalar) const {
    return float2(x + scalar, y + scalar);
}

NEO_FUNC_DEF float2 float2::operator-(float scalar) const {
    return float2(x - scalar, y - scalar);
}

NEO_FUNC_DEF float2 float2::operator*(float scalar) const {
    return float2(x * scalar, y * scalar);
}

NEO_FUNC_DEF float2 float2::operator/(float scalar) const {
    return (*this) * (1.0f / scalar);
}

NEO_FUNC_DEF float2 float2::operator+(const float2& other) const {
    return float2(x + other.x, y + other.y);
}

NEO_FUNC_DEF float2 float2::operator-(const float2& other) const {
    return float2(x - other.x, y - other.y);
}

NEO_FUNC_DEF float2 float2::operator*(const float2& other) const {
    return float2(x * other.x, y * other.y);
}

NEO_FUNC_DEF float2 float2::operator/(const float2& other) const {
    return float2(x / other.x, y / other.y);
}

NEO_FUNC_DEF float2& float2::operator+=(float scalar) {
    return *this = *this + scalar;
}

NEO_FUNC_DEF float2& float2::operator-=(float scalar) {
    return *this = *this - scalar;
}

NEO_FUNC_DEF float2& float2::operator*=(float scalar) {
    return *this = *this * scalar;
}

NEO_FUNC_DEF float2& float2::operator/=(float scalar) {
    return *this = *this / scalar;
}

NEO_FUNC_DEF float2& float2::operator+=(const float2& other) {
    return *this = *this + other;
}

NEO_FUNC_DEF float2& float2::operator-=(const float2& other) {
    return *this = *this - other;
}

NEO_FUNC_DEF float2& float2::operator*=(const float2& other) {
    return *this = *this * other;
}

NEO_FUNC_DEF float2& float2::operator/=(const float2& other) {
    return *this = *this / other;
}

NEO_FUNC_DEF float& float2::operator[](int index) {
    return scalars[index];
}

NEO_FUNC_DEF float float2::operator[](int index) const {
    return scalars[index];
}

}

#endif
