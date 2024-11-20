// ---------------------------------enums-----------------------------------
// enum is short for enumeration
// enum (enumeration) is a user-defined data type used to define a set of named integer constants. Enums provide a
// way to create symbolic names for integral values, making the code more readable and maintainable


#include <iostream>
using namespace std;
enum example
{
    A,
    B,
    C
};

int main()
{
    int value = A;   

    if (A == 0)     
    {
        cout << A << endl;
    }

    return 0;
}
/* here the default value of the enum starts from 0 and so on
but we can also specify the value
enum example
{
    A = 3,
    B,
    C
};
now here i have specified the value of A to 3 so the value of B will become 4 and so on
*/
/*
we could also specify the type of enum by default the enums are set to integers
enum example : unsigned char
{
    A,
    B,
    C
};
can be useful in scenarios where memory optimization is crucial, especially when
the range of values needed for the enum is relatively small. by default the enums are 32-bit 
note we canot use float and double non int data types
This is because enums are intended to represent discrete values, and floating-point numbers are continuous values. Using
a floating-point type for an enum would not align with the typical use case of
enums and could lead to unexpected behavior or confusion.
*/

/*
enum can also be scoped
When an enum is scoped, it means that the enumerators (the individual values within the enum) are part of a distinct
scope, and you must refer to them using the scope resolution operator (::).
enum class Status {
    OK,     // Enumerators OK and ERROR are scoped within the enum class Status
    ERROR
};

*/

/*
enum canot be modified
enum example
{
    A,
    B,
    C
};
int main()
{
    example variable = A;
}

if i use int instead of example then the int variable will not be constant we can modify its value lateron
so we use the name of enum to make a variable

forexample:
enum example
{
    A,
    B,
    C
};

int main()
{
    int variable = A;
    variable = 100;
    this will not show error
    
    example variable = A;
    variable = 100;
    this will show error as the variable canot be modiffied

we can also compare enums
}

*/
