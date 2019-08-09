// Code from https://youtu.be/CU3VYN6xGzM?t=178
// C++ Weekly - Ep 10 Variadic Expansion Wrap-Up
// In godbolt at https://godbolt.org/z/4jIxgF

#include <iostream>

template<typename T>
void print_impl(const T& t)
{
    std::cout << t << '\n';
}

template<typename ... T>
void print(const T& ... t)
{
    (void)std::initializer_list<int>{ (print_impl(t), 0)...};
}

int main()
{
    print("Hello", 42, "World");
}
