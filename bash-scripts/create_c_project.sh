#!/bin/bash

# Prompt for project name
read -p "Enter project name: " project_name
mkdir -p "$project_name"/{src,include}

# Set file names
main_file="main.c"
compiler="gcc"

# Create main source file
cat <<EOF >"$project_name/src/$main_file"
#include "../include/utils.h"

int main(int , char**) {
    printf("Hello, World!\n");
    return 0;
}


EOF

# Create header file with #pragma once
cat <<EOF >"$project_name/include/utils.h"
#pragma once

#include <stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<assert.h>
#include<error.h>
#include<stdbool.h>


int main(int , char**);
EOF

# Create Makefile
cat <<EOF >"$project_name/Makefile"
CC=$compiler
CFLAGS=-Iinclude
SRC=src/$main_file
OBJ=\$(SRC:.c=.o)
TARGET=$project_name

all: \$(TARGET)

\$(TARGET): \$(OBJ)
	\$(CC) \$(CFLAGS) -o \$(TARGET) \$(OBJ)

clean:
	rm -f src/*.o \$(TARGET)
EOF

# Create .gitignore
cat <<EOF >"$project_name/.gitignore"
*.o
$project_name
EOF

# Create README.md
cat <<EOF >"$project_name/README.md"
# $project_name

A simple C project.

## Build
\`\`\`
make
\`\`\`

## Run
\`\`\`
./$project_name
\`\`\`
EOF

echo "C project '$project_name' created successfully!"
