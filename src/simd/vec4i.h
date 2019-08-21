//
// Created by lasagnaphil on 2019-01-12.
//

#ifndef ALTMATH_VEC4I_H
#define ALTMATH_VEC4I_H

#ifdef ALTMATH_USE_SIMD

#include "vec4.h"
#include "math_utils.h"
#include <immintrin.h>

template <>
struct vec4<int> {
    union {
        struct { int x, y, z, w; };
        int v[4];
        __m128i simd;
    };

    static inline vec4i make(int v) {
        return fromSimd(_mm_set1_epi32(v));
    }

    static inline vec4i loadAligned(const int *in) {
        vec4<int> res;
        res.simd = _mm_load_si128((const __m128i*) in);
        return res;
    }

    static inline vec4i load(const int* in) {
        vec4<int> res;
        res.simd = _mm_loadu_si128((const __m128i*) in);
        return res;
    }

    static inline vec4i fromSimd(__m128i simd) {
        vec4<int> res;
        res.simd = simd;
        return res;
    }

    void store(int* out) {
        _mm_storeu_si128((__m128i*) out, simd);
    }

    void storeAligned(int *out) {
        _mm_store_si128((__m128i*) out, simd);
    }
};

template <>
inline vec4i operator+(vec4i a, vec4i b) {
    return vec4i::fromSimd(_mm_add_epi32(a.simd, b.simd));
}

template <>
inline vec4i operator+(vec4i a, int b) {
    return vec4i::fromSimd(_mm_add_epi32(a.simd, _mm_set1_epi32(b)));
}

template <>
inline vec4i operator+(int a, vec4i b) {
    return vec4i::fromSimd(_mm_add_epi32(_mm_set1_epi32(a), b.simd));
}

template <>
inline vec4i operator-(vec4i a, vec4i b) {
    return vec4i::fromSimd(_mm_sub_epi32(a.simd, b.simd));
}

template <>
inline vec4i operator-(vec4i a, int b) {
    return vec4i::fromSimd(_mm_sub_epi32(a.simd, _mm_set1_epi32(b)));
}

template <>
inline vec4i operator-(int a, vec4i b) {
    return vec4i::fromSimd(_mm_sub_epi32(_mm_set1_epi32(a), b.simd));
}

// Note: only returns low 32-bit integers from multiplication
// So you need to deal with multiplication overflow yourself....
template <>
inline vec4i operator*(vec4i a, vec4i b) {
    return vec4i::fromSimd(_mm_mullo_epi32(a.simd, b.simd));
}

template <>
inline vec4i operator*(vec4i a, int k) {
    __m128i ksimd = _mm_set1_epi32(k);
    return vec4i::fromSimd(_mm_mullo_epi32(a.simd, ksimd));
}

template <>
inline vec4i operator*(int k, vec4i a) {
    __m128i ksimd = _mm_set1_epi32(k);
    return vec4i::fromSimd(_mm_mullo_epi32(a.simd, ksimd));
}

template <>
inline vec4i operator/(vec4i a, int k) = delete;

template <>
inline vec4i& operator+=(vec4i& a, vec4i b) {
    a.simd = _mm_add_epi32(a.simd, b.simd);
    return a;
}

template <>
inline vec4i& operator-=(vec4i& a, vec4i b) {
    a.simd = _mm_sub_epi32(a.simd, b.simd);
    return a;
}

template <>
inline vec4i& operator*=(vec4i& a, vec4i b) {
    a.simd = _mm_mullo_epi32(a.simd, b.simd);
    return a;
}

template <>
inline vec4i& operator*=(vec4i& a, int k) {
    __m128i ksimd = _mm_set1_epi32(k);
    a.simd = _mm_mullo_epi32(a.simd, ksimd);
    return a;
}

template <>
inline vec4i& operator/=(vec4i& a, int k) = delete;

template <>
inline bool operator==(vec4i a, vec4i b) {
    __m128i neq = _mm_xor_si128(a.simd, b.simd);
    return (bool)_mm_test_all_zeros(neq, neq);
}

template <>
inline bool operator!=(vec4i a, vec4i b) {
    return !(a == b);
}

namespace aml {
    template <>
    inline vec4i sqrt(vec4i a) = delete;

    template <>
    inline vec4i floor(vec4i a) {
        return a;
    }

    template <>
    inline vec4i max(vec4i a, vec4i b) {
        return vec4i::fromSimd(_mm_max_epi32(a.simd, b.simd));
    }

    template <>
    inline vec4i min(vec4i a, vec4i b) {
        return vec4i::fromSimd(_mm_min_epi32(a.simd, b.simd));
    }

    template <>
    inline int dot(vec4i a, vec4i b) {
        __m128i temp_prod = _mm_mullo_epi32(a.simd, b.simd);
        __m128i temp_sum = _mm_add_epi32(temp_prod, _mm_srli_si128(temp_prod, 8));
        temp_sum = _mm_add_epi32(temp_sum, _mm_srli_si128(temp_sum, 4));
        return _mm_cvtsi128_si32(temp_sum);
    }
}

#endif
#endif //ALTMATH_VEC4I_H
