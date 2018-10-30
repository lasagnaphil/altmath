//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_VEC_UTILS_H
#define ALTMATH_VEC_UTILS_H

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "vec4f.h"

namespace aml {

    template <typename T>
    vec2<T> xy(vec3<T> v) {
        return vec2<T> {v.x, v.y};
    }

    template <typename T>
    vec2<T> xy(vec4<T> v) {
        return vec2<T> {v.x, v.y};
    }

    template <typename T>
    vec3<T> xyz(vec4<T> v) {
        return vec3<T> {v.x, v.y, v.z};
    }

    // TODO: use SIMD for norm() (vec2f, vec4f, vec2d, vec4d)
    template <typename T>
    T norm(vec2<T> v) {
        return sqrt(v.x * v.x + v.y * v.y);
    }

    template <typename T>
    T norm(vec3<T> v) {
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    template <typename T>
    T norm(vec4<T> v) {
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w + v.w);
    }

    template <typename T>
    vec2<T> normalize(vec2<T> v) {
        return v / norm(v);
    }

    template <typename T>
    vec3<T> normalize(vec3<T> v) {
        return v / norm(v);
    }

    template <typename T>
    vec4<T> normalize(vec4<T> v) {
        return v / norm(v);
    }
}

#endif //ALTMATH_VEC_UTILS_H
