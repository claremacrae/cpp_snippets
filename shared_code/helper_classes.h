class Base
{
public:
    [[nodiscard]] int in_base() const;
};

class Derived : public Base
{
public:
    [[nodiscard]] int in_derived() const;
};

class DerivedFromDerived : public Derived
{
};
