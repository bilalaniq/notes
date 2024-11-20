// -----------------------------------passby--------------------------------------

/*
there are mainly three ways through which you can pass a value to a function 
there are other ways but are simply derived from these three
    
---------------------------------passby value---------------------------
Pass by value is a parameter passing mechanism  where a copy of the actual 
value of a variable is passed to a function. This means that the function operates on a local
copy of the variable's value, and any modifications made to the parameter inside the function do not affect the original variable.
example:
void fun(int a);
int b;
fun(b);

where we are passing by value the value of a is passed to b note that if we make any changes to the a variable in the unction this will 
not effect the b variable at all 


-----------------------------------passby pointer /passby pointer-----------------
: Pass by addres refers to the method of passing the memory address (or the location in memory) of a 
variable to a function. This can be achieved using various techniques, including passing pointers or 
references that hold the memory address.
example
void fun(int *a);
int b;
fun(&b);
here i am storing the adress of b variable in poiter a

another way is 
void fun(int *a);
int b;
int * ptr = &b;
fun(ptr);
now i  am first storing the address of b variable in a poiter ptr and then i am passing the poiter to the function

--------------------------------passby refrence----------------------------------
Pass by reference is a parameter passing mechanism in programming languages where instead of passing the actual 
value of a variable to a function, you pass a reference or a memory address of the variable. This allows the 
function to directly access and modify the original variable's value.
example:
void fun(int &a);
int b;
fun(b);

here a is just a refrence to variable b




both the passby refrence and poiter are also called passby address as we are passing the address of the variable to the function
*/


//if you want to learn about return by then click here
#include"return_by.cpp"