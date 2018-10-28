//
// Created by lasagnaphil on 2018-10-27.
//

#ifndef ALTMATH_VEC3F_H
#define ALTMATH_VEC3F_H

struct vec3fp {
    float x; float y; float z;
};

inline vec3fp operator+(vec3fp a, vec3fp b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

inline vec3fp operator-(vec3fp a, vec3fp b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

inline vec3fp operator*(vec3fp a, vec3fp b) {
    return {a.x * b.x, a.y * b.y, a.z * b.z};
}

inline vec3fp operator*(vec3fp a, float k) {
    return {k * a.x, k * a.y, k * a.z};
}

inline vec3fp operator*(float k, vec3fp a) {
    return {k * a.x, k * a.y, k * a.z};
}

inline bool operator==(vec3fp a, vec3fp b) {
    return a.x == b.x && a.y == b.y;
}

inline bool operator!=(vec3fp a, vec3fp b) {
    return !(a == b);
}

#endif //ALTMATH_VEC3F_H
