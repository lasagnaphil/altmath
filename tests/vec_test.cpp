//
// Created by lasagnaphil on 2018-10-27.
//

#include <catch.hpp>

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "vec4f.h"
#include "vec2d.h"
#include "vec4d.h"

TEST_CASE("vec2f works", "[vec2f]") {
    SECTION("Is POD") {
        REQUIRE(std::is_pod<vec2f>());
    }
    SECTION("Arithmetic") {
        vec2f a {1.f, 2.f};
        vec2f b {3.f, 4.f};
        REQUIRE(a + b == vec2f {4.f, 6.f});
        REQUIRE(a - b == vec2f {-2.f, -2.f});
        REQUIRE(a * b == vec2f {3.f, 8.f});
        REQUIRE(a * 2.f == vec2f {2.f, 4.f});
        REQUIRE(2.f * a == vec2f {2.f, 4.f});
        REQUIRE(a / 2.f == vec2f {0.5f, 1.f});
        a += b;
        REQUIRE(a == vec2f {4.f, 6.f});
        a -= b;
        REQUIRE(a == vec2f {1.f, 2.f});
        a *= b;
        REQUIRE(a == vec2f {3.f, 8.f});
        a *= 2.f;
        REQUIRE(a == vec2f {6.f, 16.f});
        a /= 2.f;
        REQUIRE(a == vec2f {3.f, 8.f});
    }
    SECTION("Utility") {
        vec2f a {1.f, 2.f};
        REQUIRE(aml::normsq(a) == 5.f);
    }
}

TEST_CASE("vec3f works", "[vec3f]") {
    SECTION("Is POD") {
        REQUIRE(std::is_pod<vec3f>());
    }
    SECTION("Arithmetic") {
        vec3f a {1.f, 2.f, 3.f};
        vec3f b {4.f, 5.f, 6.f};
        REQUIRE(a + b == vec3f {5.f, 7.f, 9.f});
        REQUIRE(a - b == vec3f {-3.f, -3.f, -3.f});
        REQUIRE(a * b == vec3f {4.f, 10.f, 18.f});
        REQUIRE(a * 2.f == vec3f {2.f, 4.f, 6.f});
        REQUIRE(2.f * a == vec3f {2.f, 4.f, 6.f});
        REQUIRE(a / 2.f == vec3f {0.5f, 1.0f, 1.5f});
        a += b;
        REQUIRE(a == vec3f {5.f, 7.f, 9.f});
        a -= b;
        REQUIRE(a == vec3f {1.f, 2.f, 3.f});
        a *= b;
        REQUIRE(a == vec3f {4.f, 10.f, 18.f});
        a *= 2.f;
        REQUIRE(a == vec3f {8.f, 20.f, 36.f});
        a /= 2.f;
        REQUIRE(a == vec3f {4.f, 10.f, 18.f});
    }
    SECTION("Utility") {
        vec3f a {1.f, 2.f, 3.f};
        vec3f b {4.f, 5.f, 6.f};
        REQUIRE(aml::normsq(a) == 14.f);
        REQUIRE(aml::cross(a, b) == vec3f {-3.f, 6.f, -3.f});
    }
}

TEST_CASE("vec4f works", "[vec4f]") {
    SECTION("Is POD") {
        REQUIRE(std::is_pod<vec4f>());
    }
    SECTION("Arithmetic") {
        vec4f a {1.f, 2.f, 3.f, 4.f};
        vec4f b {5.f, 6.f, 7.f, 8.f};
        REQUIRE(a + b == vec4f {6.f, 8.f, 10.f, 12.f});
        REQUIRE(a - b == vec4f {-4.f, -4.f, -4.f, -4.f});
        REQUIRE(a * b == vec4f {5.f, 12.f, 21.f, 32.f});
        REQUIRE(a * 2.f == vec4f {2.f, 4.f, 6.f, 8.f});
        REQUIRE(2.f * a == vec4f {2.f, 4.f, 6.f, 8.f});
        REQUIRE(a / 2.f == vec4f {0.5f, 1.0f, 1.5f, 2.0f});
        a += b;
        REQUIRE(a == vec4f {6.f, 8.f, 10.f, 12.f});
        a -= b;
        REQUIRE(a == vec4f {1.f, 2.f, 3.f, 4.f});
        a *= b;
        REQUIRE(a == vec4f {5.f, 12.f, 21.f, 32.f});
        a *= 2.f;
        REQUIRE(a == vec4f {10.f, 24.f, 42.f, 64.f});
        a /= 2.f;
        REQUIRE(a == vec4f {5.f, 12.f, 21.f, 32.f});
    }
    SECTION("Utility") {
        vec4f a {1.f, 2.f, 3.f, 4.f};
        vec4f b {5.f, 6.f, 7.f, 8.f};
        REQUIRE(aml::normsq(a) == 30.f);

        vec4f cross = aml::cross(a, b);
        REQUIRE(cross.x == -4.f);
        REQUIRE(cross.y == 8.f);
        REQUIRE(cross.z == -4.f);
    }
}

