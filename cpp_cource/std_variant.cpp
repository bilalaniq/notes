// ---------------------------std::variant---------------------------
/*
`std::variant` is a powerful feature in C++17 that provides a type-safe union. It allows you to define a variable that 
can hold one of several different types, while maintaining strong type safety. Here’s a comprehensive overview of `std::variant`, 
including its usage, features, and examples.

### Overview

A `std::variant` can hold one of several specified types, known as alternatives. Unlike a traditional union, `std::variant` 
keeps track of which type it currently holds, which allows for safe access and type checking.

### Basic Syntax

```cpp
#include <variant>

std::variant<Type1, Type2, Type3> myVariant;
```

Here, `Type1`, `Type2`, and `Type3` are the types that `myVariant` can hold.

### Initialization

You can initialize a `std::variant` using one of its types:

```cpp
std::variant<int, double, std::string> v;
v = 42;                  // holds an int
v = 3.14;               // holds a double
v = "Hello, world!";    // holds a string
```

### Accessing Values

To access the value stored in a `std::variant`, you can use:

1. **`std::get<T>()`:** This retrieves the value of type `T`. If the variant does not currently hold `T`, it throws 
`std::bad_variant_access`.

   ```cpp
   try {
       int value = std::get<int>(v);
   } catch (const std::bad_variant_access& e) {
       // Handle the error
   }
   ```

2. **`std::get_if<T>()`:** This returns a pointer to the value of type `T` if it holds that type, or `nullptr` otherwise.

   ```cpp
   if (auto pValue = std::get_if<int>(&v)) {
       // *pValue is valid and holds the int
   }
   ```

### Visitor Pattern

`std::variant` works well with the visitor pattern via `std::visit`. This allows you to apply a function to the value 
held by the variant, regardless of its type.

```cpp
#include <iostream>
#include <variant>

std::variant<int, double, std::string> v = "Hello, world!";

std::visit([](auto&& arg) {
    std::cout << arg << '\n';
}, v);
```

### Comparison Operators

You can compare `std::variant` instances using the `==` and `!=` operators. The comparison checks both the type and the value.

```cpp
std::variant<int, double> v1 = 42;
std::variant<int, double> v2 = 42.0;

bool areEqual = (v1 == v2);  // false, different types
```

### Modifying the Value

You can assign a new value to the variant, which will change its held type:

```cpp
std::variant<int, double> v;
v = 3.14;           // holds double
v = 42;            // now holds int
```

### Type Safety and `std::monostate`

If you need a default or empty state, you can use `std::monostate`, which allows you to create a variant that has no meaningful value:

```cpp
#include <variant>

std::variant<std::monostate, int, double> v;
v = std::monostate();  // equivalent to an empty state
```

### Limitations

- **Non-copyable/Non-movable Types:** If any of the types in the variant are non-copyable or non-movable, `std::variant` 
must also handle those appropriately.
- **Overhead:** While `std::variant` adds some overhead compared to raw unions, it provides significant safety and convenience.

### Conclusion

`std::variant` is a robust tool for type-safe unions in C++. It provides clear and maintainable code while avoiding the pitfalls
of traditional unions. By leveraging features like `std::get`, `std::get_if`, and `std::visit`, you can effectively manage
multiple types in a clean and safe manner.


*/


// ---------------------------difference between union and std::variant--------------------------
/*
the only difference between the union and the variant is their size 
in case of union the size of the union is equal to the largest data type in that  union 
where in case of std::variant the its size is equal to sum of all the variables in it 
it is simply an class but works as an union 

#include<iostream>
#include<variant>

int main()
{
	union u
	{
		double x;
		int y;
	};

	std::variant<double, int > v;

	std::cout << sizeof(u) << std::endl;
	std::cout << sizeof(v) << std::endl;
}

------ans--------
8    which is equal to size of double 
16    where in this case it is equal to the sum of size of both double and int 

so due to these reason the std::variant is not able to do type punning where the union is able to becasue the union stores both variables
in the same memory where the variant stores them in an different memory 

so if you have high pc resources you should use std::variant as they use more memory if not then union is the best option 
as they use less memory 



snothere difference between the union and the std::variant is the safty when accessing the variable that is not recently assighned 
union will not give error but it will do type punning where the std::variant will throgh error

*/



//----------------------????????????????????------------
/*
int main()
{
	std::variant<double , int> v;
	v = 10;
	std::cout << std::get<int>(v);
	v = 10.1;
	std::cout << std::get<double>(v);
	return 0;
}

what if i try to access the double when i have initilize int the compiler will give an exception at runtime
int main()
{
	std::variant<double , int> v;
	v = 10;
	std::cout << std::get<int>(v);
	std::cout << std::get<double>(v);     this will trow exception
	v = 10.1;
	return 0;
}


we need to handle it with an try catch 
or you could also use the index function which return the index of the variable in the std::variant which is currently initilized
int main()
{
	std::variant<int , double> v;
	v = 10;
	std::cout << v.index() << std::endl;      // print out 0
	std::cout << std::get<int>(v) << std::endl;
	v = 10.1;
	std::cout << v.index() << std::endl;   // print out 1
	std::cout << std::get<double>(v) << std::endl;
	return 0;
}

using the index function you can varify which variable is initilized at this moment
but there is also an better option and that is by using get_if

#include <iostream>
#include <string>
#include <variant>

int main()
{
	std::variant<std::string , double> v;
	v = "bilal";
	if (auto value = std::get_if<std::string>(&v))
	{
		std::string& s = *value;
	}
	else {
		//treat as double 
	}	
	return 0;
}

*/


// ------------------------using std::variant as std::optional------------------
/*
#include <iostream>
#include <string>
#include<fstream> 
#include <variant>

enum struct ERRORcode
{
	notfound , noAccess
};

std::variant<std::string , ERRORcode> ReadfromFile(const std::string& Filepath)
{
	std::ifstream stream(Filepath);
	if (stream)
	{
		std::string result;
		//read file
		stream.close();
		return result;
	}
	else
		return ERRORcode::notfound;
}

int main()
{
	auto data = ReadfromFile("data.txt");
	
	if (auto value = std::get_if<std::string>(&data)) {
		std::cout << *value << std::endl;
	}else if(auto error = std::get_if<ERRORcode>(&data)){
		std::cout << "Error code: " << static_cast<int>(*error) << '\n';
	}
	else
		std::cout << "unexpected error!!!\n";


	return 0;
}



this is usefull when you donot what to get that the value is not present but what to know what went wrong 
*/


//you can also store multiple data types in an single variable by using std::any
#include"std_any.cpp"