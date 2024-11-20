// -------------------------------iomanip------------------------------------
/*
The header file `<iomanip>` is part of the C++ Standard Library and is used for input/output (I/O) manipulation. It provides facilities
to control the formatting of streams (like `std::cout` or `std::cin`) in terms of numbers, precision, alignment, and width, among
others. The functions and manipulators in `<iomanip>` help customize how data is displayed in C++.

Let’s break down its main components in detail:

### 1. **Why Include `<iomanip>`?**

In C++, when you output data to the console, the format is generally simple (just printing values). However, in many situations, you 
need to control the format of the output more precisely. This is where `<iomanip>` comes in. It allows you to set things like:
- **Field width** (how many characters wide to make a value when printing)
- **Precision** (how many digits after the decimal point to print for floating-point numbers)
- **Fill characters** (the character to use to fill space in a wide field)
- **Number formatting** (such as displaying numbers in scientific or fixed-point notation)

To use these features, you include the header `<iomanip>` at the beginning of your program.

```cpp
#include <iostream>
#include <iomanip>
```

### 2. **Common Manipulators Provided by `<iomanip>`**

Here’s an overview of the most commonly used manipulators from `<iomanip>`:

#### a. **`std::setw(int n)`** – Set the width of the field
`std::setw` is used to specify the width of the next output item. It ensures that the output occupies at least `n` characters in the 
output field. If the item is shorter than `n`, the output is padded with spaces (or another character if specified).

Example:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    int number = 42;
    std::cout << std::setw(5) << number << std::endl;  // Output: "   42"
    return 0;
}
```
Here, `setw(5)` ensures that the number 42 is printed in a field that is 5 characters wide. The remaining space is filled with spaces 
by default.

#### b. **`std::setprecision(int n)`** – Set the number of decimal places
`std::setprecision` controls the number of digits displayed for floating-point numbers. By default, it affects the total number of 
significant digits.

Example:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    double pi = 3.141592653589793;
    std::cout << std::setprecision(4) << pi << std::endl;  // Output: 3.142
    return 0;
}
```
Here, `setprecision(4)` rounds the floating-point number to 4 significant digits.

#### c. **`std::fixed` and `std::scientific`** – Control floating-point format
These manipulators change the representation of floating-point numbers to either fixed-point or scientific notation.

- **`std::fixed`** forces the output to be in fixed-point notation, where a specific number of digits after the decimal point is shown.
- **`std::scientific`** forces the output to use scientific (exponential) notation.

Example:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    double value = 123456.789;
    std::cout << std::fixed << std::setprecision(2) << value << std::endl;  // Output: 123456.79
    std::cout << std::scientific << std::setprecision(2) << value << std::endl;  // Output: 1.23e+05
    return 0;
}
```

- With `std::fixed`, the number is displayed with a specific number of digits after the decimal point.
- With `std::scientific`, the number is displayed in exponential form.

#### d. **`std::setfill(char c)`** – Set the fill character
`std::setfill` sets the character that will be used to pad fields when they are not wide enough. By default, padding is done with 
spaces, but you can change it to any character.

Example:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    int number = 42;
    std::cout << std::setw(5) << std::setfill('0') << number << std::endl;  // Output: 00042
    return 0;
}
```
Here, `std::setfill('0')` makes the padding character '0', so the number is padded with zeros instead of spaces.

#### e. **`std::left`, `std::right`, and `std::internal`** – Set the alignment of text
These manipulators control how the output is aligned within the field:

- **`std::left`**: Aligns the output to the left of the field.
- **`std::right`**: Aligns the output to the right of the field (this is the default).
- **`std::internal`**: Aligns the sign (if any) to the left, and the number to the right.

Example:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    int number = 42;
    std::cout << std::setw(5) << std::left << number << std::endl;  // Output: "42   "
    std::cout << std::setw(5) << std::right << number << std::endl;  // Output: "   42"
    std::cout << std::setw(5) << std::internal << -42 << std::endl;  // Output: "- 42"
    return 0;
}
```
- `std::left` left-aligns the number.
- `std::right` right-aligns the number (default behavior).
- `std::internal` aligns the sign to the left of the field and the number to the right.

#### f. **`std::showpoint` and `std::noshowpoint`** – Control decimal point display
- **`std::showpoint`** forces the decimal point to be shown, even for whole numbers (useful for floating-point numbers).
- **`std::noshowpoint`** prevents the decimal point from being shown if it is not needed.

Example:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    double value = 100.0;
    std::cout << std::showpoint << value << std::endl;  // Output: 100.000000
    std::cout << std::noshowpoint << value << std::endl;  // Output: 100
    return 0;
}
```

#### g. **`std::hex`, `std::dec`, and `std::oct`** – Base formatting for integers
These manipulators control how integer values are displayed, either in hexadecimal, decimal, or octal format.

- **`std::hex`**: Outputs the integer in hexadecimal (base 16).
- **`std::dec`**: Outputs the integer in decimal (base 10).
- **`std::oct`**: Outputs the integer in octal (base 8).

Example:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    int value = 255;
    std::cout << std::hex << value << std::endl;  // Output: ff
    std::cout << std::dec << value << std::endl;  // Output: 255
    std::cout << std::oct << value << std::endl;  // Output: 377
    return 0;
}
```

### 3. **Other Functions**
- **`std::resetiosflags()`**: Resets specific formatting options to their default state. 
- **`std::setiosflags()`**: Sets specific formatting flags.
- **`std::showbase`**: Forces the display of base prefixes (like `0x` for hexadecimal).

### Conclusion

In summary, `<iomanip>` is essential for controlling the output format of your program. It provides a set of powerful manipulators 
for controlling:
- Precision
- Field width
- Alignment
- Fill characters
- Base formatting

Using `<iomanip>`, you can easily make the output of your C++ program look cleaner, more readable, and professionally formatted.




*/