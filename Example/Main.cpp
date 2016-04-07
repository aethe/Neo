#include <stdio.h>
#include "../Include/neo.hpp"
using namespace neo;

void print(const float2& vector) {
    printf("[%f, %f]\n", vector.x, vector.y);
}

void print(const float4x4& matrix) {
    printf("[%f, %f, %f, %f]\n", matrix.c0.x, matrix.c1.x, matrix.c2.x, matrix.c3.x);
    printf("[%f, %f, %f, %f]\n", matrix.c0.y, matrix.c1.y, matrix.c2.y, matrix.c3.y);
    printf("[%f, %f, %f, %f]\n", matrix.c0.z, matrix.c1.z, matrix.c2.z, matrix.c3.z);
    printf("[%f, %f, %f, %f]\n", matrix.c0.w, matrix.c1.w, matrix.c2.w, matrix.c3.w);
}

int main() {
    float2 v1 = float2(1, 2);
    float2 v2 = float2(2, 3);
    float2 sum = v1 + v2;
    printf("[%.2f, %.2f]\n", v1.x, v2.y);

    float4x4 m1(
        float4(1, 4, 2, -2),
        float4(2, -3, 0, 1),
        float4(4, -4, 2, 3),
        float4(0, 1, 1, 2)
    );

    printf("Before inverse:\n");
    print(m1);
    m1 = m1.inverse();
    printf("After inverse:\n");
    print(m1);

    return 0;
}
