//
// Created by lasagnaphil on 10/28/18.
//

#ifndef FLUID_SIM_QUAT_H
#define FLUID_SIM_QUAT_H

template <typename T>
struct quat {
    T s, v0, v1, v2;

};

using quatf = quat<float>;
using quatd = quat<double>;
using quati = quat<int>;

#endif //FLUID_SIM_QUAT_H
