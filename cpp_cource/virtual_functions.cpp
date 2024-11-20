// ----------------------------------virtual function-------------------------------------
/*
a virtual function is a member function of a class that is intended to be overridden (redefined)
in a derived class. Virtual functions allow for runtime polymorphism,
Virtual functions are declared by using the virtual keyword
Derived classes can override the virtual function by providing their own implementation with the same 
signature (name, parameters, and return type). This allows for customization of behavior in subclasses.


class A
{
  public:
  virtual void function()
  {cout << "hello\n"};
};
class B : public A
{
    void function() override {cout << "changed\n";};   here i have overridden or redefined the function.
}
When you create an object of type B, it can be treated as both a A object and B object due to inheritance
*/ 
//here you can see an complex example of the virtual function

#include <iostream>
class entity
{
public :
	virtual std::string getname()  //this is an virtual function 
	{
		return "hello";
	}
	entity(){}
};
class player : public entity    //player is an derived class and the entity is an base classs
{
private:
    std::string m_name;
public:
	player(const std::string& name): m_name(name){}

	std::string  getname() override     
	/*override keyword is used to explicitly declare that a member function of a derived
	 class overrides a virtual function declared in
	 a base class. This is particularly useful for improving code readability and ensuring that intended function
	 overriding actually occurs.*/
	{
		//here i have overridden the virtual function in the derived class 
		return m_name;
	}
};

void printname(entity * E)    //When you create an object of type player, it can be treated as both a player object 
// and an entity object due to inheritance. so i am treating player object as entity object
{
	std::cout << E->getname() << std::endl;
}
int main()
{
	entity* e = new entity();
	printname(e);

	player* p = new player("player1");
	printname(p);     //if i have not set the member function to virtual then the compiler would have called the member function 
  // of entity class but when i have set it to virtual than it calls the player member function which has overridden the member function of 
  // entity class  this is called dynamic binding

	std::cin.get();
	return 0;
}
// --------------------dynamic binding /is dynamic dispatch / late binding / runtime polymorphism--------------------------------------
/*
Dynamic binding, also known as late binding or runtime polymorphism, is a feature of object-oriented programming languages like C++. 
It allows the selection of which function implementation to execute at runtime, based on the actual type of the object rather 
than the declared type of the pointer or reference.
dynamic binding is achieved through the use of virtual functions. 
Dynamic binding enables flexibility and extensibility in object-oriented designs.
*/



// --------------------------------exmple with problem-------------------------------------------
/*
#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "A constructor\n";
    }
};

class B : public A {
public:
    B() {
        cout << "B Constructor\n";
    }
};

class C : public A {
public:
    C() {
        cout << "C Constructor\n";
    }
};

class D : public B, public C {
public:
    D() {
        cout << "D Constructor\n";
    }
};

int main() {
    D obj;
    return 0;
}
   now this will give 
A constructor
B Constructor
A constructor
C Constructor
D Constructor
as an out put you can see that the A constructor is called twice so the solution is also virtual to make the compiler know that to only
generate only one object of class A 

solution 

#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "A constructor\n";
    }
};

class B : virtual public A {
public:
    B() {
        cout << "B Constructor\n";
    }
};

class C : virtual public A {
public:
    C() {
        cout << "C Constructor\n";
    }
};

class D :  public B, public C {
public:
    D() {
        cout << "D Constructor\n";
    }
};

int main() {
    D obj;
    return 0;
}

now the output will be
A constructor
B Constructor
C Constructor
D Constructor


*/

// ----------------------------------------------v_table----------------------------
/*
The vtable (virtual table) is a mechanism used by compilers to implement dynamic dispatch for virtual functions
in object-oriented programming
it is created and implemented in the following order

>>>When a member function is declared as virtual in a base class, it indicates to the compiler that this function 
may be overridden in derived classes.

>>>When a class contains at least one virtual function, the compiler typically creates a hidden data member in each object of that 
class.This hidden member is commonly known as a pointer to the vtable (or vptr). This pointer points to the vtable associated with the class.

>>> The vtable is a table of function pointers. Each entry in the vtable corresponds to a virtual function declared in the class. 
The order of entries in the vtable typically matches the order in which virtual functions are declared in the class definition.

>>>The process of selecting the appropriate function implementation at runtime based on the actual type of the object being referred 
to is called dynamic binding. This is achieved through the use of vtables and allows for polymorphic behavior.

>>>When a derived class overrides a virtual function from a base class, it provides its own implementation of that 
function. This implementation is placed in the derived class's vtable, replacing the corresponding entry from the base class's vtable.

>>>Each class in a class hierarchy typically has its own vtable. Derived classes inherit the vtable pointer from their 
 base class, but they may override virtual functions and thus have their own vtable with potentially different function pointers.

 
 Without virtual tables you wouldn't be able to make runtime polymorphism work

>>
*/

// ------------------------------------------------------pure virtual functions(interface)------------------------------
/*
pure virtual function is a virtual function declared in a base class that has 
no implementation provided in the base class. Instead, it is intended to be overridden (implemented) in derived classes.
example:
virtual int  function()  = 0;   the 0 shows that it is an pure virtual function

note that the derived class should always define each purevirtual function in itself other wise the compiler will give error

---------------implimentation(it is usally in other languages but it is simplly a class)----------
implimentation being an class having an unimplimente function and acting as templete for other classes 

---------------absract class---------
A class containing one or more pure virtual functions is called an abstract class, 
it contains at least one pure virtual function  making it impossible to 
instantiate(create) objects of that class Attempting to create objects of an abstract class will result in a compilation error.
for a abstract class we should create an virtual distructor

so for an abstract class a virtual ditructor should be  made

class abstractclass
{
	virtual function() = 0;
	virtual ~abstractclass(){}  i have created an virtual distructor for an abstract class
}


A pure virtual function has no implementation in the base class. It is declared with = 0; indicating 
that it has no body and must be overridden in derived classes.
Any derived class of an abstract class must provide implementations for all pure virtual functions declared in the base 
class. If a derived class fails to provide implementations for any pure virtual function, the compiler will show error
Pure virtual functions are often used to define an interface for a class hierarchy, specifying a set of 
methods that derived classes must implement. This helps enforce consistency and polymorphism in object-oriented designs.

example:

class Animal {
public:
    virtual void makeSound() const = 0;  this is an pure virtual function we canot create an object for animal
    virtual ~Animal() {} // for a abstract class we should create an virtual distructor
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

void animalSound(const Animal& animal) {
    animal.makeSound();
}

int main() {
    Dog dog;
    Cat cat;

    animalSound(dog); // Outputs: Woof!
    animalSound(cat); // Outputs: Meow!

}
the animal class is an abstract class and it has two subclasses dog and cat
note that if there is a pur virtual function in the base class so there must be override for that function for that function
other wise the compiler will show error 


note that if there is no defination of purevirtual functions in the derived classs then the derived class will also be called abstract class
so we canot also make object of that object
*/

#include"v-table_working.cpp"


//-------------------virtual distrucor-----------------
