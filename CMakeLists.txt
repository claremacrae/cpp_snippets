cmake_minimum_required(VERSION 3.14)
project(cpp_snippets)
set(CMAKE_CXX_STANDARD 11)
add_subdirectory(samples)

#if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
#    target_compile_options(${PROJECT_NAME} PRIVATE
#        -Wall
#        -Wextra
#        -Wpedantic
#        -Werror
#        -Wno-unused-function
#        )
#elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
#    target_compile_options(${PROJECT_NAME} PRIVATE
#        /W4
#        /WX
#        /wd4505 # unreferenced local function has been removed
#        )
#endif()
