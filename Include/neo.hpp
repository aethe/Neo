#ifndef NEO_HPP
#define NEO_HPP

#include <cmath>
#include <string>

namespace neo {

const float PI = 3.1415926535f;
const float PI_2 = 6.2831853071f;

struct float2;
struct float3;
struct float4;
struct float2x2;
struct float3x3;
struct float4x4;
struct angle;

struct float2 {

    float x, y;

    float2(): x(0.0f), y(0.0f) { }
    float2(float x, float y): x(x), y(y) { }

    float3 as_float3(float z = 0.0f) const;
    float4 as_float4(float z = 0.0f, float w = 0.0f) const;

    float length() const;
    float2 normalize() const;
    float2 proj(const float2& other) const;
    float2 perp(const float2& other) const;
    float2 reflect(const float2& normal) const;
    float2 refract(const float2& normal, float eta) const;

    float2 operator-() const;

    float2 operator+(float scalar) const;
    float2 operator-(float scalar) const;
    float2 operator*(float scalar) const;
    float2 operator/(float scalar) const;

    float2 operator+(const float2& other) const;
    float2 operator-(const float2& other) const;
    float2 operator*(const float2& other) const;
    float2 operator/(const float2& other) const;

    float2& operator+=(float scalar);
    float2& operator-=(float scalar);
    float2& operator*=(float scalar);
    float2& operator/=(float scalar);

    float2& operator+=(const float2& other);
    float2& operator-=(const float2& other);
    float2& operator*=(const float2& other);
    float2& operator/=(const float2& other);

};

struct float3 {

    float x, y, z;

    float3(): x(0.0f), y(0.0f), z(0.0f) { }
    float3(float x, float y, float z): x(x), y(y), z(z) { }

    float2 as_float2() const;
    float4 as_float4(float w = 0.0f) const;

    float length() const;
    float3 normalize() const;
    float3 proj(const float3& other) const;
    float3 perp(const float3& other) const;
    float3 reflect(const float3& normal) const;
    float3 refract(const float3& normal, float eta) const;

    float3 operator-() const;

    float3 operator+(float scalar) const;
    float3 operator-(float scalar) const;
    float3 operator*(float scalar) const;
    float3 operator/(float scalar) const;

    float3 operator+(const float3& other) const;
    float3 operator-(const float3& other) const;
    float3 operator*(const float3& other) const;
    float3 operator/(const float3& other) const;

    float3& operator+=(float scalar);
    float3& operator-=(float scalar);
    float3& operator*=(float scalar);
    float3& operator/=(float scalar);

    float3& operator+=(const float3& other);
    float3& operator-=(const float3& other);
    float3& operator*=(const float3& other);
    float3& operator/=(const float3& other);

};

struct float4 {

    float x, y, z, w;

    float4(): x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }
    float4(float x, float y, float z, float w): x(x), y(y), z(z), w(w) { }

    float2 as_float2() const;
    float3 as_float3() const;

    float length() const;
    float4 normalize() const;
    float4 proj(const float4& other) const;
    float4 perp(const float4& other) const;
    float4 reflect(const float4& normal) const;
    float4 refract(const float4& normal, float eta) const;

    float4 operator-() const;

    float4 operator+(float scalar) const;
    float4 operator-(float scalar) const;
    float4 operator*(float scalar) const;
    float4 operator/(float scalar) const;

    float4 operator+(const float4& other) const;
    float4 operator-(const float4& other) const;
    float4 operator*(const float4& other) const;
    float4 operator/(const float4& other) const;

    float4& operator+=(float scalar);
    float4& operator-=(float scalar);
    float4& operator*=(float scalar);
    float4& operator/=(float scalar);

    float4& operator+=(const float4& other);
    float4& operator-=(const float4& other);
    float4& operator*=(const float4& other);
    float4& operator/=(const float4& other);

};

struct float2x2 {

    float2 v1, v2;

    float2x2(): v1(1.0f, 0.0f), v2(0.0f, 1.0f) { }
    float2x2(const float2& v1, const float2& v2): v1(v1), v2(v2) { }
    float2x2(float v1x, float v1y, float v2x, float v2y):
        v1(v1x, v1y), v2(v2x, v2y) { }

    float3x3 as_float3x3() const;
    float4x4 as_float4x4() const;

    float2x2 transpose() const;
    float2x2 inverse() const;
    float det() const;

    float2x2 operator-() const;

    float2x2 operator+(float scalar) const;
    float2x2 operator-(float scalar) const;
    float2x2 operator*(float scalar) const;
    float2x2 operator/(float scalar) const;

    float2 operator*(const float2& vector) const;

    float2x2 operator+(const float2x2& other) const;
    float2x2 operator-(const float2x2& other) const;
    float2x2 operator*(const float2x2& other) const;

    float2x2& operator+=(float scalar);
    float2x2& operator-=(float scalar);
    float2x2& operator*=(float scalar);
    float2x2& operator/=(float scalar);

    float2x2& operator+=(const float2x2& other);
    float2x2& operator-=(const float2x2& other);
    float2x2& operator*=(const float2x2& other);

};

