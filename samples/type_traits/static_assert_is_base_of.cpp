#include "Catch.hpp"
#include "Approvals.h"

#include "helper_classes.h"

#include <type_traits>
#include <sstream>

// Works with C++11

// In this example, static_assert is used to force the developer to select
// the "right" template function, based on some invented notion of what is
// allowed.
// Sub-optimal, but still it was useful for understanding std::is_base_of.

template<class T>
void can_only_be_passed_derived(std::ostream& ss, const T& object) // ... or things inherited from Derived
{
    static_assert(std::is_base_of<Derived,T>(), "Derived or subclasses only, please");
    ss << object.in_derived() << '\n';
}

template<class T>
void must_not_be_passed_derived(std::ostream& ss, const T& object) // ... things not inherited from Derived
{
    static_assert(!std::is_base_of<Derived,T>(), "Derived no subclasses, please");
    ss << object.in_base() << '\n';
}

TEST_CASE("Static Assert is_base_of")
{
    std::stringstream ss;
    {
        Base b;
        must_not_be_passed_derived(ss, b);
        // can_only_be_passed_derived(b); does not compile
    }

    {
        Derived d;
        can_only_be_passed_derived(ss, d);
        // must_not_be_passed_derived(d); does not compile
    }

    {
        DerivedFromDerived d;
        can_only_be_passed_derived(ss, d);
        // must_not_be_passed_derived(d); does not compile
    }
    Approvals::verify(ss.str());
}
