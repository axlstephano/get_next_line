# 01_Get_next_line

# Get Next Line

## Description

This is a simple C program that implements the "get_next_line" function, which reads a text file line by line. The code is designed to be used in a larger project or as a standalone utility.

## Features

- Read text files line by line.
- Efficiently handle large files.
- Memory management to avoid leaks.
- Suitable for various programming projects.

## Usage

To use this program, follow these steps:

1. Include the `get_next_line.h` header in your project.
2. Call the `get_next_line(int fd)` function to read lines from a file descriptor.
3. The function returns a pointer to the line or `NULL` when the end of the file is reached or an error occurs.

```c
char *line;
while ((line = get_next_line(fd)) != NULL) {
    // Process the line
    printf("%s", line);
    free(line); // Remember to free the line when you're done with it
}
S