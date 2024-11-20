// ----------------------constexpr------------------------------
/*
Certainly! The `constexpr` keyword in C++ is used to declare that a function or variable can be evaluated at compile-time.
This feature was introduced in C++11 and has evolved over the subsequent standards. Here’s a detailed overview:

### 1. **Basic Concept**

- **Compile-Time Evaluation**: `constexpr` allows the compiler to evaluate the value of a function or variable at compile time
rather than at runtime. This can improve performance and enable more optimizations. and also it can be used in contexts that 
require compile-time constants, such as array sizes, template arguments, and constant expressions.

### 2. **Usage of `constexpr`**

#### **Variables**

When you declare a variable with `constexpr`, you are stating that the value of this variable is constant and known at compile time.

```cpp
constexpr int max_size = 100;
```

- `max_size` is evaluated and set at compile time.
- You can use `constexpr` variables in contexts where compile-time constants are required, such as array sizes.

you may be asking that that what is the differnce between 
int value = 100;
and 
constexpr int value = 100;
is that the non constexpr value is evaluated at runtime where the constexpr is evaluated at compile time.

#### **Functions**

A function declared with `constexpr` can be evaluated at compile time if all its arguments are compile-time constants.

```cpp
constexpr int square(int x) {
    return x * x;
}
```

- If you call `square(4)`, the compiler can evaluate it as `16` during compilation.
- The function can also be called with non-constant arguments, in which case it behaves like a regular function.

### 3. **Requirements for `constexpr` Functions**

For a function to be `constexpr`, it must meet these requirements:

1. **Body of the Function**: The body of a `constexpr` function must contain only a single return statement or a `return` 
statement and a `constexpr` expression. From C++14 onwards, `constexpr` functions can include more complex code, including 
loops and conditionals.
   
   ```cpp
   constexpr int factorial(int n) {
       return (n <= 1) ? 1 : n * factorial(n - 1);
   }
   ```

2. **Return Type**: The return type must be a literal type, which includes integral types, floating-point types, pointers to literal 
types, etc.

### 4. **`constexpr` in C++14 and Beyond**

C++14 and later standards expanded the capabilities of `constexpr`:

- **Complex Expressions**: `constexpr` functions can now include more complex logic, such as loops and conditionals, which were restricted in C++11.

   ```cpp
   constexpr int fibonacci(int n) {
       if (n <= 1) return n;
       return fibonacci(n - 1) + fibonacci(n - 2);
   }
   ```

- **Member Functions**: You can use `constexpr` for member functions, which allows them to be evaluated at compile-time.

   ```cpp
   class Point {
   public:
       constexpr Point(double x, double y) : x_(x), y_(y) {}
       constexpr double getX() const { return x_; }
       constexpr double getY() const { return y_; }
   private:
       double x_, y_;
   };
   ```

### 5. **`constexpr` and `const`**

- **`const` Variables**: A `const` variable is evaluated at runtime, though its value cannot be modified after initialization.
- **`constexpr` Variables**: These are also `const`, but the key distinction is that their value is known at compile time.

### 6. **Use Cases and Benefits**

- **Performance**: By evaluating expressions at compile time, you can reduce runtime overhead and improve performance.
- **Template Programming**: `constexpr` is particularly useful in template metaprogramming, where compile-time computations are crucial.

### 7. **Example**

Here’s a practical example that demonstrates the use of `constexpr`:

```cpp
#include <iostream>

constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    constexpr int value = factorial(5); // Evaluated at compile time
    std::cout << "Factorial of 5 is " << value << std::endl; // Output: Factorial of 5 is 120
    return 0;
}
```

In this example, `factorial(5)` is computed at compile time, and `value` is initialized with the result.

In summary, `constexpr` is a powerful feature in C++ that enhances the ability to perform compile-time computations, leading to
more efficient code and greater flexibility in writing templates and other compile-time constructs.









-------------------------?????????????????????????????????????????-----------------------------------
you may be asking that when i know an value at compile time or know what its fixed value must be what should i define it a 
a const or an consexpr 
it is more recumended to define it as an constexpr as it is evaluatted at compile time where when defining it as const it will be 
evaluated at runtime 

heres an example 
for an const expr you donot need to know the exact value of the variable 
const int maxSize = getMaxSizeFromUser(); // Value is constant but obtained at runtime

If you don’t require compile-time evaluation and just need to ensure the value is immutable after initialization
const int maxConnections = 10; // Simple constant without compile-time requirement


but for the constexpr you need to know the value for initillizing it
constexpr int maxConnections = 10; //  compile-time requirement



so you should be using constexpr when you know the exact value of the variable this prevent runtime overhead 
and makes the code execution fast



*/