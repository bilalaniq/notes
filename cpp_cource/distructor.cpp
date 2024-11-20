// --------------------------------------------------distructor----------------------------------------
/*
when ever you distroy or delete a object the distructor is called
special member function of a class that is called automatically when an object of that class goes out of scope or is explicitly deleted.
The primary purpose of a destructor is to release resources that were allocated during the object's lifetime
The destructor's name starts with (~) symbol followed by the class name.
if there is no distructor in the class the distructor is automatically craeted by the compiler
Destructors have no return type and cannot have parameters. 
Destructors typically contain cleanup code, such as releasing resources, closing files, or deallocating memory.
there is only one type of distructor and that is default distructor 
example:

class example
{
  public:
  int a;
  class(); constructor
  ~class();  distructor
};

if you have a stack bassed object the distructor will be called when the object is out of scope 
where if you have an heap based object the distructor is called when you delete the object by using delete keyword
*/
// if you want lean about heap and stack you can click this file
#include"stack_vs_heap.cpp"
//if you want to learn about virtual distructor click here
#include"virtual_distructor.cpp"