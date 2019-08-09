project(type_traits)

add_executable(
    type_trait_is_base_of
    type_trait_is_base_of.cpp)
set_property(TARGET type_trait_is_base_of PROPERTY CXX_STANDARD 17)