//
// Created by lasagnaphil on 2019-01-22.
//

#ifndef COLDETECT_MAT2_H
#define COLDETECT_MAT2_H

template <typename T>
struct mat2 {
    union {
        T m[2][2];
        T p[4];
    };

    static mat2 zero() {
        return mat2 {};
    }

    static mat2 identity() {
        mat2 m;
        m.p[0] = m.p[3] = 1;
        m.p[1] = m.p[2] = 0;
        return m;
    }

    static mat2 make(T t0, T t1, T t2, T t3) {
        mat2 m;
        m.p[0] = t0;
        m.p[1] = t1;
        m.p[2] = t2;
        m.p[3] = t3;
        return m;
    }

    static mat2 single(T t) {
        mat2 m;
        m.p[0] = m.p[1] = m.p[2] = m.p[3] = t;
        return m;
    }
};

template <typename T>
inline mat2<T> operator+(const mat2<T>& a, const mat2<T>& b) {
    mat2<T> c;
    for (int i = 0; i < 4; i++) {
        c.p[i] = a.p[i] + b.p[i];
    }
    return c;
}

template <typename T>
inline mat2<T> operator-(const mat2<T>& a, const mat2<T>& b) {
    mat2<T> c;
    for (int i = 0; i < 4; i++) {
        c.p[i] = a.p[i] - b.p[i];
    }
    return c;
}

template <typename T>
inline mat2<T> operator*(const mat2<T>& a, const mat2<T>& b) {
    mat2<T> c;
    c.p[0] = a.p[0] * b.p[0] + a.p[1] * b.p[2];
    c.p[1] = a.p[0] * b.p[1] + a.p[1] * b.p[3];
    c.p[2] = a.p[2] * b.p[0] + a.p[3] * b.p[2];
    c.p[3] = a.p[2] * b.p[1] + a.p[3] * b.p[3];
    return c;
}

template <typename T>
inline mat2<T> operator*(T k, const mat2<T>& a) {
    mat2<T> c;
    for (int i = 0; i < 4; i++) {
        c.p[i] = k * a.p[i];
    }
    return c;
}

template <typename T>
inline mat2<T> operator*(const mat2<T>& a, T k) {
    mat2<T> c;
    for (int i = 0; i < 4; i++) {
        c.p[i] = k * a.p[i];
    }
    return c;
}

template <typename T>
inline mat2<T> operator/(const mat2<T>& a, T k) {
    mat2<T> c;
    for (int i = 0; i < 4; i++) {
        c.p[i] = a.p[i] / k;
    }
    return c;
}

template <typename T>
inline mat2<T>& operator+=(mat2<T>& a, const mat2<T>& b) {
    for (int i = 0; i < 4; i++) {
        a.p[i] += b.p[i];
    };
    return a;
}

template <typename T>
inline mat2<T>& operator-=(mat2<T>& a, const mat2<T>& b) {
    for (int i = 0; i < 4; i++) {
        a.p[i] -= b.p[i];
    };
    return a;
}

template <typename T>
inline mat2<T>& operator*=(mat2<T>& a, const mat2<T>& b) {
    for (int i = 0; i < 4; i++) {
        a.p[i] *= b.p[i];
    };
    return a;
}

template <typename T>
inline mat2<T>& operator*=(mat2<T>& a, float k) {
    for (int i = 0; i < 4; i++) {
        a.p[i] *= k;
    };
    return a;
}

template <typename T>
inline mat2<T>& operator/=(mat2<T>& a, float k) {
    for (int i = 0; i < 4; i++) {
        a.p[i] /= k;
    };
    return a;
}

namespace aml {
    template <typename T>
    T det(const mat2<T>& m) {
        return m.p[0] * m.p[3] - m.p[1] * m.p[2];
    };

    template <typename T>
    mat2<T> conj(const mat2<T>& m) {
        mat2<T> res;
        res.p[0] = m.p[3];
        res.p[1] = -m.p[1];
        res.p[2] = -m.p[2];
        res.p[3] = m.p[0];
        return res;
    }

    template <typename T>
    mat2<T> inv(const mat2<T>& m) {
        return conj(m) / det(m);
    }
}

using mat2f = mat2<float>;
using mat2d = mat2<double>;

#endif //COLDETECT_MAT2_H
