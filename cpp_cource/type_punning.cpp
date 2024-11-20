// ----------------------type punning (C-style casting and pointer manipulation)---------------------------
/*
Type punning in C++ refers to the practice of treating a piece of memory as if it holds a different type than it was 
originally allocated or intended for. This can be useful in low-level programming, particularly in systems programming,
serialization, or certain optimizations. However, it can also be risky and lead to undefined behavior if not used correctly.

### Key Concepts of Type Punning

1. **Type Punning Overview**:
   - Type punning involves accessing the same memory location using different types. For example, reading an `int` as a `float`.
   - This is often used to interpret binary data in different ways.

2. **Ways to Achieve Type Punning**:
   - **Union**: The most portable and well-defined method.
   - **Type Casting**: Using reinterpret_cast, static_cast, or C-style casts.    here we are only learning about c-style casting
   - **Pointer Casting**: Casting a pointer of one type to another type.


in cpp is an strongly typed language which mean that we have an type system we can not declae every thing as auto we can but it is not 
an good practice. in other languages such as python and javascrip there are no sence of varibles they dont have type system but in cpp there
is an type system. but it is not enforeced strongly like other languages such as java and  c-sharp which is hard and is strongly enforced
in cpp you can get arround the type system very eaily 
now wheather you shoulddo it or not depends upon you as it can increase performencce where on the other hand it is very risky

now let write an code
#include<iostream>

int main()
{
  int a = 50;
  double b = a;   in this line there is an implicit conversion you can also do explicit conversion like  double b = (double)a;
  std::cout << b << std::endl;
}

now if you look up in the memory the both variables will be different from each other 
32 00 00 00 cc cc for int it is 4 bytes
00 00 00 00 00 00 49 40 cc cc  for double because it is 8 bytes 
but hat if i want to have the same memory of variable a to be stored in b there are many ways to do this but this is an 
raw way(C-style casting and pointer manipulation) to do this

int main()
{
  int a = 50;
  double b = *(double*)&a;
  std::cout << b << std::endl;
}

Casting: (double*)&a casts the address of a (an int*) to a double*. This means you're telling the compiler to treat the memory address
of a as if it were pointing to a double.
Dereferencing: *(double*)&a then dereferences this double* to read the memory at that location as if it were a double.

but this will give an very weired ans
4.6284e+54
so as said the dealing with types can be risky
but i we look up in the memory both have same 
32 00 00 00 cc cc for int 
32 00 00 00 cc cc for double
that is why we have such an weired ans 
but the double is 8 bytes of memory but in this case it is 4 bytes where the rest of the 4 is uninitilized

note that this is an simple example do not do this this is very bad and might cause your application to crash
because we have taken an 4 bytes integer and converted it into 8 byte of double in this process we have converted an int pointer to an double pointer
what is it gona do is that it is also gona look past our 4 bytes of memory and also grab that memory which is not our memory for our integer
so it could cause crash and other majour problrem this code was just for demonstration not to be used in real world application


if you do not want to create an whole new variable and just want to access that int as if it was a double then use this
  double& b = *(double*)&a;
 but this is very dangerous as if i try to modify the b 
b = 0.0f;
this is gona write to 8 bytes of memory instead of 4 bytes
it will also crash the application so be very careful with it


now you have seen all the example let us have an practical example
#include <iostream>

struct entity
{
  int a , b;
};

int main() {
  entity e1 = {1 , 2};
  int* positions = (int*)&e1;

  std::cout << positions[0] << " , "  << positions[1] << std::endl;
    
}

here you can see that i have used the struct as an int array 
note that the struct oly contail 2 int variable so the size of the struct will be of 8 bytes only so we can easily use it as int array

now heres another example which shows how c++ is good at manipulating memory
suppose you want to get the b value we could have done 
 int y = e1.y;

but we are gona do it the hard way :)
  int y = *(int*)((char*)&e1 + 4);

here i have converted the entity obj into an char pointer which is one byte and then add 4 bytes to it so that we could acces the b  variable 
and then convert that char pointer back into int pointer and then derefrencing it to store that into an int 
this is just an example to show you that how powerful cpp this code has no use in practical code and of cource you could have just used 
 int y = e1.y;


heres another example of type punning 

#include <iostream>

struct entity
{
  int a, b;

  int* getposition()
  {
    return &a;
  }
};

int main() {
  entity e1 = {1, 2};
  int* positions = e1.getposition();

  std::cout << positions[0] << " , " << positions[1] << std::endl;
}

but it depend upon the user what if he writes position[2] where there is no 3 variable 
we donot have to create an array on heap and then return it we have made it easy
we also donot have copied the varibles where we could also change them by 
positions[0] = 5;


*/

//if you want to learn about casting and union click here 
#include"union.cpp"
//you can also acieve type punning through reinterpret_cast so also learn about it in the casting section
#include"casting.cpp"