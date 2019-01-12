//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_VEC3_H
#define ALTMATH_VEC3_H

#include <math.h>

template <typename T>
struct vec3 {
    T x, y, z;

    static vec3 load(const T* v) {
        return {v[0], v[1], v[2]};
    }
    void store(T* v) {
        v[0] = x; v[1] = y; v[2] = z;
    }
};

template <typename T>
inline vec3<T> operator+(vec3<T> a, vec3<T> b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

template <typename T>
inline vec3<T> operator-(vec3<T> a, vec3<T> b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

template <typename T>
inline vec3<T> operator*(vec3<T> a, vec3<T> b) {
    return {a.x * b.x, a.y * b.y, a.z * b.z};
}

template <typename T>
inline vec3<T> operator*(vec3<T> a, T k) {
    return {k * a.x, k * a.y, k * a.z};
}

template <typename T>
inline vec3<T> operator*(T k, vec3<T> a) {
    return {k * a.x, k * a.y, k * a.z};
}

template <typename T>
inline vec3<T> operator/(vec3<T> a, T k) {
    return {a.x / k, a.y / k, a.z / k};
}

template <typename T>
inline vec3<T>& operator+=(vec3<T>& a, vec3<T> b) {
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

template <typename T>
inline vec3<T>& operator-=(vec3<T>& a, vec3<T> b) {
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

template <typename T>
inline vec3<T>& operator*=(vec3<T>& a, vec3<T> b) {
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

template <typename T>
inline vec3<T>& operator*=(vec3<T>& a, T k) {
    a.x *= k;
    a.y *= k;
    a.z *= k;
    return a;
}

template <typename T>
inline vec3<T>& operator/=(vec3<T>& a, T k) {
    a.x /= k;
    a.y /= k;
    a.z /= k;
    return a;
}

template <typename T>
inline bool operator==(vec3<T> a, vec3<T> b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

template <typename T>
inline bool operator!=(vec3<T> a, vec3<T> b) {
    return !(a == b);
}

using vec3f = vec3<float>;
using vec3d = vec3<double>;
using vec3i = vec3<int>;

namespace aml {
    template <typename T>
    inline T dot(vec3<T> a, vec3<T> b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    template <typename T>
    inline vec3<T> cross(vec3<T> a, vec3<T> b) {
        return vec3<T> {
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        };
    }

    template <typename T>
    inline T norm(vec3<T> v) {
        return sqrt(dot(v, v));
    }
    template <typename T>
    inline T normsq(vec3<T> v) {
        return dot(v, v);
    }
    template <typename T>
    inline vec3<T> normalize(vec3<T> v) {
        return v / norm(v);
    }
}

#endif //ALTMATH_VEC3_H
