//
// Created by lasagnaphil on 2019-01-22.
//

#ifndef COLDETECT_MAT2F_H
#define COLDETECT_MAT2F_H

#ifdef ALTMATH_USE_SIMD

#include "mat2.h"
#include "simd.h"

template <>
struct mat2<float> {
    union {
        float m[2][2];
        float p[4];
        __m128 simd;
    };

    static mat2f zero() {
        return mat2f {};
    }

    static mat2f identity() {
        mat2f m;
        m.p[0] = m.p[3] = 1;
        m.p[1] = m.p[2] = 0;
        return m;
    }

    static mat2 make(float t0, float t1, float t2, float t3) {
        return fromSimd(_mm_set_ps(t3, t2, t1, t0));
    }

    static mat2f single(float t) {
        return fromSimd(_mm_set1_ps(t));
    }

    static mat2f fromSimd(__m128 simd) {
        mat2f m;
        m.simd = simd;
        return m;
    }
};


template <>
inline mat2f operator+(const mat2f& a, const mat2f& b) {
    return mat2f::fromSimd(_mm_add_ps(a.simd, b.simd));
}

template <>
inline mat2f operator-(const mat2f& a, const mat2f& b) {
    return mat2f::fromSimd(_mm_sub_ps(a.simd, b.simd));
}

template <>
inline mat2f operator*(const mat2f& a, const mat2f& b) {
    return mat2f::fromSimd(
        _mm_add_ps(_mm_mul_ps(a.simd,                      VecSwizzle(b.simd, 0,3,0,3)),
                   _mm_mul_ps(VecSwizzle(a.simd, 1,0,3,2), VecSwizzle(b.simd, 2,1,2,1)))
    );
}

template <>
inline mat2f operator*(float k, const mat2f& a) {
    return mat2f::fromSimd(_mm_mul_ps(_mm_set1_ps(k), a.simd));
}

template <>
inline mat2f operator*(const mat2f& a, float k) {
    return mat2f::fromSimd(_mm_mul_ps(a.simd, _mm_set1_ps(k)));
}

template <>
inline mat2f operator/(const mat2f& a, float k) {
    return mat2f::fromSimd(_mm_div_ps(a.simd, _mm_set1_ps(k)));
}

template <>
inline mat2f& operator+=(mat2f& a, const mat2f& b) {
    a.simd = _mm_add_ps(a.simd, b.simd);
    return a;
}

template <>
inline mat2f& operator-=(mat2f& a, const mat2f& b) {
    a.simd = _mm_sub_ps(a.simd, b.simd);
    return a;
}

template <>
inline mat2f& operator*=(mat2f& a, const mat2f& b) {
    a.simd = _mm_mul_ps(a.simd, b.simd);
    return a;
}

template <>
inline mat2f& operator*=(mat2f& a, float k) {
    a.simd = _mm_mul_ps(a.simd, _mm_set1_ps(k));
    return a;
}

template <>
inline mat2f& operator/=(mat2f& a, float k) {
    a.simd = _mm_div_ps(a.simd, _mm_set1_ps(k));
    return a;
}

namespace aml {
    template <>
    inline float det(const mat2f& m) {
        return m.p[0] * m.p[3] - m.p[1] * m.p[2];
    };

    inline mat2f adjMul(const mat2f& a, const mat2f& b) {
        return mat2f::fromSimd(
            _mm_sub_ps(_mm_mul_ps(VecSwizzle(a.simd, 3,3,0,0), b.simd),
                       _mm_mul_ps(VecSwizzle(a.simd, 1,1,2,2), VecSwizzle(b.simd, 2,3,0,1)))
        );
    }

    inline mat2f mulAdj(const mat2f& a, const mat2f& b) {
        return mat2f::fromSimd(
            _mm_sub_ps(_mm_mul_ps(a.simd,                      VecSwizzle(b.simd, 3,0,3,0)),
                       _mm_mul_ps(VecSwizzle(a.simd, 1,0,3,2), VecSwizzle(b.simd, 2,1,2,1)))
        );
    }

    inline mat2f elemWiseMul(const mat2f& a, const mat2f& b) {
        return mat2f::fromSimd(_mm_mul_ps(a.simd, b.simd));
    }
    inline mat2f elemWiseDiv(const mat2f& a, const mat2f& b) {
        return mat2f::fromSimd(_mm_div_ps(a.simd, b.simd));
    }

    template <>
    inline mat2f conj(const mat2f& m) {
        mat2f res;
        res.p[0] = m.p[3];
        res.p[1] = -m.p[1];
        res.p[2] = -m.p[2];
        res.p[3] = m.p[0];
        return res;
    }

    template <>
    inline mat2f inv(const mat2f& m) {
        return conj(m) / det(m);
    }
}

#endif
#endif //COLDETECT_MAT2F_H
