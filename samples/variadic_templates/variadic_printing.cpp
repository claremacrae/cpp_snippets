// Code from https://youtu.be/CU3VYN6xGzM?t=178
// C++ Weekly - Ep 10 Variadic Expansion Wrap-Up
// In godbolt at https://godbolt.org/z/4jIxgF

#include "Catch.hpp"
#include "Approvals.h"

#include <sstream>

template<typename T>
void print_impl(std::ostream& ss, const T& t)
{
    ss << t << '\n';
}

template<typename ... T>
void print(std::ostream& ss, const T& ... t)
{
    (void)std::initializer_list<int>{ (print_impl(ss, t), 0)...};
}

TEST_CASE("Variadic Printing")
{
    std::stringstream ss;
    print(ss, "Hello", 42, "World");
    Approvals::verify(ss.str());
}
