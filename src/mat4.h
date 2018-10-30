//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_MAT4_H
#define ALTMATH_MAT4_H

template <typename T>
struct mat4 {
    T data[16];
};

using mat4f = mat4<float>;
using mat4d = mat4<double>;
using mat4i = mat4<int>;

#endif //ALTMATH_MAT4_H