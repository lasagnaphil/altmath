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
        return mat4<T> {1, 0, 0, 0,
                        0, 1, 0, 0,
                        0, 0, 1, 0,
                        trans.x, trans.y, trans.z, 1};
    }

    template <typename T>
    mat4<T> transMat(vec4<T> trans) {
        return mat4<T> {1, 0, 0, 0,
                        0, 1, 0, 0,
                        0, 0, 1, 0,
                        trans.x, trans.y, trans.z, 1};
    }

    template <typename T>
    mat4<T> lookAt(vec3<T> eye, vec3<T> center, vec3<T> up) {

        auto f = normalize(eye - center);
        auto r = normalize(cross(up, f));
        auto u = cross(f, r);

        return mat4<T> {
            r.x, r.y, r.z, -dot(r, eye),
            u.x, u.y, u.z, -dot(u, eye),
            f.x, f.y, f.z, -dot(f, eye),
            0, 0, 0, 1.0f
        };
    }

    template <typename T>
    mat4<T> ortho(T left, T right, T bottom, T top, T znear, T zfar, T handedness = 1) {
        return mat4<T>{(T)2 / (right - left), 0, 0, 0, 0,
                       (T)2 / (top - bottom), 0, 0, 0, 0,
                       -(T)2 * handedness / (zfar - znear), 0,
                       -(right + left) / (right - left),
                       -(top + bottom) / (top - bottom),
                       -(zfar + znear) / (zfar - znear), (T)1};
    }

    template <typename T>
    static mat4<T> perspective(T l, T r, T b, T t, T n, T f) {
        return {
                2 * n / (r - l), 0, 0, 0,
                0, 2 * n / (t - b), 0, 0,
                (r + l) / (r - l), (t + b) / (t - b), -2 * f * n / (f - n), -1,
                0, 0, -2 * f * n / (f - n), 0
        };
    }

    template <typename T>
    static mat4<T> perspective(T fovY, T aspect, T znear, T zfar, T handedness = 1) {
        T y = 1 / tan(fovY * (T)0.5);
        T x = y / aspect;
        T zdist = znear - zfar;
        T zfar_per_zdist = zfar/zdist;
        return {
            x, 0, 0, 0,
            0, y, 0, 0,
            0, 0, zfar_per_zdist * handedness, -1 * handedness,
            0, 0, 2.0f * znear * zfar_per_zdist, 0
        };
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
