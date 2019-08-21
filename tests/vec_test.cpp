//
// Created by lasagnaphil on 2018-10-27.
//

#include <type_traits>
#include "doctest.h"

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

#include "math_utils.h"
#include "vec_utils.h"

TEST_CASE("vec2f works") {
    SUBCASE("Is POD") {
        CHECK(std::is_pod<vec2f>());
    }
    SUBCASE("Arithmetic") {
        vec2f a {1.f, 2.f};
        vec2f b {3.f, 4.f};
        CHECK(a + b == vec2f {4.f, 6.f});
        CHECK(a - b == vec2f {-2.f, -2.f});
        CHECK(a * b == vec2f {3.f, 8.f});
        CHECK(a * 2.f == vec2f {2.f, 4.f});
        CHECK(2.f * a == vec2f {2.f, 4.f});
        CHECK(a / 2.f == vec2f {0.5f, 1.f});
        a += b;
        CHECK(a == vec2f {4.f, 6.f});
        a -= b;
        CHECK(a == vec2f {1.f, 2.f});
        a *= b;
        CHECK(a == vec2f {3.f, 8.f});
        a *= 2.f;
        CHECK(a == vec2f {6.f, 16.f});
        a /= 2.f;
        CHECK(a == vec2f {3.f, 8.f});
    }
    SUBCASE("Utility") {
        vec2f a {1.f, 2.f};
        CHECK(aml::normsq(a) == 5.f);
    }
}

TEST_CASE("vec3f works") {
    SUBCASE("Is POD") {
        CHECK(std::is_pod<vec3f>());
    }
    SUBCASE("Arithmetic") {
        vec3f a {1.f, 2.f, 3.f};
        vec3f b {4.f, 5.f, 6.f};
        CHECK(a + b == vec3f {5.f, 7.f, 9.f});
        CHECK(a - b == vec3f {-3.f, -3.f, -3.f});
        CHECK(a * b == vec3f {4.f, 10.f, 18.f});
        CHECK(a * 2.f == vec3f {2.f, 4.f, 6.f});
        CHECK(2.f * a == vec3f {2.f, 4.f, 6.f});
        CHECK(a / 2.f == vec3f {0.5f, 1.0f, 1.5f});
        a += b;
        CHECK(a == vec3f {5.f, 7.f, 9.f});
        a -= b;
        CHECK(a == vec3f {1.f, 2.f, 3.f});
        a *= b;
        CHECK(a == vec3f {4.f, 10.f, 18.f});
        a *= 2.f;
        CHECK(a == vec3f {8.f, 20.f, 36.f});
        a /= 2.f;
        CHECK(a == vec3f {4.f, 10.f, 18.f});
    }
    SUBCASE("Utility") {
        vec3f a {1.f, 2.f, 3.f};
        vec3f b {4.f, 5.f, 6.f};
        CHECK(aml::normsq(a) == 14.f);
        CHECK(aml::cross(a, b) == vec3f {-3.f, 6.f, -3.f});
    }
}

TEST_CASE("vec4f works") {
    SUBCASE("Is POD") {
        CHECK(std::is_pod<vec4f>());
    }
    SUBCASE("Arithmetic") {
        vec4f a {1.f, 2.f, 3.f, 4.f};
        vec4f b {5.f, 6.f, 7.f, 8.f};
        CHECK(a + b == vec4f {6.f, 8.f, 10.f, 12.f});
        CHECK(a - b == vec4f {-4.f, -4.f, -4.f, -4.f});
        CHECK(a * b == vec4f {5.f, 12.f, 21.f, 32.f});
        CHECK(a * 2.f == vec4f {2.f, 4.f, 6.f, 8.f});
        CHECK(2.f * a == vec4f {2.f, 4.f, 6.f, 8.f});
        CHECK(a / 2.f == vec4f {0.5f, 1.0f, 1.5f, 2.0f});
        a += b;
        CHECK(a == vec4f {6.f, 8.f, 10.f, 12.f});
        a -= b;
        CHECK(a == vec4f {1.f, 2.f, 3.f, 4.f});
        a *= b;
        CHECK(a == vec4f {5.f, 12.f, 21.f, 32.f});
        a *= 2.f;
        CHECK(a == vec4f {10.f, 24.f, 42.f, 64.f});
        a /= 2.f;
        CHECK(a == vec4f {5.f, 12.f, 21.f, 32.f});
    }
    SUBCASE("Utility") {
        vec4f a {1.f, 2.f, 3.f, 4.f};
        vec4f b {5.f, 6.f, 7.f, 8.f};
        CHECK(aml::normsq(a) == 30.f);

        vec4f cross = aml::cross(a, b);
        CHECK(cross.x == -4.f);
        CHECK(cross.y == 8.f);
        CHECK(cross.z == -4.f);
    }
}

TEST_CASE("vec2d works") {
    SUBCASE("Is POD") {
        CHECK(std::is_pod<vec2d>());
    }
    SUBCASE("Arithmetic") {
        vec2d a {1.0, 2.0};
        vec2d b {3.0, 4.0};
        CHECK(a + b == vec2d {4.0, 6.0});
        CHECK(a - b == vec2d {-2.0, -2.0});
        CHECK(a * b == vec2d {3.0, 8.0});
        CHECK(a * 2.0 == vec2d {2.0, 4.0});
        CHECK(2.0 * a == vec2d {2.0, 4.0});
        CHECK(a / 2.0 == vec2d {0.5, 1.0});
        a += b;
        CHECK(a == vec2d {4.0, 6.0});
        a -= b;
        CHECK(a == vec2d {1.0, 2.0});
        a *= b;
        CHECK(a == vec2d {3.0, 8.0});
        a *= 2.0;
        CHECK(a == vec2d {6.0, 16.0});
        a /= 2.0;
        CHECK(a == vec2d {3.0, 8.0});
    }
    SUBCASE("Utility") {
        vec2d a {1.0, 2.0};
        CHECK(aml::normsq(a) == 5.0);
    }
}

