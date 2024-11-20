// -------------------------------------Ternary Operator------------------------------
/*
Ternary operators in C++ provide a compact way to express conditional statements. 
it makes the code slitlly faster then code having if conditions

syntex:
condition ? expression1 : expression2;
here it is how it works?
If the condition is true, expression1 is evaluated and becomes the result of the entire expression.
If the condition is false, expression2 is evaluated and becomes the result of the entire expression.

example:
int x =5;
if(x > 0)
{
    y = 10;
}else
{
    y = 20;
}
i could write this if contion in the form of ternary oprator

int x = 5;
int y = (x > 0) ? 10 : 20; // If x is greater than 0, y is assigned 10, otherwise 20.



Ternary operators can also be nested within each other or used as part of larger expressions.
However, excessive nesting can make code less readable, so it's generally advised to use them judiciously
so when nesting ternary oprator it


example:
int x = 5;
int y;

if (x > 0) {
    if (x < 10) {
        y = 1;
    } else {
        y = 2;
    }
} else {
    y = 0;
}

i could write this if contion in the form of ternary oprator
int x = 5;
int y = (x > 0) ? ((x < 10) ? 1 : 2) : 0;

another example:
int a;
int b;
if(a > 5 && a < 100)
{
  if(a > 10)
  {
    b = 15;
  }else
  {
    b = 10;
  }
}else
{
    b = 5;
}
you can write by using tertiary oprator
int b = (a > 5 && a < 100) ? (a > 10 ? 15 : 10) : 5;

you could also not use the brackets but it makes the code more readable


Ternary operators are often used in places where a simple conditional assignment is needed, making the code more concise
and readable. However, complex expressions involving multiple ternary operators can sometimes be difficult to understand, 
so it's essential to balance readability and conciseness.


*/

/*
--------------------------------------how ternary oprators are faster then if conditions----------------------
this is because when using if condition an empty variable is created and then override that variable but when using ternary oprator 
no empty intermidiate vaiable is created this is beacause of return value optimization
so because the compiler do not have to create an empty variable and then distroy it so this makes ternary oprator slighty faster 
then conditional statement
*/
// if you want to learn about return value optimization click here 
#include"return_value_optimization.cpp"
