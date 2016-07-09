#ifndef NEO_HPP
#define NEO_HPP

#include <cmath>

// CUDA support
#ifdef __CUDACC__
#define NEO_CUDA_FUNC_DECL __host__ __device__
#define NEO_CUDA_FUNC_DEF __host__ __device__
#else
#define NEO_CUDA_FUNC_DECL
#define NEO_CUDA_FUNC_DEF
#endif

// Function qualifiers
#define NEO_FUNC_DECL NEO_CUDA_FUNC_DECL
#define NEO_FUNC_DEF inline NEO_CUDA_FUNC_DEF

namespace neo {

const float PI = 3.1415926535f;
const float PI_2 = 6.2831853071f;

struct float2;
struct float3;
struct float4;
struct float2x2;
struct float3x3;
struct float4x4;

struct float2 {

    union { struct { float x, y; }; float scalars[2]; };

    NEO_FUNC_DECL float2(): x(0.0f), y(0.0f) { }
    NEO_FUNC_DECL float2(float scalar): x(scalar), y(scalar) { }
    NEO_FUNC_DECL float2(float x, float y): x(x), y(y) { }

    NEO_FUNC_DECL float3 as_float3(float z = 0.0f) const;
    NEO_FUNC_DECL float4 as_float4(float z = 0.0f, float w = 0.0f) const;

    NEO_FUNC_DECL float length() const;
    NEO_FUNC_DECL float2 normalize() const;
    NEO_FUNC_DECL float2 proj(const float2& other) const;
    NEO_FUNC_DECL float2 perp(const float2& other) const;
    NEO_FUNC_DECL float2 reflect(const float2& normal) const;
    NEO_FUNC_DECL float2 refract(const float2& normal, float eta) const;

    NEO_FUNC_DECL float2 operator-() const;

    NEO_FUNC_DECL float2 operator+(float scalar) const;
    NEO_FUNC_DECL float2 operator-(float scalar) const;
    NEO_FUNC_DECL float2 operator*(float scalar) const;
    NEO_FUNC_DECL float2 operator/(float scalar) const;

    NEO_FUNC_DECL float2 operator+(const float2& other) const;
    NEO_FUNC_DECL float2 operator-(const float2& other) const;
    NEO_FUNC_DECL float2 operator*(const float2& other) const;
    NEO_FUNC_DECL float2 operator/(const float2& other) const;

    NEO_FUNC_DECL float2& operator+=(float scalar);
    NEO_FUNC_DECL float2& operator-=(float scalar);
    NEO_FUNC_DECL float2& operator*=(float scalar);
    NEO_FUNC_DECL float2& operator/=(float scalar);

    NEO_FUNC_DECL float2& operator+=(const float2& other);
    NEO_FUNC_DECL float2& operator-=(const float2& other);
    NEO_FUNC_DECL float2& operator*=(const float2& other);
    NEO_FUNC_DECL float2& operator/=(const float2& other);

    NEO_FUNC_DECL float& operator[](int index);
    NEO_FUNC_DECL float operator[](int index) const;

};

struct float3 {

    union { struct { float x, y, z; }; float scalars[3]; };

    NEO_FUNC_DECL float3(): x(0.0f), y(0.0f), z(0.0f) { }
    NEO_FUNC_DECL float3(float scalar): x(scalar), y(scalar), z(scalar) { }
    NEO_FUNC_DECL float3(float x, float y, float z): x(x), y(y), z(z) { }

    NEO_FUNC_DECL float2 as_float2() const;
    NEO_FUNC_DECL float4 as_float4(float w = 0.0f) const;

    NEO_FUNC_DECL float length() const;
    NEO_FUNC_DECL float3 normalize() const;
    NEO_FUNC_DECL float3 proj(const float3& other) const;
    NEO_FUNC_DECL float3 perp(const float3& other) const;
    NEO_FUNC_DECL float3 reflect(const float3& normal) const;
    NEO_FUNC_DECL float3 refract(const float3& normal, float eta) const;

    NEO_FUNC_DECL float3 operator-() const;

