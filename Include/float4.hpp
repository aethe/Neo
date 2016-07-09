#ifndef FLOAT4_HPP
#define FLOAT4_HPP

#include "neo.hpp"

namespace neo {

NEO_FUNC_DEF float2 float4::as_float2() const {
    return float2(x, y);
}

NEO_FUNC_DEF float3 float4::as_float3() const {
    return float3(x, y, z);
}

NEO_FUNC_DEF float float4::length() const {
    return sqrtf(dot(*this, *this));
}

NEO_FUNC_DEF float4 float4::normalize() const {
    float inverse_sqrt = 1.0f / length();
    return (*this) * inverse_sqrt;
}

NEO_FUNC_DEF float4 float4::proj(const float4& other) const {
    return other * (dot(*this, other) / dot(other, other));
}

NEO_FUNC_DEF float4 float4::perp(const float4& other) const {
    return *this - proj(other);
}

NEO_FUNC_DEF float4 float4::reflect(const float4& normal) const {
    return *this - normal * dot(*this, normal) * 2.0f;
}

NEO_FUNC_DEF float4 float4::refract(const float4& normal, float eta) const {
    float n_dot_i = dot(*this, normal);
    float k = 1.0f - eta * eta * (1.0f - n_dot_i * n_dot_i);
    if (k < 0.0f) {
        return float4(0.0f, 0.0f, 0.0f, 0.0f);
    } else {
        return *this * eta - normal * (eta * n_dot_i + sqrtf(k));
    }
}

NEO_FUNC_DEF float4 float4::operator-() const {
    return float4(-x, -y, -z, -w);
}

NEO_FUNC_DEF float4 float4::operator+(float scalar) const {
    return float4(x + scalar, y + scalar, z + scalar, w + scalar);
}

NEO_FUNC_DEF float4 float4::operator-(float scalar) const {
    return float4(x - scalar, y - scalar, z - scalar, w - scalar);
}

NEO_FUNC_DEF float4 float4::operator*(float scalar) const {
    return float4(x * scalar, y * scalar, z * scalar, w * scalar);
}

NEO_FUNC_DEF float4 float4::operator/(float scalar) const {
    return (*this) * (1.0f / scalar);
}

NEO_FUNC_DEF float4 float4::operator+(const float4& other) const {
    return float4(x + other.x, y + other.y, z + other.z, w + other.w);
}

NEO_FUNC_DEF float4 float4::operator-(const float4& other) const {
    return float4(x - other.x, y - other.y, z - other.z, w - other.w);
}

NEO_FUNC_DEF float4 float4::operator*(const float4& other) const {
    return float4(x * other.x, y * other.y, z * other.z, w * other.w);
}

NEO_FUNC_DEF float4 float4::operator/(const float4& other) const {
    return float4(x / other.x, y / other.y, z / other.z, w / other.w);
}

NEO_FUNC_DEF float4& float4::operator+=(float scalar) {
    return *this = *this + scalar;
}

NEO_FUNC_DEF float4& float4::operator-=(float scalar) {
    return *this = *this - scalar;
}

NEO_FUNC_DEF float4& float4::operator*=(float scalar) {
    return *this = *this * scalar;
}

NEO_FUNC_DEF float4& float4::operator/=(float scalar) {
    return *this = *this / scalar;
}

NEO_FUNC_DEF float4& float4::operator+=(const float4& other) {
    return *this = *this + other;
}

NEO_FUNC_DEF float4& float4::operator-=(const float4& other) {
    return *this = *this - other;
}

NEO_FUNC_DEF float4& float4::operator*=(const float4& other) {
    return *this = *this * other;
}

NEO_FUNC_DEF float4& float4::operator/=(const float4& other) {
    return *this = *this / other;
}

NEO_FUNC_DEF float& float4::operator[](int index) {
    return scalars[index];
}

NEO_FUNC_DEF float float4::operator[](int index) const {
    return scalars[index];
}

}

#endif
