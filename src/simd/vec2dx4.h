//
// Created by lasagnaphil on 2019-01-12.
//

#ifndef ALTMATH_VEC2DX4_H
#define ALTMATH_VEC2DX4_H

#ifdef ALTMATH_USE_SIMD

#include "vec2d.h"
#include "vec4d.h"

using vec2dx4 = vec2<vec4d>;

template <>
struct vec2<vec4d> {
    vec4d x, y;

    inline static vec2<vec4d> load(const double* x, const double* y) {
        return {vec4d::load(x), vec4d::load(y)};
    }

    inline static vec2<vec4d> loadAligned(const double* x, const double* y) {
        return {vec4d::loadAligned(x), vec4d::loadAligned(y)};
    }

    inline static vec2<vec4d> load(vec2d* v) {
        return {
            vec4d{v[0].x, v[1].x, v[2].x, v[3].x},
            vec4d{v[0].y, v[1].y, v[2].y, v[3].y}
        };
    }

    void store(double* vx, double* vy) {
        x.storeAligned(vx);
        y.storeAligned(vy);
    }
};

inline vec2dx4 operator*(vec2dx4 a, double k) {
    __m256d ksimd = _mm256_set1_pd(k);
    a.x.simd = _mm256_mul_pd(a.x.simd, ksimd);
    a.y.simd = _mm256_mul_pd(a.y.simd, ksimd);
    return a;
}

inline vec2dx4 operator*(double k, vec2dx4 a) {
    __m256d ksimd = _mm256_set1_pd(k);
    a.x.simd = _mm256_mul_pd(a.x.simd, ksimd);
    a.y.simd = _mm256_mul_pd(a.y.simd, ksimd);
    return a;
}

inline vec2dx4 operator/(vec2dx4 a, double k) {
    __m256d ksimd = _mm256_set1_pd(k);
    a.x.simd = _mm256_div_pd(a.x.simd, ksimd);
    a.y.simd = _mm256_div_pd(a.y.simd, ksimd);
    return a;
}

inline vec2dx4& operator*=(vec2dx4& a, double k) {
    __m256d ksimd = _mm256_set1_pd(k);
    a.x.simd = _mm256_mul_pd(a.x.simd, ksimd);
    a.y.simd = _mm256_mul_pd(a.y.simd, ksimd);
    return a;
}

inline vec2dx4& operator*=(double k, vec2dx4& a) {
    __m256d ksimd = _mm256_set1_pd(k);
    a.x.simd = _mm256_mul_pd(a.x.simd, ksimd);
    a.y.simd = _mm256_mul_pd(a.y.simd, ksimd);
    return a;
}

inline vec2dx4& operator/=(vec2dx4& a, double k) {
    __m256d ksimd = _mm256_set1_pd(k);
    a.x.simd = _mm256_div_pd(a.x.simd, ksimd);
    a.y.simd = _mm256_div_pd(a.y.simd, ksimd);
    return a;
}

#endif
#endif //ALTMATH_VEC2DX4_H
