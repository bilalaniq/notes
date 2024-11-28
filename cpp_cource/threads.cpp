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
To ensure that a detached thread finishes its work without knowing the exact time it will take, you can use a synchronization 
mechanism such as std::future, std::promise, or std::condition_variable.

*/
#include"std_async.cpp"      //for std::future
#include"std_promise.cpp"
#include"std_condition_variable.cpp"
/*

thread is considered joinable if it has been started and is still running or hasn’t been joined or detached. You can check if
a thread is joinable by calling the joinable() method. A thread becomes non-joinable after it has been joined 
you can cheak it by using 

std::thread t(func);
if (t.joinable()) {
    t.join();  // Wait for the thread to finish
}



In C++, std::thread::native_handle() provides access to the native thread handle, which is a platform-specific object used by the
operating system to manage and control threads. This handle allows you to interact with lower-level thread management systems, 
such as those in Windows (HANDLE) or POSIX systems (pthread_t).

Windows: The native handle is a HANDLE that represents a thread object in the Windows API.
POSIX (Linux, MacOS): It returns a pthread_t type, which represents a POSIX thread.

std::thread t([](){ Thread function  });
auto handle = t.native_handle();  // Access native handle



you can also swap between two threads by using the swap function
The swap() function in the context of std::thread allows you to swap the internal state of two std::thread objects. This means 
that the associated threads and their resources (like thread IDs and handles) are exchanged between the two objects.

std::thread t1(func1);
std::thread t2(func2);
t1.swap(t2);  // Swaps t1 and t2 threads


you can also move an thread to another thread like 
std::thread t3(f2, std::ref(n));
std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread






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
std::vector<int> v;
std::thread t(modify_vector, std::ref(v));
this will pass the refrence of the vector
if you want to learn about std::ref click here
*/
#include"std_ref.cpp"
/*


youu can just pass it like usual you need to use std::ref();


also note that
std::thread t1; // t1 is not a thread   
this is just anuninitilized thread and does not represent a running thread.



*/






// -------------------------------std::jthread------------------------------------------
/*
`std::jthread` is a new thread management class introduced in C++20. It is a more convenient and safer alternative to `std::thread`, 
offering automatic joining and support for cancellation. Here's a detailed explanation of `std::jthread` and how it differs from 
`std::thread`:

### Key Features of `std::jthread`:

1. **Automatic Joining:**
   One of the key differences between `std::thread` and `std::jthread` is that `std::jthread` automatically joins itself when it goes
   out of scope. This means you **do not need to explicitly call `join()`** like you do with `std::thread`. The thread is automatically
   joined when the `std::jthread` object is destroyed, ensuring that the thread is completed properly.

   ```cpp
   #include <iostream>
   #include <thread>

   void print_hello() {
       std::cout << "Hello from jthread!" << std::endl;
   }

   int main() {
       std::jthread t(print_hello);  // t automatically joins when it goes out of scope
       // No need to call t.join(), it's handled automatically
   }
   ```

2. **Cancellation Support:**
   `std::jthread` provides built-in support for thread cancellation using `std::stop_token`. This allows you to request that the
    thread stops executing gracefully. This is a big advantage over `std::thread`, which does not have built-in cancellation support.

   ```cpp
   #include <iostream>
   #include <thread>
   #include <chrono>

   void print_until_stop(std::stop_token stop) {
       for (int i = 0; !stop.stop_requested(); ++i) {
           std::cout << "Iteration: " << i << std::endl;
           std::this_thread::sleep_for(std::chrono::seconds(1));
       }
       std::cout << "Thread stopped." << std::endl;
   }

   int main() {
       std::jthread t(print_until_stop);
       std::this_thread::sleep_for(std::chrono::seconds(3));
       t.request_stop();  // Requests the thread to stop
       // No need to join, as it will be joined automatically
   }
   ```

   In this example, the thread will run until the stop request is triggered after 3 seconds, and it will exit cleanly when 
   the stop is requested.

3. **Passing Arguments:**
   `std::jthread` can take a function or callable object just like `std::thread`, but it also allows for simpler passing of 
   arguments because it automatically handles the threading arguments internally.

   ```cpp
   #include <iostream>
   #include <thread>

   void print_message(const std::string& msg) {
       std::cout << msg << std::endl;
   }

   int main() {
       std::jthread t(print_message, "Hello from jthread!");  // Arguments are passed like std::thread
   }
   ```

4. **No Need for `join()` or `detach()`:**
   Unlike `std::thread`, where you need to explicitly call `join()` or `detach()` to ensure proper thread termination, 
   `std::jthread` handles joining automatically when the thread object goes out of scope.

   - With `std::thread`, forgetting to call `join()` or `detach()` can lead to **undefined behavior** (e.g., program crash).
   - With `std::jthread`, this is avoided because the destructor ensures the thread is joined before the object is destroyed.

also note that jthread does not support detach()  function

5. **Cleaner Resource Management:**
   The automatic joining mechanism of `std::jthread` helps prevent resource leaks, making it more robust and less error-prone than 
   `std::thread`.

### Differences Between `std::thread` and `std::jthread`:

| Feature                     | `std::thread`               | `std::jthread`                      |
|-----------------------------|-----------------------------|-------------------------------------|
| **Automatic Joining**       | No, must call `join()` or `detach()` explicitly | Yes, automatically joins on destruction |
| **Cancellation Support**    | No                          | Yes, supports cooperative cancellation with `std::stop_token` |
| **Detachment**              | Must explicitly call `detach()` | No need to call `detach()`, manages itself |
| **Resource Management**     | Must manually manage joining or detachment | Automatically manages resource cleanup |
| **Argument Passing**        | Pass arguments to the thread function explicitly | Easier to pass arguments; handles them internally |


### Summary:
`std::jthread` is a higher-level thread abstraction introduced in C++20, designed to simplify thread management. 
It automatically joins the thread when it goes out of scope, supports thread cancellation, and makes working with threads safer 
and more convenient. It is often preferred over `std::thread` when you want to avoid manual resource management and leverage 
built-in cancellation mechanisms.






*/



// other topics realated to threads are 
#include"std_condition_variable.cpp"
#include"std_bind.cpp"








