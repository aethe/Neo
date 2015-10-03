#ifndef NEO_HPP
#define NEO_HPP

#include <cmath>
#include <string>

namespace neo {

const float PI = 3.1415926535f;
const float PI_2 = 6.2831853071f;

struct vec2;
struct vec3;
struct vec4;
struct mat2;
struct mat3;
struct mat4;
struct angle;

struct vec2 {

    float x, y;

    vec2(): x(0.0f), y(0.0f) { }
    vec2(float x, float y): x(x), y(y) { }

    vec3 as_vec3(float z = 0.0f) const;
    vec4 as_vec4(float z = 0.0f, float w = 0.0f) const;
    //std::string as_string() const;

    float length() const;
    vec2 normalize() const;
    float dot(const vec2& other) const;
    vec2 proj(const vec2& other) const;
    vec2 perp(const vec2& other) const;
    vec2 reflect(const vec2& normal) const;
    vec2 refract(const vec2& normal, float eta) const;
    vec2 lerp(const vec2& other, float t) const;

    vec2 operator-() const;

    vec2 operator+(float scalar) const;
    vec2 operator-(float scalar) const;
    vec2 operator*(float scalar) const;
    vec2 operator/(float scalar) const;

    vec2 operator+(const vec2& other) const;
    vec2 operator-(const vec2& other) const;
    vec2 operator*(const vec2& other) const;
    vec2 operator/(const vec2& other) const;

    vec2& operator+=(float scalar);
    vec2& operator-=(float scalar);
    vec2& operator*=(float scalar);
    vec2& operator/=(float scalar);

    vec2& operator+=(const vec2& other);
    vec2& operator-=(const vec2& other);
    vec2& operator*=(const vec2& other);
    vec2& operator/=(const vec2& other);

};

struct vec3 {

    float x, y, z;

    vec3(): x(0.0f), y(0.0f), z(0.0f) { }
    vec3(float x, float y, float z): x(x), y(y), z(z) { }

    vec2 as_vec2() const;
    vec4 as_vec4(float w = 0.0f) const;
    //std::string as_string() const;

    float length() const;
    vec3 normalize() const;
    float dot(const vec3& other) const;
    vec3 proj(const vec3& other) const;
    vec3 perp(const vec3& other) const;
    vec3 reflect(const vec3& normal) const;
    vec3 refract(const vec3& normal, float eta) const;
    vec3 lerp(const vec3& other, float t) const;
    vec3 cross(const vec3& other) const;

    vec3 operator-() const;

    vec3 operator+(float scalar) const;
    vec3 operator-(float scalar) const;
    vec3 operator*(float scalar) const;
    vec3 operator/(float scalar) const;

    vec3 operator+(const vec3& other) const;
    vec3 operator-(const vec3& other) const;
    vec3 operator*(const vec3& other) const;
    vec3 operator/(const vec3& other) const;

    vec3& operator+=(float scalar);
    vec3& operator-=(float scalar);
    vec3& operator*=(float scalar);
    vec3& operator/=(float scalar);

    vec3& operator+=(const vec3& other);
    vec3& operator-=(const vec3& other);
    vec3& operator*=(const vec3& other);
    vec3& operator/=(const vec3& other);

};

struct vec4 {

    float x, y, z, w;

    vec4(): x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }
    vec4(float x, float y, float z, float w): x(x), y(y), z(z), w(w) { }

    vec2 as_vec2() const;
    vec3 as_vec3() const;
    //std::string as_string() const;

    float length() const;
    vec4 normalize() const;
    float dot(const vec4& other) const;
    vec4 proj(const vec4& other) const;
    vec4 perp(const vec4& other) const;
    vec4 reflect(const vec4& normal) const;
    vec4 refract(const vec4& normal, float eta) const;
    vec4 lerp(const vec4& other, float t) const;

    vec4 operator-() const;

    vec4 operator+(float scalar) const;
    vec4 operator-(float scalar) const;
    vec4 operator*(float scalar) const;
    vec4 operator/(float scalar) const;

    vec4 operator+(const vec4& other) const;
    vec4 operator-(const vec4& other) const;
    vec4 operator*(const vec4& other) const;
    vec4 operator/(const vec4& other) const;

    vec4& operator+=(float scalar);
    vec4& operator-=(float scalar);
    vec4& operator*=(float scalar);
    vec4& operator/=(float scalar);

    vec4& operator+=(const vec4& other);
    vec4& operator-=(const vec4& other);
    vec4& operator*=(const vec4& other);
    vec4& operator/=(const vec4& other);

};

struct mat2 {

    vec2 v1, v2;

    mat2(): v1(1.0f, 0.0f), v2(0.0f, 1.0f) { }
    mat2(const vec2& v1, const vec2& v2): v1(v1), v2(v2) { }
    mat2(float v1x, float v1y, float v2x, float v2y):
        v1(v1x, v1y), v2(v2x, v2y) { }

