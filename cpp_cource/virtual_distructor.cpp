// -------------------------------------------virtual distructor-----------------------
/*
In C++, a **virtual destructor** is a special type of destructor used in the context of inheritance. It ensures that the destructor of a
derived class is called properly when deleting an object through a pointer to a base class. Let's break this down in detail:

### Background: Destructors in C++

A destructor in C++ is a special member function of a class that is invoked when an object of that class is destroyed. 
Its primary role is to clean up resources that the object may have acquired during its lifetime. The syntax for a destructor is 
similar to that of a constructor, but with a tilde (`~`) preceding the class name:

```cpp
class Base {
public:
    ~Base() {
        // Cleanup code
    }
};
```

### The Problem with Non-Virtual Destructors

When a base class pointer points to a derived class object, deleting the object using the base class pointer will only invoke 
the base class destructor by default. If the destructor in the base class is not declared as virtual, the derived class destructor 
will not be called, which can lead to resource leaks or undefined behavior if the derived class has its own cleanup logic.

Here's an example of the problem:

```cpp
#include <iostream>

class Base {
public:
    Base() { std::cout << "Base Constructor\n"; }
    ~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived Constructor\n"; }
    ~Derived() { std::cout << "Derived Destructor\n"; }
};

int main() {
    Base* b = new Derived();
    delete b;  // Only Base Destructor is called
    return 0;
}
```

In the above example, the output will be:
```
Base Constructor
Derived Constructor
Base Destructor
```

Notice that the `Derived` destructor is not called. This is because `Base`'s destructor is not virtual.

### Virtual Destructors

To solve this problem, you declare the destructor of the base class as `virtual`. This ensures that when an object is deleted through
a base class pointer, the correct derived class destructor is invoked first, followed by the base class destructor.

Here's the corrected version:

```cpp
#include <iostream>

class Base {
public:
    Base() { std::cout << "Base Constructor\n"; }
    virtual ~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived Constructor\n"; }
    ~Derived() { std::cout << "Derived Destructor\n"; }
};

int main() {
    Base* b = new Derived();
    delete b;  // Both Derived Destructor and Base Destructor are called
    return 0;
}
```

In this version, the output will be:
```
Base Constructor
Derived Constructor
Derived Destructor
Base Destructor
```

Here, the `Derived` destructor is called first, followed by the `Base` destructor, which is the correct and expected behavior.

### Key Points about Virtual Destructors

1. **Polymorphism**: Virtual destructors are crucial when you use polymorphism (i.e., when you have a base class pointer or reference 
to a derived class object).

2. **Performance Impact**: Virtual destructors introduce a small overhead due to the mechanism of dynamic dispatch (using a vtable), but 
this is usually minimal compared to the benefit of ensuring correct destructor behavior.

3. **Virtual Destructors and Base Classes**: If a class is intended to be a base class (even if you don’t use polymorphism right away), 
it’s good practice to declare its destructor as virtual.

### Summary

In summary, a virtual destructor in C++ ensures that the correct derived class destructor is called when an object is deleted through a 
base class pointer. This is essential for preventing resource leaks and undefined behavior in polymorphic scenarios. Always declare 
destructors as virtual in base classes that are intended to be used polymorphically.

*/