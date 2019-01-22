//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_MAT4_H
#define ALTMATH_MAT4_H

#include "vec4.h"

template <typename T>
struct mat4 {
    union {
        T m[4][4];
        T p[16];
    };

    static mat4 identity() {
        mat4 m = {};
        m.p[0] = m.p[5] = m.p[10] = m.p[15] = 1;
        return m;
    }
};

using mat4f = mat4<float>;
using mat4d = mat4<double>;
using mat4i = mat4<int>;

template <typename T>
inline bool operator==(const mat4<T>& a, const mat4<T>& b) {
    for (int i = 0; i < 16; i++) {
        if (a.p[i] != b.p[i]) return false;
    }
    return true;
}

template <typename T>
inline bool operator!=(const mat4<T>& a, const mat4<T>& b) {
    return !(a == b);
}

template <typename T>
inline mat4<T> operator+(const mat4<T>& a, const mat4<T>& b) {
    mat4<T> c;
    for (int i = 0; i < 16; i++) {
        c.p[i] = a.p[i] + b.p[i];
    }
    return c;
}

template <typename T>
inline mat4<T> operator-(const mat4<T>& a, const mat4<T>& b) {
    mat4<T> c;
    for (int i = 0; i < 16; i++) {
        c.p[i] = a.p[i] - b.p[i];
    }
    return c;
}

template <typename T>
inline mat4<T> operator*(const mat4<T>& a, const mat4<T>& b) {
    mat4<T> c = {};
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            for (int j = 0; j < 4; j++) {
                c.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return c;
}

template <typename T>
inline vec4<T> operator*(const mat4<T>& a, vec4<T> v) {
    mat4<T> c = {};
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            c.m[i] += a.m[i][k] * v[k];
        }
    }
    return c;
}

template <typename T>
inline mat4<T> operator*(T k, const mat4<T>& a) {
    mat4<T> c;
    for (int i = 0; i < 16; i++) {
        c.p[i] = k * a.p[i];
    }
    return c;
}

template <typename T>
inline mat4<T> operator*(const mat4<T>& a, T k) {
    mat4<T> c;
    for (int i = 0; i < 16; i++) {
        c.p[i] = k * a.p[i];
    }
    return c;
}

template <typename T>
inline mat4<T> operator/(const mat4<T>& a, T k) {
    mat4<T> c;
    for (int i = 0; i < 16; i++) {
        c.p[i] = a.p[i] / k;
    }
    return c;
}

template <typename T>
inline mat4<T>& operator+=(mat4<T>& a, const mat4<T>& b) {
    return a = a + b;
}

template <typename T>
inline mat4<T>& operator-=(mat4<T>& a, const mat4<T>& b) {
    return a = a - b;
}

template <typename T>
inline mat4<T>& operator*=(mat4<T>& a, const mat4<T>& b) {
    return a = a * b;
}

template <typename T>
inline mat4<T>& operator*=(mat4<T>& a, T k) {
    return a = a * k;
}

namespace aml {
}

#endif //ALTMATH_MAT4_H
