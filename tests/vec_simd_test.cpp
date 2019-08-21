//
// Created by lasagnaphil on 19. 8. 22..
//

#include "simd/vec2dx4.h"
#include "simd/vec3dx4.h"

#include "doctest.h"

TEST_CASE("vec2dx4 works") {
    SUBCASE("Is POD") {
        CHECK(std::is_pod<vec2dx4>());
    }
    SUBCASE("Arithmetic") {
        vec2d a[4], b[4];
        for (int i = 0; i < 4; i++) {
            a[i].x = 4*i;
            a[i].y = 4*i + 1;
            b[i].x = 4*i + 2;
            b[i].y = 4*i + 3;
        }
        vec2dx4 a4 = vec2dx4::load(a);
        vec2dx4 b4 = vec2dx4::load(b);

        CHECK(a4 == a4);
        CHECK(a4 != b4);

        vec2dx4 c4;
        vec2d c[4];

        c4 = a4 + b4;
        for (int i = 0; i < 4; i++) {
            c[i] = a[i] + b[i];
        }
        CHECK(c4 == vec2dx4::load(c));

        c4 = a4 - b4;
        for (int i = 0; i < 4; i++) {
            c[i] = a[i] - b[i];
        }
        CHECK(c4 == vec2dx4::load(c));

        c4 = a4 * b4;
        for (int i = 0; i < 4; i++) {
            c[i] = a[i] * b[i];
        }
        CHECK(c4 == vec2dx4::load(c));

        c4 = a4 * 2.0;
        for (int i = 0; i < 4; i++) {
            c[i] = a[i] * 2.0;
        }
        CHECK(c4 == vec2dx4::load(c));

        a4 += b4;
        for (int i = 0; i < 4; i++) {
            a[i] += b[i];
        }
        CHECK(a4 == vec2dx4::load(a));

        a4 -= b4;
        for (int i = 0; i < 4; i++) {
            a[i] -= b[i];
        }
        CHECK(a4 == vec2dx4::load(a));

        a4 *= b4;
        for (int i = 0; i < 4; i++) {
            a[i] *= b[i];
        }
        CHECK(a4 == vec2dx4::load(a));

        vec4d anormsq = aml::normsq(a4);
        CHECK(anormsq.x == aml::normsq(a[0]));
        CHECK(anormsq.y == aml::normsq(a[1]));
        CHECK(anormsq.z == aml::normsq(a[2]));
        CHECK(anormsq.w == aml::normsq(a[3]));
    }
}

TEST_CASE("vec3dx4 works") {
    SUBCASE("Is POD") {
        CHECK(std::is_pod<vec3dx4>());
    }
    SUBCASE("Arithmetic") {
        vec3d a[4], b[4];
        for (int i = 0; i < 4; i++) {
            a[i].x = 6*i;
            a[i].y = 6*i + 1;
            a[i].z = 6*i + 2;
            b[i].x = 6*i + 3;
            b[i].y = 6*i + 4;
            b[i].z = 6*i + 5;
        }
        vec3dx4 a4 = vec3dx4::load(a);
        vec3dx4 b4 = vec3dx4::load(b);

        CHECK(a4 == a4);
        CHECK(a4 != b4);

        vec3dx4 c4;
        vec3d c[4];

        c4 = a4 + b4;
        for (int i = 0; i < 4; i++) {
            c[i] = a[i] + b[i];
        }
        CHECK(c4 == vec3dx4::load(c));

        c4 = a4 - b4;
        for (int i = 0; i < 4; i++) {
            c[i] = a[i] - b[i];
        }
        CHECK(c4 == vec3dx4::load(c));

        c4 = a4 * b4;
        for (int i = 0; i < 4; i++) {
            c[i] = a[i] * b[i];
        }
        CHECK(c4 == vec3dx4::load(c));

        c4 = a4 * 2.0;
        for (int i = 0; i < 4; i++) {
            c[i] = a[i] * 2.0;
        }
        CHECK(c4 == vec3dx4::load(c));

        a4 += b4;
        for (int i = 0; i < 4; i++) {
            a[i] += b[i];
        }
        CHECK(a4 == vec3dx4::load(a));

        a4 -= b4;
        for (int i = 0; i < 4; i++) {
            a[i] -= b[i];
        }
        CHECK(a4 == vec3dx4::load(a));

        a4 *= b4;
        for (int i = 0; i < 4; i++) {
            a[i] *= b[i];
        }
        CHECK(a4 == vec3dx4::load(a));

        c4 = aml::cross(a4, b4);
        for (int i = 0; i < 4; i++) {
            c[i] = aml::cross(a[i], b[i]);
        }
        CHECK(a4 == vec3dx4::load(a));

        vec4d anormsq = aml::normsq(a4);
        CHECK(anormsq.x == aml::normsq(a[0]));
        CHECK(anormsq.y == aml::normsq(a[1]));
        CHECK(anormsq.z == aml::normsq(a[2]));
        CHECK(anormsq.w == aml::normsq(a[3]));
    }
}

#undef ALTMATH_USE_SIMD