TEST_CASE("vec2d works", "[vec2d]") {
    SECTION("Is POD") {
        REQUIRE(std::is_pod<vec2d>());
    }
    SECTION("Arithmetic") {
        vec2d a {1.0, 2.0};
        vec2d b {3.0, 4.0};
        REQUIRE(a + b == vec2d {4.0, 6.0});
        REQUIRE(a - b == vec2d {-2.0, -2.0});
        REQUIRE(a * b == vec2d {3.0, 8.0});
        REQUIRE(a * 2.0 == vec2d {2.0, 4.0});
        REQUIRE(2.0 * a == vec2d {2.0, 4.0});
        REQUIRE(a / 2.0 == vec2d {0.5, 1.0});
        a += b;
        REQUIRE(a == vec2d {4.0, 6.0});
        a -= b;
        REQUIRE(a == vec2d {1.0, 2.0});
        a *= b;
        REQUIRE(a == vec2d {3.0, 8.0});
        a *= 2.f;
        REQUIRE(a == vec2d {6.0, 16.0});
        a /= 2.f;
        REQUIRE(a == vec2d {3.0, 8.0});
    }
    SECTION("Utility") {
        vec2d a {1.0, 2.0};
        REQUIRE(aml::normsq(a) == 5.0);
    }
}

TEST_CASE("vec3d works", "[vec3d]") {
    SECTION("Is POD") {
        REQUIRE(std::is_pod<vec3d>());
    }
    SECTION("Arithmetic") {
        vec3d a {1.0, 2.0, 3.0};
        vec3d b {4.0, 5.0, 6.0};
        REQUIRE(a + b == vec3d {5.0, 7.0, 9.0});
        REQUIRE(a - b == vec3d {-3.0, -3.0, -3.0});
        REQUIRE(a * b == vec3d {4.0, 10.0, 18.0});
        REQUIRE(a * 2.0 == vec3d {2.0, 4.0, 6.0});
        REQUIRE(2.0 * a == vec3d {2.0, 4.0, 6.0});
        REQUIRE(a / 2.0 == vec3d {0.5, 1.0, 1.5});
        a += b;
        REQUIRE(a == vec3d {5.0, 7.0, 9.0});
        a -= b;
        REQUIRE(a == vec3d {1.0, 2.0, 3.0});
        a *= b;
        REQUIRE(a == vec3d {4.0, 10.0, 18.0});
        a *= 2.0;
        REQUIRE(a == vec3d {8.0, 20.0, 36.0});
        a /= 2.0;
        REQUIRE(a == vec3d {4.0, 10.0, 18.0});
    }
    SECTION("Utility") {
        vec3d a {1.0, 2.0, 3.0};
        vec3d b {4.0, 5.0, 6.0};
        REQUIRE(aml::normsq(a) == 14.0);
        REQUIRE(aml::cross(a, b) == vec3d {-3.0, 6.0, -3.0});
    }
}

TEST_CASE("vec4d works", "[vec4d]") {
    SECTION("Is POD") {
        REQUIRE(std::is_pod<vec4d>());
    }
    SECTION("Arithmetic") {
        vec4d a {1.0, 2.0, 3.0, 4.0};
        vec4d b {5.0, 6.0, 7.0, 8.0};
        REQUIRE(a + b == vec4d {6.0, 8.0, 10.0, 12.0});
        REQUIRE(a - b == vec4d {-4.0, -4.0, -4.0, -4.0});
        REQUIRE(a * b == vec4d {5.0, 12.0, 21.0, 32.0});
        REQUIRE(a * 2.0 == vec4d {2.0, 4.0, 6.0, 8.0});
        REQUIRE(2.0 * a == vec4d {2.0, 4.0, 6.0, 8.0});
        REQUIRE(a / 2.0 == vec4d {0.5, 1.0, 1.5, 2.0});
        a += b;
        REQUIRE(a == vec4d {6.0, 8.0, 10.0, 12.0});
        a -= b;
        REQUIRE(a == vec4d {1.0, 2.0, 3.0, 4.0});
        a *= b;
        REQUIRE(a == vec4d {5.0, 12.0, 21.0, 32.0});
        a *= 2.0;
        REQUIRE(a == vec4d {10.0, 24.0, 42.0, 64.0});
        a /= 2.0;
        REQUIRE(a == vec4d {5.0, 12.0, 21.0, 32.0});
    }
    SECTION("Utility") {
        vec4d a {1.0, 2.0, 3.0, 4.0};
        vec4d b {5.0, 6.0, 7.0, 8.0};
        REQUIRE(aml::normsq(a) == 30.0);

        vec4d cross = aml::cross(a, b);
        REQUIRE(cross.x == -4.0);
        REQUIRE(cross.y == 8.0);
        REQUIRE(cross.z == -4.0);
    }
}