    NEO_FUNC_DECL float3 operator+(float scalar) const;
    NEO_FUNC_DECL float3 operator-(float scalar) const;
    NEO_FUNC_DECL float3 operator*(float scalar) const;
    NEO_FUNC_DECL float3 operator/(float scalar) const;

    NEO_FUNC_DECL float3 operator+(const float3& other) const;
    NEO_FUNC_DECL float3 operator-(const float3& other) const;
    NEO_FUNC_DECL float3 operator*(const float3& other) const;
    NEO_FUNC_DECL float3 operator/(const float3& other) const;

    NEO_FUNC_DECL float3& operator+=(float scalar);
    NEO_FUNC_DECL float3& operator-=(float scalar);
    NEO_FUNC_DECL float3& operator*=(float scalar);
    NEO_FUNC_DECL float3& operator/=(float scalar);

    NEO_FUNC_DECL float3& operator+=(const float3& other);
    NEO_FUNC_DECL float3& operator-=(const float3& other);
    NEO_FUNC_DECL float3& operator*=(const float3& other);
    NEO_FUNC_DECL float3& operator/=(const float3& other);

    NEO_FUNC_DECL float& operator[](int index);
    NEO_FUNC_DECL float operator[](int index) const;

};

struct float4 {

    union { struct { float x, y, z, w; }; float scalars[4]; };

    NEO_FUNC_DECL float4(): x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }
    NEO_FUNC_DECL float4(float scalar): x(scalar), y(scalar), z(scalar), w(scalar) { }
    NEO_FUNC_DECL float4(float x, float y, float z, float w): x(x), y(y), z(z), w(w) { }

    NEO_FUNC_DECL float2 as_float2() const;
    NEO_FUNC_DECL float3 as_float3() const;

    NEO_FUNC_DECL float length() const;
    NEO_FUNC_DECL float4 normalize() const;
    NEO_FUNC_DECL float4 proj(const float4& other) const;
    NEO_FUNC_DECL float4 perp(const float4& other) const;
    NEO_FUNC_DECL float4 reflect(const float4& normal) const;
    NEO_FUNC_DECL float4 refract(const float4& normal, float eta) const;

    NEO_FUNC_DECL float4 operator-() const;

    NEO_FUNC_DECL float4 operator+(float scalar) const;
    NEO_FUNC_DECL float4 operator-(float scalar) const;
    NEO_FUNC_DECL float4 operator*(float scalar) const;
    NEO_FUNC_DECL float4 operator/(float scalar) const;

    NEO_FUNC_DECL float4 operator+(const float4& other) const;
    NEO_FUNC_DECL float4 operator-(const float4& other) const;
    NEO_FUNC_DECL float4 operator*(const float4& other) const;
    NEO_FUNC_DECL float4 operator/(const float4& other) const;

    NEO_FUNC_DECL float4& operator+=(float scalar);
    NEO_FUNC_DECL float4& operator-=(float scalar);
    NEO_FUNC_DECL float4& operator*=(float scalar);
    NEO_FUNC_DECL float4& operator/=(float scalar);

    NEO_FUNC_DECL float4& operator+=(const float4& other);
    NEO_FUNC_DECL float4& operator-=(const float4& other);
    NEO_FUNC_DECL float4& operator*=(const float4& other);
    NEO_FUNC_DECL float4& operator/=(const float4& other);

    NEO_FUNC_DECL float& operator[](int index);
    NEO_FUNC_DECL float operator[](int index) const;

};

struct float2x2 {

    union { struct { float2 c0, c1; }; float2 columns[2]; };

    NEO_FUNC_DECL float2x2(): c0(1.0f, 0.0f), c1(0.0f, 1.0f) { }
    NEO_FUNC_DECL float2x2(const float2& c0, const float2& c1): c0(c0), c1(c1) { }
    NEO_FUNC_DECL float2x2(float c0x, float c0y, float c1x, float c1y):
        c0(c0x, c0y), c1(c1x, c1y) { }

    NEO_FUNC_DECL float3x3 as_float3x3() const;
    NEO_FUNC_DECL float4x4 as_float4x4() const;

    NEO_FUNC_DECL float2x2 transpose() const;
    NEO_FUNC_DECL float2x2 inverse() const;
    NEO_FUNC_DECL float det() const;

