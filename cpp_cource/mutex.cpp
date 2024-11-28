// ---------------------------------mutex----------------------------------
/*
A **mutex** (short for mutual exclusion) in C++ is a synchronization primitive used to protect shared resources from concurrent 
access by multiple threads. It ensures that only one thread can access a critical section of code at any given time, which prevents 
race conditions and ensures the consistency of shared data.

In C++, mutexes are part of the **Standard Library** (`<mutex>`), introduced in C++11 as part of the **thread support library** to 
facilitate multi-threading.

Here is a detailed explanation of **mutexes** in C++:

### 1. **Mutex Overview**

- **Purpose**: A mutex allows only one thread to lock it at a time, and other threads that attempt to lock it while it's locked will 
block until the mutex is unlocked.
- **Critical Section**: The part of the program where shared resources are accessed. Only one thread can execute this part of the code
 at any given time when mutex protection is in place.

### 2. **Types of Mutexes in C++**

There are several types of mutexes available in the C++ standard library, each suited for different use cases.

- **std::mutex**: A basic, general-purpose mutex.

- **std::recursive_mutex**: Allows the same thread to lock the mutex multiple times without causing a deadlock. It keeps track of
 how many times it has been locked by the same thread, and it must be unlocked the same number of times to release it.

In some cases, a thread might need to lock a mutex multiple times while it's already holding the same mutex. This is a situation 
that normal mutexes (std::mutex) cannot handle. Trying to lock a mutex that is already locked by the same thread causes a deadlock,
because the thread is waiting for itself to unlock the mutex, which will never happen.

- **std::timed_mutex**: A mutex that allows a thread to try to lock it with a timeout. It is useful if a thread wants to attempt 
locking a mutex and give up if it's not available within a specific time limit.

- **std::unique_lock**: This is not a mutex itself but a class that wraps a mutex to manage its locking and unlocking automatically, 
offering more flexibility than `std::lock_guard`.

- **std::shared_mutex** (C++17 and later): Allows multiple threads to acquire shared (read) locks concurrently but ensures that only 
one thread can acquire an exclusive (write) lock at a time.





### 3. **Basic Mutex Operations**

- **lock()**: Locks the mutex. If another thread has locked it, the calling thread will block until the mutex is unlocked.
- **try_lock()**: Attempts to lock the mutex. If it is already locked, it returns `false` immediately without blocking.
- **unlock()**: Unlocks the mutex. Only the thread that locked the mutex can unlock it. If a thread unlocks a mutex it hasn't locked,
 undefined behavior will occur.


let see an simple example which will give you an overview of why mutex are important 
suppose two friends want to drive an car but the problem is that only one can drive at a time 


void drivecar(std::string name)
{
	std::cout << name << " is driving \n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << name << " is done driving \n";
}
int main() {
	std::thread t1( drivecar,"bilal");

	std::thread t2(drivecar , "ali");

	t1.join();
	t2.join();
}
output:

bilal is driving
ali is driving
alibilal is done driving
 is done driving

this is wrong as both canot derive at the same time so lets fix this using mutex

std::mutex coutMutex;

void drivecar(std::string name)
{
    // Lock the mutex to ensure only one thread can access std::cout at a time
    std::lock_guard<std::mutex> lock(coutMutex); // Automatically locks and unlocks the mutex

    std::cout << name << " is driving \n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << name << " is done driving \n";
}

int main() {

    // Create threads with drivecar function and string arguments
    std::thread t1(drivecar, "bilal"); // Pass the function and argument
    std::thread t2(drivecar, "ali");   // Pass the function and argument

    t1.join();  // Wait for t1 to finish
    t2.join();  // Wait for t2 to finish

    return 0;
}


-----------------------------------------Mutex Locking Techniques-----------------------------------
--------------------std::lock_guard<std::mutex>----------------------------
The mutex is automatically locked when the std::lock_guard is created and automatically unlocked when it goes out of scope.
When to Use: Use std::lock_guard for simple and straightforward synchronization where you want the mutex to be locked and unlocked automatically

std::mutex mtx;

void someFunction() {
    std::lock_guard<std::mutex> lock(mtx);
    // Critical section here
    // Mutex is automatically unlocked when 'lock' goes out of scope
}

Correct, std::lock_guard does not allow manual unlocking. here come the std::unique_lock which can be unlocked manually

----------------------------std::unique_lock<std::mutex>-------------------------------------
std::unique_lock is more flexible than std::lock_guard. It provides the same basic functionality (locking and unlocking a mutex),
but it gives you more control over the lock. You can lock, unlock, and re-lock the mutex at any time during its lifetime.
When to Use: Use std::unique_lock if you need more flexibility, such as manually unlocking and re-locking the mutex, or if you 
need to work with condition variables (which require std::unique_lock).

it is automatiically unlocked after its life scopes end

std::mutex mtx;

void someFunction() {
    std::unique_lock<std::mutex> lock(mtx);
    // Critical section here
    
    // You can unlock the mutex manually if needed
    lock.unlock();
    
    // Do some work that doesn't need the lock
    
    // Re-lock the mutex when necessary
    lock.lock();
}

----------------------------std::shared_lock<std::shared_mutex>--------------------------------
std::shared_lock is used in conjunction with std::shared_mutex, which allows multiple threads to hold a shared lock concurrently
(i.e., for reading), but only one thread can hold an exclusive lock (for writing) at a time. This is useful when you 
have data that can be read concurrently but should only be modified by one thread at a time.

When to Use: Use std::shared_lock when you need multiple threads to be able to read shared data concurrently, but still need exclusive access for writes.

std::shared_mutex mtx;

void readFunction() {
    std::shared_lock<std::shared_mutex> lock(mtx);
    // Read data safely
}

void writeFunction() {
    std::unique_lock<std::shared_mutex> lock(mtx);
    // Modify data safely
}

this feature is only available in c++17

----------------------------Manual Locking with mutex.lock() and mutex.unlock()------------------------
You can manually lock and unlock a mutex by calling lock() and unlock() directly. This method gives you full control over when the 
mutex is locked and unlocked, but it comes with the risk of forgetting to unlock the mutex or causing deadlocks.

When to Use: This approach is less common because std::lock_guard and std::unique_lock are safer and more idiomatic. 
However, it might be needed if you want complete manual control over locking/unlocking (e.g., in complex algorithms where you
need to perform multiple locking operations).

std::mutex mtx;

void someFunction() {
    mtx.lock();
    // Critical section here
    mtx.unlock();
}

-----------------------------std::lock() (for locking multiple mutexes)------------------------------------
std::lock() is a utility function that can be used to lock multiple mutexes at once without causing deadlocks. It is used
in scenarios where you need to lock multiple mutexes, but you want to avoid the possibility of a deadlock 
(e.g., locking mutexes in different orders).

When to Use: Use std::lock() when you need to lock more than one mutex at a time and want to prevent deadlocks by ensuring the 
mutexes are locked in a safe order.

std::mutex mtx1, mtx2;

void someFunction() {
    std::lock(mtx1, mtx2);  // Lock both mutexes at the same time
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);

    // Critical section here
}





lets now see some examples of mutex

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void printNumbers(int threadId) {
    mtx.lock();  // Lock the mutex to ensure exclusive access
    std::cout << "Thread " << threadId << " is printing numbers." << std::endl;
    mtx.unlock();  // Unlock the mutex after work is done
}

int main() {
    std::thread t1(printNumbers, 1);
    std::thread t2(printNumbers, 2);

    t1.join();  // Wait for t1 to finish
    t2.join();  // Wait for t2 to finish

    return 0;
}
```

In this example, the mutex `mtx` is used to ensure that only one thread can access the critical section (printing to the console)
at a time.

#### 4.2. **Using lock_guard**

A **`std::lock_guard`** is a RAII (Resource Acquisition Is Initialization) wrapper around a mutex. It automatically locks the mutex
when created and unlocks it when it goes out of scope, reducing the chances of forgetting to unlock the mutex.

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void printNumbers(int threadId) {
    std::lock_guard<std::mutex> lock(mtx);  // Automatically locks the mutex
    std::cout << "Thread " << threadId << " is printing numbers." << std::endl;
}

int main() {
    std::thread t1(printNumbers, 1);
    std::thread t2(printNumbers, 2);

    t1.join();  // Wait for t1 to finish
    t2.join();  // Wait for t2 to finish

    return 0;
}
```

With `std::lock_guard`, you don't have to worry about unlocking the mutex manually; it will be unlocked automatically when the 
`lock_guard` object goes out of scope.

#### 4.3. **Using unique_lock**

A **`std::unique_lock`** is more flexible than `std::lock_guard`. It allows manual locking and unlocking, and it also supports 
features like lock management and timed locks.

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void printNumbers(int threadId) {
    std::unique_lock<std::mutex> lock(mtx);  // Locks the mutex
    std::cout << "Thread " << threadId << " is printing numbers." << std::endl;
    // The mutex will be unlocked automatically when `lock` goes out of scope
}

int main() {
    std::thread t1(printNumbers, 1);
    std::thread t2(printNumbers, 2);

    t1.join();
    t2.join();

    return 0;
}
```

### 5. **Deadlocks and Avoiding Them**

A **deadlock** occurs when two or more threads are blocked forever, each waiting for a resource that is locked by another thread
. For example:

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx1;
std::mutex mtx2;

void task1() {
    mtx1.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    mtx2.lock();  // Deadlock occurs if task2 locks mtx2 first
    std::cout << "Task 1 is done." << std::endl;
    mtx1.unlock();
    mtx2.unlock();
}

void task2() {
    mtx2.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    mtx1.lock();  // Deadlock occurs if task1 locks mtx1 first
    std::cout << "Task 2 is done." << std::endl;
    mtx2.unlock();
    mtx1.unlock();
}

int main() {
    std::thread t1(task1);
    std::thread t2(task2);

    t1.join();
    t2.join();

    return 0;
}
```

#### To Avoid Deadlocks:
- **Lock ordering**: Always lock mutexes in a consistent order across all threads.
- **std::lock**: Use `std::lock` to lock multiple mutexes simultaneously, avoiding deadlocks.

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx1;
std::mutex mtx2;

void task1() {
    std::lock(mtx1, mtx2);  // Lock both mutexes simultaneously
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);  // Avoid double-locking
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);
    
    std::cout << "Task 1 is done." << std::endl;
}

void task2() {
    std::lock(mtx1, mtx2);
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);

    std::cout << "Task 2 is done." << std::endl;
}

int main() {
    std::thread t1(task1);
    std::thread t2(task2);

    t1.join();
    t2.join();

    return 0;
}
```


if you want to lock more than one mutex use std::lock where do not use std::lock_guard as it Does not prevent deadlocks 
(single mutex handling).

### 6. **Summary of Mutex Use in C++**
- **Mutexes** protect shared resources by allowing only one thread to access a critical section at a time.
- Use **`std::mutex`** to lock and unlock critical sections.
- For simple cases, **`std::lock_guard`** and **`std::unique_lock`** are recommended for automatic locking and unlocking.
- Be aware of **deadlocks**, and use consistent locking order or **`std::lock`** to avoid issues when locking multiple mutexes.








*/