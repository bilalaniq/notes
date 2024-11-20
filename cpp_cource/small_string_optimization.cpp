// ------------------------small_string_optimization-----------------
/*
Small String Optimization (SSO) is a technique used in C++ to optimize the storage and performance of small strings by avoiding 
dynamic memory allocation for them. Here's an overview of how SSO works, its benefits, and a typical implementation strategy.

### What is Small String Optimization?

- **Concept**: Instead of always allocating memory on the heap for strings, a string class can internally use a small buffer 
to store short strings directly within the object itself. This reduces memory allocation overhead and improves performance for 
small strings.
  
- **Implementation**: If the string fits within this internal buffer, it uses it; otherwise, it falls back to dynamic memory allocation.

### Benefits of SSO

1. **Performance**: Reduces the number of heap allocations for small strings, leading to faster string creation and manipulation.
  
2. **Memory Efficiency**: Helps avoid fragmentation and overhead associated with heap memory management.

3. **Cache Locality**: Since small strings are stored inline, they can benefit from better cache performance.

### Example Implementation

note that this is an example which to some extent shows the abckend working of sso in string library

Here’s a simple example of how you might implement a string class with Small String Optimization:

```cpp
#include <iostream>
#include <cstring>

class SmallString {
public:
    static constexpr size_t SSO_SIZE = 15; // Size of the small string buffer

    SmallString() : is_small(true) {
        data.small[0] = '\0'; // Initialize to empty
    }

    SmallString(const char* str) {
        size_t len = strlen(str);
        if (len < SSO_SIZE) {
            is_small = true;
            strcpy(data.small, str);
        } else {
            is_small = false;
            data.large = new char[len + 1];
            strcpy(data.large, str);
        }
    }

    ~SmallString() {
        if (!is_small) {
            delete[] data.large;
        }
    }

    const char* c_str() const {
        return is_small ? data.small : data.large;
    }

    // Copy constructor
    SmallString(const SmallString& other) {
        if (other.is_small) {
            is_small = true;
            strcpy(data.small, other.data.small);
        } else {
            is_small = false;
            size_t len = strlen(other.data.large);
            data.large = new char[len + 1];
            strcpy(data.large, other.data.large);
        }
    }

    // Copy assignment
    SmallString& operator=(const SmallString& other) {
        if (this != &other) {
            if (!is_small) {
                delete[] data.large;
            }
            if (other.is_small) {
                is_small = true;
                strcpy(data.small, other.data.small);
            } else {
                is_small = false;
                size_t len = strlen(other.data.large);
                data.large = new char[len + 1];
                strcpy(data.large, other.data.large);
            }
        }
        return *this;
    }

private:
    union Data {
        char small[SSO_SIZE + 1]; // +1 for null terminator
        char* large;
    } data;

    bool is_small; // True if small string is being used
};

int main() {
    SmallString str1("Hello, World!"); // Uses SSO
    SmallString str2("This is a longer string that will not fit."); // Allocates on heap

    std::cout << str1.c_str() << std::endl; // Outputs: Hello, World!
    std::cout << str2.c_str() << std::endl; // Outputs: This is a longer string that will not fit.

    return 0;
}
```

### Key Components of the Example

1. **Union for Storage**: The `Data` union stores either a small array for short strings or a pointer to dynamically allocated 
memory for longer strings.

2. **Size Check**: The constructor checks the length of the input string to decide whether to use the small buffer or allocate 
memory on the heap.

3. **Memory Management**: The destructor ensures that dynamically allocated memory is freed.

4. **Copying Logic**: The copy constructor and assignment operator handle copying correctly, managing the transition between small 
and large strings.

### Conclusion

Small String Optimization is a powerful technique in C++ that improves performance and memory usage for small strings. 
By combining inline storage for small strings with dynamic allocation for larger ones, you can achieve efficient string management.

*/



// --------------------------------?????????????????????????-------------------------
/*
this is the actual backend of ssc in the std::string 

_CONSTEXPR20 basic_string& assign(
    _In_reads_(_Count) const _Elem* const _Ptr, _CRT_GUARDOVERFLOW const size_type _Count) {
    // assign [_Ptr, _Ptr + _Count)
    if (_Count <= _Mypair._Myval2._Myres) {
        _ASAN_STRING_REMOVE(*this);
        _Elem* const _Old_ptr   = _Mypair._Myval2._Myptr();
        _Mypair._Myval2._Mysize = _Count;
        _Traits::move(_Old_ptr, _Ptr, _Count);
        _Traits::assign(_Old_ptr[_Count], _Elem());
        _ASAN_STRING_CREATE(*this);
        return *this;
    }

    return _Reallocate_for(
        _Count,
        [](_Elem* const _New_ptr, const size_type _Count, const _Elem* const _Ptr) _STATIC_CALL_OPERATOR {
            _Traits::copy(_New_ptr, _Ptr, _Count);
            _Traits::assign(_New_ptr[_Count], _Elem());
        },
        _Ptr);
}

yes very scary but if you look carefully you will find out that the there is an if condition if the _count which is the length of the 
string is smaller then then or equal to _Mypair._Myval2._Myres it will allcate string on memory where if not then the string will
be allocted on the heap by using an reallocate function 

now lets talk about the _Myres ellment what is this 
this is an size_t that stores the no of length that is limmited for an string to be created on the stack
_Mypair._Myval2._Myres = _BUF_SIZE - 1;

where is _BUF_SIZE is an const expression which is 16 
so if we substract 1 we will get 15 which is the limmit for the string to be created on the stack 

so if i create an string having length equal to or less than 15 it will be created on the stack where if its length is greater than the
15 it will be created dynamically

*/


// -------------------------------note---------------------------------
/*
note that at debug mode all the string will allocate dyanmic memory even if it is under the limit but in release mode it will not allocate
dynamically 
also note that if the string is above the limit then then string will be dynamic allocated twice this is beacase of debug mode

#include<iostream>
#include<string>

void* operator new(size_t size)
{
	std::cout << "allocated memory " << size << "\n";
	return malloc(size);
}

int main()
{
	std::string name = "muhammad bilal";
	
}

this will not allocate dynamically 

int main()
{
	std::string name = "muhammad bilal aniq ";
	
}

this will dynamic allocate memory memory 




lets talk about the result in debug and release mode 
have a look for
int main()
{
	std::string name = "muhammad bilal aniq ";	
}

this will obviouslly allocate dynamic memory
but for debug mode it will allocate two memory on heap 

----debug result 
allocated memory 8
allocated memory 32

----release result
allocated memory 32


this is beacasue In debug mode, the compiler includes additional information and checks to help catch errors like memory 
corruption, buffer overflows, and other issues during development. This mode might allocate extra memory for tracking purposes,
including padding around objects to catch potential problems, or allocate smaller memory chunks during intermediate steps of 
program execution.

*/