#include "helper_classes.h"

#include <type_traits>
#include <iostream>

// Works with C++17
// __cplusplus is 199711 in VS2017 and VS2019!!!
// static_assert(__cplusplus >= 201703L, "Compile with C++17 or newer, please");

template<typename Class>
void print_based_on_type(const Class& object)
{
    std::cout << std::boolalpha;
    std::cout << "is Derived, or derived from Derived: " << std::is_base_of<Derived, Class>::value << '\n';
    // https://stackoverflow.com/questions/32899259/does-c-11-support-template-class-reflection
    // https://cmake.org/cmake/help/latest/manual/cmake-compile-features.7.html#manual:cmake-compile-features(7)
    // warning: 'if constexpr' only available with -std=c++1z or -std=gnu++1z
    if constexpr ( std::is_base_of<Derived, Class>::value )
    {
        std::cout << object.in_derived() << '\n';
    }
    else
    {
        std::cout << object.in_base() << '\n';
    }
}

int main()
{
    std::cout << "__cplusplus: " << __cplusplus << '\n';
    {
        Base b;
        print_based_on_type(b);
    }

    {
        Derived d;
        print_based_on_type(d);
    }

}