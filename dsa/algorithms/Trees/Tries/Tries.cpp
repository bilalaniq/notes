// ------------------------tries/digital tree/ prefix tree------------------------
/*
A **Trie** (pronounced as "try") is a tree-like data structure that is primarily used for storing strings in a way that allows for 
efficient search, insert, and delete operations. It is particularly effective for problems involving a large collection of strings, 
such as dictionary-based operations, autocomplete systems, or IP address routing.

A **Trie** is also known as a **prefix tree** because strings with common prefixes share nodes in the tree, making the structure highly
efficient for prefix-based operations.

the easiest way to understand a trie is to think of an auto-complete feature in a text editor or search engine. When you type a few
characters, the system suggests completions based on the prefix you've entered. This is made possible by storing the words in a trie
data structure, which allows for quick prefix-based searches.


### **Properties of Trie**

- Each node in a trie represents a single character of a string.
- The root node represents an empty string or no character.
- Each path from the root to a leaf node represents a word in the trie.
- The trie stores strings in such a way that strings with the same prefix share common nodes.
- Searching for a word, prefix, or adding a word can be done in **O(k)** time, where **k** is the length of the word.

### **Trie Structure**

The core structure of a Trie consists of:
- A root node (often an empty node).
- Child nodes where each child represents one character of a string.
- A boolean flag to mark whether a node corresponds to the end of a word.

#### **Basic Operations in Trie**
1. **Insert**
   - Insert a word into the trie.
   - Traverse the trie, creating new nodes if necessary for each character of the word.
   - Mark the last character node as the end of the word.

2. **Search**
   - Search for a word in the trie.
   - Traverse the trie, checking for each character.
   - If at any point a character node does not exist, the word is not in the trie.

3. **Delete**
   - Delete a word from the trie.
   - Mark the last character node as not the end of a word.
   - Optionally, prune any nodes that are no longer needed.

4. **Prefix Search**
   - Check if there is any word in the trie that starts with a given prefix.

### **Implementation in C++**

#### **1. TrieNode Class**
Each node of the trie will be an instance of the `TrieNode` class.

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};
```

- The `children` map stores the child nodes for each character.
- The `isEndOfWord` flag indicates whether the node is the end of a valid word.

#### **2. Trie Class**
The `Trie` class will encapsulate the operations of insertion, searching, and deletion.

```cpp
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;  // Mark the end of the word
    }

    // Search for a word in the trie
    bool search(const std::string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;  // Word not found
            }
            node = node->children[c];
        }
        return node->isEndOfWord;  // True if it's the end of a word
    }

    // Search for words with a given prefix
    bool startsWith(const std::string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;  // Prefix not found
            }
            node = node->children[c];
        }
        return true;  // Prefix found
    }

    // Delete a word from the trie
    bool deleteWord(const std::string& word) {
        return deleteWordHelper(root, word, 0);
    }

    bool deleteWordHelper(TrieNode* node, const std::string& word, int index) {
        if (index == word.size()) {
            if (!node->isEndOfWord) {
                return false;  // Word does not exist
            }
            node->isEndOfWord = false;
            return node->children.empty();  // If no children, this node can be deleted
        }

        char ch = word[index];
        if (node->children.find(ch) == node->children.end()) {
            return false;  // Word does not exist
        }

        TrieNode* childNode = node->children[ch];
        bool shouldDeleteChildNode = deleteWordHelper(childNode, word, index + 1);

        if (shouldDeleteChildNode) {
            node->children.erase(ch);
            return node->children.empty() && !node->isEndOfWord;  // Return true if current node can be deleted
        }
        return false;
    }
};
```

### **Explanation of the Code**

1. **TrieNode Class**:
   - The `TrieNode` class represents a node in the Trie. It contains:
     - `children`: a map of characters to child nodes.
     - `isEndOfWord`: a flag that indicates if the node is the end of a word.

2. **Trie Class**:
   - **insert()**: Adds a word to the Trie. It traverses each character of the word and adds a new node if the character doesn't already
    exist.
   - **search()**: Checks if a word exists in the Trie by traversing the nodes for each character.
   - **startsWith()**: Checks if there is any word that starts with the given prefix.
   - **deleteWord()**: Deletes a word from the Trie by recursively calling `deleteWordHelper()`. If a word is completely deleted, the 
   function checks if the parent nodes can be pruned (deleted).

### **Example Usage**

```cpp
int main() {
    Trie trie;

    // Inserting words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");

    // Searching for words
    std::cout << "Search for 'apple': " << trie.search("apple") << std::endl;  // True
    std::cout << "Search for 'app': " << trie.search("app") << std::endl;  // True
    std::cout << "Search for 'banana': " << trie.search("banana") << std::endl;  // True
    std::cout << "Search for 'ban': " << trie.search("ban") << std::endl;  // False

    // Searching for prefixes
    std::cout << "Prefix search for 'app': " << trie.startsWith("app") << std::endl;  // True
    std::cout << "Prefix search for 'ban': " << trie.startsWith("ban") << std::endl;  // True

    // Deleting words
    trie.deleteWord("apple");
    std::cout << "Search for 'apple' after deletion: " << trie.search("apple") << std::endl;  // False

    return 0;
}
```

### **Output**:
```
Search for 'apple': 1
Search for 'app': 1
Search for 'banana': 1
Search for 'ban': 0
Prefix search for 'app': 1
Prefix search for 'ban': 1
Search for 'apple' after deletion: 0
```

### **Complexity**
- **Time Complexity**:
  - Insert: **O(k)**, where **k** is the length of the word.
  - Search: **O(k)**, where **k** is the length of the word.
  - Delete: **O(k)**, where **k** is the length of the word.
  - Prefix Search: **O(k)**, where **k** is the length of the prefix.

- **Space Complexity**:
  - The space complexity is **O(N * k)**, where **N** is the number of words inserted into the Trie and **k** is the average length 
  of the words.

### **Conclusion**
Tries are efficient for storing and retrieving strings, especially when performing operations like prefix search or autocomplete. 
The Trie data structure provides fast lookups and insertions for applications involving large sets of strings, such as search engines,
text processing, and dictionary implementations.



*/