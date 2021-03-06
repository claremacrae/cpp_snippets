// Code from https://youtu.be/o1EvPhz6UNE?t=661
// C++ Weekly - Ep 6 Intro To Variadic Templates - recursive example

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

std::vector<std::string> to_string()
{
    return {};
}

// With a large number of arguments supplied in the call, this recursive
// implementation generates one function for each of the successive calls,
// which can really slow down compilation.
// See variadic_print_with_initializer_lists.cpp for a more efficient
// version.
template <typename P1, typename... Param>
std::vector<std::string> to_string(const P1& p1, const Param&... param)
{
    std::vector<std::string> s;
    s.push_back(to_string_impl(p1));

    const auto remainder = to_string(param...);
    s.insert(s.end(), remainder.begin(), remainder.end());
    return s;
}

TEST_CASE("Variadic Printing With Recursion")
{
    std::stringstream ss;
    const auto vec = to_string("hello", 1, 5.3, "World");
    for (const auto& v : vec)
    {
        ss << v << '\n';
    }
    ApprovalTests::Approvals::verify(ss.str());
}
