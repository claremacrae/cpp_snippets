// Code from https://youtu.be/Mzi5SHi13MM?t=105
// With fix for C++11 compilation failure: https://gcc.godbolt.org/z/HBO7IC
// C++ Weekly - Ep 66 - Variadic fmin for C++11

#include "Catch.hpp"
#include "Approvals.h"

#include <algorithm>
#include <cmath>
#include <sstream>
#include <initializer_list>

template<typename First, typename ... T>
auto variadic_fmin(const First& f, const T& ... t) -> First
{
    First retval = f;
    // Initializer list ends up holding all the minimum calculations along the way
    std::initializer_list<First>{(retval = std::fmin(retval, t)) ... };
    return retval;
}

TEST_CASE("Variadic fmin")
{
    std::stringstream ss;
    ss << variadic_fmin(-1.3f, NAN, 3.0f) << '\n';

    // Note that the type of first supplied value determines the return type.
    // So if the first value is an int, then the minimum value is comverted to int.
    ss << variadic_fmin(7, -1.3f, NAN, 3.0f) << '\n';
    Approvals::verify(ss.str());
}
