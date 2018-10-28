//
// Created by lasagnaphil on 2018-10-27.
//

#include <catch.hpp>
#include "vec2fp.h"
#include "vec3fp.h"
#include "vec4f.h"
#include "vec2d.h"
#include "vec3dp.h"
#include "vec4d.h"

TEST_CASE("vec2f works", "[vec2f]") {
    SECTION("Is POD") {
        REQUIRE(std::is_pod<vec2fp>());
    }
    SECTION("Arithmetic") {
        vec2fp a {1.f, 2.f};
        vec2fp b {3.f, 4.f};
        REQUIRE(a + b == vec2fp {4.f, 6.f});
        REQUIRE(a - b == vec2fp {-2.f, -2.f});
        REQUIRE(a * b == vec2fp {3.f, 8.f});
        REQUIRE(a * 2.f == vec2fp {2.f, 4.f});
        REQUIRE(2.f * a == vec2fp {2.f, 4.f});
    }
}

TEST_CASE("vec3f works", "[vec3f]") {
    SECTION("Is POD") {
        REQUIRE(std::is_pod<vec3fp>());
    }
    SECTION("Arithmetic") {
        vec3fp a {1.f, 2.f, 3.f};
        vec3fp b {4.f, 5.f, 6.f};
        REQUIRE(a + b == vec3fp {5.f, 7.f, 9.f});
        REQUIRE(a - b == vec3fp {-3.f, -3.f, -3.f});
        REQUIRE(a * b == vec3fp {4.f, 10.f, 12.f});
        REQUIRE(a * 2.f == vec3fp {2.f, 4.f, 6.f});
        REQUIRE(2.f * a == vec3fp {2.f, 4.f, 6.f});
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
    }
}

TEST_CASE("vec3d works", "[vec3d]") {
    SECTION("Is POD") {
        REQUIRE(std::is_pod<vec3dp>());
    }
    SECTION("Arithmetic") {
        vec3dp a {1.0, 2.0, 3.0};
        vec3dp b {4.0, 5.0, 6.0};
        REQUIRE(a + b == vec3dp {5.0, 7.0, 9.0});
        REQUIRE(a - b == vec3dp {-3.0, -3.0, -3.0});
        REQUIRE(a * b == vec3dp {4.0, 10.0, 12.0});
        REQUIRE(a * 2.0 == vec3dp {2.0, 4.0, 6.0});
        REQUIRE(2.0 * a == vec3dp {2.0, 4.0, 6.0});
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
    }
}

