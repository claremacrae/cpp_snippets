#include <type_traits>
#include <iostream>

// Works with C++11

// In this example, SFINAE is used to select function overload
// based on the inheritance hierarchy of the argument.
// This works if function would otherwise have been void.
// This is much better than the static_assert and different
// function names in static_assert_is_base_of.cpp.

class Base
{
public:
    [[nodiscard]] int in_base() const
    {
        return 1;
    }
};

class Derived : public Base
{
public:
    [[nodiscard]] int in_derived() const
    {
        return 2;
    }
};

class DerivedFromDerived : public Derived
{
};

template<class T>
typename std::enable_if<std::is_base_of<Derived, T>::value>::type // This is the return type
function(const T& object) // ... or things inherited from Derived
{
    std::cout << object.in_derived() << '\n';
}

template<class T>
typename std::enable_if<! std::is_base_of<Derived, T>::value>::type // This is the return type
function(const T& object) // ... or things inherited from Derived
{
    std::cout << object.in_base() << '\n';
}

int main()
{
    {
        Base b;
        function(b);
    }

    {
        Derived d;
        function(d);
    }

    {
        DerivedFromDerived d;
        function(d);
    }
}


/*
 * Output:
1
2
2
 */