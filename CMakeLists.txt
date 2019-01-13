cmake_minimum_required(VERSION 3.11)
set(PROJECT_NAME altmath)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 14)

option(altmath_build_tests "Build tests for altmath." ON)

set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB_RECURSE PROJECT_HEADERS ${PROJECT_INCLUDE_DIR}/*.h)
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_INCLUDE_DIR})

if (altmath_build_tests)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -march=native)

    set(CATCH2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch2)
    add_library(catch2 INTERFACE)
    target_include_directories(catch2 INTERFACE ${CATCH2_DIR})

    set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)
    file(GLOB_RECURSE TEST_SOURCES ${TEST_DIR}/*.cpp)
    add_executable(altmath-tests ${TEST_SOURCES})
    target_include_directories(altmath-tests PRIVATE ${PROJECT_INCLUDE_DIR})
    target_link_libraries(altmath-tests catch2)
endif()
