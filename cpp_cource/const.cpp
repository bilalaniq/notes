// --------------------------------------------const ---------------------------------------------
/*
const is a keyword used to declare variables as constant. Once declared as const, the value of the variable cannot be changed throughout
the program's execution.
its just simply a promise that you make that an variable cannot be modified however this is still a promise and this promise can be breaked
or bypassd wheather you kept your promise or not it depend upon the programmer
so constant is simply a fake key word which is just used to make our code readable


we can use const in many ways but here we are learning the following

-----------------------------------------------------const in variables---------------------------------
when we use const in any variables we are making the variable constant meaning that in future we canot modify the variable
forexample:
const int MAX_age = 99;
MAX_age = 10;    this is wrong we canot modify the value of MAX_age as it is declared as constant

---------------------------------------------------------Const Pointers-----------------------------------
These are pointers that cannot be reassigned to point to a different memory location after initialization.
example:
int num = 10;
int num2 = 100;
int *const ptr = &num;    if i place the const key word after the type then the pointer will act as constant but not the variable inside it 
ptr = &num2;   here this will show an error as the poiter has is not modifiableso it canot point to any other variable

another example :
int num = 10;
const int* ptr = &num;    or     int const* ptr = &num;
*ptr = 100;

now here i have placed the const keyword before int which means that when ever i changes the value using the poiter the compiler will show
error but the variable it self is not constant i can change its value directaly but not by using const pointer also the pointer can modify its address

another example :
int num = 10;
int num2 = 100;
const int* const ptr = &num;
ptr = &num2;
*ptr = 100;
now these above two lines will show error using the above two axamples

SUMMARY:
>>>  const int* ptr = &num;  this restrics the pointer from changing the value of variable to which it is pointing
>>>  int const* ptr = &num;  if you place const before * (dereference operator) it has the same meaning as the above code
>>>  int* const ptr = &num;  if you place const after * (dereference operator) it means that the poiter canot be modifiable
>>>  const int* const ptr = &num;  this code is the sum of the above two codes

-----------------------------------------Const References----------------------------------
These are references that cannot be used to modify the value of the variable they refer to.
example:
int num = 10;
int num2 = 100;
const int& ref = num;   1
ref = num2;        you canot  modifify refrence because they do not work like pointers where you are not modifying the refrence you are
jsut modifying the content of the variable to which this refrence is pointing

so  int& const x in refrence is not valid where it is valid for poiters because pointers can be modified
example:
    int a = 20;
    const int& b = a;
    b++;    this will show error because the b canot modify the value of a because it is const
-----------------------------------------Const Member Functions----------------------------
These are member functions of a class that promise not to modify the state of the object.
example:
class MyClass {
private:
    int x;
public:
    int getValue() const;    note that this is only applicable for memebr function not for orrdinarry functions
};

getvalue function does not modify the state of object(meaning that it will not change the value of x) as it is set to const
if you try to modify any thing in this cosnt member function you will get error

int getValue() const;
if we set const after the function than this mean that we are making the function constant where
const int getValue();     or int const getValue();
then this mean that we are returning an int or any type which will be set constant

another example:
class MyClass {
private:
int* ptr;
int no;
public:
   const int* const getValue() const;
};
here you can see that i have used a very scary use of const here let us decode it here the
first const shows that The integer being pointed to cannot be modified through the pointer returned by this function.
next const shows that This makes the pointer itself constant, meaning the pointer returned by this function cannot be used
to modify the memory it points to
and the last const makes the function to not modify the state of object(meaning that it will not change the value of no)


--------------------------------------------------Const Parameters-----------------------------------
These are function parameters marked as const, indicating that the function won't modify the value of the parameter.
example:
void myFunction(const int x)
{
    x++;    this will show error
};
int main(){
    int a =100;
    myFunction(a);
}

----------------------------------------------const pointer parameter------------------------
example no 1
void myFunction(const int* x)
{
    (*x)++;    you canot modify the values of the variable in the pointer
};
int main(){
    int a =100;
    myFunction(&a);
}

exaample no 2
void myFunction( int* const x)
{
    int* ptr;
    (*x)++;   here you can modify the variable contents in the poiter
    x = ptr;     but you canot modify the pointer this will show error
};
int main(){
    int a =100;
    myFunction(&a);
}

----------------------------------------------const refrence parameter------------------------
example
void myFunction( const int& x)
{
    x++;  this will show error as you canot modify the contents of variable to which the refrence is pointing
};
int main(){
    int a =100;
    myFunction(a);
}
you conot modify the refrence as you know that refrence canot be modified in any case they donot work like pointers
forexample
void myFunction( const int& x)
{
    int b = 100;
    x = b;   you are not moifying the refrence where you are jsut modifying the contents of the variable to which the refrecne is pointing
};
int main(){
    int a =100;
    myFunction(a);
}


void myFunction( const int& x)
this is not a valid syntax for refrence where it is valid for pointers


----------------------------------------------const object------------------------
class MyClass {
private:
    const int data;
public:
    MyClass(int d) : data(d) {}

    void nonConstFunction(int x) {
        std::cout << "Value of x inside non-const function: " << x << std::endl;
    }
};

int main() {
    const MyClass obj(5); 
    obj.nonConstFunction(10);    this will show error as the obj is const and it can only be passed to an const function so the solution 
    return 0;                    is to mak the nonconst function constant
}



-------------------------------------------------------------------------------------------------------------------------------------





if you want to modify any the state of an class in the const function you can do it as i have said that the const keyword is
just a promise and you can bypass or break this promise and now we will break that promise
we can do this by using a mutable keyword
private:
    int *ptr;
    mutable int no;

public:
    int getValue() const
    {
        no++;
        return no;
    };
now i can modify the state of th class using mutable keyword
by using this we can modify the specific variable in const member functions

*/
// if you eant to learn about mutable click here
#include"mutable.cpp"
//there is another way through which you can modify an const variable 
#include"casting.cpp"



//there is also another keyword which is similiar to const which is constexpr
#include"constexpr.cpp"
