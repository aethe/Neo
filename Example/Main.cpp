#include <stdio.h>
#include <neo.hpp>
using namespace neo;

int main() {
    vec2 v1 = vec2(1, 2);
    vec2 v2 = vec2(2, 3);
    vec2 sum = v1 + v2;
    printf("[%.2f, %.2f]\n", v1.x, v2.y);
    return 0;
}
