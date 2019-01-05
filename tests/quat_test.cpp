//
// Created by lasagnaphil on 10/28/18.
//

#include <catch.hpp>
#include "quatf.h"
#include "mat_utils.h"

TEST_CASE("quatf works", "[quatf]") {
    SECTION("Is POD") {
        REQUIRE(std::is_pod<quatf>());
    }

    SECTION("Multiplication") {
        quatf p = {1/sqrtf(2.f), 1/sqrtf(2.f), 0.f, 0.f};
        quatf q = {1/sqrtf(2.f), 0.f, 1/sqrtf(2.f), 0.f};

        quatf c = p * aml::conj(p);
        REQUIRE(c.x == Approx(0.0f));
        REQUIRE(c.y == Approx(0.0f));
        REQUIRE(c.z == Approx(0.0f));
        REQUIRE(c.w == Approx(1.0f));
    }
}
