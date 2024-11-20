// ----------------------------------------------------static variables and function ----------------------------------------
// now we will discous static variable or function in classs/struct and out side struct/class and inside function(local static)

// --------------------static variables outside class and struct/class--------------------------
/*
when we define a static varible or function outside a class/struct we are making it private for that translation unit(cpp file)
meaning that that variable or function canot be accessed by other cpp when the two cpp files are linked togather by default all the other
variables are set public except static

and the opposite of static is extern if you whant to learn about extern keyword click here
*/
#include"extern.cpp"

//-----------------------static variables and function in struct/class--------------------------
/*
when we define a static variable inside an class or struct it has a different meaning than a struct which is deffined outside a class
so if we define a static variable inside a class we are making it common for all the object/Instance
this mean that if i change the value of a static variable using any object/Instance than it will also change the value for all the other
objects 

if we declared any static variable in a class we also need to define it.This declaration serves as a blueprint for the compiler to 
know that such a static member variable exists within the class.
for example : 
class class1
{
  public:
  static int a;
};
int class1::a;    here we are defining the static varible outsie a class
 to actually allocate storage space for the static member variable, you need to define it outside the class

by doing this  you are provideing a single storage location for the (a) variable that is shared among 
all instances/object of the Rectangle class. Without this definition, the compiler would not allocate memory for count, and
 you would encounter linker errors when trying to use it.

 we could also make function static function in a class 
 class class1
{
  public:
  static int a;
  static void call()
  {
    cout << a << endl;
  }
};
i have created an static function call() in class
note there are some rules for static function 
static functions canot directlly access the non-static variable where in the above example if i remove the static word from the variable a
then compiler will show error
this is beacause Static member functions in C++ do not have a this pointer implicitly passed to them like non-static member functions do.


Since static member functions do not operate on a specific object instance, they do not have a this pointer
associated with them. As a result, they cannot access non-static (instance) variables or methods 
directly because there is no specific object instance for them to operate on
static member functions can only directly access other static members (both variables and functions) of the 
class because they are associated with the class itself rather than with individual objects.

If you need to access non-static members within a static member function, you must either pass an 
object instance explicitly(donot know waht is this but example makes it clear) to the function
for example:
 class class1
{
  public:
  int a;
  static void call(const class1& obj)
  {
    cout << obj.a << endl;
  }
};

the static function act as a normal function which is out side the class both of them donot support this pointer

*/
//if you want to learn about this pointer then click here
#include"this.cpp"




// ------------------------------static in function (local static)-----------------------------
/*
there is another use of static keyword and that is inside an function or an member function
when you declare a static variable inside a function you are making it local to that function
the static keyword in function and class is different from each other when you diclare a static variable inside an class this mean that all 
the member functions and obj can access that variable where when we declare an static variable inside a function this mean that it is going 
to be local to that function instead of that class 

lets lean it with some coding 

void function()
{
    int i = 0;
    i++;
    cout << i << endl;
}

int main()
{
    function();
    function();
    function();
    function();
    return 0;
}

here this will print out 
1
1
1
1

but if you want to see how many times you have called the funtion you will use it like this 
    int i = 0;
 void function()
{
    i++;
    cout << i << endl;
}

but the problem with this is that you can access this variable in the main funtion if you want it not to be accesses in the main funtion 

then make the variable static so that is local for that function only and it life time extends to the end of the code execution 
 void function()
{
    static int i;      static int by default initillize from 0
    i++;
    cout << i << endl;
}
int main()
{
    function();
    function();
    function();
    function();
    return 0;
}

now the out put of theis this code will be 
1
2
3
4



this can be used to create an singleton class a singleton class is such a class which is allowed to create a single object
#include <iostream>
using namespace std;

class singliton
{
    string name;
    singliton(string NAME)
        : name(NAME)
    {
    }

public:
    static singliton &get_obj(string NAME)
    {
        static singliton instance(NAME);
        return instance;
    }
    void fun()
    {
        cout << name << endl;
    }
};
int main()
{
    singliton::get_obj("bilal").fun();
    singliton::get_obj("tree").fun();      this will be ignored as the one instance has already been created 

    return 0;
}

the out put will be 
bilal
bilal     because you canot initilize an object twice so the function will return the static object
























--------------------------------------------------------------------------------------
note that you canot use initilization list to assighn static member variables it will give an error

*/

//--------------------------?????????????????????????????-----------------------------------
/*
ther are two ways to define an singliton class 

class singliton {
private:
	static singliton s;
public:
	static singliton& get()
	{
		return s;
	}
};
singliton singliton::s;

this is one way to do it but doing like this is messy and you additionally requires to declare outside the class This is because 
static member variables are shared among all instances of the class and need to be allocated storage.

where in case of defining static member variabe in an static member function does not require an explicit definition of a 
static member variable outside the class. Instead, it creates and returns a reference to a local static variable within the function.

class singliton {

public:
	static Instrumentor& Get() {
    static Instrumentor instance;
    return instance;       
}

};

this is more readable and less messy
*/

//--------------------------------???????????????????????????????/---------------------------
/*
you may have an question that class are used to have code that is reused so why use an singliton class 
where in singliton class only creates on object 
the answer sis that it is not compulsary for us to mke it an class we can use functions to do this and wrap them in namespace 

#include <iostream>

namespace singleton {
    static const char* value = "bilal";

    static const char* get_value() {
        return value;
    }

    void display_value() {
        std::cout << get_value() << "\n";
    }
}

int main() {
    singleton::display_value(); 
    return 0;
}



but this is not recumended as the namespace has not many functionalities like classes so using classes for sinliton classes is 
an wise choice 


*/