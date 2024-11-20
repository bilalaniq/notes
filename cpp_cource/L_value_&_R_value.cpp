// ---------------------Lvalue & Rvalue-----------Lvalue refrence and Rvalue refrence--------------
/*
In C++, **lvalues** and **rvalues** are terms used to describe the value category of expressions.

### lvalue (Locator Value)
- An **lvalue** refers to an object that occupies some identifiable location in memory (i.e., it has an address). You can think of
 it as a value that can be assigned to.
- Examples:
  - Variables: `int x = 5;` (here, `x` is an lvalue)
  - Dereferenced pointers: `*ptr` (where `ptr` is a pointer)
  
### rvalue (Read Value)
- An **rvalue** refers to a temporary value that does not have a persistent location in memory. It usually represents a temporary
 object or a literal value.
- Examples:
  - Literals: `5`, `3.14`, `"Hello"`
  - Results of expressions: `x + 10` (the result is a temporary value)

### Summary
- **lvalues** can appear on the left-hand side or right-hand side of an assignment. They have a stable memory address.
- **rvalues** typically appear on the right-hand side of an assignment. They do not have a stable address and often represent 
temporary values.

### Usage in Functions
In C++, you can use these concepts to optimize your functions. For instance, you can overload functions based on whether they
accept lvalues or rvalues, using `&&` to specify rvalue references.

If you have specific use cases or examples you’d like to explore further, let me know!

*/



// --------------------------?????????????????????????????---------------------------
/*
Lvalues are also called locator values because they have location which we will be seing in furure 
but there are many ways to define L and R values so you should not just stick to their defination 

lets take an exmple to elaburTE THE CONCEPT OF Lvalue and Rvalue 

int main()
{
  int a = 10;      
}
here in this example the a is the Lvalue and 10 is the Rvalue 
so some people will say that the Lvalue is always at the left while the Rvalue is always at the right
but this is totally wrong but correct in this example 

Rvalue does not have an strorage where the Lvalue have this is why you canot set Rvalue equal to Lvalue like 
10 = a;   this will give error 

where you can do this 
int a = 10;
int b = a;
here you are setting Lvalue to another Lvalue


Rvalues does not have to be an literal like 10 we can return it using an funtion 

int getvalue()
{
return 10;
}
int main()
{
  int a = getvalue();
}
yes we indeed are returning an int but it has no storage that is why it is an Rvalue 

if we use 
getvalue() = 10;
this will give an error because we canot assighn any thing to Rvalue 


----------------------------Lvalue refrence-----------------------

but what if i return an Lvalue using this function this will work here have an look
int& getvalue()
{
static int a = 10;
return a;
}
int main()
{
  int a = getvalue();
  getvalue() = 10;         //this will work fine because we are returning an Lvalue 
}

the function is returning an Lvalue refrence 

lets take an example to understand Lvalue refrence 

void setvalue(int value)
{  
}
int main()
{
	int i = 10;
	setvalue(i);    here i am setting an Lvalue using another Lvalue 
	setvalue(10);   where i am setting Lvalue using an Rvalue this 
}

but what if i use int& or Lvalue refrence in the function parameters will it work 
void setvalue(int& value)
{  
}
int main()
{
	int i = 10;
	setvalue(i);
	setvalue(10);   now this will give an erorr because the Rvalue does not have any adress or storage 
}


there is very error which says that the value must be non const or const Lvalue or otherer errors related with const keyword
so what does this const mean 
int main()
{
	int& a = 10;      this will give an error saying that the it refrence to nonconst value must be an Lvalue
}

but we can also technically store Rvalue in an refrence

int main()
{
	const int& a = 10;
}  
this will work fine what does the compiler does is that it creates an temporary int there is an work oround to it 
int main()
{
  int temp = 10;     this is done in the backend you would not see this 
	const int& a = temp;
}  

so tecnically we are not storing Rvalue but instead storing the adress of Lvalue 

so by using this concept you can create an function which can support both Lvalue and Rvalue

void setvalue(const int& value)
{

}
int main()
{
	int a = 10;
	setvalue(a);
	setvalue(10);    this will work fine as i have already explained you above that an temp object is created in the backend
}

--------------------------Rvalue refrence---------------------------
lets take an exemple to elaburate the concept of Rvalue refrence 

int main()
{
	std::string F_name = "muhammad";
	std::string L_name = "bilal";
	std::string Full_name = F_name + L_name;
}
here what you see to your left side is Lvalue and on the right side is Rvalue

lets also create an function that takes the sting refrence and print it out 

void printname(std::string& name)
{
	std::cout << name << std::endl;
}

int main()
{
	std::string F_name = "muhammad";
	std::string L_name = "bilal";
	std::string Full_name = F_name + L_name;

	printname(Full_name);  this will work 
	printname(F_name + L_name);     but this will not work because this is an Rvalue
}

this is why you will see many of the function written in cpp like this 
void printname(const std::string& name)   because this makes the function compatible working with temporay objects or Rvalues
printname(F_name + L_name);   now this will work fine

but you have already learn this lets talk about Rvalue refrence 
lets write an example that only excepts Rvalues not Lvalue 

void printname(std::string&& name)       the && indicates that this is an Rvalue refrence 
{
	std::cout << name << std::endl;
}

int main()
{
	std::string F_name = "muhammad";
	std::string L_name = "bilal";
	std::string Full_name = F_name + L_name;

	printname(Full_name);     this will not work and give error that you canot pass Lavlue to Rvalue refrence 
	printname(F_name + L_name);  now this will work fine 
}

now lets us overload this function

#include <iostream>

void printname(const std::string& name)       this will also work for Rvalues because of the const if the overload does not exist 
{
	std::cout << "Lvalue " << name << std::endl;
}
void printname(std::string&& name)
{
	std::cout << "Rvalue " << name << std::endl;
}

int main()
{
	std::string F_name = "muhammad";
	std::string L_name = "bilal";
	std::string Full_name = F_name + L_name;

	printname(Full_name);
	printname(F_name + L_name);
}

now we the first function will take in Lvalues where the secound function will take in Rvalue



but you may be asking so what is there uses how can they help me in my code 
yes the main advantage of both Lvalue and Rvalue is optimization if you know that you are taking an temporary object or Rvalue 
you would not have to wory about making it stay alive or making sure we copy it or making sure we keep it intact we can simply steal 
the resource that might be attached to that specfic object and use them some where else because you know that this temporary object is only 
gonana be used onece by this paticular function
where in case of Lvalue you canot steal its resources as it may be used in other warious functions 

*/
//Rvalues and Lvalues are also used with move smentics
#include"Move_Semantics.cpp"


