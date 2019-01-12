//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_VEC4_H
#define ALTMATH_VEC4_H

#include <math.h>

template <typename T>
struct vec4 {
    T x, y, z, w;

    static vec4 load(const T* v) {
        return {v[0], v[1], v[2], v[3]};
    }
    void store(T* v) {
        v[0] = x; v[1] = y; v[2] = z; v[3] = w;
    }
};

template <typename T>
inline vec4<T> operator+(vec4<T> a, vec4<T> b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}

template <typename T>
inline vec4<T> operator-(vec4<T> a, vec4<T> b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}

template <typename T>
inline vec4<T> operator*(vec4<T> a, vec4<T> b) {
    return {a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}

template <typename T>
inline vec4<T> operator*(vec4<T> a, T k) {
    return {k * a.x, k * a.y, k * a.z, k * a.w};
}

template <typename T>
inline vec4<T> operator*(T k, vec4<T> a) {
    return {k * a.x, k * a.y, k * a.z, k * a.w};
}


template <typename T>
inline vec4<T> operator/(vec4<T> a, T k) {
    return {a.x / k, a.y / k, a.z / k, a.w / k};
}

template <typename T>
inline vec4<T>& operator+=(vec4<T>& a, vec4<T> b) {
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}

template <typename T>
inline vec4<T>& operator-=(vec4<T>& a, vec4<T> b) {
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}

template <typename T>
inline vec4<T>& operator*=(vec4<T>& a, vec4<T> b) {
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}

template <typename T>
inline vec4<T>& operator*=(vec4<T>& a, T k) {
    a.x *= k;
    a.y *= k;
    a.z *= k;
    a.w *= k;
    return a;
}

template <typename T>
inline vec4<T>& operator/=(vec4<T>& a, T k) {
    a.x /= k;
    a.y /= k;
    a.z /= k;
    a.w /= k;
    return a;
}

template <typename T>
inline bool operator==(vec4<T> a, vec4<T> b) {
    return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}

template <typename T>
inline bool operator!=(vec4<T> a, vec4<T> b) {
    return !(a == b);
}

using vec4f = vec4<float>;
using vec4d = vec4<double>;
using vec4i = vec4<int>;

namespace aml {
    template <typename T>
    inline T dot(vec4<T> a, vec4<T> b) {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    }

    template <typename T>
    inline vec4<T> cross(vec4<T> a, vec4<T> b) {
        return vec4<T> {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        };
    }

    template <typename T>
    inline T norm(vec4<T> v) {
        return sqrt(dot(v, v));
    }

    template <typename T>
    inline T normsq(vec4<T> v) {
        return dot(v, v);
    }

    template <typename T>
    inline vec4<T> normalize(vec4<T> v) {
        return v / norm(v);
    }
}

#endif //ALTMATH_VEC4_H
