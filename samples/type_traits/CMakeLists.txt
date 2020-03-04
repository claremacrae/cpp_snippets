project(type_traits)

# Lazy way to make all projects in this directory depend on shared_code library
link_libraries(shared_code)

add_executable(
    constexpr_if_base_of
    constexpr_if_base_of.cpp
)
set_property(TARGET constexpr_if_base_of PROPERTY CXX_STANDARD 17)

add_test(NAME constexpr_if_base_of COMMAND constexpr_if_base_of)
