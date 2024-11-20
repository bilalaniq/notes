// ---------------------------implicit convertion or construction and explicit keyword------------------------------
/*

-------------------------------implicit conversion-------------------------------------
implicit mean automatic to some extent
compilers are allow to perform implicit conversion on you code
implicit convertion converts one type of data type to another but it should not be confused with casting which is done by the programer
where the implicit convertion is done by the compiler

note that a compiler will do impicit conversion once on an line

example:
class entity
{
    int a;
    string name;
public:
    entity() : a(-1), name("unknown") {}
    entity(const string _name) : a(-1), name(_name) {}
    entity(const int no) : a(no), name("unknown") {}
    friend void print( const entity &e0);
};
void print(const entity &e0)
{
    cout << e0.name << " " << e0.a << endl;
}
int main()
{
    entity e1 = string("bilal");      or     entity e1 = entity("bilal");
    entity e2 =  21;

    print(21);
    print(string("hey"));             or     print(entity("hey"));

    return 0;
}


here see that e1 = string("bilal") and e2 = 21 which seem quit weired as e1 and e2 are nor string or int but  the compiler is implicitly
converting them to an entity object
here you can see that i have used string keyword this is beacause the as "bilal" is an array of char as it but it should be string
so the compiler converts its into string but as i hve said that the compiler only can do one implicit convertion on one line but the
string should be converted to entity so this is why i have used string to convert char array to string which is then implicitly converted
to entity class object
or i could also do is
    entity e1 = entity("bilal");
to convert it into entity class where the compiler will convert the char array to string implicitly


again you can see print(21) and  print(string("hey")); which is also odd as the parameter need const entity object
but again it is due to the implicit convertion magic which converts other data types to another

*/
// if you wannt to learn about string then click here 
#include"string.cpp"


// -------------------------------------------------explicit-------------------------------------------
/*
explicit means manual to some extent
In C++, the explicit keyword is used to specify that a constructor or conversion function cannot be used for implicit conversions.
When a constructor or conversion function is marked as explicit, it means that the compiler will not automatically 
use it to perform implicit type conversions.

example:
class entity
{
    int a;
    string name;

public:
   explicit entity() : a(-1), name("unknown") {}
   explicit entity(const string _name) : a(-1), name(_name) {}
   explicit entity(const int no) : a(no), name("unknown") {}

    friend void print( const entity &e0);
};
void print(const entity &e0)
{
    cout << e0.name << " " << e0.a << endl;
}
int main()
{
    entity e1 = string("bilal");   this will show error as there is implicit convertion which is ristricted so the solution is
    entity e1("bilal");
   
    entity e2 =  21;   it should be 
    entity e2(21);

    print(21);    it should be 
    print(entity(21));

    print(string("hey"));   it should be 
    print(entity("hey"));    

    return 0;
}



explicit is not very used function it is rarely used like when dealing with math libraries
like when you donot want t compare nos with vectors and you want to ensure that your code is safe as posssible
*/


//so the summery is that be aware that implicit convertion exist 
// if you want to learn about casting you can click here 
#include"casting.cpp"

