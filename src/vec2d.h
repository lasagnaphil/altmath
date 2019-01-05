//
// Created by lasagnaphil on 2018-10-27.
//

#ifndef ALTMATH_VEC2D_H
#define ALTMATH_VEC2D_H

#include "vec2.h"
#include <immintrin.h>

template <>
struct vec2<double> {
    union {
        struct {
            double x; double y;
        };
        __m128d simd;
    };

    static inline vec2<double> from_simd(__m128d simd) {
        vec2<double> v;
        v.simd = simd;
        return v;
    }
};

using vec2d = vec2<double>;

inline vec2d operator+(vec2d a, vec2d b) {
    return vec2d::from_simd(_mm_add_pd(a.simd, b.simd));
}

inline vec2d operator-(vec2d a, vec2d b) {
    return vec2d::from_simd(_mm_sub_pd(a.simd, b.simd));
}

inline vec2d operator*(vec2d a, vec2d b) {
    return vec2d::from_simd(_mm_mul_pd(a.simd, b.simd));
}

inline vec2d operator*(vec2d a, double k) {
    __m128d ksimd = _mm_load1_pd(&k);
    return vec2d::from_simd(_mm_mul_pd(a.simd, ksimd));
}

inline vec2d operator*(double k, vec2d a) {
    __m128d ksimd = _mm_load1_pd(&k);
    return vec2d::from_simd(_mm_mul_pd(a.simd, ksimd));
}

inline vec2d operator/(vec2d a, double k) {
    __m128d ksimd = _mm_load1_pd(&k);
    return vec2d::from_simd(_mm_div_pd(a.simd, ksimd));
}

inline vec2d& operator+=(vec2d& a, vec2d b) {
    a.simd = _mm_add_pd(a.simd, b.simd);
    return a;
}

inline vec2d& operator-=(vec2d& a, vec2d b) {
    a.simd = _mm_sub_pd(a.simd, b.simd);
    return a;
}

inline vec2d& operator*=(vec2d& a, vec2d b) {
    a.simd = _mm_mul_pd(a.simd, b.simd);
    return a;
}

inline vec2d& operator*=(vec2d& a, double k) {
    __m128d ksimd = _mm_load1_pd(&k);
    a.simd = _mm_mul_pd(a.simd, ksimd);
    return a;
}

inline vec2d& operator/=(vec2d& a, double k) {
    __m128d ksimd = _mm_load1_pd(&k);
    a.simd = _mm_div_pd(a.simd, ksimd);
    return a;
}

inline bool operator==(vec2d a, vec2d b) {
    return _mm_movemask_pd(_mm_cmpeq_pd(a.simd, b.simd)) == 0x3;
}

inline bool operator!=(vec2d a, vec2d b) {
    return !(a == b);
}

namespace aml {
    template <>
    inline double normsq(vec2d v) {
        vec2d m;
        m.simd = _mm_mul_pd(v.simd, v.simd);
        return m.x + m.y;
    }

    template <>
    inline double norm(vec2d v) {
        return sqrt(normsq(v));
    }

}

#endif //ALTMATH_VEC2D_H
