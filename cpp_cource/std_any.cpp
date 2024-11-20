// ------------------------------------std::any-----------------------------
/*
### `std::any` in C++

`std::any` is a feature introduced in C++17 that provides a type-safe container for storing single values of any type. It 
allows you to store any type without prior knowledge of what that type is. Here’s a detailed overview of `std::any`, including 
its features, usage, and examples.

#### Key Features

1. **Type Agnostic**:
   - `std::any` can hold any type, including user-defined types, as long as it is copyable or movable.

2. **Type Safety**:
   - Although `std::any` allows storing any type, you must explicitly retrieve the stored value using type checking and casting.

3. **Dynamic Type Checking**:
   - You can check the type stored in `std::any` at runtime, allowing you to handle different types safely.

4. **Memory Management**:
   - `std::any` manages the memory for the type it holds, handling the destruction of the stored object automatically.

5. **Performance Considerations**:
   - While `std::any` is flexible, it incurs a performance overhead due to dynamic memory allocation and type checks.

#### Basic Operations

Here’s how to work with `std::any`:

1. **Include the Header**:
   ```cpp
   #include <any>
   ```

2. **Creating and Storing Values**:
   You can construct an `std::any` object using different types.

   ```cpp
   std::any a = 42; // Storing an int            or you could also have used std::make_any(42);
   a = std::string("Hello, World!"); // Now storing a string
   ```

3. **Retrieving Values**:
   To retrieve a value, you use `std::any_cast`. If the stored type does not match the requested type, it throws `std::bad_any_cast`.

   ```cpp
   try {
       std::string str = std::any_cast<std::string>(a); // This works
   } catch (const std::bad_any_cast& e) {
       std::cerr << "Bad cast: " << e.what() << '\n';
   }
   ```

4. **Checking the Type**:
   You can check the type stored in an `std::any` object using the `type()` member function.

   ```cpp
   if (a.type() == typeid(std::string)) {
       // Safe to perform std::any_cast
   }
   ```

5. **Resetting the Value**:
   You can reset an `std::any` object, effectively removing its value.

   ```cpp
   a.reset(); // Now it holds an empty state
   ```

#### Example Usage

Here’s an example demonstrating how to use `std::any`:

```
#include <iostream>
#include <any>
#include <string>
#include <vector>

int main() {
    std::vector<std::any> values;

    // Storing different types in a vector of std::any
    values.push_back(42);                  // int
    values.push_back(std::string("Hello")); // string
    values.push_back(3.14);                // double

    for (const auto& value : values) {
        // Using std::any_cast with type checking
        if (value.type() == typeid(int)) {
            std::cout << "Integer: " << std::any_cast<int>(value) << '\n';
        } else if (value.type() == typeid(std::string)) {
            std::cout << "String: " << std::any_cast<std::string>(value) << '\n';
        } else if (value.type() == typeid(double)) {
            std::cout << "Double: " << std::any_cast<double>(value) << '\n';
        }
    }

    // Resetting an std::any
    values[0].reset(); // Clear the first element

    return 0;
}

 
```

### When to Use `std::any`

- **Flexibility**: Use `std::any` when you need to store different types in a single container without knowing those types at
 compile time.
- **Event Systems**: It's useful in event-driven programming, where different events might carry different types of data.
- **Plugin Systems**: In systems that support plugins or extensions, `std::any` can hold user-defined types dynamically.

### Limitations

- **Performance Overhead**: Due to dynamic memory allocation and type checks, `std::any` may introduce performance overhead compared 
to using statically typed alternatives.
- **No Compile-time Type Safety**: Unlike `std::variant`, which enforces type constraints at compile time, `std::any` requires runtime 
type checks, which can lead to runtime errors if misused.

### Conclusion

`std::any` is a powerful tool for scenarios requiring flexibility in type storage, providing a way to store and manage values of 
any type safely. While it has its drawbacks, such as potential performance overhead and the need for runtime type checks, it can 
be invaluable in certain contexts where type flexibility is paramount.

*/


