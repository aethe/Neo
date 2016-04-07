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

    union { struct { float x, y; }; float scalars[2]; };

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

    float& operator[](int index);
    float operator[](int index) const;

};

struct float3 {

    union { struct { float x, y, z; }; float scalars[3]; };

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

    float& operator[](int index);
    float operator[](int index) const;

};

struct float4 {

    union { struct { float x, y, z, w; }; float scalars[4]; };

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

    float& operator[](int index);
    float operator[](int index) const;

};

struct float2x2 {

    union { struct { float2 c0, c1; }; float2 columns[2]; };

    float2x2(): c0(1.0f, 0.0f), c1(0.0f, 1.0f) { }
    float2x2(const float2& c0, const float2& c1): c0(c0), c1(c1) { }
    float2x2(float c0x, float c0y, float c1x, float c1y):
        c0(c0x, c0y), c1(c1x, c1y) { }

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

    float2& operator[](int index);
    const float2& operator[](int index) const;

};

struct float3x3 {

    union { struct { float3 c0, c1, c2; }; float3 columns[3]; };

    float3x3(): c0(1.0f, 0.0f, 0.0f), c1(0.0f, 1.0f, 0.0f), c2(0.0f, 0.0f, 1.0f) { }
    float3x3(const float3& c0, const float3& c1, const float3& c2): c0(c0), c1(c1), c2(c2) { }
    float3x3(float c0x, float c0y, float c0z, float c1x, float c1y, float c1z, float c2x, float c2y, float c2z):
        c0(c0x, c0y, c0z), c1(c1x, c1y, c1z), c2(c2x, c2y, c2z) { }

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

    float3& operator[](int index);
    const float3& operator[](int index) const;

};

struct float4x4 {

    union { struct { float4 c0, c1, c2, c3; }; float4 columns[4]; };

    float4x4(): c0(1.0f, 0.0f, 0.0f, 0.0f), c1(0.0f, 1.0f, 0.0f, 0.0f), c2(0.0f, 0.0f, 1.0f, 0.0f), c3(0.0f, 0.0f, 0.0f, 1.0f) { }
    float4x4(const float4& c0, const float4& c1, const float4& c2, const float4& c3): c0(c0), c1(c1), c2(c2), c3(c3) { }
    float4x4(float c0x, float c0y, float c0z, float c0w, float c1x, float c1y, float c1z, float c1w, float c2x, float c2y, float c2z, float c2w, float c3x, float c3y, float c3z, float c3w):
        c0(c0x, c0y, c0z, c0w), c1(c1x, c1y, c1z, c1w), c2(c2x, c2y, c2z, c2w), c3(c3x, c3y, c3z, c3w) { }

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

    float4& operator[](int index);
    const float4& operator[](int index) const;

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
