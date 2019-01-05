//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_MAT_UTILS_H
#define ALTMATH_MAT_UTILS_H

#include <math.h>
#include "mat4.h"
#include "quat.h"
#include "vec4.h"
#include "vec3.h"
#include "vec_utils.h"
#include "utility.h"

namespace aml {
    template <typename T>
    mat4<T> scaleMat(vec3<T> scale) {
        return mat4<T> {scale.x, 0, 0, 0,
                        0, scale.y, 0, 0,
                        0, 0, scale.z, 0,
                        0, 0, 0, 1};
    }

    template <typename T>
    mat4<T> scaleMat(vec4<T> scale) {
        return mat4<T> {scale.x, 0, 0, 0,
                        0, scale.y, 0, 0,
                        0, 0, scale.z, 0,
                        0, 0, 0, 1};
    }

    template <typename T>
    mat4<T> transMat(vec3<T> trans) {
        return mat4<T> {1, 0, 0, trans.x,
                        0, 1, 0, trans.y,
                        0, 0, 1, trans.z,
                        0, 0, 0, 1};
    }

    template <typename T>
    mat4<T> transMat(vec4<T> trans) {
        return mat4<T> {1, 0, 0, trans.x,
                        0, 1, 0, trans.y,
                        0, 0, 1, trans.z,
                        0, 0, 0, 1};
    }

    template <typename T>
    mat4<T> lookAt(vec3<T> eye, vec3<T> center, vec3<T> up) {

        auto f = normalize3d(eye - center);
        auto r = normalize3d(cross(up, f));
        auto u = cross(f, r);

        return mat4<T> {
            r.x, r.y, r.z, -dot3d(r, eye),
            u.x, u.y, u.z, -dot3d(u, eye),
            f.x, f.y, f.z, -dot3d(f, eye),
            0, 0, 0, 1.0f
        };
    }

    template <typename T>
    mat4<T> ortho(T left, T right, T bottom, T top, T znear, T zfar) {
        return mat4<T>{2 / (right - left), 0, 0, 0, 0,
                       2 / (top - bottom), 0, 0, 0, 0,
                       -2 / (zfar - znear), 0,
                       -(right + left) / (right - left),
                       -(top + bottom) / (top - bottom),
                       -(zfar + znear) / (zfar - znear), 1};
    }

    template <typename T>
    mat4<T> perspective(float l, float r, float b, float t, float n, float f) {
        return {
                2 * n / (r - l), 0, 0, 0,
                0, 2 * n / (t - b), 0, 0,
                (r + l) / (r - l), (t + b) / (t - b), -2 * f * n / (f - n), -1,
                0, 0, -2 * f * n / (f - n), 0
        };
    }

    template <typename T>
    static mat4<T> perspective(T fovY, T aspect, T front, T back) {
        T tangent = tan(radians(fovY/2));
        T height = front * tangent;
        T width = height * aspect;
        return mat4<T>::perspective(-width, width, -height, height, front, back);
    }

    template <typename T>
    mat4<T> toMatrix4(quat<T> q) {
        T x2 = q.x * q.x, y2 = q.y * q.y , z2 = q.z * q.z;
        T sx = q.w * q.x, sy = q.w * q.y , sz = q.w * q.z;
        T xz = q.x * q.z, yz = q.y * q.z , xy = q.x * q.y;
        return mat4<T>{
                1 - 2 * (y2 + z2), 2 * (xy + sz), 2 * (xz - sy), 0.0f,
                2 * (xy - sz), 1 - 2 * (x2 + z2), 2 * (sx + yz), 0.0f,
                2 * (sy + xz), 2 * (yz - sx), 1 - 2 * (x2 + y2), 0.0f,
                0.0f, 0.0f, 0.0f, 1.0f
        };
    }
}
#endif //ALTMATH_MAT_UTILS_H
