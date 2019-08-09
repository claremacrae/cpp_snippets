// Code from https://youtu.be/o1EvPhz6UNE?t=993
// C++ Weekly - Ep 6 Intro To Variadic Templates

#include <sstream>
#include <iostream>
#include <vector>

template<typename T>
std::string to_string_impl(const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

template <typename ... Param>
std::vector<std::string> to_string(const Param& ... param)
{
    // Using initializer list:
    return{to_string_impl(param)...};
}

int main()
{
    const auto vec = to_string("hello", 1, 5.3, "World");
    for (const auto& v : vec)
    {
        std::cout << v << '\n';
    }
}
