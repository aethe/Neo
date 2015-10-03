#ifndef VEC2_HPP
#define VEC2_HPP

#include "neo.hpp"

namespace neo {

inline vec3 vec2::as_vec3(float z) const {
    return vec3(x, y, z);
}

inline vec4 vec2::as_vec4(float z, float w) const {
    return vec4(x, y, z, w);
}

// inline std::string vec2::as_string() const {
//     return "[" + std::to_string(x) + ", " + std::to_string(y) + "]";
// }

inline float vec2::length() const {
    return sqrtf(dot(*this));
}

inline vec2 vec2::normalize() const {
    float inverse_sqrt = 1.0f / length();
    return (*this) * inverse_sqrt;
}

inline float vec2::dot(const vec2& other) const {
    return x * other.x + y * other.y;
}

inline vec2 vec2::proj(const vec2& other) const {
    return other * (dot(other) / other.dot(other));
}

inline vec2 vec2::perp(const vec2& other) const {
    return *this - proj(other);
}

inline vec2 vec2::reflect(const vec2& normal) const {
    return *this - normal * dot(normal) * 2.0f;
}

inline vec2 vec2::refract(const vec2& normal, float eta) const {
    float n_dot_i = dot(normal);
    float k = 1.0f - eta * eta * (1.0f - n_dot_i * n_dot_i);
    if (k < 0.0f) {
        return vec2(0.0f, 0.0f);
    } else {
        return *this * eta - normal * (eta * n_dot_i + sqrtf(k));
    }
}

inline vec2 vec2::lerp(const vec2& other, float t) const {
    return (*this) * (1.0f - t) + other * t;
}

inline vec2 vec2::operator-() const {
    return vec2(-x, -y);
}

inline vec2 vec2::operator+(float scalar) const {
    return vec2(x + scalar, y + scalar);
}

inline vec2 vec2::operator-(float scalar) const {
    return vec2(x - scalar, y - scalar);
}

inline vec2 vec2::operator*(float scalar) const {
    return vec2(x * scalar, y * scalar);
}

inline vec2 vec2::operator/(float scalar) const {
    return (*this) * (1.0f / scalar);
}

inline vec2 vec2::operator+(const vec2& other) const {
    return vec2(x + other.x, y + other.y);
}

inline vec2 vec2::operator-(const vec2& other) const {
    return vec2(x - other.x, y - other.y);
}

inline vec2 vec2::operator*(const vec2& other) const {
    return vec2(x * other.x, y * other.y);
}

inline vec2 vec2::operator/(const vec2& other) const {
    return vec2(x / other.x, y / other.y);
}

inline vec2& vec2::operator+=(float scalar) {
    return *this = *this + scalar;
}

inline vec2& vec2::operator-=(float scalar) {
    return *this = *this - scalar;
}

inline vec2& vec2::operator*=(float scalar) {
    return *this = *this * scalar;
}

inline vec2& vec2::operator/=(float scalar) {
    return *this = *this / scalar;
}

inline vec2& vec2::operator+=(const vec2& other) {
    return *this = *this + other;
}

inline vec2& vec2::operator-=(const vec2& other) {
    return *this = *this - other;
}

inline vec2& vec2::operator*=(const vec2& other) {
    return *this = *this * other;
}

inline vec2& vec2::operator/=(const vec2& other) {
    return *this = *this / other;
}

}

#endif
