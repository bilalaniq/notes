// ---------------------------------operator overloading ----------------------------------
/*
Operator overloading in C++ allows you to redefine the behavior of operators when they are used with
user-defined types (classes and structures).
When an operator is overloaded for a class or structure, you provide a custom implementation for that operator.
Overloaded operators can be member functions or friend functions.
Some operators can only be overloaded as member functions (e.g., assignment operators =, subscript operator [], function call operator ()).
You can overload most binary and unary operators.


syntax:
return_type operator + (parameters) {
    // Custom implementation
}

-------------------------------difference between  binary and unary operators overloading-----------------------------------

-------------------------------binary operators overloading-----------------------------------
Binary operators include +, -, *, /, %, ==, !=, <, >, <=, >=, &&, ||, &, |, ^, <<, >>, etc.
Binary operators work with two operands.    
Binary operator overloading requires two arguments, representing the left and right operands.
Binary operator overloading can be implemented as a member function or a friend function of the class.

example:

class MyClass {
private:
    int value;
public:
    MyClass(int val = 0) : value(val) {}

    MyClass operator+(const MyClass& other) const {
        MyClass result;
        result.value = this->value + other.value;
        return result;
    }
    void display() {
        cout << "Value: " << value << endl;
    }
};
int main() {
    MyClass obj1(5);
    MyClass obj2(10);
    MyClass sum = obj1 + obj2;

    sum.display(); // Output: Value: 15
    return 0;
}



it works with two oprands here are obj1 and obj2 the overloaded oprator needs only one parameter but it should require two 
so the ans is that the left oprend always calls the oprator and the right side oprator is passed to the operator as a parameter 



-------------------------------unary operators overloading-----------------------------------
Unary operators include ++, --, -, +, !, ~, *, &, etc.
Unary operators work with a single operand.
Unary operator overloading requires only one argument, which is the operand on which the operator acts
Unary operator overloading can be implemented as a member function or a friend function of the class.

when dealing with increment and deincrement you will come across a problem 

-----------------------------prefix & postfix-------------------------------------- 
----------------------------prefix------------------
Prefix increment (++x) and decrement (--x):
These operators first increment or decrement the value of the operand and then return the updated value.

----------------------------postfix------------------
Postfix increment (x++) and decrement (x--):
These operators first return the current value of the operand and then increment or decrement the value.


>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>code

class Counter {
private:
    int count;
public:
    Counter(int c = 0) : count(c) {}

    Counter& operator++() {
        ++count;
        return *this;
    }

    Counter operator++(int & count) {
        Counter temp(*this); // Create a copy of the current object
        ++count;             // Increment the current object
        return temp;         // Return the copy (before increment)
    }

    void display() {
        cout << "Count: " << count << endl;
    }
};
int main() {
    Counter c(5);

    cout << "Prefix Increment:" << endl;
    ++c; // Prefix increment
    c.display(); // Output: Count: 6

    cout << "Postfix Increment:" << endl;
    c++; // Postfix increment
    c.display(); // Output: Count: 7

    return 0;
}


----------------------------------------overloading insertion/output oprator-----------------------------
<< Operator: Typically used for outputting data to streams, such as std::cout or std::ofstream.
Typically returns a reference to the output stream (std::ostream&).
It is usually implemented as a friend function of the class whose objects are being outputted. 
It takes an output stream (std::ostream) as its left operand and the object to be outputted as its right operand.

note that this oprator is diifernt then other oprator overloading beacause this oprator cannot be the member function of a class 
whose object it is going to print because 
The << operator is a binary operator (2 parameters, left side and right side). The first parameter is always an 
ostream object (we've mostly used cout, so far). Because of this, it cannot be defined as a member function 
(it would have to be a member of the ostream class, which we cannot change) so this is the reason that we << oprator should always 
be a freind function of the class or
This is because binary operator member functions can only take one argument and the invoking object is 
implicitly passed in as the first argument using this.


example:
 friend ostream& operator<<(ostream& out, const MyClass& obj) {
        out << "Data: " << obj.data;
        return out;
    }

----------------------------------------extraction oprator-----------------------------
this oprator is also overloaded as same as the exersion oprator
the ony difference is that we use istream istream of ostream

example :
friend std::istream& operator>>(std::istream& input, Point& obj) {
        input >> obj.value ;
        return input;
    }

--------------------------------------which oprators must be overloaded as a friend or member function-----------------
---------------------How to remember which operators can be overloaded as what (member, free, or both)?-----------------------------
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>member function
these oprators must be overoaded as a member function
Assignment operators (=)      why i have listed = oprator here i will discous it later on
Subscript operator ([])
Function call operator (())
Arrow operator (->)

>>>>>>>>>>>>>>>>>>>>>>>>>>>friend function 
<< output oprator (<<) it must be overloaded as a friend function 
>> exsertion oprator(>>) it must also be overloaded as a friend function

>>>>>>>>>>>>>>>>>>>>>>>>>>>member & friend function
For other operators, including arithmetic operators (+, -, *, /, %),
comparison operators (==, !=, <, <=, >, >=), and bitwise operators (&, |, ^, <<, >>),
you have the flexibility to overload them as either member functions or friend functions.

-------------------------------which oprators canot be overloaded-----------------------------
sizeof operator, typeid, Scope resolution (::), Class member access operator (.), Ternary or conditional operator (?:).


*/