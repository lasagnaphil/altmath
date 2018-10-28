//
// Created by lasagnaphil on 10/28/18.
//

#ifndef FLUID_SIM_QUAT_H
#define FLUID_SIM_QUAT_H

#include "mat4f.h"

template <typename T>
struct quat {
    T s, v0, v1, v2;

    inline mat4<T> toMatrix4() const {
        T x2 = v0 * v0, y2 = v1 * v1, z2 = v2 * v2;
        T sx = s * v0, sy = s * v1, sz = s * v2;
        T xz = v0 * v2, yz = v1 * v2, xy = v0 * v1;
        return mat4<T> {
            1 - 2 * (y2 + z2), 2 * (xy + sz), 2 * (xz - sy), 0.0f,
            2 * (xy - sz), 1 - 2 * (x2 + z2), 2 * (sx + yz), 0.0f,
            2 * (sy + xz), 2 * (yz - sx), 1 - 2 * (x2 + y2), 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };
    }
};

using quatf = quat<float>;
using quatd = quat<double>;
using quati = quat<int>;

#endif //FLUID_SIM_QUAT_H
