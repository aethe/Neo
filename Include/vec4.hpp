#ifndef VEC4_HPP
#define VEC4_HPP

#include "neo.hpp"

namespace neo {

inline vec2 vec4::as_vec2() const {
    return vec2(x, y);
}

inline vec3 vec4::as_vec3() const {
    return vec3(x, y, z);
}

// inline std::string vec4::as_string() const {
//     return "[" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + "]";
// }

inline float vec4::length() const {
    return sqrtf(dot(*this));
}

inline vec4 vec4::normalize() const {
    float inverse_sqrt = 1.0f / length();
    return (*this) * inverse_sqrt;
}

inline float vec4::dot(const vec4& other) const {
    return x * other.x + y * other.y + z * other.z + w * other.w;
}

inline vec4 vec4::proj(const vec4& other) const {
    return other * (dot(other) / other.dot(other));
}

inline vec4 vec4::perp(const vec4& other) const {
    return *this - proj(other);
}

inline vec4 vec4::reflect(const vec4& normal) const {
    return *this - normal * dot(normal) * 2.0f;
}

inline vec4 vec4::refract(const vec4& normal, float eta) const {
    float n_dot_i = dot(normal);
    float k = 1.0f - eta * eta * (1.0f - n_dot_i * n_dot_i);
    if (k < 0.0f) {
        return vec4(0.0f, 0.0f, 0.0f, 0.0f);
    } else {
        return *this * eta - normal * (eta * n_dot_i + sqrtf(k));
    }
}

inline vec4 vec4::lerp(const vec4& other, float t) const {
    return (*this) * (1.0f - t) + other * t;
}

inline vec4 vec4::operator-() const {
    return vec4(-x, -y, -z, -w);
}

inline vec4 vec4::operator+(float scalar) const {
    return vec4(x + scalar, y + scalar, z + scalar, w + scalar);
}

inline vec4 vec4::operator-(float scalar) const {
    return vec4(x - scalar, y - scalar, z - scalar, w - scalar);
}

inline vec4 vec4::operator*(float scalar) const {
    return vec4(x * scalar, y * scalar, z * scalar, w * scalar);
}

inline vec4 vec4::operator/(float scalar) const {
    return (*this) * (1.0f / scalar);
}

inline vec4 vec4::operator+(const vec4& other) const {
    return vec4(x + other.x, y + other.y, z + other.z, w + other.w);
}

inline vec4 vec4::operator-(const vec4& other) const {
    return vec4(x - other.x, y - other.y, z - other.z, w - other.w);
}

inline vec4 vec4::operator*(const vec4& other) const {
    return vec4(x * other.x, y * other.y, z * other.z, w * other.w);
}

inline vec4 vec4::operator/(const vec4& other) const {
    return vec4(x / other.x, y / other.y, z / other.z, w / other.w);
}

inline vec4& vec4::operator+=(float scalar) {
    return *this = *this + scalar;
}

inline vec4& vec4::operator-=(float scalar) {
    return *this = *this - scalar;
}

inline vec4& vec4::operator*=(float scalar) {
    return *this = *this * scalar;
}

inline vec4& vec4::operator/=(float scalar) {
    return *this = *this / scalar;
}

inline vec4& vec4::operator+=(const vec4& other) {
    return *this = *this + other;
}

inline vec4& vec4::operator-=(const vec4& other) {
    return *this = *this - other;
}

inline vec4& vec4::operator*=(const vec4& other) {
    return *this = *this * other;
}

inline vec4& vec4::operator/=(const vec4& other) {
    return *this = *this / other;
}

}

#endif
