//
// Created by lasagnaphil on 2018-10-27.
//

#ifndef ALTMATH_VEC4F_H
#define ALTMATH_VEC4F_H

#include "vec4.h"
#include "math_utils.h"
#include <immintrin.h>

template <>
struct vec4<float> {
    union {
        struct { float x, y, z, w; };
        __m128 simd;
    };

    static inline vec4f load(const float* v) {
        vec4f res;
        res.simd = _mm_load_ps(v);
        return res;
    }

    static inline vec4f from_simd(__m128 simd) {
        vec4f res;
        res.simd = simd;
        return res;
    }

    void store(float* v) {
        _mm_store_ps(v, simd);
    }
};

template <>
inline vec4f operator+(vec4f a, vec4f b) {
    return vec4f::from_simd(_mm_add_ps(a.simd, b.simd));
}

template <>
inline vec4f operator-(vec4f a, vec4f b) {
    return vec4f::from_simd(_mm_sub_ps(a.simd, b.simd));
}

template <>
inline vec4f operator*(vec4f a, vec4f b) {
    return vec4f::from_simd(_mm_mul_ps(a.simd, b.simd));
}

template <>
inline vec4f operator*(vec4f a, float k) {
    __m128 ksimd = _mm_set1_ps((float)k);
    return vec4f::from_simd(_mm_mul_ps(a.simd, ksimd));
}

template <>
inline vec4f operator*(float k, vec4f a) {
    __m128 ksimd = _mm_set1_ps((float)k);
    return vec4f::from_simd(_mm_mul_ps(a.simd, ksimd));
}

template <>
inline vec4f operator/(vec4f a, float k) {
    __m128 ksimd = _mm_set1_ps((float)k);
    return vec4f::from_simd(_mm_div_ps(a.simd, ksimd));
}

template <>
inline vec4f& operator+=(vec4f& a, vec4f b) {
    a.simd = _mm_add_ps(a.simd, b.simd);
    return a;
}

template <>
inline vec4f& operator-=(vec4f& a, vec4f b) {
    a.simd = _mm_sub_ps(a.simd, b.simd);
    return a;
}

template <>
inline vec4f& operator*=(vec4f& a, vec4f b) {
    a.simd = _mm_mul_ps(a.simd, b.simd);
    return a;
}

template <>
inline vec4f& operator*=(vec4f& a, float k) {
    __m128 ksimd = _mm_set1_ps(k);
    a.simd = _mm_mul_ps(a.simd, ksimd);
    return a;
}

template <>
inline vec4f& operator/=(vec4f& a, float k) {
    __m128 ksimd = _mm_set1_ps(k);
    a.simd = _mm_div_ps(a.simd, ksimd);
    return a;
}

template <>
inline bool operator==(vec4f a, vec4f b) {
    return _mm_movemask_ps(_mm_cmpeq_ps(a.simd, b.simd)) == 0xf;
}

template <>
inline bool operator!=(vec4f a, vec4f b) {
    return !(a == b);
}

namespace aml {
    template <>
    inline vec4f sqrt(vec4f a) {
        return vec4f::from_simd(_mm_sqrt_ps(a.simd));
    }
    // FROM: https://stackoverflow.com/questions/6996764/fastest-way-to-do-horizontal-float-vector-sum-on-x86
    template <>
    inline float dot(vec4f a, vec4f b) {
        __m128 m = _mm_mul_ps(a.simd, b.simd);
        __m128 shuf = _mm_movehdup_ps(m);        // broadcast elements 3,1 to 2,0
        __m128 sums = _mm_add_ps(m, shuf);
        shuf        = _mm_movehl_ps(shuf, sums); // high half -> low half
        sums        = _mm_add_ss(sums, shuf);
        return        _mm_cvtss_f32(sums);
    }

    template <>
    inline vec4f cross(vec4f a, vec4f b) {
        __m128 a1 = _mm_shuffle_ps(a.simd, a.simd, _MM_SHUFFLE(3, 0, 2, 1));
        __m128 a2 = _mm_shuffle_ps(a.simd, a.simd, _MM_SHUFFLE(3, 1, 0, 2));
        __m128 b1 = _mm_shuffle_ps(b.simd, b.simd, _MM_SHUFFLE(3, 1, 0, 2));
        __m128 b2 = _mm_shuffle_ps(b.simd, b.simd, _MM_SHUFFLE(3, 0, 2, 1));
        return vec4f::from_simd(_mm_sub_ps(_mm_mul_ps(a1, b1), _mm_mul_ps(a2, b2)));
    }

    template <>
    inline float norm(vec4f v) {
        return sqrtf(normsq(v));
    }
}

#endif //ALTMATH_VEC4F_H
