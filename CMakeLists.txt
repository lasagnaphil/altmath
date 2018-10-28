cmake_minimum_required(VERSION 3.11)
project(altmath)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -march=native)

set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB_RECURSE PROJECT_HEADERS ${PROJECT_INCLUDE_DIR}/*.h)
add_library(altmath INTERFACE)
target_include_directories(altmath INTERFACE ${PROJECT_INCLUDE_DIR})

set(CATCH2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch2)
add_library(catch2 INTERFACE)
target_include_directories(catch2 INTERFACE ${CATCH2_DIR})

set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)
file(GLOB_RECURSE TEST_SOURCES ${TEST_DIR}/*.cpp)
add_executable(altmath-tests ${TEST_SOURCES})
target_include_directories(altmath-tests PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(altmath-tests catch2)
