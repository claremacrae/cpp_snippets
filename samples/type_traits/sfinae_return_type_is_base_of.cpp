#include "catch2/catch.hpp"
#include "Approvals.h"

#include "helper_classes.h"

#include <type_traits>
#include <sstream>

// Works with C++11

// In this example, SFINAE is used to select function overload
// based on the inheritance hierarchy of the argument,
// by using std::enable_if in the return type.
// This works if function would otherwise have been void.
// This is much better than the static_assert and different
// function names in static_assert_is_base_of.cpp.

template <class T>
typename std::enable_if<
    std::is_base_of<Derived, T>::value>::type // This is the return type
function(std::ostream& ss, const T& object)   // ... or things inherited from Derived
{
    ss << object.in_derived() << '\n';
}

template <class T>
typename std::enable_if<
    !std::is_base_of<Derived, T>::value>::type // This is the return type
function(std::ostream& ss, const T& object)    // ... things not inherited from Derived
{
    ss << object.in_base() << '\n';
}

TEST_CASE("SFINAE Return Type is_base_of")
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
