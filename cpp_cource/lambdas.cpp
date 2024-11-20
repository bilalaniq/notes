//-----------------------------lamdas-------------------------
// Certainly! Lambdas in C++ are a feature introduced in C++11 that allow you to define anonymous functions directly in your code. 
//They are particularly useful for creating short, inline functions without the need to formally declare a function. Lambdas can capture 
//variables from their surrounding scope, which makes them very flexible.

// Here's a detailed breakdown of lambdas in C++:

// ### Basic Syntax

// The syntax for a lambda function in C++ is:

// ```cpp
// [capture](parameters) -> return_type {
//     // function body
// }
// ```

// Here's what each part means:

// - **`[capture]`**: This is the capture clause, which allows the lambda to access variables from the surrounding scope. 
//It can be empty if no variables are captured.
// - **`(parameters)`**: This is the parameter list, similar to the parameter list in a regular function. It can be empty if the lambda does 
//not take any parameters.
// - **`-> return_type`**: This specifies the return type of the lambda. It is optional and can be omitted if the return type can be 
//inferred by the compiler.
// - **`{ /* function body */ }`**: This is the body of the lambda where the actual code is written.

// ### Example

// Here’s a simple example of a lambda function:

// ```cpp
// #include <iostream>

// int main() {
//     // A lambda that adds two numbers
//     auto add = [](int a, int b) {
//         return a + b;
//     };

//     std::cout << "Sum: " << add(3, 4) << std::endl; // Output: Sum: 7
//     return 0;
// }
// ```

// In this example:

// - `auto add = [](int a, int b) { return a + b; };` declares a lambda function that takes two integers and returns their sum.
// - The lambda is assigned to a variable `add`, which can then be used just like any other function.

// ### Capture Clause

// The capture clause `[capture]` determines how the lambda accesses variables from its surrounding scope. There are several ways to capture variables:

// 1. **Capture by Value `[=]`**: Captures all local variables used in the lambda by value.

//     ```cpp
//     int x = 10;
//     auto lambda = [=]() {
//         std::cout << "x: " << x << std::endl;
//     };
//     lambda(); // Output: x: 10
//     ```

// 2. **Capture by Reference `[&]`**: Captures all local variables used in the lambda by reference.

//     ```cpp
//     int x = 10;
//     auto lambda = [&]() {
//         x = 20; // modifies the original x
//     };
//     lambda();
//     std::cout << "x: " << x << std::endl; // Output: x: 20
//     ```

// 3. **Capture by Specific Variables `[x, &y]`**: Captures specific variables by value or reference.

//     ```cpp
//     int x = 10;
//     int y = 20;
//     auto lambda = [x, &y]() {
//         std::cout << "x: " << x << ", y: " << y << std::endl;
//         y = 30; // modifies the original y
//     };
//     lambda();
//     std::cout << "y: " << y << std::endl; // Output: y: 30
//     ```

// 4. **Capture All by Value and Specific by Reference `[=, &y]`**: Captures all variables by value except for those explicitly captured by reference.

//     ```cpp
//     int x = 10;
//     int y = 20;
//     auto lambda = [=, &y]() {
//         std::cout << "x: " << x << ", y: " << y << std::endl;
//         y = 30; // modifies the original y
//     };
//     lambda();
//     std::cout << "y: " << y << std::endl; // Output: y: 30
//     ```

// ### Return Type

// The return type can be specified if the lambda does not have a straightforward return type. Otherwise, it is inferred automatically:

// ```cpp
// auto lambda = []() -> int {
//     return 42;
// };
// ```

// ### Mutable Lambdas

// By default, lambdas that capture by value are `const`, meaning they cannot modify the captured variables. However, if you need to modify
// captured variables, you can use the `mutable` keyword:

// ```cpp
// int x = 10;
// auto lambda = [x]() mutable {
//     x = 20; // modifies the copy of x
// };
// lambda();
// std::cout << "x: " << x << std::endl; // Output: x: 10
// ```

// ### Using Lambdas with STL Algorithms

// Lambdas are particularly useful when working with STL algorithms:

// ```cpp
// #include <algorithm>
// #include <vector>
// #include <iostream>

// int main() {
//     std::vector<int> vec = {1, 2, 3, 4, 5};

//     // Using a lambda with std::for_each
//     std::for_each(vec.begin(), vec.end(), [](int& n) {
//         n *= 2;
//     });

//     for (int n : vec) {
//         std::cout << n << ' ';
//     }

//     return 0;
// }
// ```

// In this example, `std::for_each` uses a lambda to double each element in the vector.

// ### Conclusion

// Lambdas in C++ are a powerful feature that allows for concise and flexible function definitions. They are especially useful 
// in contexts where you need a small function for a short period of time, such as when working with algorithms or callbacks. Understanding
// how to use lambdas effectively can make your C++ code more readable and maintainable.




//for working with lamdas you also need to know about std::function 
#include"std__function.cpp"