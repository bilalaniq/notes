// -----------------------------tracking allocation-----------------------
/*
you can track the no of dynamic allocation in your code by overloading the new operator 
this can be help full when you want to see that where and how many dynamic allocation are there in your code

#include<iostream>

void* operator new(size_t size)
{ 
    std::cout << "memory allocated  " << size << " Bytes\n";  
    return malloc(size);
}

struct object
{
   int x, y, z;
};
int main()
{
  object* ptr = new object();
}

this will print out memory allocated 8 Bytes

you can also provide overloaded delete operator like 

#include<iostream>

void* operator new(size_t size)
{
    std::cout << "memory allocated  " << size << " Bytes\n";
    return malloc(size);
}

void operator delete(void* memory , size_t size)
{
    std::cout << "freed " << size << " Bytes\n";
    free(memory);
}

struct object
{
    int x, y, z;
};
int main()
{
    object* ptr = new object();

    delete ptr;
}

this will print out 
allocated 8 Bytes
freed 8 Bytes


you can also use smart pointeres they will also work same way and give you result

*/


//-----------------------------???????????????????????????????????--------------------
/*
you may be asking an question that the new oprereator return pointer which is the type of object being instenciated
but why am i returning void pointer

here the reason why

The Role of operator new:

The sole responsibility of the operator new function is to allocate raw memory.
It doesn't know about the type of the object being instantiated. All it does is allocate a block of memory and return a pointer to it.
That's why it returns a void*, which is a generic pointer type representing a block of memory without a specific type.
The new expression, however, does much more than just calling operator new.

What the new Expression Does: When you write new object():

The new expression first calls operator new, which returns a void*.
Then, the new expression casts that void* to the appropriate type (object* in this case).
Finally, it constructs the object in the allocated memory.
So, even though you're returning a void* from operator new, the new expression automatically converts this void* to the correct
pointer type (e.g., object*).



The new operator in C++ returns a typed pointer to the object being allocated, not a void*. However, this happens because 
of the way the new operator works in two distinct phases:

Memory Allocation: The operator new function allocates raw memory (and it returns a void*).
Object Construction: The new operator then constructs the object in the allocated memory and returns a pointer to the fully 
constructed object






i have also explained in the new.cpp
*/