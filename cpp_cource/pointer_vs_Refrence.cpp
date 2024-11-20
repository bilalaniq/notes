//-------------------------------------------refrence vs pointers ----------------------------


/* both refrence and pointers have same function but have there difference 
                    --------------pointer----------------            *                 ------------refrence------------------
                                                                     *
> Declared using * symbol before the variable name                   *  > Declared using & symbol after the variable type.
> it involves an pointer                                             *  > doe not involves any pointer
> the address of the variable is stored in the pointer               *  > where the address is not stored any where but we gave an another
                                                                     *  name or a symbol to the variable
> where the pointer  occupy additional memory to store the address   *  > do not occupy additional memory to store the address of
of the variable                                                      *   the referenced variable. Instead, they act as an alias 
> To get the variable whose adress is stored we need to first        *   for an existing object
Dereference the pointer by using (*)                                 *(an alias is another name for the same thing)
> Can be reassigned to point to different objects.                   *  > no derefrencing is required as references are aliases.
> Requires manual memory management (allocation and deallocation)    *  > Can not be reassigned to point to different objects 
> pointer can point to different objects at different times          *  > No memory management needed, automatically follows
> Commonly used to pass arguments by address.                        *  the lifetime of the referenced object.
> Possible, you can have pointers to pointers                        *  > A reference always refers to the same object throughout its lifetime.
> More flexible, useful for dynamic memory allocation                *  > Commonly used to pass arguments by reference.
and polymorphism.                                                    *  > NOTPossible, as refrence canot be pointed.
                                                                     *  > Safer, commonly used for passing function arguments and for indicating ownership
> you can create a pointer with out assigning it any address of      *  > you canot create a refrence without assigning it
a variable                                                           *  because refrence is not a real variable it is just an refrence
                                                                     *


*/
//Ensure that you're not returning a reference to a local variable or a temporary object that will be destroyed after the function returns. 
//Returning a reference to such objects can lead to undefined behavior. so here you should retur value not refrence or a pointer










#include"passby.cpp"
// by clicking this you can see the uses of poiters and refrences when passing variables to a function 
#include"return_by.cpp"
//by clicking here you can see the use of pointers refrence and returning by value from a function
//if you are loking for more complex refrence and pointers examples which include const you can click here
#include"const.cpp"