    NEO_FUNC_DECL float2x2 operator-() const;

    NEO_FUNC_DECL float2x2 operator+(float scalar) const;
    NEO_FUNC_DECL float2x2 operator-(float scalar) const;
    NEO_FUNC_DECL float2x2 operator*(float scalar) const;
    NEO_FUNC_DECL float2x2 operator/(float scalar) const;

    NEO_FUNC_DECL float2 operator*(const float2& vector) const;

    NEO_FUNC_DECL float2x2 operator+(const float2x2& other) const;
    NEO_FUNC_DECL float2x2 operator-(const float2x2& other) const;
    NEO_FUNC_DECL float2x2 operator*(const float2x2& other) const;

    NEO_FUNC_DECL float2x2& operator+=(float scalar);
    NEO_FUNC_DECL float2x2& operator-=(float scalar);
    NEO_FUNC_DECL float2x2& operator*=(float scalar);
    NEO_FUNC_DECL float2x2& operator/=(float scalar);

    NEO_FUNC_DECL float2x2& operator+=(const float2x2& other);
    NEO_FUNC_DECL float2x2& operator-=(const float2x2& other);
    NEO_FUNC_DECL float2x2& operator*=(const float2x2& other);

    NEO_FUNC_DECL float2& operator[](int index);
    NEO_FUNC_DECL const float2& operator[](int index) const;

};

struct float3x3 {

    union { struct { float3 c0, c1, c2; }; float3 columns[3]; };

    NEO_FUNC_DECL float3x3(): c0(1.0f, 0.0f, 0.0f), c1(0.0f, 1.0f, 0.0f), c2(0.0f, 0.0f, 1.0f) { }
    NEO_FUNC_DECL float3x3(const float3& c0, const float3& c1, const float3& c2): c0(c0), c1(c1), c2(c2) { }
    NEO_FUNC_DECL float3x3(float c0x, float c0y, float c0z, float c1x, float c1y, float c1z, float c2x, float c2y, float c2z):
        c0(c0x, c0y, c0z), c1(c1x, c1y, c1z), c2(c2x, c2y, c2z) { }

    NEO_FUNC_DECL float2x2 as_float2x2() const;
    NEO_FUNC_DECL float4x4 as_float4x4() const;

    NEO_FUNC_DECL float3x3 transpose() const;
    NEO_FUNC_DECL float3x3 inverse() const;
    NEO_FUNC_DECL float det() const;

    NEO_FUNC_DECL float3x3 operator-() const;

    NEO_FUNC_DECL float3x3 operator+(float scalar) const;
    NEO_FUNC_DECL float3x3 operator-(float scalar) const;
    NEO_FUNC_DECL float3x3 operator*(float scalar) const;
    NEO_FUNC_DECL float3x3 operator/(float scalar) const;

    NEO_FUNC_DECL float3 operator*(const float3& vector) const;

    NEO_FUNC_DECL float3x3 operator+(const float3x3& other) const;
    NEO_FUNC_DECL float3x3 operator-(const float3x3& other) const;
    NEO_FUNC_DECL float3x3 operator*(const float3x3& other) const;

    NEO_FUNC_DECL float3x3& operator+=(float scalar);
    NEO_FUNC_DECL float3x3& operator-=(float scalar);
    NEO_FUNC_DECL float3x3& operator*=(float scalar);
    NEO_FUNC_DECL float3x3& operator/=(float scalar);

    NEO_FUNC_DECL float3x3& operator+=(const float3x3& other);
    NEO_FUNC_DECL float3x3& operator-=(const float3x3& other);
    NEO_FUNC_DECL float3x3& operator*=(const float3x3& other);

    NEO_FUNC_DECL float3& operator[](int index);
    NEO_FUNC_DECL const float3& operator[](int index) const;

};

struct float4x4 {

    union { struct { float4 c0, c1, c2, c3; }; float4 columns[4]; };

