#ifndef MAT3_HPP
#define MAT3_HPP

#include "neo.hpp"

namespace neo {

inline mat2 mat3::as_mat2() const {
    return mat2(v1.as_vec2(), v2.as_vec2());
}

inline mat4 mat3::as_mat4() const {
    return mat4(v1.as_vec4(), v2.as_vec4(), v3.as_vec4(), vec4(0.0f, 0.0f, 0.0f, 1.0f));
}

inline mat3 mat3::transpose() const {
    return mat3(
        vec3(v1.x, v2.x, v3.x),
        vec3(v1.y, v2.y, v3.y),
        vec3(v1.z, v2.z, v3.z)
    );
}

inline mat3 mat3::inverse() const {
    mat3 inv;

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

inline float mat3::det() const {
    return v1.x * (v2.y * v3.z - v2.z * v3.y) + v1.y * (v2.z * v3.x - v2.x * v3.z) + v1.z * (v2.x * v3.y - v2.y * v3.x);
}

inline mat3 mat3::operator-() const {
    return mat3(-v1, -v2, -v3);
}

inline mat3 mat3::operator+(float scalar) const {
    return mat3(v1 + scalar, v2 + scalar, v3 + scalar);
}

inline mat3 mat3::operator-(float scalar) const {
    return mat3(v1 - scalar, v2 - scalar, v3 - scalar);
}

inline mat3 mat3::operator*(float scalar) const {
    return mat3(v1 * scalar, v2 * scalar, v3 * scalar);
}

inline mat3 mat3::operator/(float scalar) const {
    return (*this) * (1.0f / scalar);
}

inline vec3 mat3::operator*(const vec3& vector) const {
    return vec3(
        v1.x * vector.x + v2.x * vector.y + v3.x * vector.z,
        v1.y * vector.x + v2.y * vector.y + v3.y * vector.z,
        v1.z * vector.x + v2.z * vector.y + v3.z * vector.z
    );
}

inline mat3 mat3::operator+(const mat3& other) const {
    return mat3(v1 + other.v1, v2 + other.v2, v3 + other.v3);
}

inline mat3 mat3::operator-(const mat3& other) const {
    return mat3(v1 - other.v1, v2 - other.v2, v3 - other.v3);
}

inline mat3 mat3::operator*(const mat3& other) const {
    return mat3(
        vec3(
            v1.x * other.v1.x + v2.x * other.v1.y + v3.x * other.v1.z,
            v1.y * other.v1.x + v2.y * other.v1.y + v3.y * other.v1.z,
            v1.z * other.v1.x + v2.z * other.v1.y + v3.z * other.v1.z
        ),
        vec3(
            v1.x * other.v2.x + v2.x * other.v2.y + v3.x * other.v2.z,
            v1.y * other.v2.x + v2.y * other.v2.y + v3.y * other.v2.z,
            v1.z * other.v2.x + v2.z * other.v2.y + v3.z * other.v2.z
        ),
        vec3(
            v1.x * other.v3.x + v2.x * other.v3.y + v3.x * other.v3.z,
            v1.y * other.v3.x + v2.y * other.v3.y + v3.y * other.v3.z,
            v1.z * other.v3.x + v2.z * other.v3.y + v3.z * other.v3.z
        )
    );
}

inline mat3& mat3::operator+=(float scalar) {
    return *this = *this + scalar;
}

inline mat3& mat3::operator-=(float scalar) {
    return *this = *this - scalar;
}

inline mat3& mat3::operator*=(float scalar) {
    return *this = *this * scalar;
}

inline mat3& mat3::operator/=(float scalar) {
    return *this = *this / scalar;
}

inline mat3& mat3::operator+=(const mat3& other) {
    return *this = *this + other;
}

inline mat3& mat3::operator-=(const mat3& other) {
    return *this = *this - other;
}

inline mat3& mat3::operator*=(const mat3& other) {
    return *this = *this * other;
}

}

#endif
