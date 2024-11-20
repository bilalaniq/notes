// -----------------------------------multiple return values-----------------------------
/*
by default in cpp we canot return multiple values at a time but this can be accieved
where in python you can return multiple return values


first way is to pass the variables by parameter to the function by refrence or as a pointer
example
#include <iostream>
using namespace std;

void function(int &outA, string &outB)
{
    outA = 10;
    outB = "bilal";
}

int main()
{

    int a;
    string b;

    function(a, b);
    cout << a << b << endl;

    return 0;
}

here you can see that you are assigniing multiple values using one function it may not be tecnically multiple return but does
the same work that is one way to do this and it may be the most optimal way yes there are many issues with this but performence wise it
is good

anothere way you can use it is by using pointers by using pointers you have the choice to assighn only one or multiple variables
example
#include <iostream>
using namespace std;

void function(int *outA, string *outB)
{
    if (outA)
        *outA = 10;
    if (outB)
        *outB = "bilal";
}

int main()
{

    int a;
    string b;

    function(nullptr, &b);     here you can pass the a(int) variable adress if you want to assign it
    cout << a << "  " << b << endl;

    return 0;
}



secound way to overcome this problem you can do is that make the vector or the array of the return values but when the return 
variable are different it can be a problem for you we can return integer or string but canot return both 
but that is still not the best thing to do for few reason we will cheak out in a minute


example 
#include <iostream>
using namespace std;

string *function()
{
    std::string *arr = new std::string[2];
    arr[0] = "hello";
    arr[1] = "world";
    return arr;
}

int main()
{

    std::string *strArray = function();
    std::cout << strArray[0] << " " << strArray[1] << std::endl;

    delete[] strArray;

    return 0;
}

by using this you can return multiple varibles but there are still problem with this you can also make code more in cpp by returning
std array

#include <iostream>
#include <array>
using namespace std;

std::array<string, 2> function()
{
    std::array<string, 2> arr;
    arr[0] = "hello";
    arr[1] = "world";
    return arr;
}

int main()
{

    std::array<string, 2> strArray = function();
    std::cout << strArray[0] << " " << strArray[1] << std::endl;

    return 0;
}

this code is more efficient because the std::array is maneged and we donot have to use new and delete

another way is to use vector 

#include <iostream>
#include <vector>

using namespace std;

std::vector<string> function()
{
    std::vector<string> arr; 
    arr.push_back("hello");   
    arr.push_back("world");
    return arr;
}

int main()
{
    std::vector<string> strArray = function();
    std::cout << strArray[0] << " " << strArray[1] << std::endl;

    return 0;
}

but the only difference between the vector and std::array is that array is stored in struct where the vector is stored in heap so the 
array is tecnically faster then the vector

but the main problem with the vector and array is that you can only store data of same type to overcome this problem you need t0
use tuple and pair
if you want to learn about tuple and pair click here
*/
#include"tupple.cpp"
#include"pair.cpp"

/*
but note that the pair by its name can only have only two variables where the tuples can have many variables

#include <iostream>
#include <tuple>
using namespace std;

std::tuple<int, string, string> function()
{
    std::tuple<int, string, string> t1 = make_tuple(1, "bilal", "aniq");
    return t1;
}

int main()
{
    std::tuple<int, string, string> t1 = function();
    return 0;
}


#include <iostream>
#include<utility>
using namespace std;

std::pair<int, string> function()
{
    std::pair<int, string> p1 = make_pair(1, "bilal");
    return p1;
}

int main()
{
    std::pair<int, string> p1 = function();
    return 0;
}

if you add more than two variables in pair you will get error 






------------------------------by using structs(recumended)/class------------------------
another way to return to return multiple values through a struct or a class but the struct will be more recommended as by default the data
variable are public unlike class which has private member variable by default

#include <iostream>
using namespace std;

struct return_values
{
    string value1;
    int value2;
};

return_values function()
{
    return {"bilal", 20};
}

int main()
{
    return_values r1 = function();
    cout << r1.value1 << endl;
    cout << r1.value2 << endl;
    return 0;
}

by using struct you can return multiple values


*/
// ---------------------------------------STRUCTURED BINDINGS---------------------
//accessing the variables from  tuple , pair and struct can be complex and can make our code complex and less readable so 
//structur binding is an way to make our code more readable and less complex
#include"STRUCTURED_BINDINGS.cpp"
//note that structure binding is only supportive on c++17



