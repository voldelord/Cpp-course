#include <iostream>
#include <string>

using namespace std;

class Base
{
    public:
        void hello();
};

class Derived : public Base
{
    public:
        void hello();
};

void Base::hello()
{
    cout << __PRETTY_FUNCTION__ << ": Hello!\n";
}

void Derived::hello()
{
    cout << __PRETTY_FUNCTION__ << ": Hello!\n";
}

void caller(Base &obj)
{
    reinterpret_cast<Derived*>(&obj)->hello();
}

int main()
{
    Derived d;
    caller(d);
}