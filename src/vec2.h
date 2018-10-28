//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_VEC2_H
#define ALTMATH_VEC2_H

template <typename T>
struct vec2 {
    T x, y;
};

template <typename T>
inline vec2<T> operator+(vec2<T> a, vec2<T> b) {
    return {a.x + b.x, a.y + b.y};
}

template <typename T>
inline vec2<T> operator-(vec2<T> a, vec2<T> b) {
    return {a.x - b.x, a.y - b.y};
}


template <typename T>
inline vec2<T> operator*(vec2<T> a, vec2<T> b) {
    return {a.x * b.x, a.y * b.y};
}

template <typename T, typename U>
inline vec2<T> operator*(vec2<T> a, U k) {
    return {k * a.x, k * a.y};
}

template <typename T, typename U>
inline vec2<T> operator*(U k, vec2<T> a) {
    return {k * a.x, k * a.y};
}

template <typename T, typename U>
inline vec2<T> operator/(vec2<T> a, U k) {
    return {a.x / k, a.y / k};
}

template <typename T>
inline vec2<T>& operator+=(vec2<T>& a, vec2<T> b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

template <typename T>
inline vec2<T>& operator-=(vec2<T>& a, vec2<T> b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

template <typename T>
inline vec2<T>& operator*=(vec2<T>& a, vec2<T> b) {
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

template <typename T>
inline vec2<T>& operator*=(vec2<T>& a, T k) {
    a.x *= k;
    a.y *= k;
    return a;
}

template <typename T>
inline vec2<T>& operator/=(vec2<T>& a, T k) {
    a.x /= k;
    a.y /= k;
    return a;
}

template <typename T>
inline bool operator==(vec2<T> a, vec2<T> b) {
    return a.x == b.x && a.y == b.y;
}

template <typename T>
inline bool operator!=(vec2<T> a, vec2<T> b) {
    return !(a == b);
}

using vec2f = vec2<float>;
using vec2d = vec2<double>;
using vec2i = vec2<int>;

#endif //ALTMATH_VEC2_H
