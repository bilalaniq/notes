// ----------------------------threads---------------------------
/*
In C++, threads provide a way to execute multiple tasks concurrently. Threads allow a program to perform multiple operations simultaneously, 
making better use of available CPU cores and improving the responsiveness and performance of applications. Threads can be used for various 
purposes, such as performing background tasks, handling user input, or managing asynchronous operations.

### Key Concepts

1. **Thread Basics:**
   - **Thread:** A thread is the smallest unit of execution within a process. A single process can contain multiple threads, each running concurrently.
   - **Concurrency vs. Parallelism:** Concurrency refers to the ability to handle multiple tasks at once, while parallelism refers to performing 
   multiple tasks simultaneously, often on multiple CPU cores.

2. **Threads in C++:**
   - C++11 introduced a standardized thread library that provides a set of classes and functions for managing threads. This library is part of 
   the C++ Standard Library and provides tools for creating, managing, and synchronizing threads.

### C++ Thread Library

#### 1. **Creating Threads**

You can create threads using the `std::thread` class. Here’s a basic example:

```cpp
#include <iostream>
#include <thread>

// Function to be executed by the thread
void printMessage() {
    std::cout << "Hello from the thread!" << std::endl;
}

int main() {
    // Create a thread that runs the printMessage function
    std::thread t(printMessage);    we pass an function pointer in the parameter of the thread
    
    // Wait for the thread to finish
    t.join();

    return 0;
}
```

- `std::thread` constructor takes a function or callable object as an argument and starts a new thread running that function.
- `t.join()` waits for the thread `t` to complete before continuing with the execution of the program. 
This ensures that the main thread waits for the created thread to finish its task.

#### 2. **Passing Arguments to Threads**

You can pass arguments to the function that the thread will execute:

```cpp
#include <iostream>
#include <thread>

// Function with arguments
void printNumbers(int n) {
    for (int i = 1; i <= n; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Pass an argument to the thread function
    std::thread t(printNumbers, 5);

    // Wait for the thread to finish
    t.join();

    return 0;
}
```

- `printNumbers` is a function that takes an integer argument. When creating the thread, `5` is passed as an argument.

#### 3. **Thread Synchronization**

To manage access to shared resources and avoid race conditions, you need synchronization mechanisms such as mutexes. The C++ Standard Library
 provides several synchronization tools:

- **Mutexes (`std::mutex`):** Used to protect shared data from concurrent access.

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // Mutex for synchronizing access

void printNumbers(int n) {
    std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex
    for (int i = 1; i <= n; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::thread t1(printNumbers, 5);
    std::thread t2(printNumbers, 5);

    t1.join();
    t2.join();

    return 0;
}
```



- **`std::lock_guard`:** A RAII (Resource Acquisition Is Initialization) class that automatically acquires and releases the mutex. It locks the
 mutex upon construction and releases it upon destruction.

- **Condition Variables (`std::condition_variable`):** Used to wait for or notify changes in the state.

*/
// if you wan to learn about mutex click here
#include"mutex.cpp"
/*

#### 4. **Thread Management**

- **Detaching Threads:** If you don't want to wait for a thread to finish, you can detach it. A detached thread runs independently, and 
its resources are automatically released when it finishes.

```cpp
#include <iostream>
#include <thread>

void printMessage() {
    std::cout << "Hello from the detached thread!" << std::endl;
}

int main() {
    std::thread t(printMessage);
    t.detach();  // Detach the thread

    // The main thread continues without waiting for `t` to finish

    return 0;
}
```

- **Thread Lifetime:** Be cautious with detached threads as they continue running independently. Ensure that the main thread does 
not terminate before the detached thread completes its work.

### Summary

- **Threads** in C++ are managed using the `std::thread` class from the C++ Standard Library.
- Threads allow concurrent execution of tasks, improving performance and responsiveness.
- Synchronization tools like `std::mutex` and `std::condition_variable` help manage access to shared resources and coordinate thread 
execution.
- Threads can be created, managed, and synchronized using built-in classes and functions, making it possible to develop complex
 multi-threaded applications.

Understanding and using threads effectively requires careful design to avoid common issues such as race conditions and deadlocks. Proper 
synchronization and resource management are crucial for reliable multi-threaded applications.
*/



// ---------------------------------note------------------
/*
note that there are many features within thred so only reading this will not work also read about thread on cpp-refrence 
for example you can make thread sleep for some time

using namespace std::literals::chrono_literals;
std::this_thread::sleep_for(1s);


for this you also need to know about timing in cpp 
to learn about timing in cpp click here 
*/
#include"benchmarking(timing).cpp"

//if you want to learn about mutex 


// ---------------------------------???????????????????????????????????---------------------
/*
if you want to pass an reffrence to an function in another thread you need to use std::ref()

heres an example
		std::thread t(modify_vector, std::ref(v));
this will pass the refrence of the vector 


youu can just pass it like usual you need to use std::ref();
*/