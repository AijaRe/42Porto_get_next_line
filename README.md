
# 42Porto_get_next_line

Function that reads a line from a file descriptor.  
Main concepts: 
- static variables 
- read function
- memory allocation


## Description

This function takes an opened file descriptor and returns its next line. This function has undefined behavior when reading from a binary file.
## Prototype

```C
char *get_next_line(int fd);
```
Parameters: a file descriptot (int).

## Return values
If successful, get_next_line returns a string with the full line ending in a line break (\n) when there is one. If an error occurs, or there's nothing more to read, it returns NULL.
## Bonus
Read from multiple file descriptors at the same time.

More info in the subject pdf.

## Norminette
This project has to be written in accordance with the Norm, which is the coding standard of the school 42.

The Norm includes:
- Forbidden: for, do...while, switch, case, goto, ternary operators and variable-length arrays 
- Maximum of 25 lines per function
- Maximum line length: 80 columns
- Maximum 4 parameters per function 
- Variable assignments and declarations must be on separate lines
- etc...

  
## Useful links

 - [Understanding get_next_line and 'read' function - nikito](https://www.youtube.com/watch?v=-Mt2FdJjVno)  
 - [Local, global & static variables - codequoi](https://www.codequoi.com/en/local-global-static-variables-in-c/)


