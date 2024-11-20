// -------------------------------------------------classes-------------------------------------
/*
In C++, a class is a user-defined data type that serves as a blueprint for creating
objects. It allows you to encapsulate data (member variables) and functions (member functions) into a single unit
*/

/*
classes are just made to make our code easy and simple there are no special fuctionality of classes other than simplifying our code

class player
{
  private:
  int a;
  public:
  int b;
  void call();

};
this is a class now we will talk about some vocabulary used in classes

>>>>>Member Variables (Data Members): Variables declared within a class
here a and b are member variables

>>>>>Member Functions (Methods): Functions declared within a class 
here void call() is a method function
(::) scope resolution operator is used to call method function or variables which are set public out side the class

>>>>Object: An instance of a class

>>>>>Constructor: A special member function of a class that is automatically called when an object is created
the constructor is named same as that of the class

>>>>distructor

*/
// --------------------------------------visibility mode in class/struct-------------------------------------
/*
there are three visibility mode in class/struct
> public:
Members declared as public are accessible from anywhere in the program.
Public members can be accessed by code outside the class through object instances.
Public members can also be accessed from within member functions of the class itself.
they are totally accessible by the derived class

>private:
Members declared as private are accessible only within the class itself.
Private members cannot be accessed directly from outside the class or by derived classes.

>protected:
Members declared as protected are accessible within the class itself and by its derived classes.
Protected members are not accessible outside the class, except by derived classes (inherited members).
they act as private but can be accessed by the derived classs
*/
// -------------------------------------------------------different between struct and class------------------------------------
/*
the struct and classes are both same thing the only difference is the visibility mode
in class and struct we can set the visibility of the function and variables to public ,private and protected 
but the difference between struct and class is that the default visibility mode of struct is private where the default visibility mode 
in struct is public  
due to the default visibility mode of class to private mode class are mostly used
*/ 

// by clicking here you you can see the ways to initilize an the member variabes of a class or struct 
#include "initilization_in_structs_or_class.cpp"

//----------------------------------if you want to restrict user from making objects(instances)----------------------
/*
there are two statages for that
>>>first you can make the constructor private 
class myclass
{
  private:
  myclass();
}
>>> secound way is that you can delete the default constructor 
class myclass
{
  private:
  public:
  myclass() = delete;
}
this will prevent user from creating objects of a class

*/
// topics related to class/struct 
#include "constructor.cpp"
#include "distructor.cpp"
//for member function
#include "functions.cpp"
// getter & setter
#include"getter_setter.cpp"
#include"inheritence.cpp"
#include"friends.cpp"