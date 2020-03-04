// Code from https://youtu.be/o1EvPhz6UNE?t=993
// C++ Weekly - Ep 6 Intro To Variadic Templates - initializer list example

#include "catch2/catch.hpp"
#include "Approvals.h"

#include <sstream>
#include <vector>

template <typename T> std::string to_string_impl(const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

// This is an alternative to variadic_printing_with_recursion.cpp that is
// quicker to compile, and generates smaller binaries.
template <typename... Param> std::vector<std::string> to_string(const Param&... param)
{
    // Using initializer list:
    return {to_string_impl(param)...};
}

TEST_CASE("Variadic Printing with Initializer Lists")
{
    std::stringstream ss;
    const auto vec = to_string("hello", 1, 5.3, "World");
    for (const auto& v : vec)
    {
        ss << v << '\n';
    }
    ApprovalTests::Approvals::verify(ss.str());
}
