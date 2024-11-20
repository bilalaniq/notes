// --------------------------------std::expected-----------------------------
/*

### **What is `std::expected`?**

`std::expected<T, E>` is a type introduced in the C++23 standard as part of the `<expected>` header. It represents a result of a computation that can either succeed with a value of type `T`, or fail with an error of type `E`. This type is particularly useful when you need to model computations that can fail, but you want to avoid using exceptions or relying on ambiguous return types like `std::optional` or `std::pair`.

### **Why Use `std::expected`?**

Before `std::expected`, developers often used `std::optional` to indicate success or failure, but `std::optional` only tells you if a result is present or absent — it doesn't provide any information about the reason for failure. Similarly, you might use `std::pair` or `std::tuple` to pair a result with an error code, but this introduces additional complexity and lacks type safety.

`std::expected` is designed to:

- Provide clear semantics for success or failure.
- Include both the result and the error in a type-safe manner.
- Avoid the overhead and complexity of exception handling, while still providing a way to handle and propagate errors.

### **Structure of `std::expected<T, E>`**

`std::expected<T, E>` is a template class, where:

- `T` is the type of the result on success (e.g., `int`, `std::string`, etc.).
- `E` is the type of the error that occurs on failure (e.g., `std::string`, `std::error_code`, etc.).

This structure allows you to return either:
- A value of type `T` (if the operation succeeds).
- An error of type `E` (if the operation fails).

In essence, it is a way to model functions that may return either a successful result or an error.

---

### **Basic Syntax and Example Usage**

Let's break down a basic example of how `std::expected` works.

```cpp
#include <expected>
#include <iostream>
#include <string>

// A function that divides two integers and returns an expected result
std::expected<int, std::string> divide(int a, int b) {
    if (b == 0) {
        return std::unexpected("Error: Division by zero");  // Returning an error
    }
    return a / b;  // Returning the result if no error
}

int main() {
    // Test a successful division
    auto result1 = divide(10, 2);
    if (result1) {
        std::cout << "Result: " << *result1 << std::endl;  // Accessing the successful result
    } else {
        std::cout << "Error: " << result1.error() << std::endl;  // Accessing the error message
    }

    // Test a division by zero (failure case)
    auto result2 = divide(10, 0);
    if (result2) {
        std::cout << "Result: " << *result2 << std::endl;
    } else {
        std::cout << "Error: " << result2.error() << std::endl;  // Accessing the error message
    }

    return 0;
}
```

#### **Key Points from the Example:**

- **Creating an expected object**:
  - When `divide(10, 2)` is called, it returns a successful result (`std::expected<int, std::string>` containing `5`).
  - When `divide(10, 0)` is called, it returns an error (`std::expected<int, std::string>` containing the error message `"Error: Division by zero"`).

- **Checking for success or failure**:
  - `result1` and `result2` are `std::expected<int, std::string>`. You can check if the computation was successful by using `if (result)`, where `result` implicitly checks for success.
  
- **Accessing the value or error**:
  - You can access the successful value using `*result` or `result.value()`. This will only work if the operation succeeded (i.e., the object contains a value).
  - If the computation failed, you can access the error using `result.error()`.

---

### **Core Concepts of `std::expected`**

1. **`std::expected<T, E>` State**:
   - The object can be in one of two states:
     - **Success**: Contains a value of type `T` (the result of the computation).
     - **Failure**: Contains an error of type `E`.

2. **Accessing the Value and Error**:
   - **`operator bool()`**: This operator allows you to check if the result is successful. It returns `true` if the object contains a value, and `false` if it contains an error.
   - **`value()`**: This function returns the contained value, and throws an exception if the object contains an error.
   - **`error()`**: This function returns the contained error, and throws an exception if the object contains a value.

3. **Error Representation**:
   - When an error occurs, `std::unexpected` is used to wrap the error. For example:
     ```cpp
     return std::unexpected("Error: Division by zero");
     ```
   - The error type `E` can be anything, such as a string, a custom error code type, or even a more complex error class.

---

### **Advanced Usage**

- **Chaining `std::expected` Values**:
  You can chain `std::expected` results together by propagating errors. For example, if a function returns `std::expected<T, E>`, you can return another `std::expected` from another function. This is useful in pipelines or sequences of operations that might fail at any stage.

```cpp
std::expected<int, std::string> process_and_divide(int a, int b, int c) {
    auto result1 = divide(a, b);  // First division
    if (!result1) return result1.error();  // Propagate error if failed
    
    auto result2 = divide(result1.value(), c);  // Second division
    return result2;
}
```

- **Converting Between `std::expected` and `std::optional`**:
  You can easily convert between `std::expected` and `std::optional`, though `std::expected` is a more expressive error-handling mechanism:

```cpp
std::optional<int> divide_to_optional(int a, int b) {
    auto result = divide(a, b);
    if (result) return *result;
    return std::nullopt;  // Return empty optional on failure
}
```

- **Custom Error Types**:
  You can use custom types for errors instead of just strings. This makes error handling more structured and type-safe.

```cpp
struct MyError {
    int code;
    std::string message;
};

std::expected<int, MyError> divide(int a, int b) {
    if (b == 0) {
        return std::unexpected(MyError{1, "Division by zero"});
    }
    return a / b;
}
```

---

### **Error Handling with `std::expected`**

`std::expected` provides a way to handle errors without relying on exceptions, but it still allows you to propagate detailed error information. This can be particularly useful in contexts where exceptions are either not ideal or where you need to handle multiple error conditions cleanly.

- **Advantages over Exceptions**:
  - With exceptions, you lose type safety (since `catch(...)` can catch any type), and exception handling can introduce performance overhead. `std::expected` avoids these issues and provides clear, type-safe error propagation.
  
- **Advantages over `std::optional`**:
  - `std::optional` only tells you whether something exists or not. It doesn't provide any information about why something failed. `std::expected` gives you both the result and the error, providing more context in failure cases.

---

### **Summary of Key Methods**

1. **`bool operator bool()`**: Checks if the result is a success.
2. **`value()`**: Accesses the successful value (throws an exception if error).
3. **`error()`**: Accesses the error (throws an exception if success).
4. **`std::unexpected(E&& error)`**: Used to create an error state.

---

### Conclusion

`std::expected` is a powerful and expressive tool for handling computations that can fail in C++23. It provides a clear distinction between success and failure, with the added benefit of type safety and the ability to propagate detailed error information. By using `std::expected`, you can avoid the pitfalls of exceptions and ambiguous return types, making your error-handling more robust and explicit.


*/