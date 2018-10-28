//
// Created by lasagnaphil on 2018-10-27.
//

#ifndef ALTMATH_MAT4D_H
#define ALTMATH_MAT4D_H

#include <immintrin.h>
#include "vec4d.h"

struct mat4d {
    union {
        double data[16];
        __m256d simd[4];
    };

    static mat4d from_simd(__m256d simd0, __m256d simd1, __m256d simd2, __m256d simd3) {
        mat4d mat;
        mat.simd[0] = simd0;
        mat.simd[1] = simd1;
        mat.simd[2] = simd2;
        mat.simd[3] = simd3;
        return mat;
    }

    inline double& operator[](int i) {
        return data[i];
    }

    inline const double& operator[](int i) const {
        return data[i];
    }
};

inline bool operator==(const mat4d& a, const mat4d& b) {
    return _mm256_movemask_pd(_mm256_cmp_pd(a.simd[0], b.simd[0], _CMP_EQ_OQ)) == 0xf &&
           _mm256_movemask_pd(_mm256_cmp_pd(a.simd[1], b.simd[1], _CMP_EQ_OQ)) == 0xf &&
           _mm256_movemask_pd(_mm256_cmp_pd(a.simd[2], b.simd[2], _CMP_EQ_OQ)) == 0xf &&
           _mm256_movemask_pd(_mm256_cmp_pd(a.simd[3], b.simd[3], _CMP_EQ_OQ)) == 0xf;
}

inline bool operator!=(const mat4d& a, const mat4d& b) {
    return !(a == b);
}

inline mat4d operator+(const mat4d& a, const mat4d& b) {
    __m256d v1 = _mm256_add_pd(a.simd[0], b.simd[0]);
    __m256d v2 = _mm256_add_pd(a.simd[1], b.simd[1]);
    __m256d v3 = _mm256_add_pd(a.simd[2], b.simd[2]);
    __m256d v4 = _mm256_add_pd(a.simd[3], b.simd[3]);
    return mat4d::from_simd(v1, v2, v3, v4);
}

inline mat4d operator-(const mat4d& a, const mat4d& b) {
    __m256d v1 = _mm256_sub_pd(a.simd[0], b.simd[0]);
    __m256d v2 = _mm256_sub_pd(a.simd[1], b.simd[1]);
    __m256d v3 = _mm256_sub_pd(a.simd[2], b.simd[2]);
    __m256d v4 = _mm256_sub_pd(a.simd[3], b.simd[3]);
    return mat4d::from_simd(v1, v2, v3, v4);
}

inline mat4d operator*(const mat4d& a, const mat4d& b) {
    mat4d res;
    __m256d row1 = b.simd[0];
    __m256d row2 = b.simd[1];
    __m256d row3 = b.simd[2];
    __m256d row4 = b.simd[3];
    for (int i = 0; i < 4; i++) {
        __m256d brod1 = _mm256_broadcast_sd(&a[4*i + 0]);
        __m256d brod2 = _mm256_broadcast_sd(&a[4*i + 1]);
        __m256d brod3 = _mm256_broadcast_sd(&a[4*i + 2]);
        __m256d brod4 = _mm256_broadcast_sd(&a[4*i + 3]);
        // FMA for the win!
        __m256d row = _mm256_mul_pd(brod1, row1);
        row = _mm256_fmadd_pd(brod2, row2, row);
        row = _mm256_fmadd_pd(brod3, row3, row);
        res.simd[i] = _mm256_fmadd_pd(brod4, row4, row);
    }
    return res;
}

inline vec4d operator*(const mat4d& a, vec4d v) {
    __m256d prod1 = _mm256_mul_pd(a.simd[0], v.simd);
    __m256d prod2 = _mm256_mul_pd(a.simd[1], v.simd);
    __m256d prod3 = _mm256_mul_pd(a.simd[2], v.simd);
    __m256d prod4 = _mm256_mul_pd(a.simd[3], v.simd);

    return vec4d::from_simd(
        _mm256_hadd_pd(_mm256_hadd_pd(prod1, prod2), _mm256_hadd_pd(prod3, prod4))
    );
}

inline mat4d operator*(const mat4d& a, double k) {
    __m256d ksimd = _mm256_broadcast_sd(&k);
    __m256d v1 = _mm256_mul_pd(ksimd, a.simd[0]);
    __m256d v2 = _mm256_mul_pd(ksimd, a.simd[1]);
    __m256d v3 = _mm256_mul_pd(ksimd, a.simd[2]);
    __m256d v4 = _mm256_mul_pd(ksimd, a.simd[3]);
    return mat4d::from_simd(v1, v2, v3, v4);
}

inline mat4d operator*(double k, const mat4d& a) {
    __m256d ksimd = _mm256_broadcast_sd(&k);
    __m256d v1 = _mm256_mul_pd(ksimd, a.simd[0]);
    __m256d v2 = _mm256_mul_pd(ksimd, a.simd[1]);
    __m256d v3 = _mm256_mul_pd(ksimd, a.simd[2]);
    __m256d v4 = _mm256_mul_pd(ksimd, a.simd[3]);
    return mat4d::from_simd(v1, v2, v3, v4);
}

#endif //ALTMATH_MAT4D_H
