//
// Created by lasagnaphil on 2018-10-27.
//

#define CATCH_CONFIG_RUNNER

#include "catch.hpp"

int main(int argc, char** argv) {
    int result = Catch::Session().run(argc, argv);
#ifdef _DEBUG
    getchar();
#endif
    return result;
}