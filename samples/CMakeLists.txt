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

# TODO Improve how Catch.hpp is found - ApprovalTests.cpp/ApprovalTests/Catch2Approvals.h requires a file call Catch.hpp
target_include_directories(${PROJECT_NAME} PUBLIC . ${ApprovalTestsDir}/ApprovalTests ${ApprovalTestsDir}/lib )

target_link_libraries(${PROJECT_NAME} ApprovalTests)

# This is for building any programs that depend on other than C++11
add_subdirectory(type_traits)
