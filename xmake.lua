target("altmath")
    add_includedirs("src", {public = true})

target("altmath-simd")
    add_includedirs("src", {public = true})

test_srcs = {"tests/mat_test.cpp", "tests/quat_test.cpp", "tests/vec_test.cpp", "tests/test_main.cpp"}
test_simd_srcs = {"tests/vec_simd_test.cpp"}

target("altmath-tests")
    set_kind("binary")
    add_includedirs("doctest") 
    add_files(table.unpack(test_srcs))
    add_links("pthread")
    add_deps("altmath")

target("altmath-tests-simd")
    set_kind("binary")
    add_includedirs("doctest")
    add_files(table.unpack(test_srcs))
    add_files(table.unpack(test_simd_srcs))
    add_links("pthread")
    add_cxxflags("-msse", "-msse2", "-msse3", "-mavx", "-mfma")
    add_defines("ALTMATH_USE_SIMD")
    add_deps("altmath-simd")
