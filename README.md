
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
