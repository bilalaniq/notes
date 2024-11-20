// -------------------------------pointers----------------------------------
/* pointers : Pointers are variables that store memory addresses. Instead of directly storing values,
 pointers store the address of where a value is stored in memory.

there are two types of pointers: 
> RAW pointer
> SMART pointer


size of memory address in different systems
the size of a pointer typically depends on the architecture of the system
>32 bit-system : the size of the memory address is 4 byte or 32 bits
>64 bit-system : In a 64-bit system, memory addresses are typically 64 bits or 8 bytes long

The size of a memory address is crucial because it determines the maximum amount of memory that can be accessed by 
the system. Systems with larger memory address sizes can address more memory, 
which is beneficial for tasks that require large amounts of memory, such as scientific computing, databases, and virtualization.
*/




// -----------------------------------------RAW pointer--------------------------------
/*
we can set pointer by 
void* ptr;     
where void is the type of the pointer but it does not matter we can use int string or any thing but it would not matter as ptr is just
storing memory address noting more .the size of the variable does not matter to the pointer
but compiler will show error as it want every thing to be simple straight 

void*ptr = 8;
this is wrong as the pointer cannot store any value it only store memory address

int a = 8;
void* ptr = &a;
now it will store the memory adress of a
where & is called an ampersand oprator it function is to ask the varable its memory adress

but we will not use void as when we are changing the value of the variable stored in the pointer we need to specify the type of the pointer 
so to store int we will use int pointer
int* ptr = &a;
*ptr = 10;
if i had used the void the compiler would have showed error because the compiler does not know what is the size of the void in which it 
is storing an 4 bytes of int
*ptr is called derefrencing

int a = 10;
int *ptr = &a;
int **ptr1 = &ptr;
the ptr1 will store the adress of pointer ptr which will eventually point towards  variable a
we can print the value of a by dereferencing the ptr1 twice as demonstrated
cout <<  **ptr1 << endl;
this will print out te value of a;

*/

// -----------------------------------------SMART pointer--------------------------------
// if you want to learn about samrt pointer click here 
#include"smart_pointer.cpp"

//---------------------------------------------this pointer-------------------------------
//there is another type of poiter called this poiter 
//if you want to learn about this poiter click here

#include"this.cpp"

#include"pointer_vs_Refrence.cpp" 
//by clicking here you can see the difference between a pointer and a refrence


#include"Pointer_arithmatic.cpp"
// here you can learn about Pointer arithmetic

// --------------------------------function pointer--------------------------- 
//if ypu want to learn about funtion pointer click here
#include"function_pointer.cpp"