// ------------------------------std::string_view------------------------
/*
the string is slow because it allocate memory dynamically so when you have an project which works with string your code will slow down 
because there is so mauch dynamic allocation hapning 
i am not saying that dynamic allocation is bad but when dynamic allocation is not necessary then it is bad you should do static allocation

where std::string and alot of its function love to allocate

lets see an example

#include<iostream>
#include<string>


static uint32_t s_Alloc_no = 0;                      we are keping the track how how many 
void* operator new (size_t size)
{
	std::cout << "Allocation " << size << " bytes\n";      this is an overload of new operator that is used to find out how many objects 
	s_Alloc_no++;                                          are allocated dynamically
	return malloc(size);
}

void printname(const std::string& name)
{
	std::cout << name << std::endl;
}

int main()
{
	std::string name = "muhammad bilal";
	printname(name);

	std::cout << s_Alloc_no << "  Allocations\n";
	return 0;
}

this code will give you the no of allocation which has occured in the code 

------------------result
Allocation 8 bytes
muhammad bilal
1  Allocations

as you can see that the std::string name = "muhammad bilal"; has call the new oprator and allocate 8 bytes

what if donot use string and pass const char[] to an function which takes an std::string refrence will it also dynamically allocate 
and the answer is yes
	printname("muhammad bilal");



now lets see if we use substr function of will it allocate dynamic memory

    std::string name = "muhammad bilal";
	std::string first_name = name.substr(0, 8);
	std::string last_name = name.substr(9);

-----------------result
Allocation 8 bytes
Allocation 8 bytes
Allocation 8 bytes
bilal
3  Allocations


so allready with few line of code we have so many allocations what if you are creating game or any other pig project so you will get 
into a big problem

--------------------------solution-----------------
yes there is an solution to every problem by the end of it we will make it to zero allocations 
this is where string view comes in 


In C++, `std::string_view` is a lightweight, non-owning view of a string, introduced in C++17. It allows you to refer to a portion
of a string without actually copying the underlying data. This can improve performance, especially when passing strings to functions.

### Key Characteristics of `std::string_view`:

1. **Non-owning**: `std::string_view` does not manage the memory of the string it refers to. It simply points to the existing
 character data, which means it doesn't store a copy of the string.

2. **Performance**: Since it avoids unnecessary copies, it can improve performance in scenarios where large strings are passed around.

3. **Constexpr**: `std::string_view` can be used in constant expressions, which can be useful for compile-time evaluations.

4. **Flexible**: It can be constructed from `std::string`, string literals, and character arrays, providing flexibility 
when dealing with string data.

5. **Safety**: It does not automatically null-terminate the string. It maintains a size member to indicate the length of the 
view, so you need to ensure that the underlying data remains valid for the lifetime of the `std::string_view`.

### Basic Usage

Here’s how to use `std::string_view`:

```cpp
#include <iostream>
#include <string>
#include <string_view>

void printView(std::string_view sv) {
    std::cout << sv << std::endl; // Outputs the string view
}

int main() {
    std::string str = "Hello, World!";
    std::string_view sv1 = str;       // From std::string
    std::string_view sv2 = "Goodbye"; // From string literal

    printView(sv1); // Outputs: Hello, World!
    printView(sv2); // Outputs: Goodbye

    return 0;
}
```

### Important Points to Remember

1. **Lifetime**: Make sure the underlying data (e.g., `std::string` or string literal) exists as long as the `std::string_view`
 is used. If the original string goes out of scope or is modified, the `std::string_view` may point to invalid data.

2. **Immutability**: `std::string_view` is designed for read-only access. You cannot modify the contents of the string through a
 `std::string_view`.

3. **Efficiency**: Because `std::string_view` does not allocate memory or copy data, it can be very efficient in situations
 where string data is passed to functions.

4. **Compatibility**: While `std::string_view` is a convenient way to handle strings, it does not replace `std::string`. 
Instead, it's an alternative that can be used where applicable for efficiency and convenience.

### Example of Common Use Cases

Using `std::string_view` is particularly useful when writing functions that accept string data, as it allows for more flexible
 parameter types:

```cpp
void processString(std::string_view data) {
    // Process the string view...
}

// Example usage
std::string longString = "This is a long string.";
processString(longString); // Passes std::string
processString("Short string"); // Passes string literal
```

In this way, `std::string_view` helps to write cleaner and more efficient code when handling string data in C++.



what std::string_view is simply an const char pointer to an existing string plus It maintains a size member to indicate the length of the 
view
so it just makes an view to an existing memory you donot need to copy the whole string whcih prevent dynamic allocation
it is very simple to write an class with your self which can do thisbefore c++17 people used to do stuff like this



now lets use std::string_view to make the above code faster

void printname(std::string_view name)
{
	std::cout << name << std::endl;
}

int main()
{
	std::string name = "muhammad bilal";
	std::string_view first_name(name.c_str(), 8);
	std::string_view last_name(name.c_str()+9, 5);       note that the std::string_view takes an pointer an th length of the string

	printname(last_name);

	std::cout << s_Alloc_no << "  Allocations\n";
	return 0;
}

-------------result---------------------
Allocation 8 bytes
bilal
1  Allocations


here you can see that we have reached to 1 allocation instead of 3 

but we can get rid of all the allocations
because std::string name = "muhammad bilal"; is an static string there is no use of making it an std::string instead we should make it an
const char* which will prevent that one allocation 

int main()
{
	const char* name = "muhammad bilal";
	std::string_view first_name(name, 8);
	std::string_view last_name(name + 9, 5);

	printname(last_name);
	std::cout << s_Alloc_no << "  Allocations\n";
	return 0;
}

------------------result------------------
bilal
0  Allocations

0 allocations is that not just good we have went from 3 to 0

another thing if you use 

void printname(std::string_view name)
{
	std::cout << name << std::endl;
}

	printname(last_name);   in the main code 

this will also cause no allocation

*/

