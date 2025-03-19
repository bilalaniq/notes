# envp

Here's an example of how `envp` (the environment pointer) is used in a C program. `envp` is an array of strings that represent the environment variables passed to the program at runtime.

### Example Code:

```c
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    // Print the command-line arguments (argc and argv)
    printf("Arguments:\n");
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    // Print the environment variables (envp)
    printf("\nEnvironment Variables:\n");
    for (int i = 0; envp[i] != NULL; i++) {
        printf("envp[%d]: %s\n", i, envp[i]);
    }

    return 0;
}
```

### Explanation:

- **`argv[]`** contains the command-line arguments passed to the program when it is executed.
- **`envp[]`** contains the environment variables, which are key-value pairs set by the operating system or user.

### Sample Output:

Assume you run this program with the following environment variables set:

```bash
$ export MY_VAR=123
$ export USER=example_user
$ ./your_program arg1 arg2
```

The output might look like this:

```
Arguments:
argv[0]: ./your_program
argv[1]: arg1
argv[2]: arg2

Environment Variables:
envp[0]: SHELL=/bin/bash
envp[1]: USER=example_user
envp[2]: PATH=/usr/local/bin:/usr/bin:/bin
envp[3]: MY_VAR=123
envp[4]: HOME=/home/example_user
envp[5]: LANG=en_US.UTF-8
...
envp[n]: (other environment variables)
```

### Key Points:

- `envp` contains the environment variables that provide information such as user settings, system paths, locale, etc.
- In this example, environment variables like `USER`, `PATH`, and `MY_VAR` are printed along with their values.
