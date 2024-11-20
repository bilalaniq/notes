// -------------------------------------------new vs malloc------------------------------- 
/*
both new and malloc are used to dynamically allocate memeory malloc was used in c but new is used in cpp
                         malloc   ( C )                                                           new ( C++)
> When you use malloc in C or C++, it returns a void* pointer,       *   > the new operator returns a pointer to the dynamically allocated memory of the 
which is a generic pointer type that can hold the address of any     *   specified type. Unlike malloc in C, which returns a void*, new returns
data type. Since malloc doesn't know what type of data you intend    *   a pointer to the type of object being allocated. This means
to store in the allocated memory, it returns a void* to indicate     *   that the type of the pointer returned by new
that the memory is untyped.                                          *   matches the type of the object being allocated.                       
When you assign this void* pointer to another pointer type           *
(such as int*, double*, etc.), you're essentially casting it to      *
the appropriate pointer type. This casting is necessary to tell      *
the compiler how to interpret the memory that malloc allocated.      *   > Allocates memory and calls constructor                                                       
                                                                     *   > Type-safe
> Allocates uninitialized memory does not call the constructor       *   > Throws std::bad_alloc on failure                                                        
> Not type-safe                                                      *   > Minimal overhead (Memory overhead)            
> Returns nullptr on failure                                         *   > Supports array allocation (new[])                         
> May require more memory due to alignment(Memory overhead)          *   > Automatic cleanup with delete                                                        
> Requires manual calculation of memory size                         *   > but by using new the distructor and constructor are called                                          
> Requires manual deallocation with free                             *   automatically by the delete                                     
> In C, memory allocated with malloc, calloc, or realloc is managed  *
manually, and there's no built-in support for constructors or        *
destructors like in C++. so distructor is not called                 *                                                  

// -----------------------????????????????????????????????????--------------------------------

Memory overhead refers to the additional memory consumed by a program beyond what is strictly required to store the program's
data and execute its instructions.

*/



/*
----------------------------------------backend of new-------------------------------------------
supose that c1 is a class and i want to create an object using new how will it work
code:
c1* ptr = new c1();
i have created an dynamic object using default constructor 
now at the backend the new will call malloc function
the malloc will take a size of how many bytes we want 
so this code is some how equvalent to
 
c1* ptr = malloc(sizeof(c1));
now one thing we are mising and that is tha the mullac only returns void pointer we have to also cast it to class c1 pointer 
i have also provided a link to casting so dont worry 

c1* ptr = (c1*)malloc(sizeof(c1));
by casting we have converte void pointer to class c1 pointer 

c1* ptr = (c1*)malloc(sizeof(c1));  this is the working of new in the backend but there is still a small difference and that is that
malloc donot call the constructor  and give us an pure allocated memory where in
c1* ptr = new c1();
new calls the constructor so you should not allocate memory using 
c1* ptr = (c1*)malloc(sizeof(c1));
instead you should use new
there are some situations in which you might do like this but still for most of the cases use new


after using we should always use delete to free the dynamically allocated memory 
delete c1;
simply it calls the free function 
free(c1);
but the difference between free and delete is that delete also calls the distructor where the free does not calls the distructor
you have to call the distructor of the class before freeing it

for example:

class MyClass {
public:
    MyClass() {
        std::cout << "Constructor called" << std::endl;
    }
    ~MyClass() {
        std::cout << "Destructor called" << std::endl;
    }
    void show() {
        std::cout << "Hello from MyClass" << std::endl;
    }
};
int main() {
    MyClass* ptr = static_cast<MyClass*>(malloc(sizeof(MyClass)));    or  MyClass* ptr = (MyClass*)(malloc(sizeof(MyClass)));
    if (ptr == nullptr) {
        std::cerr << "Memory allocation failed" << std::endl;
        return 1;
    }
    // Call constructor manually
    new(ptr) MyClass();          this has to do with placement new 
                                  this shows that melloc does not automatically call the constructor 
                                  like new so we need to manually call constructor and distructor

                                  or you could also use 
                                  void* mem = malloc(sizeof(MyClass));

                                  // Construct object using placement new
                                  MyClass* obj = new (mem) MyClass(args);     in this you would not have to use casting
                           
    // Call member function
    ptr->show();

    // Call destructor manually
    ptr->~MyClass();

    // Free allocated memory
    free(ptr);   this will not call the distructor this is why i have called the distructor before

 


-----------------------------------????????????????????????????????---------------------------
"Pure allocated memory" typically refers to memory that has been allocated dynamically (at runtime) and is 
not associated with any specific data or objects. In other words, it's memory that has been reserved for general 
use by a program but has not yet been initialized with any values or assigned to any variables.
for example:
int* ptr = new int; 
int* ptr = (int*)malloc(sizeof(int)); // dynamically allocate memory using malloc

"Pure allocated memory" becomes useful when you need to allocate memory for data structures, arrays, or objects
whose values will be determined later in the program's execution. 
*/


// if you want to learn about placement new click here 
#include"placement_new.cpp"
//if you want to learn about casting then click here
#include"casting.cpp"







// --------------------------------------------?????????????????????????????????/------------------------
/*
basically the malloc is used to Allocate raw memory it does not initillize the object by calling the construtor and the free 
does deallocate the memory but does not call the distructor 
where the new allocates the raw memory and also initilize the object by calling the constructor and the delete also deallocate and calls
the distructor 

and also remember that first of you compiler allocate memory then calls the constructor and the at the end it distruct the obj and then 
deallocate the memory




*/


