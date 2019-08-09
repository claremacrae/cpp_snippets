// Code from https://youtu.be/Mzi5SHi13MM?t=105
// C++ Weekly - Ep 66 - Variadic fmin for C++11

#include <algorithm>
#include <cmath>
#include <iostream>
#include <initializer_list>

template<typename First, typename ... T>
decltype(auto) variadic_fmin(const First& f, const T& ... t)
{
    First retval = f;
    // Initializer list ends up holding all the minimum calculations along the way
    std::initializer_list<First>{(retval = std::fmin(retval, t)) ... };
    return retval;
}

int main()
{
    std::cout << variadic_fmin(-1.3f, NAN, 3.0f, -5) << '\n';
}
