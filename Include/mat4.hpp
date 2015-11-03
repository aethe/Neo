#ifndef MAT4_HPP
#define MAT4_HPP

#include "neo.hpp"

namespace neo {

inline mat4 mat4::scale(const vec3& vector) {
    return mat4(
        vec4(vector.x, 0.0f, 0.0f, 0.0f),
        vec4(0.0f, vector.y, 0.0f, 0.0f),
        vec4(0.0f, 0.0f, vector.z, 0.0f),
        vec4(0.0f, 0.0f, 0.0f, 1.0f)
    );
}

inline mat4 mat4::translation(const vec3& vector) {
    return mat4(
        vec4(1.0f, 0.0f, 0.0f, 0.0f),
        vec4(0.0f, 1.0f, 0.0f, 0.0f),
        vec4(0.0f, 0.0f, 1.0f, 0.0f),
        vector.as_vec4(1.0f)
    );
}

inline mat4 mat4::rotation(const vec3& vector, const angle& alpha) {
    float cos = alpha.cos();
    float sin = alpha.sin();

    return mat4(
        vec4(cos + (1 - cos) * vector.x * vector.x, (1 - cos) * vector.x * vector.y + sin * vector.z, (1 - cos) * vector.x * vector.z - sin * vector.y, 0.0f),
        vec4((1 - cos) * vector.x * vector.y - sin * vector.z, cos + (1 - cos) * vector.y * vector.y, (1 - cos) * vector.y * vector.z + sin * vector.x, 0.0f),
        vec4((1 - cos) * vector.x * vector.z + sin * vector.y, (1 - cos) * vector.y * vector.z + sin * vector.x, cos + (1 - cos) * vector.z * vector.z, 0.0f),
        vec4(0.0f, 0.0f, 0.0f, 1.0f)
    );
}

inline mat4 mat4::rotation_x(const angle& alpha) {
    float cos = alpha.cos();
    float sin = alpha.sin();

    return mat4(
        vec4(1.0f, 0.0f, 0.0f, 0.0f),
        vec4(0.0f, cos, -sin, 0.0f),
        vec4(0.0f, sin, cos, 0.0f),
        vec4(0.0f, 0.0f, 0.0f, 1.0f)
    );
}

inline mat4 mat4::rotation_y(const angle& alpha) {
    float cos = alpha.cos();
    float sin = alpha.sin();

    return mat4(
        vec4(cos, 0.0f, sin, 0.0f),
        vec4(0.0f, 1.0f, 0.0f, 0.0f),
        vec4(-sin, 0.0f, cos, 0.0f),
        vec4(0.0f, 0.0f, 0.0f, 1.0f)
    );
}

inline mat4 mat4::rotation_z(const angle& alpha) {
    float cos = alpha.cos();
    float sin = alpha.sin();

    return mat4(
        vec4(cos, -sin, 0.0f, 0.0f),
        vec4(sin, cos, 0.0f, 0.0f),
        vec4(0.0f, 0.0f, 1.0f, 0.0f),
        vec4(0.0f, 0.0f, 0.0f, 1.0f)
    );
}

inline mat4 mat4::look_at(const vec3& origin, const vec3& target, const vec3& up) {
    vec3 z_axis = (origin - target).normalize();
    vec3 x_axis = cross(up, z_axis).normalize();
    vec3 y_axis = cross(z_axis, x_axis);

    return mat4(
        vec4(x_axis.x, y_axis.x, z_axis.x, 0.0f),
        vec4(x_axis.y, y_axis.y, z_axis.y, 0.0f),
        vec4(x_axis.z, y_axis.z, z_axis.z, 0.0f),
        vec4(dot(-x_axis, origin), dot(-y_axis, origin), dot(-z_axis, origin), 1.0f)
    );
}

inline mat2 mat4::as_mat2() const {
    return mat2(v1.as_vec2(), v2.as_vec2());
}

inline mat3 mat4::as_mat3() const {
    return mat3(v1.as_vec3(), v2.as_vec3(), v3.as_vec3());
}

inline mat4 mat4::transpose() const {
    return mat4(
        vec4(v1.x, v2.x, v3.x, v4.x),
        vec4(v1.y, v2.y, v3.y, v4.y),
        vec4(v1.z, v2.z, v3.z, v4.z),
        vec4(v1.w, v2.w, v3.w, v4.w)
    );
}

inline mat4 mat4::inverse() const {
    mat4 inv;

    inv.v1.x = v2.y * (v3.z * v4.w - v3.w * v4.z) + v2.z * (v3.w * v4.y - v3.y * v4.w) + v2.w * (v3.y * v4.z - v3.z * v4.y);
    inv.v1.y = v1.y * (v3.w * v4.z - v3.z * v4.w) + v1.z * (v3.y * v4.w - v3.w * v4.y) + v1.w * (v3.z * v4.y - v3.y * v4.z);
    inv.v1.z = v1.y * (v2.z * v4.w - v2.w * v4.z) + v1.z * (v2.w * v4.y - v2.y * v4.w) + v1.w * (v2.y * v4.z - v2.z * v4.y);
    inv.v1.w = v1.y * (v2.w * v3.z - v2.z * v3.w) + v1.z * (v2.y * v3.w - v2.w * v3.y) + v1.w * (v2.z * v3.y - v2.y * v3.z);

    inv.v2.x = v2.x * (v3.w * v4.z - v3.z * v4.w) + v2.z * (v3.x * v4.w - v3.w * v4.x) + v2.w * (v3.z * v4.x - v3.x * v4.z);
    inv.v2.y = v1.x * (v3.z * v4.w - v3.w * v4.z) + v1.z * (v3.w * v4.x - v3.x * v4.w) + v1.w * (v3.x * v4.z - v3.z * v4.x);
    inv.v2.z = v1.x * (v2.w * v4.z - v2.z * v4.w) + v1.z * (v2.x * v4.w - v2.w * v4.x) + v1.w * (v2.z * v4.x - v2.x * v4.z);
    inv.v2.w = v1.x * (v2.z * v3.w - v2.w * v3.z) + v1.z * (v2.w * v3.x - v2.x * v3.w) + v1.w * (v2.x * v3.z - v2.z * v3.x);

    inv.v3.x = v2.x * (v3.y * v4.w - v3.w * v4.y) + v2.y * (v3.w * v4.x - v3.x * v4.w) + v2.w * (v3.x * v4.y - v3.y * v4.x);
    inv.v3.y = v1.x * (v3.w * v4.y - v3.y * v4.w) + v1.y * (v3.x * v4.w - v3.w * v4.x) + v1.w * (v3.y * v4.x - v3.x * v4.y);
    inv.v3.z = v1.x * (v2.y * v4.w - v2.w * v4.y) + v1.y * (v2.w * v4.x - v2.x * v4.w) + v1.w * (v2.x * v4.y - v2.y * v4.x);
    inv.v3.w = v1.x * (v2.w * v3.y - v2.y * v3.w) + v1.y * (v2.x * v3.w - v2.w * v3.x) + v1.w * (v2.y * v3.x - v2.x * v3.y);

    inv.v4.x = v2.x * (v3.z * v4.y - v3.y * v4.z) + v2.y * (v3.x * v4.z - v3.z * v4.x) + v2.z * (v3.y * v4.x - v3.x * v4.y);
    inv.v4.y = v1.x * (v3.y * v4.z - v3.z * v4.y) + v1.y * (v3.z * v4.x - v3.x * v4.z) + v1.z * (v3.x * v4.y - v3.y * v4.x);
    inv.v4.z = v1.x * (v2.z * v4.y - v2.y * v4.z) + v1.y * (v2.x * v4.z - v2.z * v4.x) + v1.z * (v2.y * v4.x - v2.x * v4.y);
    inv.v4.w = v1.x * (v2.y * v3.z - v2.z * v3.y) + v1.y * (v2.z * v3.x - v2.x * v3.z) + v1.z * (v2.x * v3.y - v2.y * v3.x);

    float det = v1.x * inv.v1.x + v1.y * inv.v2.x + v1.z * inv.v3.x + v1.w * inv.v4.x;

    return inv / det;
}

inline float mat4::det() const {
    return v1.x * (v2.y * (v3.z * v4.w - v3.w * v4.z) - v2.z * (v3.y * v4.w - v3.w * v4.y) + v2.w * (v3.y * v4.z - v3.z * v4.y))
        - v1.y * (v2.x * (v3.z * v4.w - v3.w * v4.z) - v2.z * (v3.x * v4.w - v3.w * v4.x) + v2.w * (v3.x * v4.z - v3.z * v4.x))
        + v1.z * (v2.x * (v3.y * v4.w - v3.w * v4.y) - v2.y * (v3.x * v4.w - v3.w * v4.x) + v2.w * (v3.x * v4.y - v3.y * v4.x))
        - v1.w * (v2.x * (v3.y * v4.z - v3.z * v4.y) - v2.y * (v3.x * v4.z - v3.z * v4.x) + v2.z * (v3.x * v4.y - v3.y * v4.x));
}

inline mat4 mat4::operator-() const {
    return mat4(-v1, -v2, -v3, -v4);
}

inline mat4 mat4::operator+(float scalar) const {
    return mat4(v1 + scalar, v2 + scalar, v3 + scalar, v4 + scalar);
}

inline mat4 mat4::operator-(float scalar) const {
    return mat4(v1 - scalar, v2 - scalar, v3 - scalar, v4 - scalar);
}

inline mat4 mat4::operator*(float scalar) const {
    return mat4(v1 * scalar, v2 * scalar, v3 * scalar, v4 * scalar);
}

inline mat4 mat4::operator/(float scalar) const {
    return (*this) * (1.0f / scalar);
}

inline vec4 mat4::operator*(const vec4& vector) const {
    return vec4(
        v1.x * vector.x + v2.x * vector.y + v3.x * vector.z + v4.x * vector.w,
        v1.y * vector.x + v2.y * vector.y + v3.y * vector.z + v4.y * vector.w,
        v1.z * vector.x + v2.z * vector.y + v3.z * vector.z + v4.z * vector.w,
        v1.w * vector.x + v2.w * vector.y + v3.w * vector.z + v4.w * vector.w
    );
}

inline mat4 mat4::operator+(const mat4& other) const {
    return mat4(v1 + other.v1, v2 + other.v2, v3 + other.v3, v4 + other.v4);
}

inline mat4 mat4::operator-(const mat4& other) const {
    return mat4(v1 - other.v1, v2 - other.v2, v3 - other.v3, v4 - other.v4);
}

inline mat4 mat4::operator*(const mat4& other) const {
    return mat4(
        vec4(
            v1.x * other.v1.x + v2.x * other.v1.y + v3.x * other.v1.z + v4.x * other.v1.w,
            v1.y * other.v1.x + v2.y * other.v1.y + v3.y * other.v1.z + v4.y * other.v1.w,
            v1.z * other.v1.x + v2.z * other.v1.y + v3.z * other.v1.z + v4.z * other.v1.w,
            v1.w * other.v1.x + v2.w * other.v1.y + v3.w * other.v1.z + v4.w * other.v1.w
        ),
        vec4(
            v1.x * other.v2.x + v2.x * other.v2.y + v3.x * other.v2.z + v4.x * other.v2.w,
            v1.y * other.v2.x + v2.y * other.v2.y + v3.y * other.v2.z + v4.y * other.v2.w,
            v1.z * other.v2.x + v2.z * other.v2.y + v3.z * other.v2.z + v4.z * other.v2.w,
            v1.w * other.v2.x + v2.w * other.v2.y + v3.w * other.v2.z + v4.w * other.v2.w
        ),
        vec4(
            v1.x * other.v3.x + v2.x * other.v3.y + v3.x * other.v3.z + v4.x * other.v3.w,
            v1.y * other.v3.x + v2.y * other.v3.y + v3.y * other.v3.z + v4.y * other.v3.w,
            v1.z * other.v3.x + v2.z * other.v3.y + v3.z * other.v3.z + v4.z * other.v3.w,
            v1.w * other.v3.x + v2.w * other.v3.y + v3.w * other.v3.z + v4.w * other.v3.w
        ),
        vec4(
            v1.x * other.v4.x + v2.x * other.v4.y + v3.x * other.v4.z + v4.x * other.v4.w,
            v1.y * other.v4.x + v2.y * other.v4.y + v3.y * other.v4.z + v4.y * other.v4.w,
            v1.z * other.v4.x + v2.z * other.v4.y + v3.z * other.v4.z + v4.z * other.v4.w,
            v1.w * other.v4.x + v2.w * other.v4.y + v3.w * other.v4.z + v4.w * other.v4.w
        )
    );
}

inline mat4& mat4::operator+=(float scalar) {
    return *this = *this + scalar;
}

inline mat4& mat4::operator-=(float scalar) {
    return *this = *this - scalar;
}

inline mat4& mat4::operator*=(float scalar) {
    return *this = *this * scalar;
}

inline mat4& mat4::operator/=(float scalar) {
    return *this = *this / scalar;
}

inline mat4& mat4::operator+=(const mat4& other) {
    return *this = *this + other;
}

inline mat4& mat4::operator-=(const mat4& other) {
    return *this = *this - other;
}

inline mat4& mat4::operator*=(const mat4& other) {
    return *this = *this * other;
}

}

#endif
