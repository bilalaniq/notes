// -------------------------------------------------constructor--------------------------------------------
// is a special member function of a class that is automatically called when an instance (object) of the class is created. 
// Its main purpose is to initialize 

// ------------------------------propertis of the constructor-------------------------
/*
>Constructors have the same name as the class they belong to.
>They do not have a return type, not even void.
>they can have parameters or not
>Constructors are implicitly called when an object is created. You don't need to explicitly call the constructor; 
it is invoked automatically.

>Like other functions, constructors can be overloaded
>if you donot create a constructor than the compiler will automatically create a default constructor
>Constructors can use initialization lists to initialize data members directly 
(note that initilization list only is valid for a constructor not for other member fuctions)
*/
// if you want to learn about initilization list click 
#include"initilization_in_structs_or_class.cpp"

// ---------------------------------types of constructor-----------------------------------
/*
there are 5 types of constructor
>Default Constructor
>Parameterized Constructor
>Copy Constructor
>Move Constructor
>Explicit Constructor
*/

// -----------------------------------------------Default constructor----------------------------------------
/*
A constructor that can be called without any arguments. It either takes no parameters
If a class does not define any constructors explicitly, the compiler automatically provides a default constructor for it.
Default constructors are useful when you want to create objects without specifying any initialization parameters 
or when you want to create arrays of objects.

example:
class example
{
    int a;
  public:
  example();
};
int main
{
    example obj;
}
here you are creating an object using a default constuctor because you are not passing any parameters
 */


// -------------------------------------------------parametrized constructor ---------------------------------------------
/*
parameterized constructor in C++ is a constructor that accepts one or more parameters. Unlike the default 
constructor, which takes no arguments, a parameterized constructor allows you to initialize the object 
with specific values provided as arguments during object creation. Parameterized constructors enable customization of 
object initialization based on user-defined parameters.
there is no parametrized constructor made by the compiler it must be defined
forexample
class example
{
    int a,b;
    public:
    example();
    example(int len, int wid);   here i have done overloading of the constructors based on the parameters
};
int main
{
example obj1;
example obj2(50,20);
}
here i am creating am creating two object obj1 and obj2 where the obj1 is created using the default constructor an the obj2
is created using the parametrized constructor

note that if you are creating a parametrized constructor it isalso compulsary to create an default constructor

*/
// -----------------------------------------------copy constructor------------------------------------------------
/*
a member function that initializes an object using another object of the same class.
a copy constructor is a special type of constructor that initializes a new object as a copy of 
an existing object. It's used to create a new object that is a duplicate of another object of the 
same class.

example:
class MyClass {
private:
    int data;
public: 
    MyClass(int val) : data(val) {}
    // Copy constructor
    MyClass(const MyClass& other) {
        data = other.data;
    }
};
int main() {
    MyClass obj1(100); 
    MyClass obj2 = obj1;
}



*/
// if you want to learn about difference between assignment oprator and copy constructor click here 
#include"copy_constructor_vs_assignment_oprator.cpp" 
// if you want to learn about deep and shalow copy click here
#include"deep_vs_shalow_copy.cpp"

// ---------------------------------------------Move Constructor---------------------------------------
// if you want to learn about move constructor click here 
#include"Move_Semantics.cpp"

// ---------------------------------------------Explicit Constructor-----------------------------------
