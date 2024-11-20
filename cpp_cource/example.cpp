#include <iostream>

struct MyClass {
int a,b,c;
char x;


    MyClass() { std::cout << "Constructor called\n"; }
    ~MyClass() { std::cout << "Destructor called\n"; }
};

int main() {
std::cout << sizeof(MyClass) << std::endl;
     
    alignas(16) char buffer[sizeof(MyClass)];
    MyClass* obj = new (buffer) MyClass(); // Construct MyClass in the buffer

    std::cout << sizeof(buffer) << std::endl;
    

    // Manually call the destructor
    obj->~MyClass(); // Required to clean up the object

    // operator delete(buffer); // Free the raw memory

    return 0;
}