// ----------------------------------getter & setter--------------------------------
/*
Getter and setter methods, also known as accessor and mutator methods
they are used to read and modify the private data members of a class, respectively. They provide controlled access 
to the private data members of a class while maintaining encapsulation, which is a fundamental principle of object-oriented design.
 */

// ----------------------------------------setter(mutators)-----------------------------------
/*
Setter methods are used to modify the values of private data members of a class
Setter methods typically have a void return type because they do not return any value
They often take one or more parameters corresponding to the new values to be assigned to the private data members.
Setter methods are declared as public member functions of a class if not then we may not be able to modify the private variables
seeter methods should not be declared as const member functions because they  modify the state of the object.
for example:
class example {
private:
    int a;
    int b;
public:
    void set_values(int x, int b) 
    {
        a = x;
        b = y;
    }
};
int main()
{
 example obj;
 obj.set_values(10,20);
}
*/
// ----------------------------------------getter(accessor)-----------------------------------
/*
getter are used to retrieve the values of private data members.
Getter methods typically have a return type corresponding to the type of the data member being retrieved.
They do not take any parameters because they do not modify the state of the object.
Getter methods are often declared as public member functions of a class 
Getter methods should be declared as const member functions if they do not modify the state of the object.


for example:
class example {
private:
    int a;
public:
    int gettter() 
    {
        return a
    }
};
int main()
{
 example obj;
 cout << obj.getter() << endl;
}
*/
