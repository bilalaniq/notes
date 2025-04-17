// ------------------------------------EVP-------------------------------
/*
The openssl/evp.h header file is part of the OpenSSL library and provides an interface for cryptographic operations. '
The EVP (Envelope) API is a high-level, general-purpose interface that abstracts many of OpenSSL's cryptographic operations,
making it easier to use the underlying algorithms for tasks like hashing, encryption, decryption, signing, and verifying signatures.

The EVP functions provide a high level interface to OpenSSL cryptographic functions.

They provide the following features:

A single consistent interface regardless of the underlying algorithm or mode
Support for an extensive range of algorithms
Encryption/Decryption using both symmetric and asymmetric algorithms
Secure Hash functions
Sign/Verify
Key derivation
Message Authentication Codes
Support for external crypto engines

lets see each one in detail


-----------------------------Encryption/Decryption using both symmetric and asymmetric algorithms-----------------------------
*/
// if you want to learn about encryption and decryption click here
#include"encryption&_decryption.cpp"
/*
There are indeed other parts of the OpenSSL library and other libraries that can also perform encryption and cryptographic tasks. 
However, EVP (the high-level API in OpenSSL) simplifies these tasks, making it easier for developers to use cryptography without 
delving deeply into the low-level implementation details.



_________________________________________________________________________________________________________________________________________
| **Aspect**             | **Low-Level Cryptographic Functions**                   | **High-Level Cryptographic Functions (EVP API)**   |
|------------------------|---------------------------------------------------------|----------------------------------------------------|
| **Abstraction Level**  | Low-level: Requires the user to interactdirectly with   | High-level: Abstracts the cryptographic details    |
|                        | specific algorithms (e.g., AES, RSA).                   | and offers a unified interface.                    |
|                        |                                                         |                                                    |
| **Ease of Use**        | Complex: You must manage all details like memory,       | Simplified: Handles many of the complexities for   |
|                        | buffers, keys, modes, and padding for each algorithm.   | you, such as padding, key management, etc.         |
|                        |                                                         |                                                    |
| **Flexibility**        | Less flexible: You have to manually handle different    | Highly flexible: One set of functions (`EVP_*`) can|
|                        |  algorithms (e.g., AES, RSA) with specific functions.   | be used for many algorithms (e.g.,AES,SHA-256,RSA).|
|                        |                                                         |                                                    |
| **Code Length**        | Typically longer: You write more code for each          | Typically shorter: You can use the same functions  |
|                        | algorithm, handling specifics (key sizes, block modes). | for different algorithms,reducing theamount of code|
|                        |                                                         |                                                    |
| **Control**            | Full control: You manage each aspect of the algorithm,  | Less control: Some aspects (like padding,          |
|                        | such as encryption mode (CBC, ECB), key sizes,          | initialization vector) are handled internally      |
|                        | and padding manually.                                   | by the EVP API.                                    |
|                        |                                                         |                                                    |
| **Error Handling**     | More complicated: You need to manually check for errors | Simplified: Error handling is still necessary but  |
|                        | during the operation (e.g., key size mismatch,          | managed by the EVP API, making it easier           |
|                        | bad padding).                                           | to troubleshoot.                                   |
|                        |                                                         |                                                    |
| **Implementation       | Specific to each algorithm: Functions are distinct for  | Unified: One function set (`EVP_*`) is used for    |
|  of Algorithms*        | each algorithm (e.g., `AES_encrypt()`, `RSA_sign()`).   | many algorithms (e.g., `EVP_aes_256_cbc()`,        |
|                        |                                                         |  `EVP_sha256()`).                                  |
|                        |                                                         |                                                    |
| **Performance**        | Potentially more optimized: Since you're directly       | Slightly less optimized: The abstraction layer     |
|                        | interacting with the algorithm, it may offer            | could introduce a small overhead compared to       |
|                        | fine-grained performance control.                       | low-level code, though this difference is usually  |
|                        |                                                         | negligible.                                        |                                         
|                        |                                                         |                                                    |
| **Use Case**           | Best for custom cryptographic solutions or cases        | Best for most general cryptographic use cases      |
|                        | requiring specific optimizations or special             | (e.g., hashing, encryption, signing) where ease of |                                                    
|                        | configurations.                                         | use is a priority.                                 |
|                        |                                                         |                                                    | 
| **Memory Management**  | Manual: You must manually allocate and manage memory    | Simplified: The EVP API handles many aspects of    |
|                        | for keys, buffers, and ciphertext.                      | memory management for you (e.g., memory buffers    |
|                        |                                                         | are managed internally).                           |
|                        |                                                         |                                                    |
| **Learning Curve**     | Steep: You need to understand the intricacies of        | Easier to learn: You can focus on what you want to |
|                        | each algorithm and handle complex details such as       | do (hashing, encryption, etc.) without dealing     | 
|                        | key generation, padding, modes, etc.                    | with low-level details.                            |
|                        |                                                         |                                                    |
| **Cross-Algorithm      | Difficult: Each algorithm has a unique interface.       | Easy: The `EVP` functions are designed to work     |
| Compatibility          | For example, AES and RSA require different function     | with many different algorithms, making it easier   |
|                        | calls for similar tasks (like signing or encrypting).   | to switch between algorithms without rewriting     | 
|                        |                                                         | large portions of your code.                       |
|                        |                                                         |                                                    |
| **Algorithm            | Harder: Switching between algorithms may require        | Easier: Switching algorithms is simplified with    |
| Switching**            | significant code changes                                | functions like `EVP_DigestInit_ex()`               |
|                        | (e.g., switching from AES to RSA)                       | (to switch hashing algorithms) or `                |
|                        |                                                         | EVP_CipherInit_ex()` (for switching ciphers).      |
|                        |                                                         |                                                    |
| **Security**           | You are responsible for managing every detail           | More secure by default: The API handles important  |
|                        | (e.g., proper padding, key exchange), so more room      | aspects like padding and initialization vector     |
|                        | for errors.                                             | management, reducing the risk of common            | 
|                        |                                                         | implementation mistakes.                           |
|                        |                                                         |                                                    |
| **Portability**        | Less portable: You may have to write different code for | More portable: The same code can work across       |
|                        | each algorithm and handle dependencies.                 | different cryptographic algorithms, reducing       |                                                   
|                        |                                                         | platform-specific details.                         |
|                        |                                                         |                                                    |
|________________________|_________________________________________________________|____________________________________________________|                          


so to sum it up consider the lowlevel Cryptographic Functions as an manual car and high level Cryptographic Functions as 
an automatic car


In order to perform encryption/decryption you need to know:

Your algorithm
Your mode
Your key
Your Initialisation Vector (IV)



*/











