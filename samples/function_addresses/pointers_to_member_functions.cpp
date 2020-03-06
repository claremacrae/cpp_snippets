#include "helper_classes.h"
#include "catch2/catch.hpp"

#if __cplusplus >= 201703L
// For std::invoke
#include <functional>
#endif

// Reference: https://isocpp.org/wiki/faq/pointers-to-members

class Class
{
public:
    int memberFunction(char c, int i) const
    {
        return i;
    }

    static int staticFunction(char c, int i)
    {
        return i;
    }
};


TEST_CASE("Address of static member function compiles")
{
    // typedef int (*ClassStaticFn)(char x, int y);
    using ClassStaticFn = int (*)(char x, int y);
    ClassStaticFn staticFn = &Class::staticFunction;
    CHECK(42 == (*staticFn)('x', 42));
}

// For motivation, see https://isocpp.org/wiki/faq/pointers-to-members#macro-for-ptr-to-memfn
#define CALL_MEMBER_FN(object, ptrToMember) ((object).*(ptrToMember))

TEST_CASE("Address of const member function compiles")
{
    // For motivation, see https://isocpp.org/wiki/faq/pointers-to-members#typedef-for-ptr-to-memfn
    // typedef int (Class::*ClassMemFn)(char x, int y) const;
    using ClassMemFn = int (Class::*)(char x, int y) const;
    ClassMemFn memFn = &Class::memberFunction;

    Class c;

    // Pre C++ 17
    CHECK(42 == CALL_MEMBER_FN(c, memFn)('x', 42));

    // C++17:
#if __cplusplus >= 201703L
    CHECK(42 == std::invoke(memFn, c, 'x', 42));
#endif
}
