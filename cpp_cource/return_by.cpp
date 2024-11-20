// --------------------------------------return by refrence/pointer/value---------------------------------------
/*
The choice between returning a reference, pointer, or value from a function depends on various factors such as the semantics 
of the function, the lifetime management of the returned object, and the efficiency of passing and returning objects. 
Here's a general guideline:

>>>>>>>>>>>>>>>>>>>>>>>Return by Value:
Use when returning a small and lightweight object, or when the returned object is a temporary result and not intended to be modified by the caller.
Avoids issues related to lifetime management as the returned object is a copy.
Can be less efficient for large objects or expensive-to-copy objects due to the overhead of copying.


>>>>>>>>>>>>>>>>>>>>Return by Reference:
Use when returning an existing object that already exists and is accessible within the scope of the function.
Useful when the returned object is part of the function's internal state or when the caller needs direct access to the original object.
Requires careful consideration of the object's lifetime to ensure that the returned reference remains valid after the function returns.


>>>>>>>>>>>>>>>>>>>>Return by Pointer:
Use when returning an object dynamically allocated on the heap or when returning an object that may not exist after the function returns.
Allows returning nullptr to indicate failure or absence of an object.
Requires manual memory management (allocation and deallocation) by the caller, which can lead to memory leaks or dangling pointers if not handled properly.
Consider using smart pointers (e.g., std::unique_ptr, std::shared_ptr) to manage the lifetime of dynamically allocated objects.
*/