TEST_CASE("vec3d works") {
    SUBCASE("Is POD") {
        CHECK(std::is_pod<vec3d>());
    }
    SUBCASE("Arithmetic") {
        vec3d a {1.0, 2.0, 3.0};
        vec3d b {4.0, 5.0, 6.0};
        CHECK(a + b == vec3d {5.0, 7.0, 9.0});
        CHECK(a - b == vec3d {-3.0, -3.0, -3.0});
        CHECK(a * b == vec3d {4.0, 10.0, 18.0});
        CHECK(a * 2.0 == vec3d {2.0, 4.0, 6.0});
        CHECK(2.0 * a == vec3d {2.0, 4.0, 6.0});
        CHECK(a / 2.0 == vec3d {0.5, 1.0, 1.5});
        a += b;
        CHECK(a == vec3d {5.0, 7.0, 9.0});
        a -= b;
        CHECK(a == vec3d {1.0, 2.0, 3.0});
        a *= b;
        CHECK(a == vec3d {4.0, 10.0, 18.0});
        a *= 2.0;
        CHECK(a == vec3d {8.0, 20.0, 36.0});
        a /= 2.0;
        CHECK(a == vec3d {4.0, 10.0, 18.0});
    }
    SUBCASE("Utility") {
        vec3d a {1.0, 2.0, 3.0};
        vec3d b {4.0, 5.0, 6.0};
        CHECK(aml::normsq(a) == 14.0);
        CHECK(aml::cross(a, b) == vec3d {-3.0, 6.0, -3.0});
    }
}

TEST_CASE("vec4d works") {
    SUBCASE("Is POD") {
        CHECK(std::is_pod<vec4d>());
    }
    SUBCASE("Arithmetic") {
        vec4d a {1.0, 2.0, 3.0, 4.0};
        vec4d b {5.0, 6.0, 7.0, 8.0};
        CHECK(a + b == vec4d {6.0, 8.0, 10.0, 12.0});
        CHECK(a - b == vec4d {-4.0, -4.0, -4.0, -4.0});
        CHECK(a * b == vec4d {5.0, 12.0, 21.0, 32.0});
        CHECK(a * 2.0 == vec4d {2.0, 4.0, 6.0, 8.0});
        CHECK(2.0 * a == vec4d {2.0, 4.0, 6.0, 8.0});
        CHECK(a / 2.0 == vec4d {0.5, 1.0, 1.5, 2.0});
        a += b;
        CHECK(a == vec4d {6.0, 8.0, 10.0, 12.0});
        a -= b;
        CHECK(a == vec4d {1.0, 2.0, 3.0, 4.0});
        a *= b;
        CHECK(a == vec4d {5.0, 12.0, 21.0, 32.0});
        a *= 2.0;
        CHECK(a == vec4d {10.0, 24.0, 42.0, 64.0});
        a /= 2.0;
        CHECK(a == vec4d {5.0, 12.0, 21.0, 32.0});
    }
    SUBCASE("Utility") {
        vec4d a {1.0, 2.0, 3.0, 4.0};
        vec4d b {5.0, 6.0, 7.0, 8.0};
        CHECK(aml::normsq(a) == 30.0);

        vec4d cross = aml::cross(a, b);
        CHECK(cross.x == -4.0);
        CHECK(cross.y == 8.0);
        CHECK(cross.z == -4.0);
    }
}

TEST_CASE("vec4i works") {
    SUBCASE("Is POD") {
        CHECK(std::is_pod<vec4i>());
    }
    SUBCASE("Arithmetic") {
        vec4i a {1, 2, 3, 4};
        vec4i b {5, 6, 7, 8};
        CHECK(a + b == vec4i {6, 8, 10, 12});
        CHECK(a - b == vec4i {-4, -4, -4, -4});
        CHECK(a * b == vec4i {5, 12, 21, 32});
        CHECK(a * 2 == vec4i {2, 4, 6, 8});
        CHECK(2 * a == vec4i {2, 4, 6, 8});

        vec4f c = aml::toFloat(a) * 0.5f;
        CHECK(aml::toInt(aml::floor(c)) == vec4i {0, 1, 1, 2});
        a += b;
        CHECK(a == vec4i {6, 8, 10, 12});
        a -= b;
        CHECK(a == vec4i {1, 2, 3, 4});
        a *= b;
        CHECK(a == vec4i {5, 12, 21, 32});
        a *= 2;
        CHECK(a == vec4i {10, 24, 42, 64});
    }
    SUBCASE("Utility") {
        vec4i a {1, 2, 3, 4};
        vec4i b {5, 6, 7, 8};
        CHECK(aml::normsq(a) == 30);

        vec4i cross = aml::cross(a, b);
        CHECK(cross.x == -4);
        CHECK(cross.y == 8);
        CHECK(cross.z == -4);
    }
}


