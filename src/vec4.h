//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_VEC4_H
#define ALTMATH_VEC4_H

template <typename T>
struct vec4 {
    float x, y, z, w;
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

template <typename T, typename U>
inline vec4<T> operator*(vec4<T> a, U k) {
    return {k * a.x, k * a.y, k * a.z, k * a.w};
}

template <typename T, typename U>
inline vec4<T> operator*(U k, vec4<T> a) {
    return {k * a.x, k * a.y, k * a.z, k * a.w};
}


template <typename T, typename U>
inline vec4<T> operator/(vec4<T> a, U k) {
    return {a.x / k, a.y / k, a.z / k, a.w / k};
}

template <typename T>
inline vec4<T>& operator+=(const vec4<T>& a, vec4<T> b) {
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}

template <typename T>
inline vec4<T>& operator-=(const vec4<T>& a, vec4<T> b) {
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}

template <typename T>
inline vec4<T>& operator*=(const vec4<T>& a, vec4<T> b) {
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}

template <typename T>
inline vec4<T>& operator*=(const vec4<T>& a, T k) {
    a.x *= k;
    a.y *= k;
    a.z *= k;
    a.w *= k;
    return a;
}

template <typename T>
inline vec4<T>& operator/=(const vec4<T>& a, T k) {
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

#endif //ALTMATH_VEC4_H
