// -----------------------------fold expression----------------------------
/*
Sure! Let’s dive into fold expressions in C++ in detail, covering what they are, how they work, their syntax, and examples.

### What Are Fold Expressions?

Fold expressions were introduced in C++17 to simplify the process of applying binary operators to all elements in a parameter pack.
They provide a concise way to "fold" or reduce a parameter pack into a single value by applying a binary operation. 

### Types of Fold Expressions

There are two main types of fold expressions:

1. **Unary Fold**: Applies a unary operator to each element.
2. **Binary Fold**: Applies a binary operator between elements.

### Syntax

1. **Unary Fold**:
   - Syntax: `(<unary operator> ... <parameter pack>)`
   - Example: `(- ... args)` negates each argument.

2. **Binary Fold**:
   - Syntax: `(<parameter pack> <binary operator> ...)`
   - Example: `(args + ...)` adds all arguments together.

### How It Works

- **Expansion**: When you use a fold expression, the parameter pack is expanded according to the operator. For a binary fold, 
it generates a series of operations involving each element of the pack.
- **Associativity**: The operations follow the associativity of the operator. For example, with addition (`+`), it evaluates as 
`((arg1 + arg2) + arg3)`.

### Examples

#### 1. Binary Fold Example: Summing Values

Here’s an example that sums multiple integers using a binary fold expression:

```cpp
#include <iostream>

// Function to sum any number of integers
template<typename... Args>
int sum(Args... args) {
    return (args + ...); // Adds all arguments together
}

int main() {
    std::cout << "Sum: " << sum(1, 2, 3, 4) << std::endl; // Outputs: 10
    std::cout << "Sum: " << sum(10, 20, 30) << std::endl; // Outputs: 60
    return 0;
}
```

**Explanation**:
- The function `sum` uses `(args + ...)` to sum all the integers provided.
- When called, it expands to `1 + 2 + 3 + 4`, and the result is returned.

#### 2. Unary Fold Example: Negating Values

Here’s an example that negates multiple values using a unary fold expression:

```cpp
#include <iostream>

// Function to negate all values
template<typename... Args>
void negate(Args... args) {
    ((std::cout << -args << " "), ...); // Negates each argument and prints it
                                           //, (Comma Operator): The fold expression is applied using the comma operator here. The comma operator allows multiple 
                                               expressions to be evaluated in sequence.
    std::cout << std::endl;
}

int main() {
    negate(1, 2, 3); // Outputs: -1 -2 -3 
    negate(4.5, -3.2); // Outputs: -4.5 3.2 
    return 0;
}
```

**Explanation**:
- The function `negate` uses `((-args) ...)` to apply negation to each argument.
- Each negated value is printed in a single line.

### Important Notes

1. **Operator Overloading**: For custom types, ensure that the operators used in fold expressions are overloaded appropriately
 to handle the specific types.
  
2. **Mixing Types**: You can mix types in the parameter pack, but be cautious with operations that may not be valid across different
 types.

3. **Performance**: Fold expressions can help improve performance and readability by eliminating the need for recursive template 
functions or manual loops.

### Summary

Fold expressions provide a powerful and expressive way to work with parameter packs in C++. They simplify the application of 
operations across multiple values, making your code cleaner and easier to read. With the introduction of this feature in C++17, 
you can perform operations on variadic templates more efficiently and elegantly.


*/


