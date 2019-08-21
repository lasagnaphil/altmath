cmake_minimum_required(VERSION 3.11)
project(altmath)
set(CMAKE_CXX_STANDARD 14)

option(altmath_build_tests "Build tests for altmath." ON)

set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB_RECURSE PROJECT_HEADERS ${PROJECT_INCLUDE_DIR}/*.h)
add_library(altmath INTERFACE)
target_include_directories(altmath INTERFACE ${PROJECT_INCLUDE_DIR})

if (altmath_build_tests)
    set(ALTMATH_DOCTEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/doctest)
    add_library(altmath-doctest INTERFACE)
    target_compile_definitions(altmath-doctest INTERFACE TLS_NO_DEBUG)
    target_include_directories(altmath-doctest INTERFACE ${ALTMATH_DOCTEST_DIR})

    find_package(Threads REQUIRED)

    set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

    set(TEST_SOURCES
            ${TEST_DIR}/test_main.cpp
            ${TEST_DIR}/vec_test.cpp
            ${TEST_DIR}/quat_test.cpp
            ${TEST_DIR}/mat_test.cpp)
    add_executable(altmath-tests ${TEST_SOURCES})
    target_include_directories(altmath-tests PRIVATE ${PROJECT_INCLUDE_DIR})
    target_link_libraries(altmath-tests PRIVATE altmath-doctest Threads::Threads)

    set(TEST_SIMD_SOURCES
            ${TEST_DIR}/test_main.cpp
            ${TEST_DIR}/vec_test.cpp
            ${TEST_DIR}/quat_test.cpp
            ${TEST_DIR}/mat_test.cpp
            ${TEST_DIR}/vec_simd_test.cpp)
    add_executable(altmath-simd-tests ${TEST_SIMD_SOURCES})
    target_compile_definitions(altmath-simd-tests PRIVATE ALTMATH_USE_SIMD)
    target_compile_options(altmath-simd-tests PRIVATE -msse -msse2 -msse3 -mavx -mfma)
    target_include_directories(altmath-simd-tests PRIVATE ${PROJECT_INCLUDE_DIR})
    target_link_libraries(altmath-simd-tests PRIVATE altmath-doctest Threads::Threads)

endif()
