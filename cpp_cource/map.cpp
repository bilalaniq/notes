//------------------------------map.cpp------------------------------

/*
std::map is an associative container that stores key-value pairs with unique keys, arranged in sorted order 
(by default in ascending order), and provides logarithmic time complexity for insertion, lookup, and deletion operations.

---

# 📖 `std::map` — Full Explanation

---

## 1. What is `std::map`?

- `std::map` is a container in the C++ Standard Template Library (STL).
- It **stores elements as key-value pairs**:
  ➔ `key -> value`
- **Keys are unique** (no duplicate keys).
- **Internally**, it is implemented as a **Self-Balancing Binary Search Tree** (usually a Red-Black Tree).

---

## 2. Basic Syntax

```cpp
#include <map>
#include <iostream>

int main() {
    std::map<int, std::string> myMap;

    myMap[1] = "One";
    myMap[2] = "Two";

    std::cout << myMap[1];  // Output: One
}
```

---

## 3. How `std::map` works internally

- **Ordered**: Keys are always stored in **sorted** (ascending) order by default.
- **Tree structure**: Every time you insert, it automatically places it in the correct spot inside a **red-black tree**.
- **Search, insertion, deletion** are **O(log n)** — because red-black trees have logarithmic height.

---

## 4. Important Functions

| Function | Purpose |
|:---------|:--------|
| `insert({key, value})` | Insert a key-value pair. |
| `erase(key)` | Remove a key (and its value). |
| `find(key)` | Returns an iterator to the key if found. |
| `count(key)` | Returns 1 if key exists, 0 otherwise. |
| `size()` | Number of key-value pairs. |
| `empty()` | Checks if the map is empty. |
| `clear()` | Removes all elements. |
| `begin(), end()` | Iterators to traverse the map. |

---

### 5. Example: Full usage

```cpp
#include <map>
#include <iostream>

int main() {
    std::map<std::string, int> age;

    // Insertion
    age["Alice"] = 25;
    age["Bob"] = 30;
    age.insert({"Charlie", 35});

    // Access
    std::cout << "Alice's age: " << age["Alice"] << std::endl;

    // Find
    if (age.find("Bob") != age.end()) {
        std::cout << "Bob found!" << std::endl;
    }

    // Erase
    age.erase("Charlie");

    // Iterate
    for (auto it = age.begin(); it != age.end(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }

    // Size
    std::cout << "Size: " << age.size() << std::endl;
}
```

---

## 6. Important Notes

- If you access a non-existing key with `[]`, **it creates it** with default value!

```cpp
std::cout << myMap[100];  // Creates key 100 with default value (e.g., 0 for int)
```

- Use `find` if you don't want this automatic insertion.

---

## 7. Difference between `map` and `unordered_map`

| Feature | `std::map` | `std::unordered_map` |
|:--------|:-----------|:---------------------|
| Order | Sorted by key | No order |
| Internal Structure | Red-Black Tree | Hash Table |
| Complexity | O(log n) | O(1) average |
| When to use | Need sorted keys | Speed matters more than order |

---

## 8. Custom Comparison for `std::map`

You can **customize the sorting order** using a custom comparator:

```cpp
#include <map>
#include <iostream>

struct CompareDescending {
    bool operator()(const int& a, const int& b) const {
        return a > b; // descending order
    }
};

int main() {
    std::map<int, std::string, CompareDescending> myMap;

    myMap[1] = "One";
    myMap[3] = "Three";
    myMap[2] = "Two";

    for (auto& p : myMap) {
        std::cout << p.first << " : " << p.second << std::endl;
    }
}
```

Output will be:
```
3 : Three
2 : Two
1 : One
```

---

## 9. Common Mistakes 🚨

- Using `[]` when you don't want to create a default entry.
- Forgetting that `map` sorts keys automatically — no manual sorting needed.
- Accidentally inserting large objects — always prefer `emplace` over `insert` for efficiency.

---

## 10. Quick Summary 📋

| Property | Value |
|:---------|:------|
| Storage | Key-Value pairs |
| Key uniqueness | Yes |
| Sorted? | Yes (by key) |
| Internal structure | Red-Black Tree |
| Insert/Search/Delete complexity | O(log n) |

---

# ⚡ Would you like me to show:
- A real-world mini-project using `std::map`? (like student database or address book)
- OR a **comparison** between `std::map` and `std::unordered_map` with benchmarks?

Just say the word! 🚀


*/