// -------------------------right fold vs left fold------------------------
/*
If you use `return (args * ...);` instead of `return (... * args);`, the result will be the same in terms of output for the
multiplication, but the fold expression's **direction** changes. Here's how:

### 1. **`(... * args)`**: **Right Fold**
   This is a **right fold** (also called a *fold from the right*), which applies the operator starting from the **rightmost** 
   argument and works toward the **left**.
   
   For example, with `product(1, 2, 3, 4, 5)`, it will expand as:
   ```cpp
   1 * (2 * (3 * (4 * 5)))
   ```

### 2. **`(args * ...)`**: **Left Fold**
   This is a **left fold** (also called a *fold from the left*), which applies the operator starting from the **leftmost** argument
    and works toward the **right**.

   For the same input `product(1, 2, 3, 4, 5)`, it will expand as:
   ```cpp
   (((1 * 2) * 3) * 4) * 5
   ```

### In this case:
For multiplication (and addition, etc.), **the order does not matter** because multiplication is **associative**. So, whether
 you do:

- `1 * (2 * (3 * (4 * 5)))` (right fold)
- or `(((1 * 2) * 3) * 4) * 5` (left fold)

The result will always be the same: `120`.

### When would the difference matter?

The difference between **left** and **right folds** matters when you are using **non-associative operations** like subtraction or
 division. For instance, consider the following:

#### Subtraction with a Left Fold:
```cpp
template<typename... Args>
int subtract(Args... args) {
    return (args - ...);  // Left fold
}
```
If you call `subtract(10, 2, 1)`, it expands as:
```cpp
((10 - 2) - 1)  // Result: 7
```

#### Subtraction with a Right Fold:
```cpp
template<typename... Args>
int subtract(Args... args) {
    return (... - args);  // Right fold
}
```
For the same call `subtract(10, 2, 1)`, it expands as:
```cpp
10 - (2 - 1)  // Result: 9
```

Here, the **order of operations** makes a difference. 

### Conclusion:
- `(... * args)` is a **right fold**.
- `(args * ...)` is a **left fold**.
- In your multiplication example, both give the same result because multiplication is associative.
- The difference between left and right folds is important for **non-associative operations** like subtraction or division.


------------------------note----------------------
The naming of **right fold** or **left fold** doesn't depend solely on where the parameter pack is located but rather on how
 the operator is applied. Let me clarify this for you.

### Fold Expression Naming:
- **Right Fold** (`(... op args)`):
  - This starts applying the operator from the **rightmost** argument, moving toward the **left**.
  - Example: `(... * args)` for arguments `1, 2, 3` expands to `1 * (2 * 3)`.

- **Left Fold** (`(args op ...)`):
  - This starts applying the operator from the **leftmost** argument, moving toward the **right**.
  - Example: `(args * ...)` for arguments `1, 2, 3` expands to `(1 * 2) * 3`.

### How the Placement of Parameter Pack Affects the Fold Type:
- In **right folds**, the parameter pack (`args...`) comes after the operator, meaning the last argument is used
 first in the operation.
- In **left folds**, the parameter pack is on the left side, so the first argument is used first.

Thus, **`(... * args)`** is a **right fold**, and **`(args * ...)`** is a **left fold**, regardless of whether the parameter 
pack is written first or second in the syntax.


i will elaburate this later on in the notes so read all the blog :)




*/


//------------------------------comma(,) in fold expression------------------
/*
there are two use cases of comma operator in fold expressionr

1. Comma as a Separator (Used in Print Statements)

In many fold expressions, especially in printing or performing side effects, the comma is used to evaluate multiple expressions
in sequence. This is particularly useful when the actual result of each operation is less important than ensuring that all the
 expressions get evaluated (like printing multiple values).

 template<typename... Args>
void print_all(Args... args) {
    ((std::cout << args << " "), ...);  // Left fold using comma operator
}

int main() {
    print_all(1, 2, 3, 4, 5);  // Output: 1 2 3 4 5 
}

herse another example

    #include <iostream>

// Function to print and sum all values
template<typename... Args>
int sum_and_print(Args... args) {
    int sum = 0;
    ((std::cout << args << " ", sum += args), ...); // Left fold: print each arg and add to sum
    std::cout << "\nTotal Sum: " << sum << std::endl;
    return sum;
}

int main() {
    sum_and_print(1, 2, 3, 4, 5); // Output: 1 2 3 4 5 Total Sum: 15
    return 0;
}



2. Comma as an Operator (Actual Comma Operator)

In C++, the comma operator is a binary operator that evaluates two expressions, discards the result of the first expression, 
and returns the result of the second expression.

template<typename... Args>
int evaluate_all(Args... args) {
    return (args, ...);  
}

int main() {
    int result = evaluate_all(1, 2, 3, 4, 5);  // Output: 5
    std::cout << result << std::endl;
}



*/

//-------------------------????????????????????????????------------------------
/*
you may be asking an  question that
 (...  * args) is an right fold where (args * ... ) is an left fold 
 where if i use an comma operator 

 (args ,  ...) is an right fold where (... , args) is an left fold why is this 

 The behavior you're observing with folds and operators in C++ is indeed related to the evaluation order and how each operator 
 processes its operands

 as i have said this above 
 The naming of **right fold** or **left fold** doesn't depend solely on where the parameter pack is located but rather on how
 the operator is applied. Let me clarify this for you.

the basic evaluation order when dealing with other operator is 
Right Fold: Starts evaluating from the last operand.
Left Fold: Starts evaluating from the first operand.

but comma operator has different evaluation order
The left operand is evaluated first, but its value is discarded. The right operand is then evaluated, and its value is returned.

(args, ...)  right fold
How It Works: This expression evaluates all arguments starting from the last one to the first:
argN, (argN-1), ..., arg1

where (... , args)   left fold 
How It Works: This expression evaluates each argument in the pack from left to right, effectively constructing a series of 
evaluations:
arg1, (arg2, (arg3, ...))

this is why comma operator is different from other operator 

so this proves that the wheather a folding is left or right it does not depend upon the position of parameter pack 
rather it depends upon the evaluation order of the operator 


*/