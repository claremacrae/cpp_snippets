project(type_traits)

add_executable(
    type_trait_is_base_of
    type_trait_is_base_of.cpp)
set_property(TARGET type_trait_is_base_of PROPERTY CXX_STANDARD 17)

add_executable(
    static_assert_is_base_of
    static_assert_is_base_of.cpp
)
