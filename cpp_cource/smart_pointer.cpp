// --------------------------------smart pointer--------------------------------------------------
/*
Smart pointers are a set of classes in C++ that provide automatic memory management. They aim to overcome some of the pitfalls of 
raw pointers, such as memory leaks and dangling pointers, by providing automatic memory deallocation when objects are no longer needed.

to use smart pointers you need to include memory headerfile   #include<memory>
new allocate memory on heap where delete deallocate memory from heap where the smart pointers are used to to automate this processs 
and are ued to automate this process meaning that when you use new you wont have to use delete delte will be automatically called
in some cases you would also wont use new
smart pointers are wrapper around raw pointers and it will call new and depending upon which pointer you use it will call delete
There are three primary types of smart pointers in C++:

--------------------------------------------------- **std::unique_ptr**:
   - `std::unique_ptr` represents exclusive ownership of a dynamically allocated object.
   - It ensures that only one `std::unique_ptr` instance can point to a given resource at a time.
   - it is an scoped poiter mean that When a `std::unique_ptr` goes out of scope or is explicitly reset, it automatically releases the memory it owns.
   - It is move-only, meaning it cannot be copied, but it can be moved to transfer ownership.

they work same as of scoped pointers if you want to learn about scoped pointers then click here
*/
#include"scoped_pointer.cpp"

/*
example:
class MyClass {
public:
    MyClass(int value) : data(value) {
        std::cout << "Constructor called. Value: " << data << std::endl;
    }
    ~MyClass() {
        std::cout << "Destructor called. Value: " << data << std::endl;
    }

    void display() const {
        std::cout << "Data: " << data << std::endl;
    }

private:
    int data;
};

int main() {
    // Create a unique_ptr to dynamically allocate a MyClass object
    std::unique_ptr<MyClass> ptr(new MyClass(42));    note that you are explicitlly calling you canot use implicitlly call a unique poiter
                                                       std::unique_ptr<MyClass> ptr  = new MyClass(42);  this will show error
    // Access the object through the unique_ptr
    ptr->display();

    return 0;
    
    }
    there is another way to do this  std::unique_ptr<MyClass> ptr(new MyClass(42));
    and it is more recomended as we donot even have to call new it is called automatically by the compiler 
    std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>(42); // Strong exception safety
    if you do not use this and an constructor throw an exception you will end up with an dangling pointer with no refrence
    and that will lead to an memory leak so it is recomended to use make_unique for exception safety
    this is  recomended due to exception saftey we will talk about it in the future

*///if you want to learn about exception safety click here
#include"exception_safety.cpp"

/*

    after this the unique poiter will be deleted as it has become out of scope
    if you have leared about scoped poiters they also work the same way but have less functionality
In C++, unique pointers (std::unique_ptr) are smart pointers that provide strict ownership semantics. They ensure that only one 
unique pointer can point to a particular object at any given time. This means that when a unique pointer is moved, the ownership 
of the underlying object is transferred to the destination unique pointer, and the source pointer becomes null.



std::unique_ptr<MyClass> ptr2 = ptr1;  // Error!
but you cannot do this because  The reason is that std::unique_ptr doesn't allow direct copying. It enforces exclusive ownership 
semantics, meaning only one std::unique_ptr can own a particular resource at a time. If you try to copy it directly, the compiler will 
generate an error. this is also because in the backend of the unique pointer code the copy constructor and assignment oprator are deleted
that is why we get a compile time error as there is no copy constructor and as well as assignment oprator
and also it does not even make eny sence if you have two uniqe pointer pointing towards one obj and when one poiter get out of scope this 
will delete the obj and leave the other poiter dangling and this will cause memory leak
so for sharing we got sharing pointer but that we will learn later

so the solution is 

std::unique_ptr<MyClass> ptr2 = std::move(ptr1);
now the ptr1 will become null pointer and the ptr2 will have the owner ship of that object

if you use the ptr1 to access this will give you an error at run time so be carefull with this


---------------------------------array with unique pointers
std::unique_ptr<MyClass[]> ptr(new MyClass[3]{
        MyClass(1), MyClass(2), MyClass(3)
    });
    or 
    prt[0] = myclass(1);   ........and so on
if you want to make the    array by using
std::unique_ptr<MyClass[]> ptr = std::make_unique<MyClass[]>(3);
but it will call default constructor for each but it is call default or parametrized constructor for all the object in the arrays

 

*/