    mat3 as_mat3() const;
    mat4 as_mat4() const;
    //std::string as_string() const;

    mat2 transpose() const;
    mat2 inverse() const;
    float det() const;
    mat2 lerp(const mat2& other, float t) const;

    mat2 operator-() const;

    mat2 operator+(float scalar) const;
    mat2 operator-(float scalar) const;
    mat2 operator*(float scalar) const;
    mat2 operator/(float scalar) const;

    vec2 operator*(const vec2& vector) const;

    mat2 operator+(const mat2& other) const;
    mat2 operator-(const mat2& other) const;
    mat2 operator*(const mat2& other) const;

    mat2& operator+=(float scalar);
    mat2& operator-=(float scalar);
    mat2& operator*=(float scalar);
    mat2& operator/=(float scalar);

    mat2& operator+=(const mat2& other);
    mat2& operator-=(const mat2& other);
    mat2& operator*=(const mat2& other);

};

struct mat3 {

    vec3 v1, v2, v3;

    mat3(): v1(1.0f, 0.0f, 0.0f), v2(0.0f, 1.0f, 0.0f), v3(0.0f, 0.0f, 1.0f) { }
    mat3(const vec3& v1, const vec3& v2, const vec3& v3): v1(v1), v2(v2), v3(v3) { }
    mat3(float v1x, float v1y, float v1z, float v2x, float v2y, float v2z, float v3x, float v3y, float v3z):
        v1(v1x, v1y, v1z), v2(v2x, v2y, v2z), v3(v3x, v3y, v3z) { }

    mat2 as_mat2() const;
    mat4 as_mat4() const;
    //std::string as_string() const;

    mat3 transpose() const;
    mat3 inverse() const;
    float det() const;
    mat3 lerp(const mat3& other, float t) const;

    mat3 operator-() const;

    mat3 operator+(float scalar) const;
    mat3 operator-(float scalar) const;
    mat3 operator*(float scalar) const;
    mat3 operator/(float scalar) const;

    vec3 operator*(const vec3& vector) const;

    mat3 operator+(const mat3& other) const;
    mat3 operator-(const mat3& other) const;
    mat3 operator*(const mat3& other) const;

    mat3& operator+=(float scalar);
    mat3& operator-=(float scalar);
    mat3& operator*=(float scalar);
    mat3& operator/=(float scalar);

    mat3& operator+=(const mat3& other);
    mat3& operator-=(const mat3& other);
    mat3& operator*=(const mat3& other);

};

struct mat4 {

    vec4 v1, v2, v3, v4;

    mat4(): v1(1.0f, 0.0f, 0.0f, 0.0f), v2(0.0f, 1.0f, 0.0f, 0.0f), v3(0.0f, 0.0f, 1.0f, 0.0f), v4(0.0f, 0.0f, 0.0f, 1.0f) { }
    mat4(const vec4& v1, const vec4& v2, const vec4& v3, const vec4& v4): v1(v1), v2(v2), v3(v3), v4(v4) { }
    mat4(float v1x, float v1y, float v1z, float v1w, float v2x, float v2y, float v2z, float v2w, float v3x, float v3y, float v3z, float v3w, float v4x, float v4y, float v4z, float v4w):
        v1(v1x, v1y, v1z, v1w), v2(v2x, v2y, v2z, v2w), v3(v3x, v3y, v3z, v3w), v4(v4x, v4y, v4z, v4w) { }

    static mat4 scale(const vec3& vector);
    static mat4 translation(const vec3& vector);
    static mat4 rotation(const vec3& vector, const angle& alpha);
    static mat4 rotation_x(const angle& alpha);
    static mat4 rotation_y(const angle& alpha);
    static mat4 rotation_z(const angle& alpha);
    static mat4 look_at(const vec3& origin, const vec3& target, const vec3& up);

    mat2 as_mat2() const;
    mat3 as_mat3() const;
    //std::string as_string() const;

    mat4 transpose() const;
    mat4 inverse() const;
    float det() const;
    mat4 lerp(const mat4& other, float t) const;

    mat4 operator-() const;

    mat4 operator+(float scalar) const;
    mat4 operator-(float scalar) const;
    mat4 operator*(float scalar) const;
    mat4 operator/(float scalar) const;

    vec4 operator*(const vec4& vector) const;

    mat4 operator+(const mat4& other) const;
    mat4 operator-(const mat4& other) const;
    mat4 operator*(const mat4& other) const;

    mat4& operator+=(float scalar);
    mat4& operator-=(float scalar);
    mat4& operator*=(float scalar);
    mat4& operator/=(float scalar);

    mat4& operator+=(const mat4& other);
    mat4& operator-=(const mat4& other);
    mat4& operator*=(const mat4& other);

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

}

#endif

#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"
#include "mat2.hpp"
#include "mat3.hpp"
#include "mat4.hpp"
#include "angle.hpp"
