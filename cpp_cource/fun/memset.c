

/*

#include <stdio.h>

void *my_memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    while (n--) {
        *d++ = *s++;  // Copy byte by byte
    }

    return dest;
}

int main() {
    char src[] = "Hello, World!";
    char dest[20];  // Destination buffer

    my_memcpy(dest, src, sizeof(src));  // Copy data

    printf("Copied String: %s\n", dest);  // Output copied string
    return 0;
}


*/

// Optimized Version Using size_t

#include <stdio.h>
#include <stdint.h>

void *my_memcpy_optimized(void *dest, const void *src, size_t n)
{
    size_t i;

    // Copy in chunks of size_t for speed
    size_t *d_word = (size_t *)dest;
    const size_t *s_word = (const size_t *)src;
    for (i = 0; i < n / sizeof(size_t); i++)
    {
        d_word[i] = s_word[i]; // Copy multiple bytes at once
    }

    // Copy any remaining bytes
    unsigned char *d_byte = (unsigned char *)(d_word + i);
    const unsigned char *s_byte = (const unsigned char *)(s_word + i);
    for (i = 0; i < n % sizeof(size_t); i++)
    {
        d_byte[i] = s_byte[i];
    }

    return dest;
}

int main()
{
    char src[] = "Optimized memcpy!";
    char dest[20];

    my_memcpy_optimized(dest, src, sizeof(src));
    printf("Copied String: %s\n", dest);

    return 0;
}
