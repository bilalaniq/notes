// ------------------------------------------life time----------------------------------
/*
the lifetime of an object or variable refers to the duration for which the object exists in memory, during which it can be accessed 
and used by the program. 
the life time can be controlled it can be controlled by using heap or new
the scope refers to the region of code where a particular identifier (such as a variable or a function) is valid and can be accessed
there are many types of scopes
>>>>>>>>>>>>    Global Scope: Global Scope: Variables and functions declared outside of any function or class have global scope. 
They can be accessed from anywhere in the program, including other files if properly declared with external linkage
(extern keyword). make sure not to use static keyword if you want other files to acces that variable
*/
//if you want to learn about static click here
#include"static.cpp"

/*
>>>>>>>>>>>>>>>   Namespace Scope: Namespaces provide a way to organize code into logical groups and avoid name conflicts. Variables, 
functions, and classes declared within a namespace have namespace scope and can be accessed using the namespace qualifier ::.

>>>>>>>>>>>>>>    Local Scope (Block Scope): Variables declared within a block of code (enclosed in curly braces {}) have local 
scope. They are accessible only within that block.

>>>>>>>>>>>>>>   Class Scope (Member Scope): Variables, functions, and types declared within a class have class scope. 
They are accessible to member functions of the class and can be accessed using the member access operator . or ->.

but these scopes does not effect the variable or objects created dynamically or by using new
they are beyound these scopes
*/
// if you want to learn about new click here 
#include"new.cpp"
// if you want to learn about difference between heap and stack 
#include"stack_vs_heap.cpp"
//this topic is also related to smart pointers
#include"smart_pointer.cpp"


