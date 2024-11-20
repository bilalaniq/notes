// ---------------------------------#define----------------------------

#include <iostream>
#define integer int // It allows you to give a name to a constant value or macros e.g int, string etc

/* Macros in C and C++ are pieces of code in a program that are given a name. When the program is compiled, 
all instances of that name are replaced with the code associated with it. Macros are defined using the 
#define preprocessor directive.*/
// also note that donot use (;) after a #define statement

int main()
{
    integer a = 100;
    std::cout << a << std::endl;

    return 0;
}


// if you want to learn about macros enter
#include"macros.cpp"d