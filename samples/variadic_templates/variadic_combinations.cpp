#include <initializer_list>
#include <iostream>

// Variadic function that takes any number of containers.
// Initially, just prints container size

template<typename T>
void combinations_impl(const T& t)
{
    std::cout << t.size() << '\n';
}

// Handle the final, empty case
void combinations()
{
}

template<typename C1, typename ... C>
void combinations(const C1& c1, const C& ... c)
{
    combinations_impl(c1);
    // Then print the remainder
    combinations(c...);
}

int main()
{
    auto c1 = {1, 2, 3, 4};
    auto c2 = {"Hello", "World"};
    auto c3 = {2.7, 5.4, 9.3};
    combinations(c1, c2, c3);
}
