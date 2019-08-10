#include <type_traits>
#include <iostream>

// Works with C++11

// In this example, tag dispatch is used to select function overload
// based on the inheritance hierarchy of the argument,
// by using a pair of _impl functions that are selected
// based on the type of the argument.
// This works with functions that are not void. 
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
void function_impl(std::true_type, const T& object) // ... or things inherited from Derived
{
    std::cout << object.in_derived() << '\n';
}

template<class T>
void function_impl(std::false_type, const T& object) // ... or things inherited from Derived
{
    std::cout << object.in_base() << '\n';
}

template<class T>
void function(const T& object)
{
    function_impl(std::is_base_of<Derived,T>{}, object);
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