#include "helper_classes.h"

#include <type_traits>
#include <iostream>

// Works with C++11

// In this example, static_assert is used to force the developer to select
// the "right" template function, based on some invented notion of what is
// allowed.
// Sub-optimal, but still it was useful for understanding std::is_base_of.

template<class T>
void can_only_be_passed_derived(const T& object) // ... or things inherited from Derived
{
    static_assert(std::is_base_of<Derived,T>(), "Derived or subclasses only, please");
    std::cout << object.in_derived() << '\n';
}

template<class T>
void must_not_be_passed_derived(const T& object) // ... or things inherited from Derived
{
    static_assert(!std::is_base_of<Derived,T>(), "Derived no subclasses, please");
    std::cout << object.in_base() << '\n';
}

int main()
{
    {
        Base b;
        must_not_be_passed_derived(b);
        // can_only_be_passed_derived(b); does not compile
    }

    {
        Derived d;
        can_only_be_passed_derived(d);
        // must_not_be_passed_derived(d); does not compile
    }

    {
        DerivedFromDerived d;
        can_only_be_passed_derived(d);
        // must_not_be_passed_derived(d); does not compile
    }
}


/*
 * Output:
1
2
2
 */