//L & R values are also used in std::forward click here to learn
#include"std_forward.cpp"

//to learn about std::forward you also neeed to know about universal refrence or forward refrence so alo learn that






//-------------------------------univesal refrece or(forward refrence)--------------
/*
Universal references, also known as forwarding references, are a powerful feature in C++ that allows you to write flexible and
efficient functions that can accept both lvalues and rvalues. Let’s delve into the details of universal references, their usage,
and how they work.

### Definition

A universal reference is defined in the context of a template function, specifically using the syntax `T&&` where `T` is a deduced
type. The key aspect is that it allows the function to bind to both lvalues and rvalues based on the argument passed to it.

### How They Work

1. **Type Deduction**:
   - When a template function is instantiated, the type `T` is deduced based on the value category of the argument passed:
     - If you pass an lvalue, `T` is deduced to `Type&`.
     - If you pass an rvalue, `T` is deduced to `Type`.

2. **Binding Behavior**:
   - When `T` is deduced as `Type&`, `T&&` becomes an lvalue reference. This means that the function can bind to an lvalue.
   - When `T` is deduced as `Type`, `T&&` becomes an rvalue reference. This means that the function can bind to an rvalue.

### Perfect Forwarding

The primary advantage of universal references is **perfect forwarding**. This allows you to forward arguments to other functions 
while preserving their value category. To achieve perfect forwarding, you use `std::forward<T>(obj)`.

### Example

Here’s a detailed example demonstrating universal references and perfect forwarding:

#include<iostream>
#include<utility>

struct S {};

void f(S& obj)
{
std::puts("f(S&)");
}

void f(S&& obj)
{
std::puts("f(S&&)");
}

template<typename T>
void wraper(T&& obj)        note tht this is an universal refrence not an rvalue refrence because the templetes are involved
{
    f(std::forward<T>(obj));
}

int main()
{
 S s1;
wraper(s1);       this is passing an Lvalue an will then forward to f& function
wraper(S{});      this is passing an Rvalue an will then forward to f&& function

}




### Key Points

- **Type Deduction**: Universal references rely on template type deduction to determine whether to treat the argument as an 
lvalue or an rvalue.
- **Perfect Forwarding**: The use of `std::forward` is essential for maintaining the value category of the argument.
- **Efficiency**: By avoiding unnecessary copies, universal references help improve performance in generic programming.

### Common Use Cases

1. **Generic Functions**: Universal references are often used in generic functions and algorithms that need to handle both lvalues
 and rvalues.
2. **Move Semantics**: They are also used in move constructors and move assignment operators to enable efficient resource management.
3. **Container Implementations**: Many standard library containers and algorithms make use of universal references for element 
insertion and manipulation.

### Conclusion

Universal references are a crucial part of modern C++ programming, enabling efficient and flexible code. They allow you to write
generic functions that work seamlessly with both lvalues and rvalues, making them an essential concept for anyone looking to leverage
the full power of C++.
*/





// ---------------------------rvalue refrence vs universal (forwarding) refrence ------------------------
/*
Rvalue Reference (std::string&& name): Accepts only rvalues and binds to temporary objects.
Universal Reference (T&& in a template): Can bind to both lvalues and rvalues, and its behavior depends on how the template 
argument is deduced.
Perfect Forwarding: Using std::forward<T>(name) allows you to maintain the original value category of the argument when passing 
it to another function
*/