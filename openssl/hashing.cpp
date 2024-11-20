// -------------------------------------hashing(Message Digest)-------------------------
/*
**Hashing** is a fundamental concept in computer science and cryptography. It refers to the process of converting an input 
(usually data such as a file, password, or message) into a fixed-size string or number, called a **hash value** or **hash code**. 
This transformation is done by a **hash function**.

The primary characteristics of a hash function are:
1. **Deterministic**: The same input always produces the same output.
2. **Fixed Size**: Regardless of the size of the input, the output (hash) will always be of a fixed length.
3. **Fast Computation**: Hashing should be quick to compute, even for large inputs.
4. **Pre-image Resistance**: It should be computationally infeasible to reverse the process and retrieve the original input from the 
hash.

this mean that Reversing a cryptographic hash function is considered impossible in the sense that it is computationally infeasible 
to determine the original input from its hash value, provided the hash function is secure and has pre-image resistance.

5. **Collision Resistance**: It should be extremely difficult (ideally impossible) to find two different inputs that produce the same
hash.
6. **Avalanche Effect**: A small change in the input should produce a completely different hash.

---

### **Why is Hashing Important?**

Hashing is used for various purposes in computer science and security, including:

- **Data Integrity**: Hashing is used to ensure that data has not been altered or corrupted during transmission or storage.
 By comparing the hash of the received data with the expected hash, you can verify its integrity.  
- **Password Storage**: Instead of storing actual passwords, systems often store the hash of a password. When a user logs in, the 
system hashes the entered password and compares it to the stored hash. This adds an extra layer of security, as even if the password 
database is compromised, attackers only get the hashed versions, not the actual passwords.

- **Digital Signatures**: Hashing is an integral part of digital signatures. A digital signature involves hashing the message, 
encrypting the hash with a private key, and then verifying the hash with a public key.

- **Cryptographic Applications**: Hashing functions are widely used in cryptographic protocols like SSL/TLS, HMAC 
(Hash-based Message Authentication Code), blockchain (Bitcoin), and more.

- **Checksums and Fingerprints**: Hashing is used to create checksums and fingerprints for large files or datasets, enabling quick 
comparison and identification of changes.

---

### **How Does Hashing Work?**

A **hash function** takes an input (or "message") of any size and converts it into a fixed-size output. Here's an example of how
 it works:

1. **Input**: You provide the data (text, file, etc.) to the hash function.
2. **Processing**: The hash function processes the input through a series of mathematical operations to generate a hash value.
3. **Output**: The result is a fixed-size string of characters, often represented as a hexadecimal number.

For example, using the SHA-256 hash function on the string `"hello"` would result in a fixed-size hash value that is always the 
same length (64 characters), regardless of the length of the input.

#### Example:
- **Input**: `"hello"`
- **SHA-256 Hash**: `2cf24dba5fb0a30e26e83b2ac5b9e29e1b170e6f8f7cc47d500105cb213b89a7`

This 64-character output is the hash of the input string "hello". If the input changes even slightly 
(e.g., `"hello "` with an extra space), the output hash will change completely.

---

### **Types of Hash Functions**

There are various types of hash functions, each with its own use cases. The most common types are:

#### 1. **Cryptographic Hash Functions**

Cryptographic hash functions are designed to be secure and are widely used in security protocols, digital signatures, and password
storage.

**Characteristics of Cryptographic Hash Functions**:
- **Deterministic**: The same input will always produce the same output.
- **Fixed Size**: The hash output is always of a fixed length, regardless of the input size.
- **Pre-image Resistance**: Given a hash output, it should be computationally infeasible to find the original input.
- **Collision Resistance**: It should be very hard to find two different inputs that produce the same hash output.
- **Avalanche Effect**: A small change in the input should produce a drastically different output hash.

**Popular Cryptographic Hash Functions**:
- **MD5 (Message Digest Algorithm 5)**: Produces a 128-bit hash value (32 hexadecimal characters). While fast, MD5 is no longer 
considered secure for cryptographic purposes because it is vulnerable to collisions.
  
- **SHA-1 (Secure Hash Algorithm 1)**: Produces a 160-bit hash (40 hexadecimal characters). Like MD5, SHA-1 is also considered broken
due to collision vulnerabilities.

- **SHA-256**: Part of the SHA-2 family of hash functions, produces a 256-bit hash (64 hexadecimal characters). SHA-256 is 
widely used in modern cryptographic applications, such as Bitcoin, SSL/TLS, and more.

- **SHA-3**: The latest member of the Secure Hash Algorithm family, designed to be resistant to certain vulnerabilities that 
SHA-1 and SHA-2 might face in the future. It uses a different underlying construction than SHA-2.

**Example Use Cases**:
- **Digital Signatures**: Ensuring data integrity and authenticity.
- **Password Hashing**: Securely storing user passwords.
- **Message Integrity**: Verifying that a message hasn't been tampered with.
- **Blockchain**: Ensuring immutability and security in cryptocurrency transactions.

---

#### 2. **Non-Cryptographic Hash Functions**

Non-cryptographic hash functions are primarily used for data structure purposes, such as hashing data in hash tables or checksums
 for error detection.

**Characteristics of Non-Cryptographic Hash Functions**:
- **Speed**: These functions are optimized for performance rather than security.
- **Lower Security Guarantees**: They do not provide cryptographic security and should not be used for purposes like digital
 signatures or password storage.
- **Collision Resistance**: While collisions are still minimized, these hash functions are not designed to be resistant to attacks.

**Popular Non-Cryptographic Hash Functions**:
- **FNV-1**: A fast and simple hash function used in hash tables.
- **MurmurHash**: An efficient non-cryptographic hash function used in various software systems for hashing large datasets.
- **CityHash**: A high-quality hash function developed by Google for hashing large data (used in distributed systems).

**Example Use Cases**:
- **Hash Tables**: Efficient data lookups in programming.
- **Checksums**: Verifying the integrity of data without cryptographic guarantees.

---

### **Collision Resistance and Security**

One of the most important properties of a cryptographic hash function is **collision resistance**. A **collision** occurs when
 two different inputs produce the same hash output.

- **Ideal Collision Resistance**: In a cryptographically secure hash function, finding two inputs that result in the same hash 
should be practically impossible, even if an attacker knows the hash output.
- **Broken Hash Functions**: When hash functions like **MD5** or **SHA-1** are vulnerable to collisions, it means that attackers 
could craft different inputs that yield the same hash, undermining the integrity of systems relying on the hash.

For example, an attacker might use a collision in a hash function to replace one file with another, while keeping the hash value
 the same, thus bypassing integrity checks.

---

### **Hashing Use Cases in Practice**

1. **Password Hashing**:
   Instead of storing user passwords directly, systems typically store the hash of a password. When the user attempts to log in,
the system hashes the entered password and compares it with the stored hash. This ensures that even if the database is compromised,
the actual passwords are not exposed.

2. **Data Integrity**:
   Hashing is used to verify that data hasn't been tampered with. For example, when downloading a file, a website might provide a 
   hash value that you can use to verify that the file you downloaded is the same as the one on the server.

3. **Digital Signatures**:
   Digital signatures involve hashing the message and then encrypting the hash value with a private key. This ensures that the message 
   is both authentic (i.e., it came from the sender) and has not been tampered with.

4. **Blockchain**:
   Cryptocurrencies like Bitcoin use hashing as a core component to ensure the integrity and immutability of transactions. In Bitcoin, 
miners solve computational problems to find a valid hash for a block, securing the chain and preventing fraud.

---

### **Summary: Key Points About Hashing**
__________________________________________________________________________________________________________________________________________
| **Aspect**             | **Encryption**                                  | **Hashing**                                                  |
|------------------------|-------------------------------------------------|--------------------------------------------------------------|
| **Purpose**            | To make data unreadable to unauthorized users   | To generate a fixed-size identifier (hash) for data          |
|                        |                                                 |                                                              |
| **Process**            | Data is converted to unreadable ciphertext      | Data is processed into a fixed-size string using a hash      |
|                        | using a key                                     | function                                                     |
|                        |                                                 |                                                              |         
| **Reversibility**      | Reversible with the correct key (decryption)    | Irreversible, no way to retrieve the original data           |
|                        |                                                 |                                                              |         
| **Key Used**           | Secret key (symmetric) or public/private keys   | No key required                                              |
|                        | (asymmetric)                                    |                                                              |         
|                        |                                                 |                                                              |         
| **Use Cases**          | Secure communication, file encryption, etc.     | Password storage, data integrity, digital signatures, etc.   |
|________________________|_________________________________________________|______________________________________________________________|



*/