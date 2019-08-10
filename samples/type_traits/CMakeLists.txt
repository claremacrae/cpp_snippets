project(type_traits)

# Lazy way to make all projects in this directory depend on shared_code library
link_libraries(shared_code)

add_executable(
    constexpr_if_base_of
    constexpr_if_base_of.cpp
)
set_property(TARGET constexpr_if_base_of PROPERTY CXX_STANDARD 17)

add_executable(
    static_assert_is_base_of
    static_assert_is_base_of.cpp
)

add_executable(
    sfinae_return_type_is_base_of
    sfinae_return_type_is_base_of.cpp
)

add_executable(
    sfinae_template_type_is_base_of
    sfinae_template_type_is_base_of.cpp
)

add_executable(
    tag_dispatch_is_base_of
    tag_dispatch_is_base_of.cpp
)