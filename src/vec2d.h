//
// Created by lasagnaphil on 2018-10-27.
//

#ifndef ALTMATH_VEC2D_H
#define ALTMATH_VEC2D_H

#include "vec2.h"
#include "math_utils.h"
#include <immintrin.h>

template <>
struct vec2<double> {
    union {
        struct { double x; double y; };
        double v[2];
        __m128d simd;
    };

    static inline vec2<double> make(double v) {
        return from_simd(_mm_set1_pd(v));
    }

    static inline vec2<double> load(const double* in) {
        vec2<double> res;
        res.simd = _mm_load_pd(in);
        return res;
    }

    static inline vec2<double> from_simd(__m128d simd) {
        vec2<double> res;
        res.simd = simd;
        return res;
    }

    void store(double *out) {
        _mm_storeu_pd(out, simd);
    }

    void storeAligned(double *out) {
        _mm_store_pd(out, simd);
    }
};

using vec2d = vec2<double>;

template <>
inline vec2d operator+(vec2d a, vec2d b) {
    return vec2d::from_simd(_mm_add_pd(a.simd, b.simd));
}

template <>
inline vec2d operator-(vec2d a, vec2d b) {
    return vec2d::from_simd(_mm_sub_pd(a.simd, b.simd));
}

template <>
inline vec2d operator*(vec2d a, vec2d b) {
    return vec2d::from_simd(_mm_mul_pd(a.simd, b.simd));
}

template <>
inline vec2d operator*(vec2d a, double k) {
    __m128d ksimd = _mm_load1_pd(&k);
    return vec2d::from_simd(_mm_mul_pd(a.simd, ksimd));
}

template <>
inline vec2d operator*(double k, vec2d a) {
    __m128d ksimd = _mm_load1_pd(&k);
    return vec2d::from_simd(_mm_mul_pd(a.simd, ksimd));
}

template <>
inline vec2d operator/(vec2d a, double k) {
    __m128d ksimd = _mm_load1_pd(&k);
    return vec2d::from_simd(_mm_div_pd(a.simd, ksimd));
}

template <>
inline vec2d& operator+=(vec2d& a, vec2d b) {
    a.simd = _mm_add_pd(a.simd, b.simd);
    return a;
}

template <>
inline vec2d& operator-=(vec2d& a, vec2d b) {
    a.simd = _mm_sub_pd(a.simd, b.simd);
    return a;
}

template <>
inline vec2d& operator*=(vec2d& a, vec2d b) {
    a.simd = _mm_mul_pd(a.simd, b.simd);
    return a;
}

template <>
inline vec2d& operator*=(vec2d& a, double k) {
    __m128d ksimd = _mm_load1_pd(&k);
    a.simd = _mm_mul_pd(a.simd, ksimd);
    return a;
}

template <>
inline vec2d& operator/=(vec2d& a, double k) {
    __m128d ksimd = _mm_load1_pd(&k);
    a.simd = _mm_div_pd(a.simd, ksimd);
    return a;
}

template <>
inline bool operator==(vec2d a, vec2d b) {
    return _mm_movemask_pd(_mm_cmpeq_pd(a.simd, b.simd)) == 0x3;
}

template <>
inline bool operator!=(vec2d a, vec2d b) {
    return !(a == b);
}

namespace aml {
    template <>
    inline vec2d sqrt(vec2d a) {
        return vec2d::from_simd(_mm_sqrt_pd(a.simd));
    }

    template <>
    inline vec2d floor(vec2d a) {
        return vec2d::from_simd(_mm_floor_pd(a.simd));
    }

    template <>
    inline double dot(vec2d a, vec2d b) {
        vec2d m;
        m.simd = _mm_mul_pd(a.simd, b.simd);
        return m.x + m.y;
    }

    template <>
    inline double norm(vec2d v) {
        return sqrt(normsq(v));
    }

}

#endif //ALTMATH_VEC2D_H