struct float3x3 {

    float3 v1, v2, v3;

    float3x3(): v1(1.0f, 0.0f, 0.0f), v2(0.0f, 1.0f, 0.0f), v3(0.0f, 0.0f, 1.0f) { }
    float3x3(const float3& v1, const float3& v2, const float3& v3): v1(v1), v2(v2), v3(v3) { }
    float3x3(float v1x, float v1y, float v1z, float v2x, float v2y, float v2z, float v3x, float v3y, float v3z):
        v1(v1x, v1y, v1z), v2(v2x, v2y, v2z), v3(v3x, v3y, v3z) { }

    float2x2 as_float2x2() const;
    float4x4 as_float4x4() const;

    float3x3 transpose() const;
    float3x3 inverse() const;
    float det() const;

    float3x3 operator-() const;

    float3x3 operator+(float scalar) const;
    float3x3 operator-(float scalar) const;
    float3x3 operator*(float scalar) const;
    float3x3 operator/(float scalar) const;

    float3 operator*(const float3& vector) const;

    float3x3 operator+(const float3x3& other) const;
    float3x3 operator-(const float3x3& other) const;
    float3x3 operator*(const float3x3& other) const;

    float3x3& operator+=(float scalar);
    float3x3& operator-=(float scalar);
    float3x3& operator*=(float scalar);
    float3x3& operator/=(float scalar);

    float3x3& operator+=(const float3x3& other);
    float3x3& operator-=(const float3x3& other);
    float3x3& operator*=(const float3x3& other);

};

struct float4x4 {

    float4 v1, v2, v3, v4;

    float4x4(): v1(1.0f, 0.0f, 0.0f, 0.0f), v2(0.0f, 1.0f, 0.0f, 0.0f), v3(0.0f, 0.0f, 1.0f, 0.0f), v4(0.0f, 0.0f, 0.0f, 1.0f) { }
    float4x4(const float4& v1, const float4& v2, const float4& v3, const float4& v4): v1(v1), v2(v2), v3(v3), v4(v4) { }
    float4x4(float v1x, float v1y, float v1z, float v1w, float v2x, float v2y, float v2z, float v2w, float v3x, float v3y, float v3z, float v3w, float v4x, float v4y, float v4z, float v4w):
        v1(v1x, v1y, v1z, v1w), v2(v2x, v2y, v2z, v2w), v3(v3x, v3y, v3z, v3w), v4(v4x, v4y, v4z, v4w) { }

    static float4x4 scale(const float3& vector);
    static float4x4 translation(const float3& vector);
    static float4x4 rotation(const float3& vector, const angle& alpha);
    static float4x4 rotation_x(const angle& alpha);
    static float4x4 rotation_y(const angle& alpha);
    static float4x4 rotation_z(const angle& alpha);
    static float4x4 look_at(const float3& origin, const float3& target, const float3& up);

    float2x2 as_float2x2() const;
    float3x3 as_float3x3() const;

    float4x4 transpose() const;
    float4x4 inverse() const;
    float det() const;

    float4x4 operator-() const;

    float4x4 operator+(float scalar) const;
    float4x4 operator-(float scalar) const;
    float4x4 operator*(float scalar) const;
    float4x4 operator/(float scalar) const;

    float4 operator*(const float4& vector) const;

    float4x4 operator+(const float4x4& other) const;
    float4x4 operator-(const float4x4& other) const;
    float4x4 operator*(const float4x4& other) const;

    float4x4& operator+=(float scalar);
    float4x4& operator-=(float scalar);
    float4x4& operator*=(float scalar);
    float4x4& operator/=(float scalar);

    float4x4& operator+=(const float4x4& other);
    float4x4& operator-=(const float4x4& other);
    float4x4& operator*=(const float4x4& other);

};

struct angle {

    static angle radians(float radians);
    static angle degrees(float degrees);

    float as_radians() const;
    float as_degrees() const;

    float cos() const;
    float sin() const;

private:
    float radians_;

    angle(): radians_(0.0f) { }
    angle(float radians): radians_(radians) { }

};

float dot(const float2& lhs, const float2& rhs);
float dot(const float3& lhs, const float3& rhs);
float dot(const float4& lhs, const float4& rhs);

float3 cross(const float3& lhs, const float3& rhs);

float2 lerp(const float2& lhs, const float2& rhs, float t);
float3 lerp(const float3& lhs, const float3& rhs, float t);
float4 lerp(const float4& lhs, const float4& rhs, float t);
float2x2 lerp(const float2x2& lhs, const float2x2& rhs, float t);
float3x3 lerp(const float3x3& lhs, const float3x3& rhs, float t);
float4x4 lerp(const float4x4& lhs, const float4x4& rhs, float t);

}

#endif

#include "float2.hpp"
#include "float3.hpp"
#include "float4.hpp"
#include "float2x2.hpp"
#include "float3x3.hpp"
#include "float4x4.hpp"
#include "angle.hpp"
#include "functions.hpp"
