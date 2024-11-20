// --------------------------------------deep vs shalow copy  --------------------------------
/*        Shallow Copy                            *            Deep Copy
> Copies the memory addresses of the original     *  > Creates a new object and then recursively copies the contents of all dynamically
object's members to the new object.               *  allocated memory and other resources from the original object to the new object.                                
> Superficial: Only copies the top-level          *  > Comprehensive: Copies both the top-level structure and the contents of 
structure, not the contents of the dynamically    *  dynamically allocated memory
allocated memory.                                 *  > Allocates new memory for the copied object, ensuring that changes in one               
> Shares the same dynamically allocated memory    *  object do not affect the other.
between the original and the copied object.       *  > Changes in one object do not affect the other, as they have separate memory allocations.                                        
> Changes in one object affect the other since    *  > Requires a custom copy constructor or a copy assignment operator to 
they share the same memory locations.             *  ensure deep copying of dynamically allocated resources.                                  
> Typically involves invoking the default copy    *  > Requires careful management of memory allocation and deallocation 
constructor or performing member-wise assignment  *  to prevent memory leaks and dangling pointers.                                               
> May lead to issues with resource management     *
if not handled properly, such as double deletion  *
or memory corruption.                             *                     
                                                  *
                                                  *   
*/                                                 

// -----------------------------------------------Deep copy---------------------------------
/*
#include <iostream>

class DeepCopy {
private:
    int* data;

public:
    // Constructor
    DeepCopy(int value) {
        data = new int(value);
    }

    // Copy constructor (performs deep copy)
    DeepCopy(const DeepCopy& other) {
        data = new int(*other.data); // Allocate new memory and copy value
    }
  
    // Destructor
    ~DeepCopy() {
        delete data; // Free dynamically allocated memory
    }
   int add() {
        (*data)++;
    }
   
    // Getter method
    int getData() const {
        return *data;
    }
};

int main() {
    DeepCopy original(10);
    DeepCopy copy(original); // Perform deep copy
   original.add();
    std::cout << "Original data: " << original.getData() << std::endl;
    std::cout << "Copy data: " << copy.getData() << std::endl;
    

    return 0;
}


*/
//here if i increse the orignal value the copy value will not increase it will remain the same as they donot share the same 
//memory address

// -----------------------------------------------shallow copy---------------------------------
/*
#include <iostream>

class ShallowCopy
{
private:
    int *data;

public:
    // Constructor
    ShallowCopy(int value)
    {
        data = new int(value);
    }

    // Copy constructor (performs shallow copy)
    ShallowCopy(const ShallowCopy &other)
    {
        data = other.data; // Shallow copy: share the same memory
    }

    // Destructor
    ~ShallowCopy()
    {
        delete data; // Free dynamically allocated memory
    }
int add() 
    {
        (*data)++;
    }
    // Getter method
    int getData() const
    {
        return *data;
    }
};

int main()
{
    ShallowCopy original(10);
    ShallowCopy copy(original); // Perform shallow copy
    
    original.add();
    std::cout << "Original data: " << original.getData() << std::endl;
    std::cout << "Copy data: " << copy.getData() << std::endl;

    return 0;
}

*/
//here you can see that when i change the value of orignal the value of the copy also changes which shows that the both the data shares the
// same memory addres


// ----------------------------------------------????????????????????????????????????----------------------------- 
/*
note that the concept of shallow copy and deep copy is only in the dynamically allocated variables it is not applicable on the static 
variables as there is always deep copy in  the static variable but dnamically allocated variables are ristricted to both deep and shallow copy

this is because of the pointers because the dynamic variables/objects always use pointers
it is due to the address when two pointers share one address shallow copy happends and when each pointer point to seprate address then deep 
copy happends 
so whether it is dynamic variable or static it is the pointer that cause this problem so when dealing with pointer you should always 
use precausions

if you are copying any class obj which has an pointer as an member so you need to define an copy constructor or an assignment oprator
that do deep copy of the pointer
otherwize shallow copy will occur and will cause problem

*/
//by learning the string class you can learn more about copying
#include"string_class.cpp"