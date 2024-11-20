// -------------------------------this-------------------------------------
/*
the this pointer is a special pointer that holds the address of the current object. It is an implicit parameter in non-static
member functions and is accessible within the scope of these functions.
Inside a member function of a class, you can use the this pointer to refer to the current object on which the member function is called.

example:
class MyClass {
private:
    int data;

public:
    void setData(int data) {
        this->data = data; // Use 'this' to access the data member
    }
};  

Even if you don't explicitly use the this pointer in member functions, it is still implicitly available and can be used 
to access members.
class MyClass {
private:
    int data;
public:
    void setData(int data) {
        data = data; // This assigns the parameter 'data' to itself, not the data member
        // To access the data member, you need to use 'this':
        this->data = data;
    }
};
in such cases this keyword is mostly used


---------------------------------back end of this--------------------------
in the back end the this works like this 
suppose e1 is the object of class example

e1* const ptr = &e1;
the const keyword show that THIS canot be poited to anyother adress then the obj calling it 

In a const member function, the this pointer is of type const MyClass*, meaning that you cannot modify the members 
of the object through this. the code will become
const e1* const ptr = &e1;
the first const shows that the obj within the poiter canot be modified
for example:
class MyClass {
public:
    void fun() const {
      *this = 20;  this will show arrow as the function is const and also the this pointer has also been made const and unmodifiable  
    }
};


*/
// if you want to learn about const and its placment click here 
#include"const.cpp"

/*
this->value the arrow symbol is called arrow oprator i could also have used (*this).value but because arrow poiter look good 
this is why i have used arrow oprator
if you want to learn about arrow oprarator then click here
*/
#include"arrow_oprator.cpp" 


// ----------------------------------------????????????????????????????????-------------------------------
/*
why you should not use delte this 
Using delete this can lead to undefined behavior and memory corruption because it deallocates the memory of the 
object while the member function is still executing. 

*/

