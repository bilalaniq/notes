// ------------------------------------------------mutable-------------------------------------------
/*
there are two uses of mutables one is related to const and other is related to lambdas

-------------------------------------mutable with const----------------------------
mutable keyword is used to declare a data member of a class that can be modified even if the containing object is declared as const.
if you want to modify any the state of an class in the const member function you can do it as i have said that the const keyword is
just a promise and you can bypass or break this promise and now we will break that promise
we can do this by using a mutable keyword
private:
    mutable int no;
public:
    int getValue() const
    {
        no++;
        return no;
    };
now i can modify the state of th class using mutable keyword
by using this we can modify the specific variable in const member functions



-------------------------------------mutable with lambdas----------------------------
note that we will discous lamddas in the future so then see the mutable v again


*/


//if you want to learn about lambdas you can click here 
#include"lambdas.cpp"