/*

------------------------------------------------**std::shared_ptr**:
   - `std::shared_ptr` represents shared ownership of a dynamically allocated object.
   - It keeps track of the number of `std::shared_ptr` instances pointing to the same resource using reference counting.
   meaning that when there is one pointer pointing to that obj the refrence counting will be 1 and will increase on but when the refrence 
   count become 0 the object is deleted by calling delete
   - When the last `std::shared_ptr` pointing to a resource goes out of scope or is reset, the memory is deallocated.
   - `std::shared_ptr` allows multiple `std::shared_ptr` instances to share ownership of the same resource.
   - It can be copied, and each copy shares ownership of the resource.

*/
// if you want to lear about refrence counting click here 
#include"refrence_counting.cpp"
/*   
example:

class MyClass {
public:
    MyClass() {
        std::cout << "Constructor called" << std::endl;
    }
    ~MyClass() {
        std::cout << "Destructor called" << std::endl;
    }
    void doSomething() {
        std::cout << "Doing something..." << std::endl;
    }
};

int main() {
    // Creating a shared pointer to a dynamically allocated MyClass object
    std::shared_ptr<MyClass> ptr1(new MyClass());

    // Creating another shared pointer pointing to the same object
    std::shared_ptr<MyClass> ptr2 = ptr1;

    // Accessing the object through ptr2
    ptr2->doSomething();

    // The object will be automatically deleted when both ptr1 and ptr2 go out of scope

    return 0;
}

std::shared_ptr<MyClass> ptr1(new MyClass());
as i have talked about unique pointer that this way is not recumended because of exception safety but for shared pointers this has 
another reason and that reason is due to refrence counting or control block
if you want to learn about control block click here
*/
#include"control_block.cpp"
/*
because when you create an shared pointer it also allocaate another part of memory called the control block where it stores the refrence count 
and when you also use new it also allocates another object but this all happends in the back of the code  so you wont see two allocation but 
if you use 
std::shared_ptr<MyClass> ptr1 = std::shared_ptr<MyClass>();
it will be more efficient because when you use shared entity it will allocate an control block and when you want to allocate the object 
constructor using call later on so you are doing two allocation but if you use
std::shared_ptr<MyClass> ptr1 = std::shared_ptr<MyClass>();
it will allocate both control block and the object at the same time which prevent double allocton so it is more effecient to use it 
and it also get rid of the new key word it also call it automatically

lets see it by overloading the new and free oprator lets see what happends in the backend 
#include<iostream>
#include<memory>

void* operator new(size_t size)
{
    std::cout << "memory allocated  " << size << " Bytes\n";
    return malloc(size);
}

void operator delete(void* memory , size_t size)
{
    std::cout << "freed " << size << " Bytes\n";
    free(memory);
}

struct object
{
    int x, y, z;
};
int main()
{
    std::shared_ptr<object> ptr(new object());
}

what will this output 
-----------------result----------------
memory allocated  12 Bytes
memory allocated  16 Bytes
freed 12 Bytes
freed 12 Bytes     this is ide dependent some ide may do this other may not
freed 16 Bytes

what is this but i am creating only one object but thats what i have explained earliar
lets break it down 
--------memory allocated  12 Bytes
is due to the new oprator called which creates an object
--------memory allocated  16 Bytes
memory allocated on the control block
--------freed 12 Bytes 
memory freed from the object
--------freed 12 bytes
The second freed 12 Bytes might be an output from operator delete being invoked on a separate reference or from some additional cleanup.
this is ide dependent not allways
--------freed 16 Bytes
memory freed from control block


now lets see what happend when i use std::make_share what happend 

    std::shared_ptr<object> ptr = std::make_shared<object>();

---------------result----------------
memory allocated  24 Bytes
freed 24 Bytes

When you use std::make_shared<object>(), it behaves differently from manually creating a shared_ptr with new because it combines
the allocation of both the object and the control block into a single memory allocation. 

and it help increase performence
i have also done benchmarking at the end whcih shows the std::make_share is faster then normal raw shared pointers




another thing to notice that the shared pointer This issue arises because std::shared_ptr does not directly support array-like access 
using the [] operator. 

2)shared_ptr<myclass> p(new myclass[12]);

since shared_ptr "do not have deleter for arrays". in backcode so it will show error in run time
so you canot use smart pointers to point towards array 
but there are ways you can but are complex you ave to call the delete here manually when the  

std::shared_ptr<MyClass> p(new MyClass[3],[](MyClass* a){ delete[] a;});

[](MyClass* a){ delete[] a; }: This is a lambda function serving as a custom deleter. It's passed to the std::shared_ptr constructor 
as the second argument. The purpose of the custom deleter is to ensure that the dynamically allocated array is properly deallocated 
when the std::shared_ptr goes out of scope. In this case, the lambda function deletes the array using delete[].
*/
#include"lambdas.cpp"

