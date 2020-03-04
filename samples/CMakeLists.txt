project(samples)

add_executable(${PROJECT_NAME}
        main.cpp
        type_traits/static_assert_is_base_of.cpp
        type_traits/sfinae_return_type_is_base_of.cpp
        type_traits/sfinae_template_type_is_base_of.cpp
        type_traits/tag_dispatch_is_base_of.cpp
        variadic_templates/variadic_combinations.cpp
        variadic_templates/variadic_printing.cpp
        variadic_templates/variadic_printing_with_initializer_lists.cpp
        variadic_templates/variadic_fmin.cpp
        variadic_templates/variadic_printing_with_recursion.cpp
        )

target_link_libraries(${PROJECT_NAME} shared_code)
target_link_libraries(${PROJECT_NAME} ApprovalTests::ApprovalTests Catch2::Catch2)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

# This is for building any programs that depend on other than C++11
add_subdirectory(type_traits)
