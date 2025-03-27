# .init, .ctors, .init_array & .finit_array

in this section we will be talking about `.init, .ctors, .init_array & .finit_array` and how they works

In C++, dynamic initializations for non-local variables happen before the first statement of the main function. All (most?) implementations just ensure such dynamic initializations happen before main.

As an extension, GCC supports `__attribute__((constructor))` which can make an arbitrary function run before main. A constructor function can have an optional priority `(__attribute__((constructor(N))))`.

Priorities from 0 to 100 are reserved for the implementation (-Wprio-ctor-dtor catches violation), e.g. gcov uses `__attribute__((destructor(100)))`. Applications can use 101 to 65535. 65535 (.init_array or .ctors, without a suffix) has the same priority as a non-local variable's dynamic initialization in C++.

we have already talked about the [attribute](../__attribute__/Readme.md) and [constructor & distructor](../c_con_&_dis/Readme.md)




> **Note:**
> On ELF platforms, initialization functions (constructors) are implemented using two schemes:
>
> - **Legacy approach**: Uses `.init` / `.ctors` sections.
> - **Modern approach**: Uses `.init_array`.
