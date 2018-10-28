//
// Created by lasagnaphil on 2018-10-27.
//

#ifndef ALTMATH_MAT4_H
#define ALTMATH_MAT4_H

// NOTE: because of trying to implement simple and fast multiplication,
// the matrix only uses xmm registers (SSE).
// Later I would try writing an AVX version.
// Useful link: https://stackoverflow.com/questions/18499971/efficient-4x4-matrix-multiplication-c-vs-assembly

#include <immintrin.h>
#include "vec4f.h"

struct mat4f {
    union {
        float data[16];
        __m128 simd[4];
    };

    static mat4f from_simd(__m128 simd0, __m128 simd1, __m128 simd2, __m128 simd3) {
        mat4f mat;
        mat.simd[0] = simd0;
        mat.simd[1] = simd1;
        mat.simd[2] = simd2;
        mat.simd[3] = simd3;
        return mat;
    }

    inline float& operator[](int i) {
        return data[i];
    }

    inline const float& operator[](int i) const {
        return data[i];
    }
};

inline bool operator==(const mat4f& a, const mat4f& b) {
    return _mm_movemask_ps(_mm_cmpeq_ps(a.simd[0], b.simd[0])) == 0xf &&
           _mm_movemask_ps(_mm_cmpeq_ps(a.simd[1], b.simd[1])) == 0xf &&
           _mm_movemask_ps(_mm_cmpeq_ps(a.simd[2], b.simd[2])) == 0xf &&
           _mm_movemask_ps(_mm_cmpeq_ps(a.simd[3], b.simd[3])) == 0xf;
}

inline bool operator!=(const mat4f& a, const mat4f& b) {
    return !(a == b);
}

inline mat4f operator+(const mat4f& a, const mat4f& b) {
    __m128 v1 = _mm_add_ps(a.simd[0], b.simd[0]);
    __m128 v2 = _mm_add_ps(a.simd[1], b.simd[1]);
    __m128 v3 = _mm_add_ps(a.simd[2], b.simd[2]);
    __m128 v4 = _mm_add_ps(a.simd[3], b.simd[3]);
    return mat4f::from_simd(v1, v2, v3, v4);
}

inline mat4f operator-(const mat4f& a, const mat4f& b) {
    __m128 v1 = _mm_sub_ps(a.simd[0], b.simd[0]);
    __m128 v2 = _mm_sub_ps(a.simd[1], b.simd[1]);
    __m128 v3 = _mm_sub_ps(a.simd[2], b.simd[2]);
    __m128 v4 = _mm_sub_ps(a.simd[3], b.simd[3]);
    return mat4f::from_simd(v1, v2, v3, v4);
}

inline mat4f operator*(const mat4f& a, const mat4f& b) {
    mat4f res;
    __m128 row1 = b.simd[0];
    __m128 row2 = b.simd[1];
    __m128 row3 = b.simd[2];
    __m128 row4 = b.simd[3];
    for (int i = 0; i < 4; i++) {
        __m128 brod1 = _mm_set1_ps(a[4*i + 0]);
        __m128 brod2 = _mm_set1_ps(a[4*i + 1]);
        __m128 brod3 = _mm_set1_ps(a[4*i + 2]);
        __m128 brod4 = _mm_set1_ps(a[4*i + 3]);
        __m128 row = _mm_add_ps(
            _mm_add_ps(
                _mm_mul_ps(brod1, row1),
                _mm_mul_ps(brod2, row2)
            ),
            _mm_add_ps(
                _mm_mul_ps(brod3, row3),
                _mm_mul_ps(brod4, row4)
            )
        );
        res.simd[i] = row;
    }
    return res;
}

inline vec4f operator*(const mat4f& a, vec4f v) {
    __m128 prod1 = _mm_mul_ps(a.simd[0], v.simd);
    __m128 prod2 = _mm_mul_ps(a.simd[1], v.simd);
    __m128 prod3 = _mm_mul_ps(a.simd[2], v.simd);
    __m128 prod4 = _mm_mul_ps(a.simd[3], v.simd);

    return vec4f::from_simd(
        _mm_hadd_ps(_mm_hadd_ps(prod1, prod2), _mm_hadd_ps(prod3, prod4))
    );
}

inline mat4f operator*(const mat4f& a, float k) {
    __m128 ksimd = _mm_load1_ps(&k);
    __m128 v1 = _mm_mul_ps(ksimd, a.simd[0]);
    __m128 v2 = _mm_mul_ps(ksimd, a.simd[1]);
    __m128 v3 = _mm_mul_ps(ksimd, a.simd[2]);
    __m128 v4 = _mm_mul_ps(ksimd, a.simd[3]);
    return mat4f::from_simd(v1, v2, v3, v4);
}

inline mat4f operator*(float k, const mat4f& a) {
    __m128 ksimd = _mm_load1_ps(&k);
    __m128 v1 = _mm_mul_ps(ksimd, a.simd[0]);
    __m128 v2 = _mm_mul_ps(ksimd, a.simd[1]);
    __m128 v3 = _mm_mul_ps(ksimd, a.simd[2]);
    __m128 v4 = _mm_mul_ps(ksimd, a.simd[3]);
    return mat4f::from_simd(v1, v2, v3, v4);
}

#endif //ALTMATH_MAT4_H
