#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "neo.hpp"

namespace neo {

inline float dot(const float2& lhs, const float2& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

inline float dot(const float3& lhs, const float3& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

inline float dot(const float4& lhs, const float4& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

inline float3 cross(const float3& lhs, const float3& rhs) {
    float new_x = lhs.y * rhs.z - lhs.z * rhs.y;
    float new_y = lhs.z * rhs.x - lhs.x * rhs.z;
    float new_z = lhs.x * rhs.y - lhs.y * rhs.x;
    return float3(new_x, new_y, new_z);
}

inline float2 lerp(const float2& lhs, const float2& rhs, float t) {
    return lhs * (1.0f - t) + rhs * t;
}

inline float3 lerp(const float3& lhs, const float3& rhs, float t) {
    return lhs * (1.0f - t) + rhs * t;
}

inline float4 lerp(const float4& lhs, const float4& rhs, float t) {
    return lhs * (1.0f - t) + rhs * t;
}

inline float2x2 lerp(const float2x2& lhs, const float2x2& rhs, float t) {
    return float2x2(lerp(lhs.v1, rhs.v1, t), lerp(lhs.v2, rhs.v2, t));
}

inline float3x3 lerp(const float3x3& lhs, const float3x3& rhs, float t) {
    return float3x3(lerp(lhs.v1, rhs.v1, t), lerp(lhs.v2, rhs.v2, t), lerp(lhs.v3, rhs.v3, t));
}

inline float4x4 lerp(const float4x4& lhs, const float4x4& rhs, float t) {
    return float4x4(lerp(lhs.v1, rhs.v1, t), lerp(lhs.v2, rhs.v2, t), lerp(lhs.v3, rhs.v3, t), lerp(lhs.v4, rhs.v4, t));
}

}

#endif
