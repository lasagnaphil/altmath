//
// Created by lasagnaphil on 19. 8. 22..
//

#ifndef ALTMATH_SPLINES_H
#define ALTMATH_SPLINES_H

template <typename T>
vec4<T> catmullRom(double a) {
    vec4<T> coeffs;
    coeffs.x = -0.5*a + a*a - 0.5*a*a*a;
    coeffs.y = 1 - 2.5*a*a + 1.5*a*a*a;
    coeffs.z = 0.5*a + 2*a*a - 1.5*a*a*a;
    coeffs.w = -0.5*a*a + 0.5*a*a*a;
    return coeffs;
}

#endif //ALTMATH_SPLINES_H
