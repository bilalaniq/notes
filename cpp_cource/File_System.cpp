// ------------------------------------File System Library------------------------------
/*
The `<filesystem>` library in C++ provides a comprehensive set of tools for working with files and directories. Introduced in C++17,
it allows for easier and more portable file system manipulation. Below is an overview of the key components and functions available 
in the `<filesystem>` library.

### Key Components

1. **Paths**: Represent file or directory paths.
2. **File Status**: Check the status of files and directories.
3. **Directory Iteration**: Iterate through the contents of a directory.
4. **File Operations**: Create, remove, and manipulate files and directories.

### Main Classes

- **`std::filesystem::path`**: Represents a file system path.
- **`std::filesystem::file_status`**: Represents the status of a file or directory.
- **`std::filesystem::directory_entry`**: Represents a single entry in a directory.

### Overview of Functions

#### Path Operations

- **`std::filesystem::path`**: Constructor and member functions
  - **`path(const char* p)`**: Creates a path object from a string.
  - **`path(const std::string& p)`**: Creates a path from a `std::string`.
  - **`operator/`**: Overloaded to allow easy path concatenation.
  - **`filename()`**: Returns the filename component of the path.
  - **`extension()`**: Returns the file extension.
  - **`parent_path()`**: Returns the parent directory of the path.
  - **`stem()`**: Returns the filename without the extension.
  - **`string()`**: Converts the path to a `std::string`.

#### File Status Operations

- **`std::filesystem::status(const path& p)`**: Returns the file status of the path.
- **`std::filesystem::exists(const path& p)`**: Checks if the file or directory exists.
- **`std::filesystem::is_regular_file(const path& p)`**: Checks if the path is a regular file.
- **`std::filesystem::is_directory(const path& p)`**: Checks if the path is a directory.
- **`std::filesystem::is_empty(const path& p)`**: Checks if the directory is empty.
- **`std::filesystem::file_size(const path& p)`**: Returns the size of the file.

#### Directory Operations

- **`std::filesystem::create_directory(const path& p)`**: Creates a new directory.
- **`std::filesystem::remove(const path& p)`**: Deletes a file or empty directory.
- **`std::filesystem::remove_all(const path& p)`**: Recursively deletes a directory and its contents.
- **`std::filesystem::rename(const path& old, const path& new)`**: Renames or moves a file or directory.
- **`std::filesystem::create_directories(const path& p)`**: Creates a directory and any necessary parent directories.

#### Iterating Over Directories

- **`std::filesystem::directory_iterator`**: Iterator for directory entries.
- **`std::filesystem::recursive_directory_iterator`**: Iterates recursively through a directory.
  
Example of iteration:
```cpp
for (const auto& entry : std::filesystem::directory_iterator("path/to/dir")) {
    std::cout << entry.path() << std::endl;
}
```

#### File Copying and Moving

- **`std::filesystem::copy(const path& from, const path& to)`**: Copies a file or directory.
- **`std::filesystem::copy_file(const path& from, const path& to)`**: Copies a file with options for overwriting.
- **`std::filesystem::copy_directory(const path& from, const path& to)`**: Copies a directory recursively.

#### Miscellaneous Functions

- **`std::filesystem::current_path()`**: Returns the current working directory.
- **`std::filesystem::path absolute(const path& p)`**: Returns the absolute path of a given path.
- **`std::filesystem::relative(const path& p, const path& base)`**: Returns the relative path from the base path to the given path.

#### Filesystem Configuration

- **`std::filesystem::status_error(const path& p)`**: Checks for file system errors.
- **`std::filesystem::permissions(const path& p)`**: Gets or sets the permissions of a file or directory.

### Example Usage

Here's a brief example demonstrating some of these functions:

```cpp
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    fs::path dir = "example_dir";

    // Create a directory
    if (fs::create_directory(dir)) {
        std::cout << "Directory created: " << dir << std::endl;
    }

    // Check if the directory exists
    if (fs::exists(dir)) {
        std::cout << "Directory exists: " << dir << std::endl;
    }

    // List files in the directory
    for (const auto& entry : fs::directory_iterator(dir)) {
        std::cout << entry.path() << std::endl;
    }

    // Clean up
    fs::remove_all(dir);
    return 0;
}
```

### Conclusion

The `<filesystem>` library in C++ provides a powerful and flexible way to work with file systems, making tasks such as file 
manipulation and directory management much more straightforward and portable. With functions for almost all common file operations,
it greatly simplifies the development of applications that need to interact with the file system.




*/


