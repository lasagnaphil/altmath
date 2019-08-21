//
// Created by lasagnaphil on 2019-01-12.
//

#ifndef ALTMATH_VEC3DX4_H
#define ALTMATH_VEC3DX4_H

#ifdef ALTMATH_USE_SIMD

#include "vec3.h"
#include "vec4d.h"


using vec3dx4 = vec3<vec4d>;

template <>
struct vec3<vec4d> {
    vec4d x, y, z;

    static vec3<vec4d> load(const double* x, const double* y, const double *z) {
        return {
                vec4d::loadAligned(x),
            vec4d::loadAligned(y),
            vec4d::loadAligned(z)
        };
    }

    inline static vec3<vec4d> load(vec3d* v) {
        return {
            vec4d{v[0].x, v[1].x, v[2].x, v[3].x},
            vec4d{v[0].y, v[1].y, v[2].y, v[3].y},
            vec4d{v[0].z, v[1].z, v[2].z, v[3].z}
        };
    }

    void store(double* vx, double* vy, double* vz) {
        x.storeAligned(vx);
        y.storeAligned(vy);
        z.storeAligned(vz);
    }
};

inline vec3dx4 operator*(vec3dx4 a, double k) {
    __m256d ksimd = _mm256_set1_pd(k);
    a.x.simd = _mm256_mul_pd(a.x.simd, ksimd);
    a.y.simd = _mm256_mul_pd(a.y.simd, ksimd);
    a.z.simd = _mm256_mul_pd(a.z.simd, ksimd);
    return a;
}

inline vec3dx4 operator*(double k, vec3dx4 a) {
    __m256d ksimd = _mm256_set1_pd(k);
    a.x.simd = _mm256_mul_pd(a.x.simd, ksimd);
    a.y.simd = _mm256_mul_pd(a.y.simd, ksimd);
    a.z.simd = _mm256_mul_pd(a.z.simd, ksimd);
    return a;
}

inline vec3dx4 operator/(vec3dx4 a, double k) {
    __m256d ksimd = _mm256_set1_pd(k);
    a.x.simd = _mm256_div_pd(a.x.simd, ksimd);
    a.y.simd = _mm256_div_pd(a.y.simd, ksimd);
    a.z.simd = _mm256_div_pd(a.z.simd, ksimd);
    return a;
}

inline vec3dx4& operator*=(vec3dx4& a, double k) {
    __m256d ksimd = _mm256_set1_pd(k);
    a.x.simd = _mm256_mul_pd(a.x.simd, ksimd);
    a.y.simd = _mm256_mul_pd(a.y.simd, ksimd);
    a.z.simd = _mm256_mul_pd(a.z.simd, ksimd);
    return a;
}

inline vec3dx4& operator*=(double k, vec3dx4& a) {
    __m256d ksimd = _mm256_set1_pd(k);
    a.x.simd = _mm256_mul_pd(a.x.simd, ksimd);
    a.y.simd = _mm256_mul_pd(a.y.simd, ksimd);
    a.z.simd = _mm256_mul_pd(a.z.simd, ksimd);
    return a;
}

inline vec3dx4& operator/=(vec3dx4& a, double k) {
    __m256d ksimd = _mm256_set1_pd(k);
    a.x.simd = _mm256_div_pd(a.x.simd, ksimd);
    a.y.simd = _mm256_div_pd(a.y.simd, ksimd);
    a.z.simd = _mm256_div_pd(a.z.simd, ksimd);
    return a;
}

#endif
#endif //ALTMATH_VEC3DX4_H
