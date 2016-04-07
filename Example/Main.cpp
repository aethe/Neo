#include <stdio.h>
#include "../Include/neo.hpp"
using namespace neo;

int main() {
    float2 v1 = float2(1, 2);
    float2 v2 = float2(2, 3);
    float2 sum = v1 + v2;
    printf("[%.2f, %.2f]\n", v1.x, v2.y);
    return 0;
}
