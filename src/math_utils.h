//
// Created by lasagnaphil on 10/28/18.
//

#ifndef ALTMATH_UTILITY_H
#define ALTMATH_UTILITY_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <cmath>

namespace aml {
    template <typename T>
    inline T max(T a, T b) {
        return (a > b)? a : b;
    }

    template <typename T>
    inline T min(T a, T b) {
        return (a < b)? a : b;
    }

    inline float sqrt(float x) {
        return ::sqrtf(x);
    }

    inline double sqrt(double x) {
        return ::sqrt(x);
    }

    inline float floor(float x) {
        return ::floorf(x);
    }

    inline double floor(double x) {
        return ::floor(x);
    }
}


namespace aml {

template <typename T>
inline T clamp(T value, T lower, T upper) {
    return max(lower, min(value, upper));
}

inline float radians(float deg) {
    return deg * M_PI / 180.0;
}

inline float degrees(float rad) {
    return rad * 180.0 / M_PI;
}

inline double radians(double deg) {
    return deg * M_PI / 180.0;
}

inline double degrees(double rad) {
    return rad * 180.0 / M_PI;
}

template <typename T>
T powi(T d, unsigned int i) {
    double res = 1.0;
    while (i > 0) {
        res *= d;
        i--;
    }
    return res;
}

template <typename T>
T sigmoid(T x) {
    return (T)1 / ((T)1 + exp(-x));
}

template <typename T>
int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

}

#endif //ALTMATH_UTILITY_H
