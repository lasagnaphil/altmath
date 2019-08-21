//
// Created by lasagnaphil on 2018-10-27.
//

#ifndef ALTMATH_MAT4F_H
#define ALTMATH_MAT4F_H

#ifdef ALTMATH_USE_SIMD

// NOTE: because of trying to implement simple and fast multiplication,
// the matrix only uses xmm registers (SSE).
// Later I would try writing an AVX version.
// Useful link: https://stackoverflow.com/questions/18499971/efficient-4x4-matrix-multiplication-c-vs-assembly

#include "simd.h"
#include "mat4.h"
#include "mat2f.h"
#include "vec4f.h"

template <>
struct mat4<float> {
    union {
        float p[16];
        float m[4][4];
        __m128 simd[4];
    };

    static mat4<float> from_simd(__m128 simd0, __m128 simd1, __m128 simd2, __m128 simd3) {
        mat4<float> mat;
        mat.simd[0] = simd0;
        mat.simd[1] = simd1;
        mat.simd[2] = simd2;
        mat.simd[3] = simd3;
        return mat;
    }

    static mat4<float> identity() {
        mat4 m = {};
        m.p[0] = m.p[5] = m.p[10] = m.p[15] = 1.0f;
        return m;
    }

    inline float& operator[](int i) {
        return p[i];
    }

    inline const float& operator[](int i) const {
        return p[i];
    }
};

using mat4f = mat4<float>;

template <>
inline bool operator==(const mat4f& a, const mat4f& b) {
    return _mm_movemask_ps(_mm_cmpeq_ps(a.simd[0], b.simd[0])) == 0xf &&
           _mm_movemask_ps(_mm_cmpeq_ps(a.simd[1], b.simd[1])) == 0xf &&
           _mm_movemask_ps(_mm_cmpeq_ps(a.simd[2], b.simd[2])) == 0xf &&
           _mm_movemask_ps(_mm_cmpeq_ps(a.simd[3], b.simd[3])) == 0xf;
}

template <>
inline bool operator!=(const mat4f& a, const mat4f& b) {
    return !(a == b);
}

template <>
inline mat4f operator+(const mat4f& a, const mat4f& b) {
    __m128 v1 = _mm_add_ps(a.simd[0], b.simd[0]);
    __m128 v2 = _mm_add_ps(a.simd[1], b.simd[1]);
    __m128 v3 = _mm_add_ps(a.simd[2], b.simd[2]);
    __m128 v4 = _mm_add_ps(a.simd[3], b.simd[3]);
    return mat4f::from_simd(v1, v2, v3, v4);
}

template <>
inline mat4f operator-(const mat4f& a, const mat4f& b) {
    __m128 v1 = _mm_sub_ps(a.simd[0], b.simd[0]);
    __m128 v2 = _mm_sub_ps(a.simd[1], b.simd[1]);
    __m128 v3 = _mm_sub_ps(a.simd[2], b.simd[2]);
    __m128 v4 = _mm_sub_ps(a.simd[3], b.simd[3]);
    return mat4f::from_simd(v1, v2, v3, v4);
}

template <>
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

template <>
inline vec4f operator*(const mat4f& a, vec4f v) {
    __m128 prod1 = _mm_mul_ps(a.simd[0], v.simd);
    __m128 prod2 = _mm_mul_ps(a.simd[1], v.simd);
    __m128 prod3 = _mm_mul_ps(a.simd[2], v.simd);
    __m128 prod4 = _mm_mul_ps(a.simd[3], v.simd);

    return vec4f::fromSimd(
            _mm_hadd_ps(_mm_hadd_ps(prod1, prod2), _mm_hadd_ps(prod3, prod4))
    );
}

template <>
inline mat4f operator*(const mat4f& a, float k) {
    __m128 ksimd = _mm_load1_ps(&k);
    __m128 v1 = _mm_mul_ps(ksimd, a.simd[0]);
    __m128 v2 = _mm_mul_ps(ksimd, a.simd[1]);
    __m128 v3 = _mm_mul_ps(ksimd, a.simd[2]);
    __m128 v4 = _mm_mul_ps(ksimd, a.simd[3]);
    return mat4f::from_simd(v1, v2, v3, v4);
}

