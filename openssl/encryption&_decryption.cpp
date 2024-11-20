// ----------------------------------encryption & decryption---------------------------------
/*
### **Encryption and Decryption** in Full Detail

**Encryption** and **decryption** are two fundamental operations in the field of **cryptography**, which is the science of securing
information. These operations allow us to protect the confidentiality, integrity, and authenticity of data. Let's break down what 
encryption and decryption are, how they work, and their different types.

---

### **What is Encryption?**

**Encryption** is the process of converting **plaintext** (i.e., readable data) into **ciphertext** (i.e., unreadable, scrambled data) 
using a mathematical algorithm and a secret key. The purpose of encryption is to ensure that only authorized parties can read the data,
while unauthorized parties, without the correct key, will not be able to interpret the data.

#### Why is Encryption Important?
- **Privacy**: It protects sensitive information from being exposed to unauthorized individuals or entities.
- **Security**: Encryption ensures that even if data is intercepted during transmission (e.g., over the internet), it cannot be 
understood without the decryption key.
- **Compliance**: Many industries and regulatory frameworks (like GDPR, HIPAA, etc.) require the use of encryption to safeguard customer
data.

---

### **How Does Encryption Work?**

Encryption involves the use of two primary elements:
1. **Algorithm**: A mathematical procedure or method that transforms the plaintext into ciphertext (e.g., AES, RSA).
2. **Key**: A piece of information (a string of bits) used to control the encryption and decryption process. The key is essential 
because the same encryption algorithm can produce different ciphertexts depending on the key used.

There are **two main types of encryption**: **Symmetric encryption** and **Asymmetric encryption**.

---

### **1. Symmetric Encryption (Secret Key Encryption)**

In **symmetric encryption**, the **same key** is used for both **encryption** and **decryption**. This means that both the sender and
the receiver must have access to the secret key and keep it safe.

#### How Symmetric Encryption Works:
1. **Encryption**: The sender uses the encryption algorithm with a secret key to convert plaintext into ciphertext.
2. **Transmission**: The ciphertext is sent over an insecure medium (e.g., the internet).
3. **Decryption**: The receiver, who possesses the same secret key, uses it with the decryption algorithm to convert the ciphertext 
back to plaintext.

#### Example Algorithms:
- **AES (Advanced Encryption Standard)**: A widely-used symmetric encryption algorithm that encrypts data in fixed-size blocks 
(e.g., 128, 192, or 256 bits).
- **DES (Data Encryption Standard)**: An older encryption algorithm that is now considered insecure due to its small key size.
- **RC4 (Rivest Cipher 4)**: A stream cipher that encrypts data one bit or byte at a time.

#### Strengths:
- **Efficiency**: Symmetric encryption is faster than asymmetric encryption, making it suitable for encrypting large amounts of data.
- **Simple**: The same key is used for both encryption and decryption, so it's conceptually simpler.

#### Weaknesses:
- **Key Distribution Problem**: Since the same key is used for both encryption and decryption, it must be securely shared between
the parties involved. If an attacker intercepts the key, they can decrypt the message.
- **Scalability**: If many parties need to communicate securely, each pair of parties would need a unique shared secret key, 
which can lead to complex key management.

---

### **2. Asymmetric Encryption (Public Key Encryption)**

In **asymmetric encryption**, two **different keys** are used:
- **Public Key**: This key is freely available to everyone and is used for encryption.
- **Private Key**: This key is kept secret by the owner and is used for decryption.

#### How Asymmetric Encryption Works:
1. **Encryption**: The sender uses the recipient’s **public key** to encrypt the plaintext. Anyone can use the public key to encrypt data,
but only the recipient who possesses the corresponding **private key** can decrypt it.
2. **Transmission**: The ciphertext is sent over an insecure medium.
3. **Decryption**: The receiver uses their **private key** to decrypt the ciphertext and recover the plaintext.

#### Example Algorithms:
- **RSA**: A widely used asymmetric encryption algorithm, primarily used for securing communications over the internet.
- **ECC (Elliptic Curve Cryptography)**: A family of algorithms based on the mathematics of elliptic curves, known for providing strong
security with smaller key sizes compared to RSA.
- **DSA (Digital Signature Algorithm)**: Often used for digital signatures, it’s based on asymmetric encryption principles.

#### Strengths:
- **Key Distribution**: Asymmetric encryption solves the key distribution problem of symmetric encryption.
The **public key** can be shared openly, and only the recipient’s **private key** can decrypt the message.
- **Digital Signatures**: Asymmetric encryption also allows for the creation of **digital signatures**, which can verify the 
authenticity and integrity of the message.

#### Weaknesses:
- **Performance**: Asymmetric encryption is computationally more expensive and slower than symmetric encryption, making it less 
efficient for large data.
- **Larger Key Sizes**: To maintain high levels of security, asymmetric encryption algorithms require much larger keys compared to 
symmetric encryption.

---

### **What is Decryption?**

**Decryption** is the reverse process of encryption. It converts the **ciphertext** (the encrypted, unreadable data) back into the 
original **plaintext** (the readable data) using a decryption algorithm and a key.

#### How Decryption Works:
- In **symmetric encryption**, the same key that was used to encrypt the data is used for decryption.
- In **asymmetric encryption**, the **private key** corresponding to the **public key** used to encrypt the data is used for decryption.

Decryption ensures that the data, when received by the intended party, can be restored to its original form.

---

### **Encryption and Decryption in Action (Example)**

Here’s a simple illustration:

#### Scenario: Sending a Secure Message

- **Alice** wants to send a confidential message to **Bob**.
- **Bob** shares his **public key** with Alice (the public key can be freely distributed).
- **Alice** encrypts her message using Bob's **public key**.
- The encrypted message (ciphertext) is sent to Bob.
- Bob uses his **private key** (which only he possesses) to decrypt the message and read it.

#### In Symmetric Encryption:
- Alice and Bob share a **secret key** beforehand.
- Alice encrypts the message using the secret key.
- Bob decrypts the message using the same secret key.

---

### **Types of Encryption**

1. **Block Cipher**:
   - A **block cipher** encrypts data in fixed-size chunks (or blocks), typically 128 or 256 bits.
   - **Examples**: AES, DES, 3DES.
   - Block ciphers usually work in modes such as ECB (Electronic Codebook), CBC (Cipher Block Chaining), etc., to securely encrypt data.

2. **Stream Cipher**:
   - A **stream cipher** encrypts data one bit or byte at a time, suitable for encrypting data streams.
   - **Examples**: RC4, Salsa20.
   - Stream ciphers are generally faster than block ciphers, but block ciphers are typically more secure in practice.

---

### **Encryption in Practice**

- **SSL/TLS**: Protocols like SSL/TLS use encryption to secure communications over the internet (e.g., HTTPS).
- **Disk Encryption**: Tools like **BitLocker** (Windows), **FileVault** (Mac), or **LUKS** (Linux) use encryption to secure the data 
on a hard drive or storage device.
- **End-to-End Encryption**: Used in messaging apps like **Signal** or **WhatsApp**, where the message is encrypted on the sender's 
device and can only be decrypted on the recipient's device.

---

### **Summary of Key Differences Between Encryption and Decryption**:
_________________________________________________________________________________________________________________________________
| **Aspect**    | **Encryption**                                   | **Decryption**                                              |
|---------------|--------------------------------------------------|---------------------------------------------------          |
| **Purpose**   | Convert plaintext into unreadable ciphertext     | Convert ciphertext back into readable plaintext             |
| **Key Used**  | Public key (asymmetric) or secret key (symmetric)| Private key (asymmetric) or the same secret key (symmetric) |
| **Operation** | Protects data confidentiality                    | Restores data to its original form                          |
| **Used By**   | Sender (to secure data)                          | Receiver (to retrieve the original data)                    |
|_______________|__________________________________________________|_____________________________________________________________|
---

### Conclusion:
- **Encryption** and **decryption** are fundamental concepts for securing data. **Encryption** ensures that sensitive information is 
protected from unauthorized access by converting it into unreadable data. 
**Decryption** restores the original information to its readable form, but only with the correct key.
- Symmetric encryption uses the same key for both operations, while asymmetric encryption uses a pair of keys (public and private). 
Both have their use cases depending on the need for security, efficiency, and scalability.

*/
// if you want to learn about hashing click here 
#include"hashing.cpp"