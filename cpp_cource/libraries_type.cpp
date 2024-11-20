// ----------------------------------------libraries----------------------------------
/*
"library" refers to a collection of precompiled code modules (functions, classes, variables, etc.) that provide specific 
functionality. These libraries are designed to be reused by other programs, allowing developers to leverage existing code 
rather than reinventing the wheel for common tasks.

there are two type of libraries
>staatic 
>dynamic (shared libraries)



Dynamic and static libraries are two ways of packaging and distributing code in C++ and many other programming languages.
Here's how they differ:

1. **Static Libraries**:
   - Static libraries are compiled versions of code that are linked directly into the executable at compile time.
   - They are also called "archives" because they are essentially collections of object files bundled together.
   - When you compile your program, the necessary code from the static library is included in the final executable.
   - Static libraries increase the size of the executable because all the library code is included, even if not all of it is used.
   - They are easier to distribute because you only need to distribute the executable file, and all the required code is already 
     contained within it.
   - Static linking can lead to potential issues with versioning conflicts if different parts of the program use different versions
     of the same library.

2. **Dynamic Libraries**: (shared libraries)
   - Dynamic libraries are separate files that contain compiled code, but they are not linked directly into the executable at compile 
     time.
   - Instead, they are loaded into memory and linked at runtime when the program starts or when the library is explicitly loaded.
   - Dynamic libraries are also known as shared libraries because they can be shared among multiple programs.
   - They reduce the size of the executable because the library code is not included; instead, the program references functions 
     and symbols in the dynamic library.
   - Dynamic linking allows for more efficient memory usage since the library code is loaded into memory only once and shared among 
     multiple programs.
   - Updates to dynamic libraries are easier to distribute because you only need to replace the library file, and all programs that 
     use it will automatically use the updated version.
   - However, dynamic linking introduces dependencies on external library files, which must be present on the system where the program 
     is run.




In summary, the main differences between dynamic and static libraries lie in when the linking occurs (compile time vs. runtime), how 
they are distributed, their impact on executable size, memory usage, and ease of updating. The choice between dynamic and static linking 
depends on factors such as performance requirements, ease of distribution, and the specific needs of the project.




----------------------------------how to know which file is static and which is dynamic-------------------------------------
In general, libraries can be compiled as either dynamic or static, but it ultimately depends on how the library was built by its 
developers. Here are some ways to determine whether a library is dynamic or static:

1. **Documentation**:
   - The documentation provided with the library should specify whether it is intended to be used as a dynamic or static library. 
     Developers typically include this information to guide users on how to link the library with their projects.

2. **File Extensions**:
   - On Unix-like systems (Linux, macOS), shared libraries typically have file extensions like `.so` (Shared Object) for dynamic 
     libraries and `.a` (Archive) for static libraries. On Windows, dynamic libraries often have `.dll` (Dynamic Link Library) extensions, 
     while static libraries may have `.lib` extensions.

3. **Command-Line Tools**:
   - You can use command-line tools to inspect the properties of library files. On Unix-like systems, you can use commands 
     like `file` or `ldd` to determine whether a file is a dynamic or static library and to see its dependencies.
     - For example, running `file your_library.so` or `file your_library.a` will provide information about the file type.
     - Running `ldd your_library.so` will list the dynamic dependencies of the shared library.
   - On Windows, you can use tools like `dumpbin` or `Dependency Walker` to inspect library files and see whether they are dynamic 
     or static.

4. **Linking Behavior**:
   - When you compile your program and link it with a library, the linking process will differ depending on whether the library is 
     dynamic or static.
     - Static libraries are linked directly into the executable during the compilation process.
     - Dynamic libraries are not linked directly into the executable but are instead referenced for dynamic linking at runtime.

5. **Size of Executable**:
   - If you notice that your executable file size is larger than expected, it might indicate that static libraries are being linked 
     into the executable. Conversely, if the executable size is relatively small and there are accompanying `.dll` or `.so` files, it 
     suggests dynamic linking.

By using a combination of these methods, you can usually determine whether a library is dynamic or static and how to properly link it 
with your projects.

*/
//if you want to learn about dinamic an dstatic lib then click here
#include"static_libraries.cpp"
#include"dynamic_libraries.cpp"
