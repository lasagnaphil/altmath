//
// Created by lasagnaphil on 10/28/18.
//

#ifndef FLUID_SIM_QUAT_H
#define FLUID_SIM_QUAT_H

// Some parts from https://github.com/adriankrupa/swift3D

#include "vec3.h"
#include "vec4.h"

template <typename T>
struct quat {
    // Note: should we use wxyz or xyzw layout?
    // xyzw Pros:
    // - Compatible with vec4, so more efficient quat-vec multiplication
    // xyzw Cons:
    // - More confusing initialization
    T x, y, z, w;
};

template <typename T>
inline quat<T> operator-(quat<T> q) {
    return quat<T> {-q.x, -q.y, -q.z, -q.w};
}

template <typename T>
inline quat<T> operator+(quat<T> p, quat<T> q) {
    return quat<T> {p.x + q.x, p.y + q.y, p.z + q.z, p.w + q.w};
}

template <typename T>
inline quat<T> operator-(quat<T> p, quat<T> q) {
    return quat<T> {p.x - q.x, p.y - q.y, p.z - q.z, p.w - q.w};
}

template <typename T>
inline quat<T> operator*(quat<T> p, quat<T> q) {
    T x = p.w * q.x + p.x * q.w + p.y * q.z - p.z * q.y;
    T y = p.w * q.y + p.y * q.w + p.z * q.x - p.x * q.z;
    T z = p.w * q.z + p.z * q.w + p.x * q.y - p.y * q.x;
    T w = p.w * q.w - p.x * q.x - p.y * q.y - p.z * q.z;
    return quat<T> {x, y, z, w};
}

template <typename T>
inline quat<T> operator*(quat<T> q, vec3<T> v) {
    vec3<T> qv {q.x, q.y, q.z};
    vec3<T> uv = aml::cross(qv, v);
    vec3<T> uuv = aml::cross(qv, uv);
    return v + ((uv * q.w) + uuv) * (T)2;
}

template <typename T>
inline quat<T> operator*(quat<T> q, vec4<T> v) {
    vec4<T> qv {q.x, q.y, q.z, q.w};
    vec4<T> uv = aml::cross(qv, v);
    vec4<T> uuv = aml::cross(qv, uv);
    return v + ((uv * q.w) + uuv) * (T)2;
}

template <typename T>
inline quat<T> operator*(quat<T> q, float k) {
    return quat<T> {q.x * k, q.y * k, q.z * k, q.w * k};
}

template <typename T>
inline quat<T> operator*(float k, quat<T> q) {
    return q * k;
}

template <typename T>
inline quat<T> operator/(quat<T> q, float k) {
    return quat<T> {q.x / k, q.y / k, q.z / k, q.w / k};
}

using quatf = quat<float>;
using quatd = quat<double>;
using quati = quat<int>;

namespace aml {
    template <typename T>
    inline quat<T> conj(quat<T> q) {
        return quat<T> {-q.x, -q.y, -q.z, -q.w};
    }

    template <typename T>
    inline T normsq(quat<T> q) {
        return q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
    }

    template <typename T>
    inline T norm(quat<T> q) {
        return sqrt(normsq(q));
    }

    template <typename T>
    inline quat<T> normalize(quat<T> q) {
        return q / norm(q);
    }
}

#endif //FLUID_SIM_QUAT_H
