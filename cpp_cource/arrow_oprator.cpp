// -----------------------------------arrow oprator-----------------------
/*
the arrow operator (->) is used to access members of a class or structure that is referenced by a pointer. It is essentially
a shorthand notation for accessing members through a pointer.
When you have a pointer to an object, you can use the arrow operator to access members of that object directly through the pointer.
The arrow operator is used in conjunction with a pointer to an object. It dereferences the pointer and accesses the
member of the object being pointed to
The arrow operator is typically used when you have a pointer to an object and want to access members of that object without
explicitly dereferencing the pointer

*/

/*
#include<iostream>

class MyClass {
public:
    int data;
    void printData() {
        std::cout << "Data: " << data << std::endl;
    }
};

int main() {
    MyClass obj;
    obj.data = 10;

    MyClass* ptr = &obj;     //to use this pointer you first need to derefrence it and then call
    // ptr.data    error!!!      correct way is
    // (*ptr).printData();    remember that you got to first derefrence the pointer in the bracket because the . oprator has more precitence then *
    //you could store the derefrence of the pointer in an refrence like
    //  MyClass& ref = *ptr;
    //  now you cold call using this rerence like this
    // ref.printData();

    //but this takes lot of space and we have to write lot of code to over come this problem we use arrow oprator

    ptr->data = 20;
    ptr->printData();

    // it first derefrence the pointer and then call the member function or varible

    return 0;
}
*/

// -----------------------------------we can also overload the arrow operator -------------------------
// let us see an example

/*
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class MyClass {
    int data = 10;
public:
    void printData() const {
        std::cout << "Data: " << data << std::endl;
    }
};
class scopedpointer
{
 MyClass * ptr;
public:
    scopedpointer(MyClass * p) :ptr(p) { };
    ~scopedpointer()
    {
        delete ptr;
    };

    MyClass* getobj(){ return ptr; }
    MyClass* operator ->()
    {
        return ptr;
    }
    const MyClass* operator ->() const
    {
        return ptr;
    }

};



int main(){
    scopedpointer obj = new MyClass();
    //now let us create an function in scoped pointer to call the my class variables another way is to make the member variables of myclass
    //public but thats not a good slution
    // this is beacause we canot access the my class members using scoped pointer class

    // obj.getobj()->printData();

    // or i could also have used
    // MyClass* obj = new MyClass();
    // obj->printData();
    //but i want to use scoped pointer

    // but these all are very complicated and very less readable so we will provide an overloded arrow oprator
    obj->printData();    //now this is mre readdable and good code then obj.getobj()->printData();

    //if the obj is const then you should know that it can only call const functions so you should provide an seprate const defination
    //for every function also
    const scopedpointer obj2 = new MyClass();
    obj2->printData();


return 0;
}
*/

// onother place where we can use arrow oprator is to find the offset of a member variables in a class/struct
#include <iostream>
using namespace std;
struct vector3
{
    float a, b ,c;    //we are gona learn about offset in the future but for now
    //the offset of a = 0 byte , b = 4 bytes , c = 8 bytes
    // if i move the arrangement of the variables the class/struct will work same but they will then have different layout in the memory
};

int main()
{
//now we will write a code which will show the offset of the member variables in the struct i donot know what and how it work but we will
//learn in the future

   int offset_a = (int)&((vector3*)nullptr)->a;
   int offset_b = (int)&((vector3*)nullptr)->b;
   int offset_c = (int)&((vector3*)nullptr)->c;

   cout << offset_a << endl;
   cout << offset_b << endl;
   cout << offset_c << endl;

// we will learn the offset in the future it is quite advance 
    return 0;
}

// if you want to learn about offset then click here
#include "offset.cpp"