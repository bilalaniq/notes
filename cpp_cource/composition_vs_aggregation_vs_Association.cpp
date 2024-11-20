// -----------------------------------composition vs aggregation vs Association --------------------------------
/*
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  Association
Association represents a relationship between two or more classes where objects of one class are related to objects of another class.
It's a general-purpose relationship and doesn't imply any specific ownership or lifetime management.
Associations can be one-to-one, one-to-many, or many-to-many.
In C++, association is typically implemented using member variables, pointers, or references.

example :
class Student {
private:
    Teacher* advisor; // Association with Teacher class
public:
    // Constructor, methods, etc.
};

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   Aggregation(weak relation ship)
Aggregation is a specialized form of association where objects of one class "have" or "own" objects of another class, 
but the owned objects can exist independently
The lifetime of the owned objects is not managed by the owning object
Aggregation represents a "has-a" relationship with weaker ownership semantics
In C++, aggregation is often implemented using pointers or references to objects of other classes.

example :
class Library {
private:
    std::vector<Book*> books; // Aggregation with Book class
public:
    // Constructor, methods, etc.
};




>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  Composition(strong relationship)
Composition is a stronger form of aggregation where objects of one class are composed of objects of another class, 
and the lifetime of the composed objects is managed by the owning object
The composed objects cannot exist without the owning object.
Composition represents a "whole-part" relationship with strong ownership semantics.
In C++, composition is typically implemented using member variables of other classes within the class definition.

example:
class Car {
private:
    Engine engine; // Composition with Engine class
    std::vector<Wheel> wheels; // Composition with Wheel class
public:
    // Constructor, methods, etc.
};






*/