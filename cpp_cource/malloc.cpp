// ----------------------------------------malloc  calloc, or realloc------------------------------------
/*
In C++, malloc is not a part of the standard C++ library. It's actually a function from the C standard library (<cstdlib>) 
used for dynamic memory allocation.
malloc dynamically allocates a block of memory of the specified size (in bytes). It returns a pointer to the beginning of
the allocated memory block. If the allocation fails, it returns a void pointer.

example:
int *ptr = (int *)malloc(10 * sizeof(int));
This line allocates memory for an array of 10 integers and assigns the pointer to ptr.

Check for Null: Always check if the memory allocation was successful
if (ptr == nullptr) {
    // Allocation failed
}
Once memory is allocated, you can use it like any other dynamically allocated memory.

After you're done using the allocated memory, it's important to free it using the free function
free(ptr);

However, in modern C++, it's more common and recommended to use new and delete operators or smart pointers like std::unique_ptr 
or std::shared_ptr for dynamic memory allocation and deallocation. These methods are safer and more flexible than using malloc 
and free, as they automatically manage the memory and ensure proper cleanup, reducing the risk of memory leaks and other issues.


example:
int *ptr = (int*)malloc(sizeof(int));
if (ptr == nullptr) {
    // Allocation failed
} else {
    // Use the allocated memory
    *ptr = 42; // Assigning a value to the allocated memory
}

*/
//if you want to learn about new click here
// #include"new.cpp"
//if you want to learn more about malloc and its difference with new you can click here
#include"new_vs_malloc.cpp"

//these are the links to artical which go indepth of how malloc works
// https://gee.cs.oswego.edu/dl/html/malloc.html
// https://people.freebsd.org/~jasone/jemalloc/bsdcan2006/jemalloc.pdf