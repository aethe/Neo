#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "neo.hpp"

namespace neo {

inline float dot(const vec2& lhs, const vec2& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

inline float dot(const vec3& lhs, const vec3& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

inline float dot(const vec4& lhs, const vec4& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

inline vec3 cross(const vec3& lhs, const vec3& rhs) {
    float new_x = lhs.y * rhs.z - lhs.z * rhs.y;
    float new_y = lhs.z * rhs.x - lhs.x * rhs.z;
    float new_z = lhs.x * rhs.y - lhs.y * rhs.x;
    return vec3(new_x, new_y, new_z);
}

inline vec2 lerp(const vec2& lhs, const vec2& rhs, float t) {
    return lhs * (1.0f - t) + rhs * t;
}

inline vec3 lerp(const vec3& lhs, const vec3& rhs, float t) {
    return lhs * (1.0f - t) + rhs * t;
}

inline vec4 lerp(const vec4& lhs, const vec4& rhs, float t) {
    return lhs * (1.0f - t) + rhs * t;
}

inline mat2 lerp(const mat2& lhs, const mat2& rhs, float t) {
    return mat2(lerp(lhs.v1, rhs.v1, t), lerp(lhs.v2, rhs.v2, t));
}

inline mat3 lerp(const mat3& lhs, const mat3& rhs, float t) {
    return mat3(lerp(lhs.v1, rhs.v1, t), lerp(lhs.v2, rhs.v2, t), lerp(lhs.v3, rhs.v3, t));
}

inline mat4 lerp(const mat4& lhs, const mat4& rhs, float t) {
    return mat4(lerp(lhs.v1, rhs.v1, t), lerp(lhs.v2, rhs.v2, t), lerp(lhs.v3, rhs.v3, t), lerp(lhs.v4, rhs.v4, t));
}

}

#endif
