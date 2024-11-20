// ----------------------RTTI(runtime type information) vs CTTI(compiletime type information)-------------------------------------
/*
Certainly! Here’s a comparison of compile-time type information versus runtime type information (RTTI) 
____________________________________________________________________________________________________________________________________________________
| Feature                        | Compile-Time Type Information                        | Runtime Type Information (RTTI)                          |
|--------------------------------|------------------------------------------------------|----------------------------------------------------------|
| **Type Checking**              | Performed during compilation                         | Performed during program execution                       |
| **Usage**                      | Used with `static_cast` and compile-time checks      | Used with `dynamic_cast` and `typeid` for dynamic checks |
| **Efficiency**                 | No runtime overhead; checks done at compile time     | Incurs runtime overhead due to type checks and metadata  |
| **Type Safety**                | Checked at compile time; errors detected early       | Checked at runtime; safe casting if types are compatible |
| **Requirement**                | No special requirements; works with non-polymorphic  | Requires polymorphic classes                             |
|                                | classes                                              | (base class must have virtual functions)                 |
| **Flexibility**                | Limited to known types at compile time               | Handles unknown types at runtime                         |
| **Type Conversion**            | `static_cast` for conversions between related types  | `dynamic_cast` for safe downcasting with runtime checks  |
| **Error Handling**             | Compile-time errors if cast is invalid               | Returns `nullptr` for invalid casts with `dynamic_cast`  |
| **Example**                    | `Derived* d = static_cast<Derived*>(basePtr);`       | `Derived* d = dynamic_cast<Derived*>(basePtr);`          |
| **Type Information Retrieval** | Not applicable; relies on compile-time type knowledge| `typeid` for retrieving type information at runtime      |
| **Typical Use Case**           | When you know the types and their relationships at   | When dealing with polymorphism and the exact type is     |
|                                | compile time                                         | not known at compile time                                |
|__________________________________________________________________________________________________________________________________________________|

### Summary

- **Compile-Time Type Information** is used when types are known and fixed at compile time. It is efficient but limited in flexibility 
and requires that all type relationships be established before the program runs.

- **Runtime Type Information (RTTI)** provides the ability to work with types that are not fully known until the program is running, 
offering more flexibility at the cost of some runtime overhead and requiring polymorphic base classes.


lets see an example where the CTTI fails and RTTI is required 

base * b = new derived();

In summary, while the compiler knows about the type relationships and ensures type safety at compile time, the exact runtime type of the 
object is managed dynamically and requires RTTI to be determined and handled effectively.


*/

//----------------------------??????????????????????????????-----------------------------
/*
you may be asking why dynamic casting requires an polymorphic class(having atleast one virtual function) 

RTTI and Virtual Tables:

Virtual Table (Vtable): When a class has virtual functions, the C++ compiler generates a virtual table for that class. The vtable is a data 
structure that holds pointers to the virtual functions of the class.

Vtable Pointer: Each object of a polymorphic class contains a pointer to its class’s vtable. This pointer allows the program to determine the 
actual type of the object and call the correct virtual function at runtime.

Mechanism: To perform a dynamic_cast, the runtime system needs to access the vtable of the object to determine its actual type and verify
the validity of the cast. Without a vtable, the runtime system has no way of checking the actual type of the object.

RTTI relies on the vtable mechanism to provide type information at runtime. If a class does not have virtual functions, it does not 
have a vtable, and therefore the runtime system cannot provide information about its actual type.

Type Safety: dynamic_cast checks the actual type of the object and ensures that the cast is safe. This check involves accessing the vtable
to perform this validation. Without RTTI support, dynamic_cast cannot verify the correctness of the cast and will not work.

*/