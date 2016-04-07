#ifndef FLOAT4X4_HPP
#define FLOAT4X4_HPP

#include "neo.hpp"

namespace neo {

inline float4x4 float4x4::scale(const float3& vector) {
    return float4x4(
        float4(vector.x, 0.0f, 0.0f, 0.0f),
        float4(0.0f, vector.y, 0.0f, 0.0f),
        float4(0.0f, 0.0f, vector.z, 0.0f),
        float4(0.0f, 0.0f, 0.0f, 1.0f)
    );
}

inline float4x4 float4x4::translation(const float3& vector) {
    return float4x4(
        float4(1.0f, 0.0f, 0.0f, 0.0f),
        float4(0.0f, 1.0f, 0.0f, 0.0f),
        float4(0.0f, 0.0f, 1.0f, 0.0f),
        vector.as_float4(1.0f)
    );
}

inline float4x4 float4x4::rotation(const float3& vector, const angle& alpha) {
    float cos = alpha.cos();
    float sin = alpha.sin();

    return float4x4(
        float4(cos + (1 - cos) * vector.x * vector.x, (1 - cos) * vector.x * vector.y + sin * vector.z, (1 - cos) * vector.x * vector.z - sin * vector.y, 0.0f),
        float4((1 - cos) * vector.x * vector.y - sin * vector.z, cos + (1 - cos) * vector.y * vector.y, (1 - cos) * vector.y * vector.z + sin * vector.x, 0.0f),
        float4((1 - cos) * vector.x * vector.z + sin * vector.y, (1 - cos) * vector.y * vector.z + sin * vector.x, cos + (1 - cos) * vector.z * vector.z, 0.0f),
        float4(0.0f, 0.0f, 0.0f, 1.0f)
    );
}

inline float4x4 float4x4::rotation_x(const angle& alpha) {
    float cos = alpha.cos();
    float sin = alpha.sin();

    return float4x4(
        float4(1.0f, 0.0f, 0.0f, 0.0f),
        float4(0.0f, cos, -sin, 0.0f),
        float4(0.0f, sin, cos, 0.0f),
        float4(0.0f, 0.0f, 0.0f, 1.0f)
    );
}

inline float4x4 float4x4::rotation_y(const angle& alpha) {
    float cos = alpha.cos();
    float sin = alpha.sin();

    return float4x4(
        float4(cos, 0.0f, sin, 0.0f),
        float4(0.0f, 1.0f, 0.0f, 0.0f),
        float4(-sin, 0.0f, cos, 0.0f),
        float4(0.0f, 0.0f, 0.0f, 1.0f)
    );
}

inline float4x4 float4x4::rotation_z(const angle& alpha) {
    float cos = alpha.cos();
    float sin = alpha.sin();

    return float4x4(
        float4(cos, -sin, 0.0f, 0.0f),
        float4(sin, cos, 0.0f, 0.0f),
        float4(0.0f, 0.0f, 1.0f, 0.0f),
        float4(0.0f, 0.0f, 0.0f, 1.0f)
    );
}

inline float4x4 float4x4::look_at(const float3& origin, const float3& target, const float3& up) {
    float3 z_axis = (origin - target).normalize();
    float3 x_axis = cross(up, z_axis).normalize();
    float3 y_axis = cross(z_axis, x_axis);

    return float4x4(
        float4(x_axis.x, y_axis.x, z_axis.x, 0.0f),
        float4(x_axis.y, y_axis.y, z_axis.y, 0.0f),
        float4(x_axis.z, y_axis.z, z_axis.z, 0.0f),
        float4(dot(-x_axis, origin), dot(-y_axis, origin), dot(-z_axis, origin), 1.0f)
    );
}

inline float2x2 float4x4::as_float2x2() const {
    return float2x2(c0.as_float2(), c1.as_float2());
}

inline float3x3 float4x4::as_float3x3() const {
    return float3x3(c0.as_float3(), c1.as_float3(), c2.as_float3());
}

inline float4x4 float4x4::transpose() const {
    return float4x4(
        float4(c0.x, c1.x, c2.x, c3.x),
        float4(c0.y, c1.y, c2.y, c3.y),
        float4(c0.z, c1.z, c2.z, c3.z),
        float4(c0.w, c1.w, c2.w, c3.w)
    );
}

inline float4x4 float4x4::inverse() const {
    float4x4 inv;

    inv.c0.x = c1.y * (c2.z * c3.w - c2.w * c3.z) + c1.z * (c2.w * c3.y - c2.y * c3.w) + c1.w * (c2.y * c3.z - c2.z * c3.y);
    inv.c0.y = c0.y * (c2.w * c3.z - c2.z * c3.w) + c0.z * (c2.y * c3.w - c2.w * c3.y) + c0.w * (c2.z * c3.y - c2.y * c3.z);
    inv.c0.z = c0.y * (c1.z * c3.w - c1.w * c3.z) + c0.z * (c1.w * c3.y - c1.y * c3.w) + c0.w * (c1.y * c3.z - c1.z * c3.y);
    inv.c0.w = c0.y * (c1.w * c2.z - c1.z * c2.w) + c0.z * (c1.y * c2.w - c1.w * c2.y) + c0.w * (c1.z * c2.y - c1.y * c2.z);

    inv.c1.x = c1.x * (c2.w * c3.z - c2.z * c3.w) + c1.z * (c2.x * c3.w - c2.w * c3.x) + c1.w * (c2.z * c3.x - c2.x * c3.z);
    inv.c1.y = c0.x * (c2.z * c3.w - c2.w * c3.z) + c0.z * (c2.w * c3.x - c2.x * c3.w) + c0.w * (c2.x * c3.z - c2.z * c3.x);
    inv.c1.z = c0.x * (c1.w * c3.z - c1.z * c3.w) + c0.z * (c1.x * c3.w - c1.w * c3.x) + c0.w * (c1.z * c3.x - c1.x * c3.z);
    inv.c1.w = c0.x * (c1.z * c2.w - c1.w * c2.z) + c0.z * (c1.w * c2.x - c1.x * c2.w) + c0.w * (c1.x * c2.z - c1.z * c2.x);

    inv.c2.x = c1.x * (c2.y * c3.w - c2.w * c3.y) + c1.y * (c2.w * c3.x - c2.x * c3.w) + c1.w * (c2.x * c3.y - c2.y * c3.x);
    inv.c2.y = c0.x * (c2.w * c3.y - c2.y * c3.w) + c0.y * (c2.x * c3.w - c2.w * c3.x) + c0.w * (c2.y * c3.x - c2.x * c3.y);
    inv.c2.z = c0.x * (c1.y * c3.w - c1.w * c3.y) + c0.y * (c1.w * c3.x - c1.x * c3.w) + c0.w * (c1.x * c3.y - c1.y * c3.x);
    inv.c2.w = c0.x * (c1.w * c2.y - c1.y * c2.w) + c0.y * (c1.x * c2.w - c1.w * c2.x) + c0.w * (c1.y * c2.x - c1.x * c2.y);

    inv.c3.x = c1.x * (c2.z * c3.y - c2.y * c3.z) + c1.y * (c2.x * c3.z - c2.z * c3.x) + c1.z * (c2.y * c3.x - c2.x * c3.y);
    inv.c3.y = c0.x * (c2.y * c3.z - c2.z * c3.y) + c0.y * (c2.z * c3.x - c2.x * c3.z) + c0.z * (c2.x * c3.y - c2.y * c3.x);
    inv.c3.z = c0.x * (c1.z * c3.y - c1.y * c3.z) + c0.y * (c1.x * c3.z - c1.z * c3.x) + c0.z * (c1.y * c3.x - c1.x * c3.y);
    inv.c3.w = c0.x * (c1.y * c2.z - c1.z * c2.y) + c0.y * (c1.z * c2.x - c1.x * c2.z) + c0.z * (c1.x * c2.y - c1.y * c2.x);

    float det = c0.x * inv.c0.x + c0.y * inv.c1.x + c0.z * inv.c2.x + c0.w * inv.c3.x;

    return inv / det;
}

inline float float4x4::det() const {
    return c0.x * (c1.y * (c2.z * c3.w - c2.w * c3.z) - c1.z * (c2.y * c3.w - c2.w * c3.y) + c1.w * (c2.y * c3.z - c2.z * c3.y))
        - c0.y * (c1.x * (c2.z * c3.w - c2.w * c3.z) - c1.z * (c2.x * c3.w - c2.w * c3.x) + c1.w * (c2.x * c3.z - c2.z * c3.x))
        + c0.z * (c1.x * (c2.y * c3.w - c2.w * c3.y) - c1.y * (c2.x * c3.w - c2.w * c3.x) + c1.w * (c2.x * c3.y - c2.y * c3.x))
        - c0.w * (c1.x * (c2.y * c3.z - c2.z * c3.y) - c1.y * (c2.x * c3.z - c2.z * c3.x) + c1.z * (c2.x * c3.y - c2.y * c3.x));
}

inline float4x4 float4x4::operator-() const {
    return float4x4(-c0, -c1, -c2, -c3);
}

inline float4x4 float4x4::operator+(float scalar) const {
    return float4x4(c0 + scalar, c1 + scalar, c2 + scalar, c3 + scalar);
}

inline float4x4 float4x4::operator-(float scalar) const {
    return float4x4(c0 - scalar, c1 - scalar, c2 - scalar, c3 - scalar);
}

inline float4x4 float4x4::operator*(float scalar) const {
    return float4x4(c0 * scalar, c1 * scalar, c2 * scalar, c3 * scalar);
}

inline float4x4 float4x4::operator/(float scalar) const {
    return (*this) * (1.0f / scalar);
}

inline float4 float4x4::operator*(const float4& vector) const {
    return float4(
        c0.x * vector.x + c1.x * vector.y + c2.x * vector.z + c3.x * vector.w,
        c0.y * vector.x + c1.y * vector.y + c2.y * vector.z + c3.y * vector.w,
        c0.z * vector.x + c1.z * vector.y + c2.z * vector.z + c3.z * vector.w,
        c0.w * vector.x + c1.w * vector.y + c2.w * vector.z + c3.w * vector.w
    );
}

inline float4x4 float4x4::operator+(const float4x4& other) const {
    return float4x4(c0 + other.c0, c1 + other.c1, c2 + other.c2, c3 + other.c3);
}

inline float4x4 float4x4::operator-(const float4x4& other) const {
    return float4x4(c0 - other.c0, c1 - other.c1, c2 - other.c2, c3 - other.c3);
}

inline float4x4 float4x4::operator*(const float4x4& other) const {
    return float4x4(
        float4(
            c0.x * other.c0.x + c1.x * other.c0.y + c2.x * other.c0.z + c3.x * other.c0.w,
            c0.y * other.c0.x + c1.y * other.c0.y + c2.y * other.c0.z + c3.y * other.c0.w,
            c0.z * other.c0.x + c1.z * other.c0.y + c2.z * other.c0.z + c3.z * other.c0.w,
            c0.w * other.c0.x + c1.w * other.c0.y + c2.w * other.c0.z + c3.w * other.c0.w
        ),
        float4(
            c0.x * other.c1.x + c1.x * other.c1.y + c2.x * other.c1.z + c3.x * other.c1.w,
            c0.y * other.c1.x + c1.y * other.c1.y + c2.y * other.c1.z + c3.y * other.c1.w,
            c0.z * other.c1.x + c1.z * other.c1.y + c2.z * other.c1.z + c3.z * other.c1.w,
            c0.w * other.c1.x + c1.w * other.c1.y + c2.w * other.c1.z + c3.w * other.c1.w
        ),
        float4(
            c0.x * other.c2.x + c1.x * other.c2.y + c2.x * other.c2.z + c3.x * other.c2.w,
            c0.y * other.c2.x + c1.y * other.c2.y + c2.y * other.c2.z + c3.y * other.c2.w,
            c0.z * other.c2.x + c1.z * other.c2.y + c2.z * other.c2.z + c3.z * other.c2.w,
            c0.w * other.c2.x + c1.w * other.c2.y + c2.w * other.c2.z + c3.w * other.c2.w
        ),
        float4(
            c0.x * other.c3.x + c1.x * other.c3.y + c2.x * other.c3.z + c3.x * other.c3.w,
            c0.y * other.c3.x + c1.y * other.c3.y + c2.y * other.c3.z + c3.y * other.c3.w,
            c0.z * other.c3.x + c1.z * other.c3.y + c2.z * other.c3.z + c3.z * other.c3.w,
            c0.w * other.c3.x + c1.w * other.c3.y + c2.w * other.c3.z + c3.w * other.c3.w
        )
    );
}

inline float4x4& float4x4::operator+=(float scalar) {
    return *this = *this + scalar;
}

inline float4x4& float4x4::operator-=(float scalar) {
    return *this = *this - scalar;
}

inline float4x4& float4x4::operator*=(float scalar) {
    return *this = *this * scalar;
}

inline float4x4& float4x4::operator/=(float scalar) {
    return *this = *this / scalar;
}

inline float4x4& float4x4::operator+=(const float4x4& other) {
    return *this = *this + other;
}

inline float4x4& float4x4::operator-=(const float4x4& other) {
    return *this = *this - other;
}

inline float4x4& float4x4::operator*=(const float4x4& other) {
    return *this = *this * other;
}

inline float4& float4x4::operator[](int index) {
    return columns[index];
}

inline const float4& float4x4::operator[](int index) const {
    return columns[index];
}

}

#endif
