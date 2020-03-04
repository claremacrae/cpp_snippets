#include "catch2/catch.hpp"
#include "Approvals.h"

#include <initializer_list>
#include <sstream>

// Variadic function that takes any number of containers.
// Initially, just prints container size

template<typename T>
void combinations_impl(std::ostream& ss, const T& t)
{
    ss << t.size() << '\n';
}

// Handle the final, empty case
void combinations(std::ostream& /*ss*/)
{
}

template<typename C1, typename ... C>
void combinations(std::ostream& ss, const C1& c1, const C& ... c)
{
    combinations_impl(ss, c1);
    // Then print the remainder
    combinations(ss, c...);
}

TEST_CASE("Variadic Combinations")
{
    auto c1 = {1, 2, 3, 4};
    auto c2 = {"Hello", "World"};
    auto c3 = {2.7, 5.4, 9.3};
    std::stringstream ss;
    combinations(ss, c1, c2, c3);
    ApprovalTests::Approvals::verify(ss.str());
}
