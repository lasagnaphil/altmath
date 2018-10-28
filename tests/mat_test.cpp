//
// Created by lasagnaphil on 2018-10-27.
//

#include <catch.hpp>

#include "mat4f.h"
#include "mat4d.h"
#include "vec4f.h"
#include "vec4d.h"

#include "mat_utils.h"
#include "utility.h"

TEST_CASE("mat4f works", "[mat4f]") {
    SECTION("Is POD") {
        REQUIRE(std::is_pod<mat4f>());
    }
    SECTION("Basic arithmetic") {
        mat4f a = {0.f, 1.f, 2.f, 3.f,
                   4.f, 5.f, 6.f, 7.f,
                   8.f, 9.f, 10.f, 11.f,
                   12.f, 13.f, 14.f, 15.f};
        mat4f b = a;
        vec4f v = {1.f, 2.f, 3.f, 4.f};

        REQUIRE(a == b);
        REQUIRE(a + b == mat4f {0.f, 2.f, 4.f, 6.f,
                                8.f, 10.f, 12.f, 14.f,
                                16.f, 18.f, 20.f, 22.f,
                                24.f, 26.f, 28.f, 30.f});
        REQUIRE(a - b == mat4f {0.f, 0.f, 0.f, 0.f,
                                0.f, 0.f, 0.f, 0.f,
                                0.f, 0.f, 0.f, 0.f,
                                0.f, 0.f, 0.f, 0.f});
        REQUIRE(a*2.f == mat4f {0.f, 2.f, 4.f, 6.f,
                                8.f, 10.f, 12.f, 14.f,
                                16.f, 18.f, 20.f, 22.f,
                                24.f, 26.f, 28.f, 30.f});
        REQUIRE(2.f*a == mat4f {0.f, 2.f, 4.f, 6.f,
                                8.f, 10.f, 12.f, 14.f,
                                16.f, 18.f, 20.f, 22.f,
                                24.f, 26.f, 28.f, 30.f});
        REQUIRE(a * b == mat4f {56.f, 62.f, 68.f, 74.f,
                                152.f, 174.f, 196.f, 218.f,
                                248.f, 286.f, 324.f, 362.f,
                                344.f, 398.f, 452.f, 506.f});
        REQUIRE(a * v == vec4f {20.f, 60.f, 100.f, 140.f});
    }
}

TEST_CASE("mat4d works", "[mat4d]") {
    SECTION("Is POD") {
        REQUIRE(std::is_pod<mat4d>());
    }
    SECTION("Basic arithmetic") {
        mat4d a = {0.0, 1.0, 2.0, 3.0,
                   4.0, 5.0, 6.0, 7.0,
                   8.0, 9.0, 10.0, 11.0,
                   12.0, 13.0, 14.0, 15.0};
        mat4d b = a;
        vec4d v = {1.0, 2.0, 3.0, 4.0};

        REQUIRE(a == b);
        REQUIRE(a + b == mat4d {0.0, 2.0, 4.0, 6.0,
                                8.0, 10.0, 12.0, 14.0,
                                16.0, 18.0, 20.0, 22.0,
                                24.0, 26.0, 28.0, 30.0});
        REQUIRE(a - b == mat4d {0.0, 0.0, 0.0, 0.0,
                                0.0, 0.0, 0.0, 0.0,
                                0.0, 0.0, 0.0, 0.0,
                                0.0, 0.0, 0.0, 0.0});
        REQUIRE(a*2.0 == mat4d {0.0, 2.0, 4.0, 6.0,
                                8.0, 10.0, 12.0, 14.0,
                                16.0, 18.0, 20.0, 22.0,
                                24.0, 26.0, 28.0, 30.0});
        REQUIRE(2.0*a == mat4d {0.0, 2.0, 4.0, 6.0,
                                8.0, 10.0, 12.0, 14.0,
                                16.0, 18.0, 20.0, 22.0,
                                24.0, 26.0, 28.0, 30.0});
        REQUIRE(a * b == mat4d {56.0, 62.0, 68.0, 74.0,
                                152.0, 174.0, 196.0, 218.0,
                                248.0, 286.0, 324.0, 362.0,
                                344.0, 398.0, 452.0, 506.0});
        REQUIRE(a * v == vec4d {20.0, 60.0, 100.0, 140.0});
    }
}

