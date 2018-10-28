//
// Created by lasagnaphil on 2018-10-27.
//

#ifndef ALTMATH_VEC2F_H
#define ALTMATH_VEC2F_H

#include <immintrin.h>

struct vec2fp {
    float x; float y;
};

inline vec2fp operator+(vec2fp a, vec2fp b) {
    return {a.x + b.x, a.y + b.y};
}

inline vec2fp operator-(vec2fp a, vec2fp b) {
    return {a.x - b.x, a.y - b.y};
}

inline vec2fp operator*(vec2fp a, vec2fp b) {
    return {a.x * b.x, a.y * b.y};
}

inline vec2fp operator*(vec2fp a, float k) {
    return {k * a.x, k * a.y};
}

inline vec2fp operator*(float k, vec2fp a) {
    return {k * a.x, k * a.y};
}

inline bool operator==(vec2fp a, vec2fp b) {
    return a.x == b.x && a.y == b.y;
}

inline bool operator!=(vec2fp a, vec2fp b) {
    return !(a == b);
}

#endif //ALTMATH_VEC2F_H
