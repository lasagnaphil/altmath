//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_VEC_UTILS_H
#define ALTMATH_VEC_UTILS_H

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

namespace aml {

template <typename T>
vec2<T> xy(vec4<T> v) {
    return vec2<T>(v.x, v.y);
}

template <typename T>
vec3<T> xyz(vec4<T> v) {
    return vec3<T>(v.x, v.y, v.z);
}

template <typename T>
T norm2d(vec2<T> v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

template <typename T>
T norm2d(vec3<T> v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

template <typename T>
T norm2d(vec4<T> v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

template <typename T>
T norm3d(vec3<T> v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

template <typename T>
T norm3d(vec4<T> v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

template <typename T>
T norm4(vec4<T> v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

template <typename T>
vec4<T> normalize3d(vec4<T> v) {
    return v * (1 / norm3d(v));
}

template <typename T>
vec4<T> normalize4d(vec4<T> v) {
    return v * (1 / norm4(v));
}
}

#endif //ALTMATH_VEC_UTILS_H
