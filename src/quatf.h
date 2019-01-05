//
// Created by lasagnaphil on 2019-01-05.
//

#ifndef ALTMATH_QUATF_H
#define ALTMATH_QUATF_H

#include "quat.h"
#include "vec4f.h"

#include "immintrin.h"

template <>
struct quat<float> {
    // Note: should we use wxyz or xyzw layout?
    // xyzw Pros:
    // - Compatible with vec4, so more efficient quat-vec multiplication
    // xyzw Cons:
    // - More confusing initialization
    union {
        struct {
            float x, y, z, w;
        };
        __m128 simd;
    };

    static inline quatf from_simd(__m128 simd) {
        quatf v;
        v.simd = simd;
        return v;
    }
};

template <>
inline quatf operator-(quatf q) {
    __m128 mone = _mm_set_ps1(-1.0f);
    return quatf::from_simd(_mm_mul_ps(mone, q.simd));
}

template <>
inline quatf operator+(quatf p, quatf q) {
    return quatf::from_simd(_mm_add_ps(p.simd, q.simd));
}

template <>
inline quatf operator-(quatf p, quatf q) {
    return quatf::from_simd(_mm_sub_ps(p.simd, q.simd));
}

// Courtesy of http://momchil-velikov.blogspot.com/2013/10/fast-sse-quternion-multiplication.html

#define _mm_pshufd(r,i) __m128 (_mm_shuffle_epi32 (__m128i (r), i))

template <>
inline quatf operator*(quatf p, quatf q) {
    __m128 t0 = _mm_pshufd (p.simd, _MM_SHUFFLE (3, 3, 3, 3)); /* 1, 0.5 */
    __m128 t1 = _mm_pshufd (q.simd, _MM_SHUFFLE (2, 3, 0, 1)); /* 1, 0.5 */

    __m128 t3 = _mm_pshufd (p.simd, _MM_SHUFFLE (0, 0, 0, 0)); /* 1, 0.5 */
    __m128 t4 = _mm_pshufd (q.simd, _MM_SHUFFLE (1, 0, 3, 2)); /* 1, 0.5 */

    __m128 t5 = _mm_pshufd (p.simd, _MM_SHUFFLE (1, 1, 1, 1)); /* 1, 0.5 */
    __m128 t6 = _mm_pshufd (q.simd, _MM_SHUFFLE (2, 0, 3, 1)); /* 1, 0.5 */

    __m128 m0 = _mm_mul_ps (t0, t1); /* 5/4, 1 */
    __m128 m1 = _mm_mul_ps (t3, t4); /* 5/4, 1 */
    __m128 m2 = _mm_mul_ps (t5, t6); /* 5/4, 1 */

    __m128 t7 = _mm_pshufd (p.simd, _MM_SHUFFLE (2, 2, 2, 2)); /* 1, 0.5 */
    __m128 t8 = _mm_pshufd (q.simd, _MM_SHUFFLE (3, 2, 0, 1)); /* 1, 0.5 */

    __m128 m3 = _mm_mul_ps (t7, t8); /* 5/4, 1 */

    __m128 e = _mm_addsub_ps (m0, m1); /* 3, 1 */

    e = _mm_pshufd (e, _MM_SHUFFLE (1, 3, 0, 2)); /* 1, 0.5 */
    e = _mm_addsub_ps (e, m2); /* 3, 1 */

    e = _mm_pshufd (e, _MM_SHUFFLE (2, 0, 1, 3)); /* 1, 0.5 */
    e = _mm_addsub_ps (e, m3); /* 3, 1 */

    e = _mm_pshufd (e, _MM_SHUFFLE (2, 3, 1, 0)); /* 1, 0.5 */

    return quatf::from_simd(e);
}

template <>
inline quatf operator*(quatf q, vec3f v) {
    vec4f qv = vec4f::from_simd(q.simd);
    vec4f vnew = vec4f {v.x, v.y, v.z, 0.0};
    vec4f uv = aml::cross(qv, vnew);
    vec4f uuv = aml::cross(qv, uv);
    vec4f res = vnew + ((uv * q.w) + uuv) * 2.f;
    return quatf::from_simd(res.simd);
}

// TODO: optimize the two cross() invocations
template <>
inline quatf operator*(quatf q, vec4f v) {
    vec4f qv = vec4f::from_simd(q.simd);
    vec4f uv = aml::cross(qv, v);
    vec4f uuv = aml::cross(qv, uv);
    vec4f res = v + ((uv * q.w) + uuv) * 2.f;
    return quatf::from_simd(res.simd);
}

template <>
inline quatf operator*(quatf q, float k) {
    return quatf::from_simd(_mm_mul_ps(q.simd, _mm_set1_ps(k)));
}

template <>
inline quatf operator*(float k, quatf q) {
    return q * k;
}

template <>
inline quatf operator/(quatf q, float k) {
    return quatf::from_simd(_mm_div_ps(q.simd, _mm_set1_ps(k)));
}

namespace aml {
    template <>
    inline float norm(quatf q) {
        return norm(vec4f::from_simd(q.simd));
    }
}

#undef _mm_pshufd

#endif //ALTMATH_QUATF_H
