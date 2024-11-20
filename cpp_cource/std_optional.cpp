// ------------------------------------std::optional---------------------
/*
`std::optional` is a feature introduced in C++17 that provides a way to represent optional (or nullable) values. 
It can be particularly useful when you want to indicate that a variable might not have a value, instead of using pointers 
or special sentinel values.

### Basic Usage

Here's a quick rundown on how to use `std::optional`:

1. **Include the Header:**
   You need to include the header file that contains `std::optional`.

   ```cpp
   #include <optional>
   ```

2. **Declaring an Optional:**
   You can declare an `std::optional` like this:

   ```cpp
   std::optional<int> optInt; // Initially empty (no value)
   ```

3. **Assigning a Value:**
   You can assign a value to an `optional`:

   ```cpp
   optInt = 42; // Now contains a value
   ```

4. **Checking if it has a Value:**
   You can check if it contains a value using `has_value()` or the implicit conversion to `bool`:

   ```cpp
   if (optInt.has_value()) {                             or you could simply use if(optInt) this will also work
       // Safe to access optInt.value()
       std::cout << *optInt << std::endl; // Dereferencing the optional
   }
   ```

5. **Accessing the Value:**
   You can access the value safely using `value()` or the dereference operator `*`:

   ```cpp
   int value = optInt.value(); // Throws std::bad_optional_access if empty
   ```

6. **Resetting the Optional:**
   If you want to clear the value, you can use `reset()`:

   ```cpp
   optInt.reset(); // Now it has no value
   ```

### Example Code

Here's a complete example that demonstrates its use:

```cpp
#include <iostream>
#include <optional>

std::optional<int> findValue(bool returnValue) {
    if (returnValue) {
        return 42; // Return an optional with a value
    } else {
        return std::nullopt; // Return an empty optional
    }
}

int main() {
    auto result = findValue(true);
    
    if (result) { // Checks if result has a value
        std::cout << "Found value: " << *result << std::endl;
    } else {
        std::cout << "No value found." << std::endl;
    }

    return 0;
}
```

### Benefits of `std::optional`

- **Type Safety:** Unlike raw pointers, `std::optional` clearly indicates the possibility of absence of value.
- **No Need for Sentinel Values:** You can avoid using special values (like `-1` or `nullptr`) to indicate "no value."
- **Cleaner Code:** It helps in writing cleaner and more expressive code.

### Limitations

- `std::optional` cannot be used with types that are not default constructible.
- It introduces a slight overhead compared to using raw types or pointers, though usually negligible.

Using `std::optional` can greatly enhance the clarity and safety of your C++ code, especially when dealing with optional values!

*/


// ------------------------??????????????????????????????????????????--------------------------
/*
lets create an code that opens an file and read its contents first of all we will use other ways than std::optional 

one way of doing it would be like this 

#include<iostream>
#include<fstream> 

std::string ReadFile(const std::string& Filepath)
{
	std::ifstream stream(Filepath);
	if (stream)
	{
		std::string result;
		//read file
		stream.close();


		return result;
	}
	return {};

}

int main()
{
	std::string data = ReadFile("data.txt ");
	if (data != "")
	{
		std::cout << "file opened succesfully\n";
	}else
		std::cout << "file did not opened succesfully\n";
}

but this has an huge problem what if the file is present and it is emty so this will be wrong 
lets try another way

---------------using bool---------
#include<iostream>
#include<fstream> 

std::string ReadFile(const std::string& Filepath, bool& success)
{
	std::ifstream stream(Filepath);
	if (stream)
	{
		std::string result;
		//read file
		stream.close();

		success = true;

		return result;
	}
	success = false;
	return {};

}

int main()
{
	bool FileOpenedSuccessfully;
	std::string data = ReadFile("data.txt ", FileOpenedSuccessfully);
	if (FileOpenedSuccessfully)
	{
		std::cout << "file opened succesfully\n";
	}else
		std::cout << "file did not opened succesfully\n";


}

--------------------using raw pointers----------------------
#include<iostream>
#include<fstream> 

char* ReadFile(const std::string& Filepath)
{
	std::ifstream stream(Filepath);
	if (stream)
	{
		stream.seekg(0, std::ios::end);
		std::streamsize size = stream.tellg();
		stream.seekg(0, std::ios::beg);


		char* result = new char[size + 1];
		if (result) {
			stream.read(result, size);
			result[size] = '\0'; // Null-terminate the string
			stream.close();
			return result;
		}
	}
	return nullptr;

}

int main()
{
	char* data = ReadFile("data.txt");
	if (data != nullptr)
	{
		std::cout << "file opened succesfully\n";
	}else
		std::cout << "file did not opened succesfully\n";
}


you can see that using raw pointers to validate that wheather the file is opened or not is complex

these above code are not good and are not quite readable and not safe so lets use the correct way

-----------------using optional---------- 
#include<iostream>
#include<fstream> 
#include<optional>

std::optional<std::string> ReadFile(const std::string& Filepath)
{
	std::ifstream stream(Filepath);
	if (stream)
	{
		std::string result;
		//read file
		stream.close();
		return result;
	}
	return {};
}

int main()
{
	std::optional<std::string> data = ReadFile("data.txt ");
	if (data)
	{
		std::cout << "file opened succesfully\n";
	}else
		std::cout << "file did not opened succesfully\n";
}


another place where the std::optional can be very usefull is that if the file is not present you can give the string an default value
like
	std::string value = data.value_or("Not present");

you are providing an default value to the string if the file is not opened

for example you have have a file which contains the count no od how many times you want to run benchmarking
you could do is 
std::optional<int> count;
int c = count.value_or(100);

so if it is not present or file is not opened you can provide an default value to that variable

*/
//you could also use std::variant if you wnat the code to tell what went wrong instead of showing you that the file is emty 
//or the file did no open
#include"std_variant.cpp"