//
// Created by lasagnaphil on 2018-10-27.
//

#ifndef ALTMATH_VEC4F_H
#define ALTMATH_VEC4F_H

#include "vec4.h"
#include <immintrin.h>

template <>
struct vec4<float> {
    union {
        struct { float x, y, z, w; };
        __m128 simd;
    };

    static inline vec4f from_simd(__m128 simd) {
        vec4f v;
        v.simd = simd;
        return v;
    }
};

inline vec4f operator+(vec4f a, vec4f b) {
    return vec4f::from_simd(_mm_add_ps(a.simd, b.simd));
}

inline vec4f operator-(vec4f a, vec4f b) {
    return vec4f::from_simd(_mm_sub_ps(a.simd, b.simd));
}

inline vec4f operator*(vec4f a, vec4f b) {
    return vec4f::from_simd(_mm_mul_ps(a.simd, b.simd));
}

inline vec4f operator*(vec4f a, float k) {
    __m128 ksimd = _mm_set1_ps((float)k);
    return vec4f::from_simd(_mm_mul_ps(a.simd, ksimd));
}

inline vec4f operator*(float k, vec4f a) {
    __m128 ksimd = _mm_set1_ps((float)k);
    return vec4f::from_simd(_mm_mul_ps(a.simd, ksimd));
}

inline vec4f operator/(vec4f a, float k) {
    __m128 ksimd = _mm_set1_ps((float)k);
    return vec4f::from_simd(_mm_div_ps(a.simd, ksimd));
}

inline vec4f& operator+=(vec4f& a, vec4f b) {
    a.simd = _mm_add_ps(a.simd, b.simd);
    return a;
}

template <typename T>
inline vec4f& operator-=(vec4f& a, vec4f b) {
    a.simd = _mm_sub_ps(a.simd, b.simd);
    return a;
}

template <typename T>
inline vec4f& operator*=(vec4f& a, vec4f b) {
    a.simd = _mm_mul_ps(a.simd, b.simd);
    return a;
}

inline vec4f& operator*=(vec4f& a, float k) {
    __m128 ksimd = _mm_set1_ps(k);
    a.simd = _mm_mul_ps(a.simd, ksimd);
    return a;
}

inline vec4f& operator/=(vec4f& a, float k) {
    __m128 ksimd = _mm_set1_ps(k);
    a.simd = _mm_div_ps(a.simd, ksimd);
    return a;
}

inline bool operator==(vec4f a, vec4f b) {
    return _mm_movemask_ps(_mm_cmpeq_ps(a.simd, b.simd)) == 0xf;
}

inline bool operator!=(vec4f a, vec4f b) {
    return !(a == b);
}

#endif //ALTMATH_VEC4F_H