// -----------------------------backend working of std::any and comparing it with std::variant----------------------
/*
at the first glance the std::any may look like std::variant 
we can store any type in the std::any where in case of std::variant we have to list all the possible data types it can hold
so some people may think that std::variant is worse as we need to list all the possible data types where for std::any we donot need to worry 
about them 
but here they are wrong the fact that the std::variant requires to list all the possible data types make it type safe
lets see an example 

#include<iostream>
#include<any>
#include<variant>
#include <string>

int main() {
	std::any data;
	data = 2;
	data = "cherno";
	std::string string = std::any_cast<std::string>(data);      this will throw an bad_any_cast exception 
                                                                as there is no string becase the std::any is treating "cherno" as char 
	return 0;
}

so you have to use 
	data = std::string("cherno");

lets see how std::variant can handle this situation
#include<iostream>
#include<any>
#include<variant>
#include <string>

int main() {
	std::variant<int , std::string> data;
	data = 2;
	data = "cherno";
	std::string string = std::get<std::string>(data);

	return 0;
}
here the std::variant has no problem as we have already listed all the possible data types that it can hold so it is just impilcitly
converting the char to std::string where in case of std::any it has no idea that if it should store char or 
std::string so it does not do any implicit conversion so if you want to strore std::string you need to explicitlly convert it 


the other difference between the std::variant and std::any is that how they store the data 
in case of the std::variant it stores its data in the union simply it is an type safe union
where in case of std::any it also uses union to store data but there is an difference 
if you go in the source you will see that there are two variable(not technically) 
big_storage and small_storage 
small_storage is allighned union or simply union of all the types in the types
*/
//if you want to learn about allignment union click here
#include"Aligned_union.cpp"
/*
where the big_storage is just an void pointer which is used to dynamically allocate data 
there is also another variable(any_smal_size_variable) which stores the max size for an small_storage to be if it excede the std::any will use 
bif_storage which is dynamically allocate but dynamic allocation is slow 

this size can be 32 bytes but this may be implimentation specific but for visual studio it is 32 bytes 

so this mean that if you are storing int and float or double then the it will work same as std::variant but if the size is exceded than
the small_strorage then the exceding data is stored in the big_storage which is dynamically allocated
which is slow 


#include <iostream>
#include <string>
#include<any>

class MyClass {
public:
    std::string str1;
    std::string str2;
};

int main() {
    std::any data;
    data = 10;                        //this will not be dynamically allocated
    data = MyClass();                //this will be dynamicaly allocated
    data = 
    std::cout << "Size of MyClass: " << sizeof(data) << " bytes" << std::endl;
    return 0;
}

lets see the above example which uses sta::any to store differnt types of data in vector
but what if the size the data is greate then the smal_storge so then there willl be dynamic allocation so we will use std::variant

#include <iostream>
#include <variant>
#include <string>
#include <vector>

int main() {
    // Define a variant that can hold int, std::string, or double
    using ValueType = std::variant<int, std::string, double>;
    std::vector<ValueType> values;

    // Storing different types in a vector of std::variant
    values.push_back(42);                    // int
    values.push_back(std::string("Hello"));   // string
    values.push_back(3.14);                  // double

    for (const auto& value : values) {
        // Using std::get_if for type checking and safe retrieval
        if (const auto* intPtr = std::get_if<int>(&value)) {
            std::cout << "Integer: " << *intPtr << '\n';
        } else if (const auto* strPtr = std::get_if<std::string>(&value)) {
            std::cout << "String: " << *strPtr << '\n';
        } else if (const auto* doublePtr = std::get_if<double>(&value)) {
            std::cout << "Double: " << *doublePtr << '\n';
        }
    }

    // No need to reset like std::any, just remove the element if needed
    values.erase(values.begin()); // Example of removing the first element

    return 0;
}


so it is more preffored to use std::variant instead of std::any because it is quite useless 
use std::variant insted of std::any
*/

// you can also store any kind of data in an single variable using void pointer
//if you want to learn about void pointers click here
#include"void_pointer.cpp"