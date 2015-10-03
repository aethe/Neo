#ifndef MAT2_HPP
#define MAT2_HPP

#include "neo.hpp"

namespace neo {

inline mat3 mat2::as_mat3() const {
    return mat3(v1.as_vec3(), v2.as_vec3(), vec3(0.0f, 0.0f, 1.0f));
}

inline mat4 mat2::as_mat4() const {
    return mat4(v1.as_vec4(), v2.as_vec4(), vec4(0.0f, 0.0f, 1.0f, 0.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f));
}

// inline std::string mat2::as_string() const {
//     return "[" + v1.as_string() + ", " + v2.as_string() + "]";
// }

inline mat2 mat2::transpose() const {
    return mat2(
        vec2(v1.x, v2.x),
        vec2(v1.y, v2.y)
    );
}

inline mat2 mat2::inverse() const {
    mat2 inv;

    inv.v1.x = v2.y;
    inv.v1.y = -v1.y;
    inv.v2.x = -v2.x;
    inv.v2.y = v1.x;

    float det = v1.x * inv.v1.x + v1.y * inv.v2.x;

    return inv / det;
}

inline float mat2::det() const {
    return v1.x * v2.y - v1.y * v2.x;
}

inline mat2 mat2::lerp(const mat2& other, float t) const {
    return mat2(v1.lerp(other.v1, t), v2.lerp(other.v2, t));
}

inline mat2 mat2::operator-() const {
    return mat2(-v1, -v2);
}

inline mat2 mat2::operator+(float scalar) const {
    return mat2(v1 + scalar, v2 + scalar);
}

inline mat2 mat2::operator-(float scalar) const {
    return mat2(v1 - scalar, v2 - scalar);
}

inline mat2 mat2::operator*(float scalar) const {
    return mat2(v1 * scalar, v2 * scalar);
}

inline mat2 mat2::operator/(float scalar) const {
    return (*this) * (1.0f / scalar);
}

inline vec2 mat2::operator*(const vec2& vector) const {
    return vec2(
        v1.x * vector.x + v2.x * vector.y,
        v1.y * vector.x + v2.y * vector.y
    );
}

inline mat2 mat2::operator+(const mat2& other) const {
    return mat2(v1 + other.v1, v2 + other.v2);
}

inline mat2 mat2::operator-(const mat2& other) const {
    return mat2(v1 - other.v1, v2 - other.v2);
}

inline mat2 mat2::operator*(const mat2& other) const {
    return mat2(
        vec2(
            v1.x * other.v1.x + v2.x * other.v1.y,
            v1.y * other.v1.x + v2.y * other.v1.y
        ),
        vec2(
            v1.x * other.v2.x + v2.x * other.v2.y,
            v1.y * other.v2.x + v2.y * other.v2.y
        )
    );
}

inline mat2& mat2::operator+=(float scalar) {
    return *this = *this + scalar;
}

inline mat2& mat2::operator-=(float scalar) {
    return *this = *this - scalar;
}

inline mat2& mat2::operator*=(float scalar) {
    return *this = *this * scalar;
}

inline mat2& mat2::operator/=(float scalar) {
    return *this = *this / scalar;
}

inline mat2& mat2::operator+=(const mat2& other) {
    return *this = *this + other;
}

inline mat2& mat2::operator-=(const mat2& other) {
    return *this = *this - other;
}

inline mat2& mat2::operator*=(const mat2& other) {
    return *this = *this * other;
}

}

#endif
