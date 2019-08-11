#include "Catch.hpp"
#include "Approvals.h"

#include "helper_classes.h"

#include <type_traits>
#include <sstream>

// Works with C++11

// In this example, tag dispatch is used to select function overload
// based on the inheritance hierarchy of the argument,
// by using a pair of _impl functions that are selected
// based on the type of the argument.
// This works with functions that are not void. 
// This is much better than the static_assert and different
// function names in static_assert_is_base_of.cpp.

template<class T>
void function_impl(std::ostream& ss, std::true_type, const T& object) // ... or things inherited from Derived
{
    ss << object.in_derived() << '\n';
}

template<class T>
void function_impl(std::ostream& ss, std::false_type, const T& object) // ... things not inherited from Derived
{
    ss << object.in_base() << '\n';
}

template<class T>
void function(std::ostream& ss, const T& object)
{
    function_impl(ss, std::is_base_of<Derived,T>{}, object);
}

TEST_CASE("Tag Dispatch is_base_of")
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
    Approvals::verify(ss.str());
}
