// ---------------------------PCH(Precompiled Header)------------------
/*
 In Microsoft Visual Studio, using Precompiled Headers (PCH) is a common practice to speed up the build process. Here's a step-by-step
 guide on how to set up and use PCH in Visual Studio:

### Setting Up Precompiled Headers in Visual Studio

1. **Create a Precompiled Header File**

   - **Add a Header File for Precompilation:**
     - Right-click on your project in the Solution Explorer.
     - Select "Add" > "New Item..."
     - Choose "Header File (.h)" and name it something like `pch.h`.

   - **Add Common Includes to the Header File:**
     ```cpp
     // pch.h
     #ifndef PCH_H
     #define PCH_H

     #include <iostream>
     #include <vector>
     // Add other commonly used headers here

     #endif // PCH_H
     ```

2. **Create a Source File to Generate the Precompiled Header**

   - **Add a CPP File for Precompilation:**
     - Right-click on your project in the Solution Explorer.
     - Select "Add" > "New Item..."
     - Choose "C++ File (.cpp)" and name it something like `pch.cpp`.

   - **Include the Header File in the CPP File:**
     ```cpp
     // pch.cpp
     #include "pch.h"
     ```

   - **Compile pch.cpp as a Precompiled Header:**
     - Right-click on `pch.cpp` in the Solution Explorer.
     - Select "Properties".
     - In the "Configuration Properties" section, go to "C/C++" > "Precompiled Headers".
     - Set "Precompiled Header" to "Create (/Yc)".
     - Ensure "Precompiled Header File" is set to `pch.h`.

3. **Configure Other Source Files to Use the Precompiled Header**

   - **Set Up Other Source Files:**
     - For each source file that should use the precompiled header, you need to specify that it will use `pch.h`.

     - Right-click on each `.cpp` file in the Solution Explorer.
     - Select "Properties".
     - Go to "Configuration Properties" > "C/C++" > "Precompiled Headers".
     - Set "Precompiled Header" to "Use (/Yu)".
     - Ensure "Precompiled Header File" is set to `pch.h`.

4. **Ensure Proper Include Guards**

   - Verify that `pch.h` includes guards to prevent multiple inclusions, as shown in the example above.

### Summary of Steps

1. Create a header file (`pch.h`) with common includes.
2. Create a CPP file (`pch.cpp`) that includes `pch.h` and compile it as a precompiled header.
3. Configure other CPP files to use the precompiled header by setting their properties accordingly.

### Important Tips

- **Consistency:** Ensure that all source files that include `pch.h` are properly configured to use precompiled headers.
- **Dependency Management:** Changes in `pch.h` or `pch.cpp` may require recompilation of all files that use the precompiled header.
- **Optimization:** Use PCH files primarily for headers that are used across multiple files and rarely change.

By following these steps, you can take advantage of precompiled headers to significantly reduce your build times in Visual Studio.



Advantages of Using PCH
Faster Compilation Times: By compiling the header files only once and reusing the compiled result, the overall compilation time is reduced.
Consistency: Ensures that the headers included are consistent across different source files.
Considerations
Precompiled Header Management: Using PCH files can add complexity to your build system. It's important to manage them correctly to avoid issues.
Dependencies: Changes in the precompiled header file or its dependencies can require recompiling a lot of code, so it’s important to use them wisely.
Overall, precompiled headers are a powerful tool for improving build performance in large C++ projects.
*/


//--------------------------note----------------------------
/*
note that you should only add those files in the pch header file that you would not cange as that code is not your code an you surely would 
not change nything in that code
what i ment to say is that you should only add those files in the pch header file which is not changed offenly

*/