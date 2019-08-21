//
// Created by lasagnaphil on 19. 8. 22..
//

#ifndef ALTMATH_VEC_UTILS_H
#define ALTMATH_VEC_UTILS_H

#ifdef ALTMATH_USE_SIMD

#include "vec_utils.h"

namespace aml {
    template <>
    inline vec4d toDouble(vec4i v) {
        return vec4d::fromSimd(_mm256_cvtepi32_pd(v.simd));
    }

    template <>
    inline vec4d toDouble(vec4f v) {
        return vec4d::fromSimd(_mm256_cvtps_pd(v.simd));
    }

    template <>
    inline vec4f toFloat(vec4d v) {
        return vec4f::fromSimd(_mm256_cvtpd_ps(v.simd));
    }

    inline vec2i toInt(vec2d v) {
        int x = _mm_cvtsi128_si32((__m128i) v.simd);
        int y = _mm_extract_epi32(v.simd, 1);
        return vec2i {x, y};
    }

    inline vec4i toInt(vec4f v) {
        return vec4i::fromSimd(_mm_cvtps_epi32(v.simd));
    }

    inline vec4i toInt(vec4d v) {
        return vec4i::fromSimd(_mm256_cvtpd_epi32(v.simd));
    }
}

#endif
#endif //ALTMATH_VEC_UTILS_H
