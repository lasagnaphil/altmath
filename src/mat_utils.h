//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_MAT_UTILS_H
#define ALTMATH_MAT_UTILS_H

#include "mat4.h"
#include "vec4.h"
#include "vec3.h"

namespace aml {
    template <typename T>
    mat4<T> matFromScale(vec3<T> scale) {
        return mat4<T> {scale.x, 0, 0, 0,
                        0, scale.y, 0, 0,
                        0, 0, scale.z, 0,
                        0, 0, 0, 1};
    }

    template <typename T>
    mat4<T> matFromScale(vec4<T> scale) {
        return mat4<T> {scale.x, 0, 0, 0,
                        0, scale.y, 0, 0,
                        0, 0, scale.z, 0,
                        0, 0, 0, 1};
    }

    template <typename T>
    mat4<T> matFromTrans(vec4<T> trans) {
        return mat4<T> {1, 0, 0, trans.x,
                        0, 1, 0, trans.y,
                        0, 0, 1, trans.z,
                        0, 0, 0, 1};
    }
}
#endif //ALTMATH_MAT_UTILS_H
