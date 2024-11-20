// ---------------------------------------------friends.cpp------------------------------------------
/*
---------------------------------------friend fnction----------------------------------

a friend function is a function that is not a member of a class but has access to the private and protected members of the 
class if it has been declared as a friend inside that class. This allows the function to operate with the class's private and
protected  and public members as if it were a member of the class itself

we must first define/declare the function in the class as friend function and then initilize it out side the class
you can define/declare it in  private protected and public section section of the class it does not effcet the working of the function 

example:
class MyClass {
private:
    int data;
public:
    MyClass(int d) : data(d) {}
    friend void friendFunction(MyClass obj); // Declaration of friend function
};
void friendFunction(MyClass obj) {
    std::cout << "Data accessed by friend function: " << obj.data << std::endl;
}

int main() {
    MyClass obj(10);
    friendFunction(obj);
    return 0;
}


Use friend functions only when there's a clear need for non-member access to private or protected members.
Consider alternative approaches (like public member functions) whenever possible to maintain data hiding principles.




---------------------------------------friend class----------------------------------


a friend class is a class that gains special access to the private , protected and public members (data members and member functions) of 
another class. This allows for a deeper level of interaction and collaboration between the two classes, compared to using friend 
functions.
You declare a friend class within the class definition using the friend keyword followed by the name of the friend class
The friend relationship is one-directional: If class A is a friend of class B, class B does not automatically become a friend of class A.

example:

class c2;
class c1 {
private:
  int balance;
public:
  c1(int value) : balance(value) {}
  friend class c2;        //friend class
};
class c2 {
public:
};

Excessive use of friend classes can break encapsulation and make code harder to understand and maintain.
Use friend classes judiciously, only when a clear need exists for tight collaboration and direct access to private members.
Consider alternative approaches (like public member functions or helper classes)


*/
/*
------------------------------------difference between inheritence and frind class---------------------------------
                   inheritence                                              friend class
> Establishes an "is-a" relationship between classes.  *    > Creates a special association between two classes. A friend class 
A derived class inherits members and behavior          *    gains access to the private and protected members of another class, 
from a base class.                                     *    but there's no inheritance involved.               
> Derived classes inherit public and protected         *    > A friend class has access to all private, protected, and public members of the friend class. 
members from the base class. Private members are       *    > The friend relationship grants access, but there's less control over how the friend 
not inherited.                                         *    class interacts with the private members.           
>  The base class defines the interface and behavior   *    > Use friend classes for specific collaborations or helper functions that 
that derived classes must adhere to.                   *    require direct access to private members of another class, but where                                
> Use inheritance when you want one class to           *    inheritance isn't the appropriate relationship. In this scenario, the friend
"be a kind of" another class and inherit its           *    class doesn't need to create new data members; it simply interacts with the existing members of the other class.
functionality with potential specialization. In this   *
case, the derived class can have its own data members  *
specific to its purpose.                               *                         
                                                       *


*/
  