#ifndef VEC3_HPP
#define VEC3_HPP

#include "neo.hpp"

namespace neo {

inline vec2 vec3::as_vec2() const {
    return vec2(x, y);
}

inline vec4 vec3::as_vec4(float w) const {
    return vec4(x, y, z, w);
}

inline float vec3::length() const {
    return sqrtf(dot(*this, *this));
}

inline vec3 vec3::normalize() const {
    float inverse_sqrt = 1.0f / length();
    return (*this) * inverse_sqrt;
}

inline vec3 vec3::proj(const vec3& other) const {
    return other * (dot(*this, other) / dot(other, other));
}

inline vec3 vec3::perp(const vec3& other) const {
    return *this - proj(other);
}

inline vec3 vec3::reflect(const vec3& normal) const {
    return *this - normal * dot(*this, normal) * 2.0f;
}

inline vec3 vec3::refract(const vec3& normal, float eta) const {
    float n_dot_i = dot(*this, normal);
    float k = 1.0f - eta * eta * (1.0f - n_dot_i * n_dot_i);
    if (k < 0.0f) {
        return vec3(0.0f, 0.0f, 0.0f);
    } else {
        return *this * eta - normal * (eta * n_dot_i + sqrtf(k));
    }
}

inline vec3 vec3::operator-() const {
    return vec3(-x, -y, -z);
}

inline vec3 vec3::operator+(float scalar) const {
    return vec3(x + scalar, y + scalar, z + scalar);
}

inline vec3 vec3::operator-(float scalar) const {
    return vec3(x - scalar, y - scalar, z - scalar);
}

inline vec3 vec3::operator*(float scalar) const {
    return vec3(x * scalar, y * scalar, z * scalar);
}

inline vec3 vec3::operator/(float scalar) const {
    return (*this) * (1.0f / scalar);
}

inline vec3 vec3::operator+(const vec3& other) const {
    return vec3(x + other.x, y + other.y, z + other.z);
}

inline vec3 vec3::operator-(const vec3& other) const {
    return vec3(x - other.x, y - other.y, z - other.z);
}

inline vec3 vec3::operator*(const vec3& other) const {
    return vec3(x * other.x, y * other.y, z * other.z);
}

inline vec3 vec3::operator/(const vec3& other) const {
    return vec3(x / other.x, y / other.y, z / other.z);
}

inline vec3& vec3::operator+=(float scalar) {
    return *this = *this + scalar;
}

inline vec3& vec3::operator-=(float scalar) {
    return *this = *this - scalar;
}

inline vec3& vec3::operator*=(float scalar) {
    return *this = *this * scalar;
}

inline vec3& vec3::operator/=(float scalar) {
    return *this = *this / scalar;
}

inline vec3& vec3::operator+=(const vec3& other) {
    return *this = *this + other;
}

inline vec3& vec3::operator-=(const vec3& other) {
    return *this = *this - other;
}

inline vec3& vec3::operator*=(const vec3& other) {
    return *this = *this * other;
}

inline vec3& vec3::operator/=(const vec3& other) {
    return *this = *this / other;
}

}

#endif
