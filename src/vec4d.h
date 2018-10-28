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
    return vec4d::from_simd(_mm256_mul_pd(ksimd, a.simd));
}

inline vec4d operator*(double k, vec4d a) {
    __m256d ksimd = _mm256_broadcast_sd(&k);
    return vec4d::from_simd(_mm256_mul_pd(ksimd, a.simd));
}

inline bool operator==(vec4d a, vec4d b) {
    return _mm256_movemask_pd(_mm256_cmp_pd(a.simd, b.simd, _CMP_EQ_OQ)) == 0xf;
}

inline bool operator!=(vec4d a, vec4d b) {
    return !(a == b);
}

using vec3dx = vec4d;

#endif //ALTMATH_VEC4D_H
