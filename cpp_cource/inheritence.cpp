// --------------------------------inheritence----------------------------------
/*
the main function of inheritence in classes is to prevent duplication of code

Inheritance is a fundamental concept in object-oriented programming (OOP) that allows a class 
to inherit properties and behavior from another class. Inheritance establishes an "is-a" relationship between classes,
where a derived class (also known as a subclass or child class) inherits attributes and methods 
from a base class (also known as a superclass or parent class).

Base Class (Superclass): The class whose members are inherited by another class is called the base class or superclass.
Derived Class (Subclass): The class that inherits properties and behavior from a base class is called the derived class or subclass.

-----------------------------types of inheritence---------------------------------------
>>>>>>>>>>>>>>>>>>>>>>>>Single Inheritance: A derived class inherits from only one base class.
                                       Base Class
                                          ^
                                          |
                                       Derived Class
example:
// Base class
class Base {
};
class Derived : public Base {
};

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Multilevel Inheritance: A derived class inherits from a base class, and another 
class inherits from the derived class.
                                      Base Class
                                          ^
                                          |
                                     Derived Class 1
                                          ^
                                          |
                                     Derived Class 2
                    
class Base {
};
class Derived1 : public Base {
};
class Derived2 : public Derived1 {
};

>>>>>>>>>>>>>>>>>>>>>>>>>>>Multiple Inheritance: A derived class inherits from multiple base classes.
                               Base Class 1    Base Class 2
                                    ^             ^
                                     \           /
                                      \         /
                                       \       /
                                        \     /
                                         \   /
                                     Derived Class
example:// Base class 1
class Base1 {
};
// Base class 2
class Base2 {
};
// Derived class inheriting from both Base1 and Base2
class Derived : public Base1, public Base2 {
};
                                     

>>>>>>>>>>>>>>>>>>>>>>>>>Hierarchical Inheritance: Multiple derived classes inherit from a single base class.
                                         Base Class
                                         ^        ^
                                        /          \
                                       /            \
                                 Derived Class 1  Derived Class 2
example:
class Animal {
};
class Dog : public Animal {
};
class Cat : public Animal {
};

>>>>>>>>>>>>>>>>>>>>Hybrid (Virtual) Inheritance: Combination of multiple and multilevel inheritance, involving virtual base classes.
                                        Base Class
                                         ^       ^
                                        /         \
                             Derived class1     derived Class 2
                                        ^         ^
                                         \       /
                                      Derived Class 3

example:
class Base {
};
class Derived1 : virtual public Base {
};
class Derived2 : virtual public Base {
};
class Derived : public Derived1, public Derived2 {
};

>>>>>>>>>>>>>diamond problem 
this is a type of problem than arise when a class inherited from two or more classes that have common base class
                                        Base Class
                                         ^       ^
                                        /         \
                             Derived class1     derived Class 2
                                        ^         ^
                                         \       /
                                      Derived Class 3
so problem is that there will be two copies of base class in the derived class 3
so to overcome this problem we use the virtual keyword or virtual base class


>>>>>>>>>>>>>>>virtual base class
Virtual base class is a feature in C++ used to prevent the duplication of base class objects in a multiple 
inheritance scenario. When a class is virtually inherited, it ensures that only one instance of the base class 
is created in the entire inheritance hierarchy, regardless of how many times it's inherited. This helps to avoid 
ambiguity and save memory by ensuring that common base class components are shared among derived classes

the virtual keywords in the above example has set the base class to act as a virtual base class in derived 1 & 2


>>>>>>>>>>>>>ambiguity

Ambiguity refers to a situation in programming where there is uncertainty or confusion about which definition or 
implementation should be used. In C++, ambiguity often arises in scenarios involving multiple inheritance, function 
overloading, or name conflicts.


-----------------------------------visibility mode inheritence----------------------------
class Derived : public Base
>default visibility mode is private 

>when the visibility mode is set to public than the Public members of Base remain public in Derived and are accessible to everyone.
Protected members of Base remain protected in Derived class. Private members of Base are not accessible in Derived.

>when the visibility mode is set to private then Public and protected members of Base become private in Derived.
Private members of Base remain inaccessible in Derived.

>when the visibility mode is set to protected then the Public members of Base become protected in Derived.Protected members of 
Base become protected in Derived. Private members of Base remain inaccessible in Derived.

note that there is no  case in which private data of the base class is inherited to derived class 
*/

//When you create an object of derived class, it can be treated as both a derived object and an base object due to inheritance




// to overwrite a method function in the derived class we use virtual 
// functions click here to learn about virtual functions
#include"virtual_functions.cpp"