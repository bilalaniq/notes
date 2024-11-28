// -----------------------------std::condition variable----------------------------
/*
A `std::condition_variable` is a synchronization primitive used in multi-threaded C++ programming to block one or more threads
until a particular condition is met. It allows threads to wait for certain events or conditions to be satisfied before proceeding. 
In other words, it lets a thread "sleep" until something happens, and then it is "notified" that it can continue. This is especially
useful when dealing with problems like producer-consumer, thread coordination, or managing access to shared resources.

Here is a **detailed explanation** of `std::condition_variable` in C++.

### **Overview of Condition Variable**

A **condition variable** allows threads to wait until they are notified by another thread. It is used in conjunction with a **mutex**
or **lock** to ensure that shared resources are accessed safely. The waiting thread(s) will **release the lock** on the mutex while they
are sleeping and will **re-acquire the lock** when they are notified.

### **Key Concepts**

1. **Mutex** (`std::mutex`): A mutex (short for mutual exclusion) is used to ensure that only one thread can access the shared
resource at a time. It prevents race conditions in concurrent programming.
   
2. **Condition Variable** (`std::condition_variable`): It allows threads to wait for some condition to become true before proceeding.
It is typically used to synchronize access to shared data or resources between threads.

3. **Locking**: A `std::condition_variable` works with a **mutex** to guarantee that when a thread waits on the condition variable, 
no other thread can modify the shared data.

4. **Notify**: Another thread can notify waiting threads about a condition change, allowing them to resume execution.

---

### **When to Use `std::condition_variable`**

- **Producer-Consumer Problem**: A common use case for a condition variable is when one thread (the producer) generates data and 
another thread (the consumer) processes that data. The consumer waits for the producer to produce data.
- **Thread Coordination**: When you need to synchronize threads based on some condition, like waiting for a task to complete before 
starting another.
- **Thread-safe signaling**: To signal threads to start, stop, or take action based on a certain event (such as signaling a worker 
thread that work is available).

---

### **Components of `std::condition_variable`**

1. **`wait()`**: This function is used by the thread to block itself and wait for the condition to be notified. When a thread calls 
`wait()`, it releases the mutex and goes into a blocked state until it is notified by another thread.
   
2. **`notify_one()`**: This function is used to wake up one of the threads that are waiting on the condition variable.
   
3. **`notify_all()`**: This function is used to wake up all threads that are waiting on the condition variable.

---

### **Usage Pattern**

- Threads that are waiting on a condition variable typically use `std::unique_lock<std::mutex>` (or `std::lock_guard<std::mutex>`) 
to lock the mutex while they are waiting.
- When the condition is met (usually by another thread), it notifies the waiting threads to wake up and resume execution.

The condition variable ensures that threads wait for a specific condition before proceeding, which is crucial for ensuring safe and 
orderly access to shared resources in multi-threaded programs.

---

### **Steps for Using a Condition Variable**

1. **Lock a Mutex**: Before calling `wait()`, a thread must hold a mutex to ensure exclusive access to the shared resource.
   
2. **Call `wait()` on the Condition Variable**: This will block the thread and release the mutex, allowing other threads to acquire
 the mutex and modify the shared data.
   
3. **Notify Other Threads**: Once the condition has been met (for example, a producer produces data), another thread will call 
`notify_one()` or `notify_all()` to wake up waiting threads.

---

### **Example: Producer-Consumer Problem Using Condition Variable**

The producer-consumer problem is a classic example of when to use `std::condition_variable`.

- The **producer** thread will produce data and push it into a shared queue.
- The **consumer** thread will wait for data to be available in the queue. When data is available, it will process it.
- If the queue is empty, the consumer will **wait** until the producer pushes new data into the queue.

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;                  // Mutex to protect the shared queue
std::condition_variable cv;      // Condition variable for synchronization
std::queue<int> dataQueue;       // Shared queue for storing data
bool done = false;               // Flag to indicate when to stop

void producer() {
    for (int i = 1; i <= 5; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
        std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex
        dataQueue.push(i);    // Produce data
        std::cout << "Produced: " << i << std::endl;
        cv.notify_one();      // Notify the consumer that data is available
    }

    // Notify the consumer to stop processing after production is complete
    {
        std::lock_guard<std::mutex> lock(mtx);
        done = true;
        cv.notify_one();
    }
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);  // Lock the mutex
        cv.wait(lock, [] { return !dataQueue.empty() || done; }); // Wait for data or stop signal

        if (done && dataQueue.empty()) {
            break;  // Exit when no more data is available
        }

        int data = dataQueue.front();
        dataQueue.pop();
        std::cout << "Consumed: " << data << std::endl;
    }
}

int main() {
    std::thread prod(producer);    // Start producer thread
    std::thread cons(consumer);    // Start consumer thread

    prod.join();  // Wait for producer to finish
    cons.join();  // Wait for consumer to finish

    return 0;
}
```

### **How It Works**

- **Producer**:
  - The producer thread produces an integer (simulated by `std::this_thread::sleep_for`) and pushes it into the shared queue.
  - After pushing data, the producer calls `cv.notify_one()`, notifying the consumer that new data is available.

- **Consumer**:
  - The consumer thread waits on the condition variable (`cv.wait(lock, []{ return !dataQueue.empty(); })`) until there’s data in
   the queue.
  - When data becomes available (via notification), the consumer consumes it.
  - The consumer also checks if the production is done (`done` flag) and exits when there’s no more data and production is complete.

---

### **Important Notes on `std::condition_variable`**

1. **Spurious Wakeups**: `std::condition_variable::wait()` may wake up without being notified (spurious wakeup). This is why you 
should always call `wait()` in a loop that checks the condition.
   
   ```cpp
   cv.wait(lock, []{ return !dataQueue.empty(); });
   ```
   This ensures that even if the thread wakes up without being notified, it will check the condition again and only proceed if 
   the condition is truly met.

2. **Mutex Ownership**: When calling `wait()`, the mutex is released to allow other threads to acquire the mutex and make progress.
 When the thread is notified, it re-acquires the mutex to continue execution.

3. **Notify Mechanism**:
   - `notify_one()` wakes up **one** thread waiting on the condition variable.
   - `notify_all()` wakes up **all** threads waiting on the condition variable.

   Typically, `notify_one()` is used to wake up a single thread, but if there are multiple threads waiting and you want to wake all
    of them, you can use `notify_all()`.

---

### **Conclusion**

- **`std::condition_variable`** is an essential tool in multi-threaded programming when you need to block threads until a certain 
condition is met, and then notify them when they can continue.
- It allows you to synchronize threads based on shared conditions, such as waiting for data to become available or a task to complete.
- When using `std::condition_variable`, you typically use it with `std::mutex` to ensure that access to shared data is synchronized 
and thread-safe.

By using `std::condition_variable`, you can write more efficient and robust multi-threaded programs, especially when you need to 
coordinate tasks across multiple threads in a controlled manner.







*/