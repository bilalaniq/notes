// ------------------------------------------fstream------------------------------
/*
`<fstream>` in C++ is a header file that provides functionalities for file input and output (I/O) operations. It includes classes
and functions for handling file streams, allowing you to read from and write to files. The primary classes used for file I/O in this 
header are `std::ifstream`, `std::ofstream`, and `std::fstream`.

### Key Classes

1. **std::ifstream**: Used for reading from files.
2. **std::ofstream**: Used for writing to files.
3. **std::fstream**: Used for both reading and writing to files.

### Basic Operations

#### Including the Header

To use file streams, include the `<fstream>` header:

```cpp
#include <fstream>
#include <iostream>
#include <string>
```

### Opening and Closing Files

You can open a file when creating a file stream object or later using the `open()` method. Always ensure you close the file after 
operations using the `close()` method.

#### Example of `std::ifstream`

```cpp
std::ifstream inputFile("example.txt"); // Open for reading

if (!inputFile.is_open()) {
    std::cerr << "Failed to open file." << std::endl;
    return 1;
}

// Reading from the file
std::string line;
while (std::getline(inputFile, line)) {
    std::cout << line << std::endl; // Process each line
}

inputFile.close(); // Close the file
```

#### Example of `std::ofstream`

```cpp
std::ofstream outputFile("output.txt"); // Open for writing

if (!outputFile.is_open()) {
    std::cerr << "Failed to open file." << std::endl;
    return 1;
}

// Writing to the file
outputFile << "Hello, World!" << std::endl;

outputFile.close(); // Close the file
```

#### Example of `std::fstream`

```cpp
std::fstream file("data.txt", std::ios::in | std::ios::out | std::ios::app); // Open for reading and writing

if (!file.is_open()) {
    std::cerr << "Failed to open file." << std::endl;
    return 1;
}

// Writing to the file
file << "Appending some text." << std::endl;

// Moving to the beginning to read the content
file.seekg(0); // Seek to the start of the file

std::string line;
while (std::getline(file, line)) {
    std::cout << line << std::endl; // Read and print each line
}

file.close(); // Close the file
```

### File Opening Modes

You can specify different modes when opening a file. The following modes are commonly used:

- `std::ios::in`: Open for reading.
- `std::ios::out`: Open for writing (truncates the file if it exists).
- `std::ios::app`: Append mode (writes to the end of the file).
- `std::ios::ate`: Open the file and seek to the end.
- `std::ios::trunc`: Truncate the file (clear its contents) when opened for writing.
- `std::ios::binary`: Open the file in binary mode.

#### Example of Using Modes

```cpp
std::ofstream outputFile("binaryData.bin", std::ios::binary);
if (!outputFile) {
    std::cerr << "Could not open file." << std::endl;
    return 1;
}

int data = 42;
outputFile.write(reinterpret_cast<const char*>(&data), sizeof(data)); // Write binary data
outputFile.close();
```

### Error Handling

Always check if the file opened successfully using `is_open()` or by checking the stream state:

```cpp
if (!inputFile) {
    std::cerr << "Error reading the file." << std::endl;
}
```

You can also use `fail()`, `eof()`, and `bad()` to check for specific stream errors:

- `fail()`: Returns true if an input/output operation failed.
- `eof()`: Returns true if the end of the file has been reached.
- `bad()`: Returns true if a non-recoverable error occurred.

### Reading and Writing Data

You can read and write various data types using overloaded operators:

#### Writing:

```cpp
int number = 10;
outputFile << "Number: " << number << std::endl; // Writes formatted data
```

#### Reading:

```cpp
int number;
inputFile >> number; // Reads formatted data
```

For reading and writing binary data, use `read()` and `write()` methods:

```cpp
outputFile.write(reinterpret_cast<char*>(&number), sizeof(number)); // Binary write
inputFile.read(reinterpret_cast<char*>(&number), sizeof(number)); // Binary read
```

### Conclusion

Using `<fstream>`, you can effectively manage file operations in C++. Remember to handle files carefully, check for errors, and ensure 
files are closed properly after use. This will help prevent resource leaks and potential data corruption.
*/

//if you want to learn about file system click here
#include"File_System.cpp"