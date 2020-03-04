#include "catch2/catch.hpp"
#include "Approvals.h"

#include "helper_classes.h"

#include <type_traits>
#include <sstream>

// Works with C++11

// In this example, SFINAE is used to select function overload
// based on the inheritance hierarchy of the argument,
// by using std::enable_if in an unnamed, defaulted template type.
// This works with functions that are not void. 
// This is much better than the static_assert and different
// function names in static_assert_is_base_of.cpp.

// See https://stackoverflow.com/a/38215920/104370
template<
    class T,
    typename std::enable_if<std::is_base_of<Derived, T>::value, int>::type = 0>
void function(std::ostream& ss, const T& object) // ... or things inherited from Derived
{
    ss << object.in_derived() << '\n';
}

template<
    class T,
    typename std::enable_if<! std::is_base_of<Derived, T>::value, int>::type = 0>
void function(std::ostream& ss, const T& object) // ... things not inherited from Derived
{
    ss << object.in_base() << '\n';
}

TEST_CASE("SFINAE Template Type is_base_of")
{
    std::stringstream ss;
    {
        Base b;
        function(ss, b);
    }

    {
        Derived d;
        function(ss, d);
    }

    {
        DerivedFromDerived d;
        function(ss, d);
    }
    ApprovalTests::Approvals::verify(ss.str());
}