    NEO_FUNC_DECL float4x4(): c0(1.0f, 0.0f, 0.0f, 0.0f), c1(0.0f, 1.0f, 0.0f, 0.0f), c2(0.0f, 0.0f, 1.0f, 0.0f), c3(0.0f, 0.0f, 0.0f, 1.0f) { }
    NEO_FUNC_DECL float4x4(const float4& c0, const float4& c1, const float4& c2, const float4& c3): c0(c0), c1(c1), c2(c2), c3(c3) { }
    NEO_FUNC_DECL float4x4(float c0x, float c0y, float c0z, float c0w, float c1x, float c1y, float c1z, float c1w, float c2x, float c2y, float c2z, float c2w, float c3x, float c3y, float c3z, float c3w):
        c0(c0x, c0y, c0z, c0w), c1(c1x, c1y, c1z, c1w), c2(c2x, c2y, c2z, c2w), c3(c3x, c3y, c3z, c3w) { }

    static NEO_FUNC_DECL float4x4 scale(const float3& vector);
    static NEO_FUNC_DECL float4x4 translation(const float3& vector);
    static NEO_FUNC_DECL float4x4 rotation(const float3& vector, float angle);
    static NEO_FUNC_DECL float4x4 rotation_x(float angle);
    static NEO_FUNC_DECL float4x4 rotation_y(float angle);
    static NEO_FUNC_DECL float4x4 rotation_z(float angle);
    static NEO_FUNC_DECL float4x4 look_at(const float3& origin, const float3& target, const float3& up);

    NEO_FUNC_DECL float2x2 as_float2x2() const;
    NEO_FUNC_DECL float3x3 as_float3x3() const;

    NEO_FUNC_DECL float4x4 transpose() const;
    NEO_FUNC_DECL float4x4 inverse() const;
    NEO_FUNC_DECL float det() const;

    NEO_FUNC_DECL float4x4 operator-() const;

    NEO_FUNC_DECL float4x4 operator+(float scalar) const;
    NEO_FUNC_DECL float4x4 operator-(float scalar) const;
    NEO_FUNC_DECL float4x4 operator*(float scalar) const;
    NEO_FUNC_DECL float4x4 operator/(float scalar) const;

    NEO_FUNC_DECL float4 operator*(const float4& vector) const;

    NEO_FUNC_DECL float4x4 operator+(const float4x4& other) const;
    NEO_FUNC_DECL float4x4 operator-(const float4x4& other) const;
    NEO_FUNC_DECL float4x4 operator*(const float4x4& other) const;

    NEO_FUNC_DECL float4x4& operator+=(float scalar);
    NEO_FUNC_DECL float4x4& operator-=(float scalar);
    NEO_FUNC_DECL float4x4& operator*=(float scalar);
    NEO_FUNC_DECL float4x4& operator/=(float scalar);

    NEO_FUNC_DECL float4x4& operator+=(const float4x4& other);
    NEO_FUNC_DECL float4x4& operator-=(const float4x4& other);
    NEO_FUNC_DECL float4x4& operator*=(const float4x4& other);

    NEO_FUNC_DECL float4& operator[](int index);
    NEO_FUNC_DECL const float4& operator[](int index) const;

};

NEO_FUNC_DECL float dot(const float2& lhs, const float2& rhs);
NEO_FUNC_DECL float dot(const float3& lhs, const float3& rhs);
NEO_FUNC_DECL float dot(const float4& lhs, const float4& rhs);

NEO_FUNC_DECL float3 cross(const float3& lhs, const float3& rhs);

NEO_FUNC_DECL float2 lerp(const float2& lhs, const float2& rhs, float t);
NEO_FUNC_DECL float3 lerp(const float3& lhs, const float3& rhs, float t);
NEO_FUNC_DECL float4 lerp(const float4& lhs, const float4& rhs, float t);
NEO_FUNC_DECL float2x2 lerp(const float2x2& lhs, const float2x2& rhs, float t);
NEO_FUNC_DECL float3x3 lerp(const float3x3& lhs, const float3x3& rhs, float t);
NEO_FUNC_DECL float4x4 lerp(const float4x4& lhs, const float4x4& rhs, float t);

}

#endif

#include "float2.hpp"
#include "float3.hpp"
#include "float4.hpp"
#include "float2x2.hpp"
#include "float3x3.hpp"
#include "float4x4.hpp"
#include "functions.hpp"
