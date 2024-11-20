// -------------------------------------------string-----------------------------------------------
/*
a "string" is a sequence of characters, typically used to represent text.
it is basically a group of chracters or array of chracters


cosnt char* name = "bilal";
this is the way of representing a string in c
here is its memory view
0x0089DEE0  62 69 6c 61 6c  00
the last  00 is called null termination chracter through this we know where a string ends
we can not know the size of the string through this the compiler know where the string has end

if we make string manually using char and do not put null termination chracter out compiler will print 
more than just the string   
char name2[5] = { 'b' ,'i','l','a','l' };
cout << name << endl;
here i have created a string manually 
output is bilal╠╠╠╠╠╠╠╠╠╠╠0█
you can see the junk values which are printed because there i no null terminator chracter

char name2[6] = { 'b' ,'i','l','a','l','\0'};
cout << name << endl;
but if i use \0(or you could also use simple 0 int) wich is bacically the null terminator chracter which also needs an space in the array so this is why i have 
used 6
the memory is 
0x0089DEE0  62 69 6c 61 6c  CC CC CC
as you can see that there is no null terminator chracter 00 
wher the CC are this is beacause when we are in debuging mode the compiler replace every thing with cc


-------------------------------types of string -------------------
these are the types of the string 

1. **C-style strings (Null-terminated strings):**
- C++ inherited C-style strings, which are arrays of characters terminated by a null character (`'\0'`). They are declared as arrays 
of characters (`char[]`) and manipulated using functions from `<cstring>` (or `<string.h>` in C). For example:
     char str[] = "Hello";

note that if you are dealing with any 

2. **String literals:**
- String literals are constant character arrays. They are used directly in the code and are typically enclosed in double quotes 
(`"`). In C++, they have type `const char[]`. For example:
     char* str = "Hello";

the main difference between C-type string and the string literals is that you can modify C-sring by using 
str[0] = 'b';
where the string literals are imutable meaning you canot modify them they are only for read only



3. **`std::string` from the C++ Standard Library:**
- `std::string` is a modern and flexible string type provided by the C++ Standard Library (`<string>`). It provides a wide range of 
operations and is managed dynamically, which means it handles memory allocation and resizing automatically. `std::string` is the 
preferred string type in C++ for most applications due to its safety and convenience. For example:
     std::string s = "Hello";

it has an constructor which takes an const char array and then convert it into string object
if you hover the mouse over the "Hello" you will se an const char array where s is the string obj


4. **Wide strings (`std::wstring`):**
- `std::wstring` is similar to `std::string`, but it stores wide characters (`wchar_t`), which are typically used for Unicode or 
multibyte characters. It is defined in `<string>` and provides operations suited for wide characters. For example:
     std::wstring ws = L"Hello";
    

5. **Raw string literals (C++11 and later):**
- Raw string literals allow you to define strings without escaping special characters. They are enclosed in `R"(` and `)"`, where 
`(` and `)` can be replaced by any delimiter. Raw string literals are particularly useful for writing regular expressions or strings 
that contain a lot of escape sequences. For example:
     std::string regex = R"(\d{3}-\d{2}-\d{4})";

Each type of string in C++ has its own advantages and use cases, so the choice depends on the specific requirements of your program, 
such as performance considerations, manipulation needs, or compatibility with external libraries.
*/




// -------------------------------------------??????????????????????????//--------------------------------
/*
note that if you are passing string to a function donot use passby value rather passit by refrence or pointer as the string coping 
takes time and is slow
for example :
consider an function which take an string as an parameter 

void function(std::string s)
{
cout << s << endl;
}

this is not recommended as a copy of string is being created which is slow  because when we copy an string a new char array is created on
heap to store that same text 
and also if you modify the string it will not effect the string in the main code 

so the solution to this problem is to pass the string through refrence 
void function(cont std::string &s)
{
cout << s << endl;
}

to learn why i have used const click here to learn
*/
#include"const.cpp"



//if you want to learn about string class and how they work click here 
#include"string_class.cpp"


//string does dynamic alloction which is slow if you want to make you string faster click here
#include"std_string_view.cpp"