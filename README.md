# altmath - The Alternative Math Library

### NOTE: WORK IN PROGRESS

## Motivation

Tired of finding a C++ math library that was just right for graphics and physics simulations, I decided to reinvent the wheel and make my own. (I promise: this wheel will actually be round this time!)

It follows these rules:

- All structs are POD (Plain-Old Data) types. 

  This is often overlooked and never applied to any C++ library. I think vectors should be POD, so when you hand in an array of ``vec3``'s to OpenGL/Vulkan/etc..., you can guarantee that they are aligned the same as ``float[3]``. Other C++ libraries actually just "assume" that even if vec3 is not POD, it would have the fields x, y, and z contiguously like a POD layout. This assumption is not specified by the C++ standard, so this is actually relying on compiler-specific behavior! (Although it seems like nobody had any problems with this, so maybe I am overreacting. For an explanation, check out this [link](https://stackoverflow.com/questions/17197373/can-glm-be-used-as-plain-old-data-in-gluniformx).) As an added bonus, I can easily make this library C-compatible if I want.
  
  Also, I prefer static factory methods instead of constructors. Case closed.

- It supports both float and double types... because they are both useful to me.
  
- Use SIMD aggressively (like, the lastest shiny stuff like AVX/FMA).

  Almost all CPUs from 2014 will support AVX/FMA, so I've used it as the default when ``ALTMATH_USE_SIMD`` flag is on. However, (if I have the time) I will later make a CMake option to disable AVX/FMA (only SSE), or SIMD entirely.
  
- Use functions instead of methods.

  This is because of template specialization wonkyness. Basically, if you make your generic functions as methods, you can't specialize just some of them; you need to specialize all of it instead. Also, for a math library, freeform functions feel more natural than methods... (although this is just personal preference)

- Follows GLSL-like name convention.

  Just personal preference.

It implements:

- ``vec2``, ``vec3``, ``vec4``
- ``mat4``
- ``quat``

There are also types that are SIMDed when the preprocessor variable ``ALTMATH_USE_SIMD`` is defined:

- ``vec2d``, ``vec4f``, ``vec4d``
- ``mat2f``, ``mat4f``, ``mat4d``
- ``quatf``

Using those specialized types won't automatically make your code really fast in every occasion. For example, the dot product doesn't give that much of a speed boost in SIMD. I will later try benchmarking this library to see how much performance you can gain.

So just remember that sometimes you really need to restructure your data to AOSOA layout and use SIMD with your bare hands...

Note that I am planning to make ``vec2dx4``, ``vec3dx4``, ``vec4dx4`` types for this purpose.

## Requirements

- C++11 x86_64 compiler
- Optional AVX/FMA support
    - Note: AVX/FMA doesn't work on MinGW GCC right now because of alignment issues, so use MinGW Clang instead

## License

MIT
