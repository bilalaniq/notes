// ---------------------------scoped pointer class (unique pointer)-----------------------------------
/*                                                                                                                         
it is also a unique pointer which is an example of smart pointer                                                           
it is a class that wrapps over a pointer which upon construction heap allocated the poiter and upon distruction delete the 
pointer                                                                                                                    
*/                                                                                                                         
#include<iostream>
using namespace std;
class entity
{
    int value;

public:
    entity()
    {
        cout << "constructor called\n";
    }
    ~entity()
    {
        cout << "distructor called\n";
    }
};
class scoped_pointer
{
    entity *ptr;

public:
    scoped_pointer(entity *pointer) : ptr(pointer) {}
    ~scoped_pointer()
    {
        delete ptr;
    }
};
int main()
{
    {
    scoped_pointer p1 = new entity(); //  i have made the entity object dynamically which will be made on heap and will be called when the
    }// pointer of scoped pointer is out of scope    
    return 0;
// when this pointer will be out of this block it will be automatically delte itself so it has the same working as samart pointers
}

//this has the same working as unique pointer which is a smart pointer but it is requmended to use smart pointer instead of 
// scoped pointer 