//
// Created by lasagnaphil on 2018-10-27.
//

#ifndef ALTMATH_VEC4F_H
#define ALTMATH_VEC4F_H

#include <immintrin.h>

struct vec4f {
    union {
        struct {
            float x;
            float y;
            float z;
            float w;
        };
        __m128 simd;
    };

    static inline vec4f from_simd(__m128 simd) {
        vec4f v;
        v.simd = simd;
        return v;
    }
};

inline vec4f operator+(vec4f a, vec4f b) {
    return vec4f::from_simd(_mm_add_ps(a.simd, b.simd));
}

inline vec4f operator-(vec4f a, vec4f b) {
    return vec4f::from_simd(_mm_sub_ps(a.simd, b.simd));
}

inline vec4f operator*(vec4f a, vec4f b) {
    return vec4f::from_simd(_mm_mul_ps(a.simd, b.simd));
}

inline vec4f operator*(vec4f a, float k) {
    __m128 ksimd = _mm_load_ps1(&k);
    return vec4f::from_simd(_mm_mul_ps(ksimd, a.simd));
}

inline vec4f operator*(float k, vec4f a) {
    __m128 ksimd = _mm_load_ps1(&k);
    return vec4f::from_simd(_mm_mul_ps(ksimd, a.simd));
}

inline bool operator==(vec4f a, vec4f b) {
    return _mm_movemask_ps(_mm_cmpeq_ps(a.simd, b.simd)) == 0xf;
}

inline bool operator!=(vec4f a, vec4f b) {
    return !(a == b);
}

typedef vec4f vec4fp;
typedef vec4f vec3f;
typedef vec4f vec2f;

#endif //ALTMATH_VEC4F_H