/*

------------------------------------------------**std::weak_ptr**:
   - `std::weak_ptr` is a non-owning observer to an object managed by `std::shared_ptr`.
   - It allows you to access the object it points to as long as there is at least one `std::shared_ptr` owning it.
   - Unlike `std::shared_ptr`, `std::weak_ptr` does not contribute to the reference count of the resource it points to.
   - It is primarily used to break circular references between `std::shared_ptr` instances, preventing memory leaks.

std::shared_ptr<MyClass> shared = std::shared_ptr<MyClass>();
  std::weak_ptr<int> weak = shared;

now this will have te refrence of the shared pointer but will not increase the refrence counting which the shared pointer was
incremnting because it does not allocate the control box like the shared pointer
note if you copy a shared pointer from a shared pointer it will increase the refrence counting but when you copy shared pointer 
from a weak pointer it will not increase the weak pointer
it is usefull when you donot want to take ownership of the object
so it is important to know that the weak pointer does not keep the obj alive if the shared pointer has becoome out of scope

for example :
  std::weak_ptr<int> weak;
  {
    std::shared_ptr<MyClass> shared = std::shared_ptr<MyClass>();
    weak = shared;
  }
but if you want to use the weak pointer here you canot use it beacause the shared pointer has been out of scope
now this weak pointer will become dangling pointer







Smart pointers provide several advantages over raw pointers, including:

- Automatic memory management: They ensure that memory is deallocated when it is no longer needed, reducing the risk of memory leaks.
- Exception safety: They provide strong exception safety guarantees, ensuring that resources are properly released even in the presence of exceptions.
- Readable and maintainable code: They make ownership semantics explicit, improving code clarity and reducing the likelihood of errors.

By using smart pointers, you can write safer and more robust code while avoiding common pitfalls associated with manual memory management.


where shared pointers come with many advantages they also have there disadvantges they also cause overhed 
this is why unique pointer are more recumended because they have low overhead then shared pointers 
so unique pointer > shared pointers        in terms of prefrence
*/
// if you want to learn about overhead click here 
#include"overhead.cpp"


// --------------------------------comparison between shared and unique and weak pointer in term of performence 
//if you want to lean about benchmarking click here
#include"benchmarking(timing).cpp"
/*
here the code which compares benchmarks between shared and unique pointers

#include<iostream>
#include<chrono>
#include<memory>
#include<array>

struct timer
{
	std::chrono::time_point<std::chrono::high_resolution_clock> M_startTimepoint , Endpoint;
	timer()
	{
		M_startTimepoint = std::chrono::high_resolution_clock::now();
	}
	~timer()
	{
		stop();
	}

	void stop()
	{
		Endpoint = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(Endpoint - M_startTimepoint).count();

		double milli_s = duration * 0.001;

		std::cout << "microsec = " << duration << "  &    millisec = " << milli_s << std::endl;

	}
};

int main()
{
	struct vector
	{
		float x, y;
	};
	std::cout << "shared pointer using make_shared\n";
	{
		std::array<std::shared_ptr<vector>, 1000> sharedptr;
		timer t;
		for(int i = 0; i < sharedptr.size(); i++)
		{
			sharedptr[i] = std::make_shared<vector>();
		}
	}

	std::cout << "shared pointer with out using make_shared	\n";


	{
		std::array<std::shared_ptr<vector>, 1000> sharedptr;
		timer t;
		for (int i = 0; i < sharedptr.size(); i++)
		{
			sharedptr[i] = std::shared_ptr<vector>(new vector());
		}
	}

	std::cout << "unique pointer with make_unique\n";

	{
		std::array<std::unique_ptr<vector>, 1000> sharedptr;
		timer t;
		for (int i = 0; i < sharedptr.size(); i++)
		{
			sharedptr[i] = std::make_unique<vector>();
		}
	}

	std::cout << "unique pointer without make_unique\n";

	{
		std::array<std::unique_ptr<vector>, 1000> sharedptr;
		timer t;
		for (int i = 0; i < sharedptr.size(); i++)
		{
			sharedptr[i] = std::unique_ptr<vector>(new vector());
		}
	}
	

	

}



------------------------debug mode-----------------------
shared pointer using make_shared
microsec = 10219  &    millisec = 10.219

shared pointer with out using make_shared
microsec = 2752  &    millisec = 2.752

unique pointer with make_unique
microsec = 1465  &    millisec = 1.465

unique pointer without make_unique
microsec = 2184  &    millisec = 2.184

------------------------release mode-----------------------
shared pointer using make_shared
microsec = 185  &    millisec = 0.185

shared pointer with out using make_shared
microsec = 307  &    millisec = 0.307

unique pointer with make_unique
microsec = 106  &    millisec = 0.106

unique pointer without make_unique
microsec = 126  &    millisec = 0.126



by looking at these benchmarks you can see that the shared pointers are slower then unique pointers
and you can also see that make_unique and make_shared make the code faster instead of making the code slow 
so you should be using them 
*/













