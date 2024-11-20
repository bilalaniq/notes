//---------------------------------------initializing a struct or a class -----------------------------
// there are 4 ways of initilizing a struct or a class

/*
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Initializer Lists in Constructor:

struct Point {
    int x;
    int y;
    Point(int a, int b) : x(a), y(b) {}
};
Point p(10, 20);

note that the member variable should be placed in initilization list with order for example you should initilize x first and then y
as some compiler may give error

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Aggregate Initialization:

struct Point {
    int x;
    int y;
};
Point p = {10, 20};

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Default Member Initialization:
struct Point {
    int x = 10;
    int y = 20;
};
Point p; // Members x and y are initialized with default values

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Member-wise Initialization:
struct Point {
    int x;
    int y;
};
Point p;
p.x = 10;
p.y = 20;


>>>>>>>>>>>>>>>>>> combination of both initilization list and Default Member Initialization
struct Point {
    int x;
    int y;
    Point(int a = 10, int b = 10) : x(a), y(b) {}
};
Point p(10, 20);

in this if we donot provide any values forexample
Point p;

so the default values will be used




*/

// -----------------------------------------?????????????????????????????????????????-------------------------------------
/*
---------------------------------why always use initilization list-------------------------------------
you should always consider using initilization list not beacause to make you code more readable but beacause there is another reason
and that reason is that it help to prvent duplication of an object when initilization and makes code more efficient and fast


the example below show how the initilization list help us prevent aditional object creation

*/
#include <iostream>
using namespace std;
class example
{
public:
    example()
    {
        cout << "printed entity" << endl;
    }
    example(int x)
    {
        cout << "printed entity with " << x << endl;
    }
};
class entity
{
    string name;
    example exp; // first object made

public:
    entity(int x)
    {
        name = "unknown";
        exp = x; // or exp = example(10)   this is where is the error occurs as it is making another object and replacing the previously
        // made object by using initilization list we will be able to overcome this problem 
        //since exp is already an object of type example, this assignment is not directly possible.
        // compiler attempts to convert the integer 10 to an object of type example by using the constructor example(int), 
        //This results in the creation of a temporary example object using the constructor example(int) 
    }
    // solution:
               
        // entity(int x) : exp(x)          //this is safe because  directly initializes the exp member with the value 10.                   
        // {                               //This initialization syntax directly constructs the exp member object using the appropriate 
        //     name = "unknown";           //constructor (example(int) in this case).
        // }
    entity(const std::string _name) : name(_name)
    {
    }
};
int main()
{

    entity e0(10);
    return 0;
}


/*If you have a member variable example exp; declared in the entity class, it will indeed be initialized before the body of the 
constructor is executed. However, when you explicitly initialize it in the constructor's initialization list using exp(10), 
it will not create an additional object.*/


/*
When you use initialization lists in constructors, objects are initialized directly using constructors with 
provided arguments. In your case, when you use entity(): exp(10), it initializes the exp object directly with the
constructor example(10). This means only one object is created and initialized.

However, when you don't use initialization lists and instead initialize exp inside the constructor body like exp = 10;,
the following sequence of events occurs:

The default constructor of example is called to create the exp object.
Then, the assignment operator (operator=) of example is invoked with the argument 10. This essentially creates a temporary example 
object with 10 as an argument, and then assigns it to the existing exp object.
so there is an extra obj being created wich is useless so this is the reason why we use initilization list it is prefered

Using initialization lists is preferred because it directly initializes the member objects without going through additional 
steps like creating temporary objects and then assigning them. This can lead to better performance and cleaner code.


*/