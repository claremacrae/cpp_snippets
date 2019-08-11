project(samples)

add_executable(${PROJECT_NAME}
    main.cpp
    variadic_templates/variadic_combinations.cpp
    variadic_templates/variadic_printing.cpp
    variadic_templates/variadic_printing_with_initializer_lists.cpp
    variadic_templates/variadic_fmin.cpp
    variadic_templates/variadic_printing_with_recursion.cpp
    )
# TODO Improve how Catch.hpp is found - ApprovalTests.cpp/ApprovalTests/Catch2Approvals.h requires a file call Catch.hpp
target_include_directories(${PROJECT_NAME} PUBLIC . ${ApprovalTestsDir}/ApprovalTests ${ApprovalTestsDir}/lib )

target_link_libraries(${PROJECT_NAME} ApprovalTests)

add_subdirectory(type_traits)
