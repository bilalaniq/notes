# **Bitmaps**

A **bitmap** (also known as a bit array, bitset, or bit vector) is a **compact data structure** that uses **bits** to efficiently represent and manipulate sets, flags, or binary states.

A **bitmap** is an array of bits where each **bit** represents **true/false**, **on/off**, or **1/0** states. It is used for memory-efficient storage of boolean values.

**Example**: Storing the availability of **1 million users** would take **1 million bytes** using `bool[]`, but only **125 KB** using a **bitmap**.

---

## **2. Where are Bitmaps Used?**

📌 **Memory-efficient storage** (e.g., representing large datasets in limited memory).  
📌 **Bitmap Indexing** (e.g., databases use bitmaps for fast searching).  
📌 **Flags and Permissions** (e.g., file permissions, process states).  
📌 **Graph and Set Operations** (e.g., finding unique elements, intersections).  
📌 **Compression and Image Processing** (e.g., BMP file format).

---

## **3. Implementing Bitmaps in C++**

### **(a) Using `std::bitset` (Best for Fixed-Size Bitmaps)**

C++ provides `std::bitset<N>`, a convenient, fixed-size bitmap.

```cpp
#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> bitmap("10110011"); // Initialize with a binary string
    std::cout << "Bitmap: " << bitmap << std::endl;

    bitmap.set(2, 0);  // Set bit at index 2 to 0
    bitmap.flip(5);    // Toggle bit at index 5
    std::cout << "Modified Bitmap: " << bitmap << std::endl;

    std::cout << "Bit at position 3: " << bitmap[3] << std::endl;
}
```

### **Output**:

```
Bitmap: 10110011
Modified Bitmap: 10010011
Bit at position 3: 0
```

✅ **Advantages**:  
✔️ Easy to use  
✔️ Supports bitwise operations  
❌ **Fixed size** (Cannot change size dynamically)

---

### **(b) Using `vector<bool>` (Dynamically Sized Bitmap)**

If you need a **resizable bitmap**, use `std::vector<bool>`.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<bool> bitmap(10, false); // 10-bit bitmap initialized to 0

    bitmap[3] = true; // Set bit 3 to 1
    bitmap[7] = true; // Set bit 7 to 1

    for (bool bit : bitmap)
        std::cout << bit;

    return 0;
}
```

### **Output**:

```
0001000010
```

✅ **Advantages**:  
✔️ **Dynamic size** (resizeable)  
✔️ Easy indexing  
❌ **May use extra memory** (uses 1 byte per bit in some implementations)

---

### **(c) Using `uint8_t` for Efficient Bitmap Storage**

If you want **manual control** over a **compact bitmap**, use `uint8_t`, `uint16_t`, `uint32_t`.

```cpp
#include <iostream>
#include <cstdint>

int main() {
    uint8_t bitmap = 0b10110110; // 8-bit bitmap (1 byte)

    // Check if bit 2 is set
    std::cout << "Bit 2 is " << ((bitmap & (1 << 2)) ? "ON" : "OFF") << std::endl;

    // Set bit 1
    bitmap |= (1 << 1);

    // Clear bit 3
    bitmap &= ~(1 << 3);

    // Toggle bit 6
    bitmap ^= (1 << 6);

    std::cout << "Modified Bitmap: " << std::bitset<8>(bitmap) << std::endl;
}
```

### **Output**:

```
Bit 2 is ON
Modified Bitmap: 10100111
```

✅ **Advantages**:  
✔️ **Highly memory-efficient**  
✔️ **Fast bitwise operations**  
❌ **Requires manual bit manipulation**

---

### **(d) Dynamic Bitmap Using `std::vector<uint8_t>`**

For **large and efficient** bitmaps, use `std::vector<uint8_t>`.

```cpp
#include <iostream>
#include <vector>

class Bitmap {
private:
    std::vector<uint8_t> data;
    size_t size;

public:
    Bitmap(size_t n) : size(n), data((n + 7) / 8, 0) {}

    void set(size_t pos, bool value) {
        if (value)
            data[pos / 8] |= (1 << (pos % 8)); // Set bit
        else
            data[pos / 8] &= ~(1 << (pos % 8)); // Clear bit
    }

    bool get(size_t pos) const {
        return data[pos / 8] & (1 << (pos % 8));
    }

    void print() const {
        for (size_t i = 0; i < size; i++)
            std::cout << get(i);
        std::cout << std::endl;
    }
};

int main() {
    Bitmap bitmap(16);
    bitmap.set(3, true);
    bitmap.set(7, true);
    bitmap.set(10, true);
    bitmap.print();
}
```

### **Output**:

```
0001000100100000
```

✅ **Advantages**:  
✔️ **Highly efficient for large bitmaps**  
✔️ **Compact memory usage**  
❌ **Requires more complex logic**

---

## **4. Bitmap Operations & Bitwise Manipulations**

### **(a) Checking if a Bit is Set**

```cpp
bool isSet = (bitmap & (1 << position)) != 0;
```

### **(b) Setting a Bit**

```cpp
bitmap |= (1 << position);
```

### **(c) Clearing a Bit**

```cpp
bitmap &= ~(1 << position);
```

### **(d) Toggling a Bit**

```cpp
bitmap ^= (1 << position);
```

### **(e) Counting Set Bits (`std::bitset::count()`)**

```cpp
std::bitset<8> b(0b10101100);
std::cout << "Set bits: " << b.count() << std::endl;
```

---

## **5. Pros and Cons of Using Bitmaps**

| **Pros**                                       | **Cons**                                            |
| ---------------------------------------------- | --------------------------------------------------- |
| Saves memory (compact storage)                 | Bit manipulation can be tricky                      |
| Fast operations using bitwise operators        | Harder to debug                                     |
| Efficient for large boolean datasets           | Needs manual handling in raw arrays                 |
| Used in indexing, permissions, and compression | Fixed-size bitsets (`std::bitset`) can't be resized |

---

## **6. Conclusion**

🔹 **Bitmaps** are an efficient way to store and manipulate boolean data using **bits** instead of full bytes.  
🔹 **`std::bitset`** is best for **small fixed-size** bitmaps, while **`std::vector<uint8_t>`** is best for **large dynamic bitmaps**.  
🔹 **Bitwise operations (`&`, `|`, `^`, `~`, `<<`, `>>`)** are crucial for efficient bitmap manipulation.