/*
-------------------------------------------Secure Hash functions---------------------------------
A Message Digest or Hash Function takes any arbitrary message (with any content or length) as an input and provides a fixed size hash
value as a result. Specifically the function exhibits the following properties:

It is simple to create a hash value for any given message
It is computationally infeasible to calculate a message from any given hash (i.e. the function is one-way)
It is infeasible to modify a message without also modifying the hash value
It is infeasible to find two messages that result in the same hash

The OpenSSL library supports a wide number of different hash functions including the popular Category:SHA-2 set of hash functions
(i.e. SHA-224, SHA-256, SHA-384 and SHA-512).


Using an OpenSSL message digest/hash function, consists of the following steps:

Create a Message Digest context
Initialise the context by identifying the algorithm to be used (built-in algorithms are defined in evp.h)
Provide the message whose digest needs to be calculated. Messages can be divided into sections and provided over a number of calls to
the library if necessary
Caclulate the digest
Clean up the context if no longer required

Message digest algorithms are identified using an EVP_MD object. These are built-in to the library and obtained through appropriate 
library calls (e.g. such as EVP_sha256() or EVP_sha512())



following is the example to do hasing of an message using evp in cpp


#include <iostream>
#include <iomanip>       //
#include <openssl/evp.h>
#include <openssl/sha.h>

void hash_sha256(const std::string& input, unsigned char* output) {
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if (ctx == nullptr) {
        std::cerr << "Error creating EVP_MD_CTX." << std::endl;
        return;
    }

    if (EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr) != 1) {
        std::cerr << "Error initializing SHA-256." << std::endl;
        EVP_MD_CTX_free(ctx);
        return;
    }

    if (EVP_DigestUpdate(ctx, input.c_str(), input.length()) != 1) {
        std::cerr << "Error updating SHA-256." << std::endl;
        EVP_MD_CTX_free(ctx);
        return;
    }

    unsigned int length = 0; 
    if (EVP_DigestFinal_ex(ctx, output, &length) != 1) {
        std::cerr << "Error finalizing SHA-256." << std::endl;
        EVP_MD_CTX_free(ctx);
        return;
    }

    EVP_MD_CTX_free(ctx);
}

void print_hash(unsigned char* hash, unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    std::cout << std::endl;
}

int main() {
    std::string input_data = "Hello, OpenSSL!"; 

    unsigned char hash[EVP_MAX_MD_SIZE]; 
    hash_sha256(input_data, hash);

    std::cout << "SHA-256 hash: ";
    print_hash(hash, SHA256_DIGEST_LENGTH);

    return 0;
}

*/

// if you want to learn about iomanip library click here
#include"../chernocpp/cpp_cource/iomanip.cpp"
// and also if you want to learn about sha click here
#include"sha.cpp"