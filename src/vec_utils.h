//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_VEC_UTILS_H
#define ALTMATH_VEC_UTILS_H

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "vec2d.h"
#include "vec4f.h"
#include "vec4d.h"

namespace aml {

    template<typename T>
    inline vec2<T> xy(vec3<T> v) {
        return vec2<T>{v.x, v.y};
    }

    template<typename T>
    inline vec2<T> xy(vec4<T> v) {
        return vec2<T>{v.x, v.y};
    }

    template <typename T>
    inline vec3<T> xyz(vec4<T> v) {
        return vec3<T> {v.x, v.y, v.z};
    }

    template <typename T>
    inline vec2d toDouble(vec2<T> v) {
        return vec2d {(float)v.x, (float)v.y};
    }

    template <typename T>
    inline vec3d toDouble(vec3<T> v) {
        return vec3d {(float)v.x, (float)v.y, (float)v.z};
    }

    template <typename T>
    inline vec4d toDouble(vec4<T> v) {
        return vec4d {(float)v.x, (float)v.y, (float)v.z, (float)v.w};
    }

    template <typename T>
    inline vec2f toFloat(vec2<T> v) {
        return vec2f {(float)v.x, (float)v.y};
    }

    template <typename T>
    inline vec3f toFloat(vec3<T> v) {
        return vec3f {(float)v.x, (float)v.y, (float)v.z};
    }

    template <typename T>
    inline vec4f toFloat(vec4<T> v) {
        return vec4f {(float)v.x, (float)v.y, (float)v.z, (float)v.w};
    }
}

#endif //ALTMATH_VEC_UTILS_H
