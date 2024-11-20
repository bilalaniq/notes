// ------------------------------------------stack vs heap-----------------------------------------
/*
                             stack                                 *                     heap                                      
>> Stack memory is automatically allocated and deallocated         * >> Heap memory is allocated manually by the programmer                                                        
by the compiler                                                    * using functions like (malloc, calloc, realloc, or the new) operator                                                           
                                                                   * Memory is deallocated using corresponding deallocation                                                          
                                                                   * functions (free for malloc, delete for new).                                                         
>> Variables allocated on the stack have a limited lifetime, tied  * >> Variables allocated on the heap have a dynamic lifetime.                                                           
to the scope of the function or block in which they are            * They can persist beyond the scope of the function or block                                                           
declared. Once the function exits or the block ends, the           * in which they are created, and their lifetime is determined                                                           
memory allocated on the stack is automatically  deallocated.       * by the programmer     
                                                                   *
>>Stack memory is fast because it involves simple operations       * >> Heap memory operations are slower compared to the stack                                                          
like incrementing and decrementing the stack pointer. Memory       * because they involve manual memory management. Memory                                                           
allocation and deallocation are handled efficiently by the compiler* allocation and deallocation require more complex operations.                                                         
                                                                   *                                                           
>> The size of the stack is typically limited by the system or     * >>The size of the heap is also limited by available system memory.                                                        
compiler. It's often smaller than heap memory, and exceeding       * It can dynamically grow and shrink during program execution as                                                           
its limits can lead to a stack overflow.                           * memory is allocated and deallocated.                                                    
                                                                   *                                                           
>>: Stack memory follows a Last-In, First-Out                      * >>: Heap memory allows random access to memory via                                                           
(LIFO) order. Variables are pushed onto the stack when they        * pointers. Pointers are used to access and manipulate                                                           
are declared and popped off the stack when they go out of scope.   * data stored on the heap.                                                   
                                                                   *                                                           
>> The size of the stack is determined at compile time and         * >> Heap memory can grow and shrink dynamically                                                          
is fixed. It cannot dynamically grow or shrink                     * during program execution, depending on memory allocation and                                                           
during program execution.                                          * deallocation operations.                                                          
                                                                   *                                                           
>>Variables created on the stack are called                        * >>the variables and the objects created on heap are called                                                         
stack variables or automatic variables.                            * dynamically allocated variables or dynamically allocated objects.

>>Does not contribute to memory fragmentation                      * >>Can contribute to memory fragmentation if not managed properly   
*/



//note that stack arrays require a size known at compile time, while heap arrays can be allocated dynamically with sizes
//determined at runtime. 


//Memory fragmentation occurs when a system's memory is allocated and deallocated in such a way that free memory becomes
//divided into small chunks that are too small to satisfy larger allocation requests. This phenomenon can happen in various
//memory management scenarios, including dynamic memory allocation.

//if you want to know the working of new you can click here
#include"new.cpp"
// if you alos want to learn about malloc click here 
#include"malloc.cpp"
// if you also want to learn about smart poiters as they are also related to dynamic allocation
#include"pointer.cpp"
//if you want to learn about lifetime then click here
#include"life_time.cpp"

//note that both stack and heap are located in the RAM


// --------------------???????????????????????????????----------------------------
/*
---------------------why stack is faster then heap 
the reason behind this is that due to the following reasons 

>>>>>>>>>Memory Allocation:

---------Stack: Memory allocation and deallocation on the stack are very fast because it's a simple, Last In First Out (LIFO) structure.
When a function is called, a block of memory is reserved on the stack for local variables. When the function returns, the memory
is automatically reclaimed. This push and pop mechanism is straightforward and requires minimal bookkeeping.
---------Heap: The heap is used for dynamic memory allocation (e.g., when using malloc in C or new in C++). Allocating and freeing
memory on the heap involves more complex management. The heap requires searching for a free block of memory of the appropriate size
and maintaining metadata about allocated and free blocks, which introduces overhead and can lead to fragmentation.

>>>>>>>>>>Access Speed:

---------Stack: Accessing data on the stack is generally faster because it involves simple pointer arithmetic. The stack pointer is adjusted to
allocate or deallocate memory, and access to stack variables is usually cache-friendly because stack frames are often contiguous.
---------Heap: Accessing data on the heap can be slower due to the potential for fragmentation and non-contiguous memory blocks.
Additionally, the overhead of managing free memory blocks and metadata can impact performance.

>>>>>>>>>Lifetime and Scope:

---------Stack: Variables on the stack have a well-defined scope and lifetime tied to function calls. This makes stack memory management
straightforward and fast.
---------Heap: Variables on the heap have a dynamic lifetime. They need to be explicitly managed, which adds overhead. If not managed properly,
heap memory can lead to memory leaks or fragmentation.






so in simple words allocating memory on the heap is an hole another thing where allocating memory on the stack is just one cpu instruction
i have said one cpu instruction because the memory from stack fits on one cache line of the cpu where in case of heap it fits in multiple
cache lines

if you want to learn about cache lines click here
*/
#include"cache_lines.cpp"