// -------------------------------benchmarking code with and without std::string_view----------------
/*
#include<iostream>
#include<string>
#include<string_view>
#include<chrono>

struct Set_Timer
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

	Set_Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~Set_Timer()
	{
		stop_timer();
	}
	void stop_timer()
	{
		end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		std::cout << duration.count() << " micosec" << std::endl;
	}
};

static uint32_t s_Alloc_no = 0;
void* operator new (size_t size)
{
	std::cout << "Allocation " << size << " bytes\n";
	s_Alloc_no++;
	return malloc(size);
}
#define String_view 1
#if String_view

void printname(std::string_view name)
{
	std::cout << name << std::endl;
}
#else
void printname(std::string& name)
{
	std::cout << name << std::endl;
}
#endif

int main()
{
#if String_view
	{
		Set_Timer t1;
		const char* name = "muhammad bilal";
		std::string_view first_name(name, 8);
		std::string_view last_name(name + 9, 5);
		printname(last_name);
	}
#else
	{
		Set_Timer t1;
		std::string name = "muhammad bilal";
		std::string first_name = name.substr(0, 8);
		std::string last_name = name.substr(9, 5);
		printname(last_name);
	}
#endif
	std::cout << s_Alloc_no << "  Allocations\n";
	return 0;
}

when you will read all the code you will understand it i will not explain it 
0 is when the code uses std::string where 1 is when the code does not uses std::string


now the result 
325 micosec for using std::string
308 micosec for using std::string_view 

yes at this point this may seem an very small difference but when dealing with lots of string and with large project this difference can
increase to many secounds or minutes


*/


//you may be thinking that string is allways slow but that is not the case allways compiler also do small string optimization (ssc)
//which prevent dynamic alloction if you want to learn about ssc click here
#include"small_string_optimization.cpp"