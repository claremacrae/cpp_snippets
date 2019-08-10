#include <initializer_list>
#include <iostream>

template<typename T>
void combinations_impl(const T& t)
{
    std::cout << t.size() << '\n';
}

//template <typename ... Container>
//void combinations(const Container& ... container)
//{
//    // Using initializer list:
//    {combinations_impl(container)...};
//}

template<typename C1>
void combinations(const C1& c1)
{
    combinations_impl(c1);
}

template<typename C1, typename C2>
void combinations(const C1& c1, const C2& c2)
{
    combinations_impl(c1);
    combinations(c2);
}

template<typename C1, typename C2, typename C3>
void combinations(const C1& c1, const C2& c2, const C3& c3)
{
    combinations_impl(c1);
    combinations(c2, c3);
}

int main()
{
    auto c1 = {1, 2, 3, 4};
    auto c2 = {"Hello", "World"};
    auto c3 = {2.7, 5.4, 9.3};
    combinations(c1, c2, c3);
}
