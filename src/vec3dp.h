//
// Created by lasagnaphil on 2018-10-27.
//

#ifndef ALTMATH_VEC3D_H
#define ALTMATH_VEC3D_H

struct vec3dp {
    float x; float y; float z;
};

inline vec3dp operator+(vec3dp a, vec3dp b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

inline vec3dp operator-(vec3dp a, vec3dp b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

inline vec3dp operator*(vec3dp a, vec3dp b) {
    return {a.x * b.x, a.y * b.y, a.z * b.z};
}

inline vec3dp operator*(vec3dp a, float k) {
    return {k * a.x, k * a.y, k * a.z};
}

inline vec3dp operator*(float k, vec3dp a) {
    return {k * a.x, k * a.y, k * a.z};
}

inline bool operator==(vec3dp a, vec3dp b) {
    return a.x == b.x && a.y == b.y;
}

inline bool operator!=(vec3dp a, vec3dp b) {
    return !(a == b);
}

#endif //ALTMATH_VEC3D_H
