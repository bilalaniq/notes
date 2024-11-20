// -----------------------------------important functions------------------------------------
// this plzce is to store some important functions which are rare 

/* -------------------------------------memset----------------------------------
this is used to set initialize dynamic and static arrays
int arr[10];
memset(arr, 0, sizeof(arr));
oryou could also use
memset(arr, 0, sizeof(int)*10);
it initialize the values to 0

char arr[10]
memset(arr, 'a', sizeof(arr));
this will replace a in all the index of the array
syntex: memset(arr, 2, size of the array or size of the array type * index of array);
*/

// -------------------------------------extern-------------------------------
/*
extern keyword is used to declare a variable, 
function, or object as existing somewhere else in another translation unit (or another cpp file)
which is used in external likage
in simple words extern is the opposite of static keyword it simply says that any globlee variable or function defined in another cpp 
file will also be used in this file also  

syntax: extern int a;
*/
// if you want to learn about extern click here 
#include"extern.cpp"

//------------------------------------------override------------------
/*
override keyword is used to explicitly declare that a member function of a derived class overrides 
a virtual function declared in a base class. This is particularly useful for improving code
readability and ensuring that intended function overriding actually occurs.
example:
class Base {
public:
    virtual void foo();
};
class Derived : public Base {
public:
    void foo() override;
};
*/
//if you want to learn about virtual function click here 
#include"virtual_functions.cpp"

// ------------------------------------------auto-------------------------------
/*

*/
// --------------------------------------------constexpr--------------------------------
/*
constexpr is a keyword in C++ that indicates that a variable or function is evaluated at 
compile time. It stands for "constant expression" and is used to specify that a value or function result can 
be computed at compile time rather than at runtime.
syntax:
constexpr int size = 5; // Define a compile-time constant
*/
// --------------------------------------sizeof() and size()----------------
/*
sizeof() is an operator in C++ that returns the size in bytes of a type or an object.
It is evaluated at compile time.
it is used to find the no of bytes of any variable 
forexample:
int no;
sizeof(no);  this will give the 4 whic is the size of int

note that sizeof 
where 
size() is a member function provided by certain C++ Standard Library containers, such as std::array, std::vector, std::string, etc.
It returns the number of elements stored in the container.
It is evaluated at runtime.
Array size() C++ function works only with the arrays defined using the syntax of std::array declaration (Standard Template Library).
it does not works on raw arrays

for example:
array<int , 5 > arr = {1,1,1,1,1};
cout << arr.size();

this will return 5 
*/
//if you want to learn about arrays so click here 
#include"arrays.cpp"

// --------------------------------------mutable-----------------------------
/*
if you want to modify any the state of an class in the const member function you can do it as i have said that the const keyword is
just a promise and you can bypass or break this promise and now we will break that promise
we can do this by using a mutable keyword
private:
    int *ptr;
    mutable int no;

public:
    int getValue() const
    {
        no++;
        return no;
    };
now i can modify the state of th class using mutable keyword
by using this we can modify the specific variable in const member functions
*/
// if you want to learn more about mutable click here 
#include"mutable.cpp"
//if you want to learn about about constant/const click here
#include"const.cpp"