//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_VEC4_H
#define ALTMATH_VEC4_H

#include <math.h>

template <typename T>
struct vec4 {
    union {
        struct {
            T x, y, z, w;
        };
        T v[4];
    };

    static vec4 make(T x) {
        return {x, x, x, x};
    }
    static vec4 load(const T* in) {
        return {in[0], in[1], in[2], in[3]};
    }
    void store(T* out) {
        out[0] = x; out[1] = y; out[2] = z; out[3] = w;
    }
};

template <typename T>
inline vec4<T> operator+(vec4<T> a, vec4<T> b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}

template <typename T>
inline vec4<T> operator+(vec4<T> a, T b) {
    return {a.x + b, a.y + b, a.z + b, a.w + b};
}

template <typename T>
inline vec4<T> operator+(T a, vec4<T> b) {
    return {a + b.x, a + b.y, a + b.z, a + b.w};
}

template <typename T>
inline vec4<T> operator-(vec4<T> a, vec4<T> b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}

template <typename T>
inline vec4<T> operator-(vec4<T> a, T b) {
    return {a.x - b, a.y - b, a.z - b, a.w - b};
}

template <typename T>
inline vec4<T> operator-(T a, vec4<T> b) {
    return {a - b.x, a - b.y, a - b.z, a - b.w};
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
