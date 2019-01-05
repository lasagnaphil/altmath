//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_VEC_UTILS_H
#define ALTMATH_VEC_UTILS_H

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

namespace aml {
    template<typename T>
    vec2<T> xy(vec3<T> v) {
        return vec2<T>{v.x, v.y};
    }

    template<typename T>
    vec2<T> xy(vec4<T> v) {
        return vec2<T>{v.x, v.y};
    }

    template <typename T>
    vec3<T> xyz(vec4<T> v) {
        return vec3<T> {v.x, v.y, v.z};
    }
}

#endif //ALTMATH_VEC_UTILS_H
