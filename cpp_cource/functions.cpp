//------------------------------------functions--------------------------------
// functions are just block of code which are used to do a specific task
// later when we get to classes these functions are called methods
// the primary purpose of a function is to prevdnt code duplication and make it more readable



// int function();
// this is a function before declaring a function we need to define a return type of the function
// for example the return type of int fuction will be int and for the void function it will be nothing as void is nothing

// int function(int a , int b);
// the int a and int b specified in the bracket are called parameters which a function takes when the function is called in the  int main

/* int function(int a , int b)
{
    return a*b;
}*/
// the return a*b  return an int value to main code

// --------------------------------------why not make evey line your function------------------------
/*
we should not make every line a function because it makes the code slow
when we call a function the compiler creates a entire a stack frame for the function and push thing like
parmeters and the return address on the stack and then the compiler moves to another part of binary in order
to start executing instruction from our out function and then return the return value to the orignal place
so this jumping around the memory in order to execute functions all that takes time it slow down our code
*/

// -----------------------is uing return at the end of main function nessesary ------------------------
/*using return at the end of the main fuction depend upon the user 

the main function and only the main function is exempt from this kind of must return a value if you donot 
return any thing in the end of the main function the compiler will set return 0 to default but this is only
for main function where all the other function except for void must return something

but using return 0; at the end of the main function is recumended to make the code more readable
*/
// ------------------------------------------const functions----------------------------
/*
Declaring a member function as const indicates that the function does not modify the state of the 
object on which it is called. This is a key feature of const member functions, as it allows them 
to be called on const objects and ensures const-correctness.
meaning that When you call a const member function (such as a const getter function) on an object, the 
object is treated as const within the scope of that function call. This means that you 
cannot modify the state of the object within the const member function, regardless of whether the 
object itself is const or non-const.

example:
class MyClass {
private:
    int value;
public:
    MyClass(int v) : value(v) {}
    int getValue() const  
    {
        return value;
    }
};
int main() {
    MyClass Obj(5); 
    int value = Obj.getValue(); 
    // value = Obj.getValue();  but wheter you have created a const obj or not when you pass it to a const function the obj is treates as constant object
    return 0;
}

syntax:
int function() const  
to decalre a const function you must place const after the function but if you place the const before the function like this
const int function() 
the function return type will be const but not the function
*/
// if you want to learn about const functions and variable click here 
#include"const.cpp"

// -------------------------static function---------------------------
/*
by diclaring a function static the linker does not effect the function meaning that the static function will only be available for that 
translating unit only 

*/
/*
by clicking here you can see what is the difference between static finction/varible inside and outside a class/struct
*/
#include"static.cpp"

// -----------------------------------------------member/method function-----------------------------------------
/*
Member functions are functions that are declared within a class and operate on objects of that class
for example 

class example {
private:
    int a;
    int b;

public:
   void display()
   {
    cout << a << endl;
    cout << b << endl;
   }

int main()
{
    example obj;
    obj.display();
}
here the display() is an an member or method function;
*/

// -----------------------------------------virtual function------------------------------
// you can learn about virtual function by clicking over here 
#include"virtual_functions.cpp"