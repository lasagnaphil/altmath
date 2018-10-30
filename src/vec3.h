//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_VEC3_H
#define ALTMATH_VEC3_H

template <typename T>
struct vec3 {
    T x, y, z;
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

#endif //ALTMATH_VEC3_H