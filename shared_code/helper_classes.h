class Base
{
public:
    int in_base() const;
};

class Derived : public Base
{
public:
    int in_derived() const;
};

class DerivedFromDerived : public Derived
{
};
