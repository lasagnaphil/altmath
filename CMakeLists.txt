cmake_minimum_required(VERSION 3.11)
project(altmath)
set(CMAKE_CXX_STANDARD 14)

option(altmath_build_tests "Build tests for altmath." ON)

set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB_RECURSE PROJECT_HEADERS ${PROJECT_INCLUDE_DIR}/*.h)
add_library(altmath INTERFACE)
target_include_directories(altmath INTERFACE ${PROJECT_INCLUDE_DIR})
target_compile_options(altmath INTERFACE -msse -msse2 -msse3 -mavx -mfma)

if (altmath_build_tests)
    set(DOCTEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/doctest)
    add_library(altmath-doctest INTERFACE)
    target_include_directories(altmath-doctest INTERFACE ${DOCTEST_DIR})

    set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)
    file(GLOB_RECURSE TEST_SOURCES ${TEST_DIR}/*.cpp)
    add_executable(altmath-tests ${TEST_SOURCES})
    target_compile_options(altmath-tests PRIVATE -msse -msse2 -msse3 -mavx -mfma)
    target_include_directories(altmath-tests PRIVATE ${PROJECT_INCLUDE_DIR})
    target_link_libraries(altmath-tests altmath-doctest)
endif()
