#include <iostream>
using namespace std;


class Base
{
public:
    void (Base::*vptr[3])() = {
        &Base::function1,
        &Base::function2,
        &Base::function3};

    void function1()
    {
        cout << "Base function1()" << endl;
    }

    void function2()
    {
        cout << "Base function2()" << endl;
    }

    void function3()
    {
        cout << "Base function3()" << endl;
    }

    void callfun()
    {
       
    }
};

class Derived1 : public Base
{
public:
static void (Derived1::*vptr[3])();
    Derived1()
    {
        vptr[0] = nullptr;
        vptr[1] = nullptr;
        vptr[2] = nullptr;

        vptr[0] = &Derived1::function1;
        vptr[1] = &Derived1::function2;
        vptr[2] = &Derived1::function3;
    }

    void function1()
    {
        cout << "Derived1 function1()" << endl;
    }

    void function2()
    {
        cout << "Derived1 function2()" << endl;
    }

    void function3()
    {
        cout << "Derived1 function3()" << endl;
    }
};

void (Derived1::*Derived1::vptr[3])() = {};

int main()
{
    Base *ptr1 = new Base();
    Base *ptr2 = new Derived1();

    delete ptr1;
    delete ptr2;

    return 0;
}