// --------------------------------------file system vs fstraam library----------------------------------
/*
Here’s a comparison between the **File System Library (`std::filesystem`)** and **`fstream`** in C++, presented in a table format to highlight their features, use cases, and differences.

+-----------------------------------------------------------------------------------------------------------------------------------------+
| Feature/Aspect            | File System Library (`std::filesystem`)                 | `fstream`                                        |
|---------------------------|-------------------------------------------------------------------------------------------------------------|
| **Purpose**               | Provides functionality for interacting with the         | Designed for both reading from and writing to     |
|                           | file system (directories, paths, file properties).      | files.                                            |
|                           |                                                         |                                                   |
| **Primary Functions**     | Directory manipulation, path handling, file status      | File input and output operations (text and binary)|
|                           | checks, file properties.                                |                                                   |
|                           |                                                         |                                                   |
| **File Creation**         | Can create directories and check if files exist         | Can create files when writing                     |
|                           | (e.g., `create_directory`, `exists`).                   | (if the file does not already exist).             |                                            
|                           |                                                         |                                                   |
| **File Management**       | Enables recursive directory iteration, renaming,        | Supports reading, writing, and modifying file     |
|                           | removing, and checking file types.                      | content.                                          |
|                           |                                                         |                                                   |  
| **Error Handling**        | Throws exceptions (e.g., `filesystem_error`)            | Uses `std::ios::fail()` to check if operations    |
|                           | for various file system errors                          | were successful.                                  |                                   
|                           | (permissions, path not found).                          |                                                   |
|                           |                                                         |                                                   |
| **Read/Writing            | Does not read file contents directly; provides          | Provides methods for both reading and writing data|
|   Operations**            | access to file attributes.                              | (e.g., >> and << operators).                      |
|                           |                                                         |                                                   |
| **Performance**           | More efficient for file system operations               | Optimized for reading from and writing to files,  |
|                           | (e.g., checking existence, iterating directories).      | especially with buffered I/O.                     |
|                           |                                                         |                                                   |
| **Path Representation**   | Uses `std::filesystem::path` to represent file paths    | Uses standard string types                        |
|                           | and handle path manipulations.                          | (e.g., `std::string` or `const char*`) for        |
|                           |                                                         |  file names.                                      |
|                           |                                                         |                                                   |
| **Cross-Platform Support**| Fully cross-platform (supports Windows, Linux,          | Also cross-platform, but file path handling       |
|                           | macOS, etc.) for file system operations.                | may differ across systems.                        |
|                           |                                                         |                                                   |
| **Usage Example**         |                                                         |                                                   |
|                           | #include <filesystem>                                   | #include <fstream>                                |
|                           | namespace fs = std::filesystem;                         | std::fstream outFile("file.txt");                 |
|                           | fs::create_directory("dir");                            | outFile << "Hello, World!";                       |
|                           | ```                                                     | outFile.close();                                  |
|                           |                                                         |                                                   |
| **Typical Use Cases**     | Managing files and directories, checking file           | Reading configuration files, writing logs, saving |
|                           | properties, creating nested directories.                | user data, or generating reports.                 |
|                           |                                                         |                                                   |
| **Data Handling**         | No direct data manipulation, focuses on                 | Direct manipulation of file content, supports     |
|                           | file system structure.                                  | various data types (text, binary).                |
|___________________________|_________________________________________________________|___________________________________________________|

### Summary

- **File System Library (`std::filesystem`)**: This library is geared towards managing the structure and properties of files and 
directories, making it suitable for applications that need to interact with the file system itself, such as checking for file existence,
creating directories, or iterating through file structures.

fstream: This class provides capabilities for both reading and writing data to files, making it versatile for handling file I/O 
operations. It allows you to open files in different modes (read, write, or both) and supports formatted input/output.

Using both in conjunction allows you to manage the file system effectively while also handling file I/O operations smoothly.
*/
