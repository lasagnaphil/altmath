//
// Created by lasagnaphil on 10/28/18.
//

#include <type_traits>
#include "doctest.h"

#include "quatf.h"
#include "mat_utils.h"

TEST_CASE("quatf works") {
    SUBCASE("Is POD") {
        CHECK(std::is_pod<quatf>());
    }

    SUBCASE("Multiplication") {
        using doctest::Approx;

        quatf p = {1/sqrtf(2.f), 1/sqrtf(2.f), 0.f, 0.f};
        quatf q = {1/sqrtf(2.f), 0.f, 1/sqrtf(2.f), 0.f};

        quatf c = p * aml::conj(p);
        CHECK(c.x == Approx(0.0f));
        CHECK(c.y == Approx(0.0f));
        CHECK(c.z == Approx(0.0f));
        CHECK(c.w == Approx(1.0f));
    }
}