template <>
inline mat4f operator*(float k, const mat4f& a) {
    __m128 ksimd = _mm_load1_ps(&k);
    __m128 v1 = _mm_mul_ps(ksimd, a.simd[0]);
    __m128 v2 = _mm_mul_ps(ksimd, a.simd[1]);
    __m128 v3 = _mm_mul_ps(ksimd, a.simd[2]);
    __m128 v4 = _mm_mul_ps(ksimd, a.simd[3]);
    return mat4f::from_simd(v1, v2, v3, v4);
}

template <>
inline mat4f& operator+=(mat4f& a, const mat4f& b) {
    return a = a + b;
}

template <>
inline mat4f& operator-=(mat4f& a, const mat4f& b) {
    return a = a - b;
}

template <>
inline mat4f& operator*=(mat4f& a, const mat4f& b) {
    return a = a * b;
}

template <>
inline mat4f& operator*=(mat4f& a, float k) {
    return a = a * k;
}

namespace aml {
    // Courtesy of https://lxjk.github.io/2017/09/03/Fast-4x4-Matrix-Inverse-with-SSE-SIMD-Explained.html
    inline float det(const mat4f& m) {
        mat2f A = mat2f::fromSimd(_mm_movelh_ps(m.simd[0], m.simd[1]));
        mat2f B = mat2f::fromSimd(_mm_movehl_ps(m.simd[1], m.simd[0]));
        mat2f C = mat2f::fromSimd(_mm_movelh_ps(m.simd[2], m.simd[3]));
        mat2f D = mat2f::fromSimd(_mm_movehl_ps(m.simd[3], m.simd[2]));

        float detA = det(A);
        float detB = det(B);
        float detC = det(C);
        float detD = det(D);

        // tr = tr((A#B)(D#C))
        mat2f D_C = adjMul(D, C);
        mat2f A_B = adjMul(A, B);
        vec4f diag = vec4f::fromSimd(_mm_mul_ps(A_B.simd, VecSwizzle(D_C.simd, 0,2,1,3)));
        float tr = elemWiseSum(diag);

        return detA * detD + detB * detC - tr;
    }

    inline mat4f inv(const mat4f& m) {
        mat2f A = mat2f::fromSimd(_mm_movelh_ps(m.simd[0], m.simd[1]));
        mat2f B = mat2f::fromSimd(_mm_movehl_ps(m.simd[1], m.simd[0]));
        mat2f C = mat2f::fromSimd(_mm_movelh_ps(m.simd[2], m.simd[3]));
        mat2f D = mat2f::fromSimd(_mm_movehl_ps(m.simd[3], m.simd[2]));

        float detA = det(A);
        float detB = det(B);
        float detC = det(C);
        float detD = det(D);

        mat2f D_C = adjMul(D, C);
        mat2f A_B = adjMul(A, B);
        mat2f X_ = detD * A - B * D_C;
        mat2f W_ = detA * D - C * A_B;
        mat2f Y_ = detB * C - mulAdj(D, A_B);
        mat2f Z_ = detC * B - mulAdj(A, D_C);
        // tr = tr((A#B)(D#C))
        vec4f diag = vec4f::fromSimd(_mm_mul_ps(A_B.simd, VecSwizzle(D_C.simd, 0,2,1,3)));
        float tr = elemWiseSum(diag);
        float detM = detA * detD + detB * detC - tr;
        mat2f adjSignMask = mat2f::make(1.f, -1.f, -1.f, 1.f);
        mat2f rDetM = adjSignMask / detM;

        X_ *= rDetM;
        Y_ *= rDetM;
        Z_ *= rDetM;
        W_ *= rDetM;

        mat4f r;
        r.simd[0] = VecShuffle(X_.simd, Y_.simd, 3,1,3,1);
        r.simd[1] = VecShuffle(X_.simd, Y_.simd, 2,0,2,0);
        r.simd[2] = VecShuffle(Z_.simd, W_.simd, 3,1,3,1);
        r.simd[3] = VecShuffle(Z_.simd, W_.simd, 2,0,2,0);

        return r;
    }
}

#endif
#endif //ALTMATH_MAT4F_H
