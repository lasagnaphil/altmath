//
// Created by lasagnaphil on 10/28/18.
//

#include <catch.hpp>
#include "quat.h"

TEST_CASE("quatf works", "[quatf]") {
    SECTION("Is POD") {
        REQUIRE(std::is_pod<quatf>());
    }
}
