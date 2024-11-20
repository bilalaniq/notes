// -------------------------------std::async--------------------------
/*
### `std::async` in C++

`std::async` is a function provided in the C++ Standard Library that allows you to run tasks asynchronously. It enables you to
 execute functions in a separate thread, making it easier to perform concurrent operations without managing threads directly.

#### Key Features

1. **Asynchronous Execution**:
   - `std::async` can run a function in a separate thread, allowing the main thread to continue executing while the function 
   is being processed.

2. **Return Values**:
   - It returns a `std::future` object, which can be used to retrieve the result of the asynchronous operation once it completes.

3. **Automatic Thread Management**:
   - You don’t have to manage threads directly; `std::async` handles the thread creation and destruction for you.

4. **Launch Policies**:
   - You can specify how the function is executed: either in a new thread or potentially in the calling thread, using launch policies.

#### Syntax

```cpp
std::future<ReturnType> std::async(std::launch policy, Callable&& f, Args&&... args);
```

- **policy**: Determines whether the function should run in a new thread or potentially the calling thread.
- **f**: The callable object (function, lambda, etc.) to be executed.
- **args**: Arguments to pass to the callable.

#### Launch Policies

`std::async` allows you to specify one of two launch policies:

- `std::launch::async`: Forces the function to run in a new thread.
- `std::launch::deferred`: The function will not run until the result is explicitly requested, at which point it will run in the
 current thread.

You can combine both:

```cpp
std::launch::async | std::launch::deferred
```

#### Example

Here’s a basic example of using `std::async`:

```cpp
#include <iostream>
#include <future>
#include <chrono>

int compute(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate a long computation
    return x * x;
}

int main() {
    // Start an asynchronous task
    std::future<int> result = std::async(std::launch::async, compute, 5);

    std::cout << "Doing other work while waiting for the result...\n";

    // Retrieve the result (this will block until the computation is finished)
    std::cout << "The result is: " << result.get() << std::endl;

    return 0;
}
```

#### Handling Exceptions

If the asynchronous function throws an exception, you can catch it when calling `get()`:

```cpp
try {
    std::future<int> result = std::async(std::launch::async, compute, -1);
    std::cout << result.get() << std::endl; // This will throw an exception
} catch (const std::exception& e) {
    std::cout << "Caught an exception: " << e.what() << std::endl;
}
```

#### Performance Considerations

- **Overhead**: Using `std::async` introduces some overhead due to thread management.
- **Thread Pooling**: Depending on the implementation, it may not create a new thread for each call, especially with 
`std::launch::deferred`.

#### Best Practices

1. **Use `std::async` for Simple Asynchrony**: When you need to run a function asynchronously without worrying about thread management.
2. **Manage Resources Carefully**: Ensure that resources accessed by the asynchronous function are thread-safe.
3. **Check for Exceptions**: Always handle exceptions when retrieving results from a `std::future`.

### Summary

`std::async` is a powerful tool for concurrent programming in C++. It simplifies the creation and management of threads, 
allowing you to run tasks asynchronously with ease. By leveraging `std::future`, you can efficiently retrieve results and handle
errors from your asynchronous operations.





*/


// -------------------------------std::async vs std::threads---------------
/*
`std::async` and threads in C++ are both used for concurrent programming, but they serve different purposes and have different 
characteristics. Here’s a comparison:

### `std::async`
- **Higher-level abstraction**: It provides a simpler interface for asynchronous operations, automatically managing threads 
under the hood.
- **Return values**: `std::async` returns a `std::future`, which can be used to retrieve the result of the asynchronous operation 
once it's complete.
- **Automatic management**: The lifetime of the threads is managed for you, which means you don't have to worry about 
explicitly joining or detaching them.
- **Launch policies**: You can specify whether to run the task in a new thread or to potentially run it in the calling thread 
(using `std::launch`).
- **Exception handling**: Exceptions thrown within the asynchronous task can be captured and rethrown when you call `get()` 
on the `std::future`.

### Threads
- **Lower-level control**: You have more control over thread creation, management, and synchronization.
- **Manual management**: You need to explicitly join or detach threads, which can lead to more complexity and potential issues 
if not handled properly.
- **No automatic return**: You have to manage return values and shared state manually, often using synchronization primitives 
like mutexes or condition variables.
- **More overhead**: Depending on the implementation, thread management can introduce more overhead compared to using `std::async`.

### When to Use Which
- **Use `std::async`** when you want a simple, straightforward way to run tasks asynchronously and handle their results without 
diving deep into thread management.
- **Use threads** when you need fine-grained control over thread lifetimes, performance optimizations, or when dealing with more 
complex concurrency scenarios.

### Example Usage

**Using `std::async`:**
```cpp
#include <future>
#include <iostream>

int calculate() {
    // Simulate long computation
    return 42;
}

int main() {
    std::future<int> result = std::async(std::launch::async, calculate);
    std::cout << "Result: " << result.get() << std::endl; // Blocks until result is available
    return 0;
}
```

**Using Threads:**
```cpp
#include <iostream>
#include <thread>

void calculate(int& result) {
    // Simulate long computation
    result = 42;
}

int main() {
    int result;
    std::thread t(calculate, std::ref(result));
    t.join(); // Wait for the thread to finish
    std::cout << "Result: " << result << std::endl;
    return 0;
}
```

In summary, choose `std::async` for ease of use and manageability, and threads for more control and customization in your
 concurrent programming needs.

if you want to lean about threads click here 
*/
#include"threads.cpp"

/*
when sharing resources between threads there could ebe many errors as the main thread is trying to access the vector v 
before the asynchronous task has completed modifying it.

When to Lock Resources:
Concurrent Access: If two or more threads are reading from and writing to the same resource (like a vector), you need to ensure that access is synchronized to prevent data races.
Shared State: If multiple threads might modify shared data simultaneously, you need locks or other synchronization mechanisms.


If there were a scenario where both threads were accessing resources at the same time (for instance, you would use a mutex:
*/
// if you want to learn about std::mutex click here 
#include"std_mutex.cpp"




// ---------------------------------???????????????????????????????????---------------------
/*
if you want to pass an reffrence to an function in async you need to use std::ref()

heres an example
	std::future<void> result = std::async(std::launch::async, modify_vector, std::ref(Vector));
this will pass the refrence of the vector 


youu can just pass it like usual you need to use std::ref();
*/