//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_VEC_UTILS_H
#define ALTMATH_VEC_UTILS_H

#include "math_utils.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "vec2d.h"
#include "vec4f.h"
#include "vec4d.h"
#include "vec4i.h"
#include "vec2dx4.h"
#include "vec3dx4.h"

#define ELEMWISE_FUN(FNNAME) \
namespace aml { \
    template <typename T> \
    inline vec2<T> FNNAME(vec2<T> a, vec2<T> b) { \
        return vec2<T>{aml::FNNAME(a.x, b.x), aml::FNNAME(a.y, b.y)}; \
    } \
    template <typename T> \
    inline vec3<T> FNNAME(vec3<T> a, vec3<T> b) { \
        return vec3<T>{aml::FNNAME(a.x, b.x), aml::FNNAME(a.y, b.y), aml::FNNAME(a.z, b.z)}; \
    } \
    template <typename T> \
    inline vec4<T> FNNAME(vec4<T> a, vec4<T> b) { \
        return vec4<T>{aml::FNNAME(a.x, b.x), aml::FNNAME(a.y, b.y), aml::FNNAME(a.z, b.z), aml::FNNAME(a.w, b.w)}; \
    } \
} \

ELEMWISE_FUN(max)
ELEMWISE_FUN(min)
ELEMWISE_FUN(sqrt)
ELEMWISE_FUN(floor)

#undef ELEMWISE_FUN

#define ELEMWISE_VEC_FUN(FNNAME) \
namespace aml { \
    template <typename T> \
    inline vec2<vec4<T>> FNNAME(vec2<vec4<T>> v) { \
        return vec2<vec4<T>> {aml::FNNAME(v.x), aml::FNNAME(v.y)}; \
    } \
    template <typename T> \
    inline vec3<vec4<T>> FNNAME(vec3<vec4<T>> v) { \
        return vec3<vec4<T>> {aml::FNNAME(v.x), aml::FNNAME(v.y), aml::FNNAME(v.z)}; \
    } \
    template <typename T> \
    inline vec4<vec4<T>> FNNAME(vec4<vec4<T>> v) { \
        return vec4<vec4<T>> {aml::FNNAME(v.x), aml::FNNAME(v.y), aml::FNNAME(v.z), aml::FNNAME(v.w)}; \
    } \
}

ELEMWISE_VEC_FUN(max)
ELEMWISE_VEC_FUN(min)
ELEMWISE_VEC_FUN(sqrt)
ELEMWISE_VEC_FUN(floor)

#undef ELEMWISE_VEC_FUN

#define ELEMWISE_CVT(FNNAME, TYPE) \
namespace aml { \
    template <typename T> \
    inline vec2<TYPE> FNNAME(vec2<T> v) { \
        return vec2<TYPE> {(TYPE)v.x, (TYPE)v.y}; \
    } \
    template <typename T> \
    inline vec3<TYPE> FNNAME(vec3<T> v) { \
        return vec3<TYPE> {(TYPE)v.x, (TYPE)v.y, (TYPE)v.z}; \
    } \
    template <typename T> \
    inline vec4<TYPE> FNNAME(vec4<T> v) { \
        return vec4<TYPE> {(TYPE)v.x, (TYPE)v.y, (TYPE)v.z, (TYPE)v.w}; \
    } \
}

ELEMWISE_CVT(toFloat, float)
ELEMWISE_CVT(toDouble, double)
ELEMWISE_CVT(toInt, int)

#undef ELEMWISE_CVT

#define ELEMWISE_VEC_CVT(FNNAME, TYPE) \
namespace aml { \
    template <typename T> \
    inline vec2<vec4<TYPE>> FNNAME(vec2<vec4<T>> v) { \
        return vec2<vec4<TYPE>> {aml::FNNAME(v.x), aml::FNNAME(v.y)}; \
    } \
    template <typename T> \
    inline vec3<vec4<TYPE>> FNNAME(vec3<vec4<T>> v) { \
        return vec3<vec4<TYPE>> {aml::FNNAME(v.x), aml::FNNAME(v.y), aml::FNNAME(v.z)}; \
    } \
    template <typename T> \
    inline vec4<vec4<TYPE>> FNNAME(vec4<vec4<T>> v) { \
        return vec4<vec4<TYPE>> {aml::FNNAME(v.x), aml::FNNAME(v.y), aml::FNNAME(v.z), aml::FNNAME(v.w)}; \
    } \
}

ELEMWISE_VEC_CVT(toFloat, float)
ELEMWISE_VEC_CVT(toDouble, double)
ELEMWISE_VEC_CVT(toInt, int)

#undef ELEMWISE_VEC_CVT

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

namespace aml {
    template<typename T>
    inline vec2<T> xy(vec3<T> v) {
        return vec2<T>{v.x, v.y};
    }

    template<typename T>
    inline vec2<T> xy(vec4<T> v) {
        return vec2<T>{v.x, v.y};
    }

    template <typename T>
    inline vec3<T> xyz(vec4<T> v) {
        return vec3<T> {v.x, v.y, v.z};
    }

}

#endif //ALTMATH_VEC_UTILS_H
