#include <stdio.h>
#include "../Include/neo.hpp"
using namespace neo;

void print(const float2& vector) {
    printf("[%f, %f]\n", vector.x, vector.y);
}

void print(const float3& vector) {
    printf("[%f, %f, %f]\n", vector.x, vector.y, vector.z);
}

void print(const float4& vector) {
    printf("[%f, %f, %f, %f]\n", vector.x, vector.y, vector.z, vector.w);
}

void print(const float4x4& matrix) {
    printf("[%f, %f, %f, %f]\n", matrix.c0.x, matrix.c1.x, matrix.c2.x, matrix.c3.x);
    printf("[%f, %f, %f, %f]\n", matrix.c0.y, matrix.c1.y, matrix.c2.y, matrix.c3.y);
    printf("[%f, %f, %f, %f]\n", matrix.c0.z, matrix.c1.z, matrix.c2.z, matrix.c3.z);
    printf("[%f, %f, %f, %f]\n", matrix.c0.w, matrix.c1.w, matrix.c2.w, matrix.c3.w);
}

int main() {
    printf("Size of float2 is %ld bytes.\n", sizeof(float2));
    printf("Size of float3 is %ld bytes.\n", sizeof(float3));
    printf("Size of float4 is %ld bytes.\n", sizeof(float4));
    printf("Size of float2x2 is %ld bytes.\n", sizeof(float2x2));
    printf("Size of float3x3 is %ld bytes.\n", sizeof(float3x3));
    printf("Size of float4x4 is %ld bytes.\n", sizeof(float4x4));

    float2 v2(1, -2);
    float3 v3(-2, 0, 1);
    float4 v4(-1, -1, 5, 4);

    float2x2 m2(
        float2(-1, 4),
        float2(-2, 3)
    );

    float3x3 m3(
        float3(2, 1, 1),
        float3(-2, 4, 3),
        float3(3, -3, 1)
    );

    float4x4 m4(
        float4(1, 0, -2, 3),
        float4(1, 2, -2, -2),
        float4(0, 1, 0, -5),
        float4(3, 1, 0, 1)
    );

    printf("\n");
    printf("v3.z = %f\n", v3.z);
    printf("v4.scalars[2] = %f\n", v4.scalars[2]);
    printf("v2[1] = %f\n", v2[1]);
    printf("m2.c0.y = %f\n", m2.c0.y);
    printf("m3[1].x = %f\n", m3[1].x);
    printf("m4[3][1] = %f\n", m4[3][1]);

    return 0;
}
