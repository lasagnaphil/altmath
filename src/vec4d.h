//
// Created by lasagnaphil on 2018-10-27.
//

#ifndef ALTMATH_VEC4D_H
#define ALTMATH_VEC4D_H

#include "vec4.h"
#include <immintrin.h>

template <>
struct vec4<double> {
    union {
        struct { double x, y, z, w; };
        __m256d simd;
    };

    static inline vec4d from_simd(__m256d simd) {
        vec4d v;
        v.simd = simd;
        return v;
    }
};

inline vec4d operator+(vec4d a, vec4d b) {
    return vec4d::from_simd(_mm256_add_pd(a.simd, b.simd));
}

inline vec4d operator-(vec4d a, vec4d b) {
    return vec4d::from_simd(_mm256_sub_pd(a.simd, b.simd));
}

inline vec4d operator*(vec4d a, vec4d b) {
    return vec4d::from_simd(_mm256_mul_pd(a.simd, b.simd));
}

inline vec4d operator*(vec4d a, double k) {
    __m256d ksimd = _mm256_broadcast_sd(&k);
    return vec4d::from_simd(_mm256_mul_pd(a.simd, ksimd));
}

inline vec4d operator*(double k, vec4d a) {
    __m256d ksimd = _mm256_broadcast_sd(&k);
    return vec4d::from_simd(_mm256_mul_pd(a.simd, ksimd));
}

inline vec4d operator/(vec4d a, double k) {
    __m256d ksimd = _mm256_broadcast_sd(&k);
    return vec4d::from_simd(_mm256_div_pd(a.simd, ksimd));
}

inline vec4d& operator+=(vec4d& a, vec4d b) {
    a.simd = _mm256_add_pd(a.simd, b.simd);
    return a;
}

template <typename T>
inline vec4d& operator-=(vec4d& a, vec4d b) {
    a.simd = _mm256_sub_pd(a.simd, b.simd);
    return a;
}

template <typename T>
inline vec4d& operator*=(vec4d& a, vec4d b) {
    a.simd = _mm256_mul_pd(a.simd, b.simd);
    return a;
}

inline vec4d& operator*=(vec4d& a, double k) {
    __m256d ksimd = _mm256_broadcast_sd(&k);
    a.simd = _mm256_mul_pd(a.simd, ksimd);
    return a;
}

inline vec4d& operator/=(vec4d& a, double k) {
    __m256d ksimd = _mm256_broadcast_sd(&k);
    a.simd = _mm256_div_pd(a.simd, ksimd);
    return a;
}

inline bool operator==(vec4d a, vec4d b) {
    return _mm256_movemask_pd(_mm256_cmp_pd(a.simd, b.simd, _CMP_EQ_OQ)) == 0xf;
}

inline bool operator!=(vec4d a, vec4d b) {
    return !(a == b);
}

namespace aml {
    template <>
    inline double normsq(vec4d v) {
        __m256d m = _mm256_mul_pd(v.simd, v.simd);
        __m256d temp = _mm256_hadd_pd(m, m);
        __m128d lo = _mm256_extractf128_pd(temp, 0);
        __m128d hi = _mm256_extractf128_pd(temp, 1);
        __m128d dp = _mm_add_pd(lo, hi);
        return _mm_cvtsd_f64(dp);
    }

    template <>
    inline double norm(vec4d v) {
        return sqrt(normsq(v));
    }
}

#endif //ALTMATH_VEC4D_H
