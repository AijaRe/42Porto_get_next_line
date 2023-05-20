# 42Porto_get_next_line

Function that reads a line from a file descriptor.  
  
DESCRIPTION  
This function takes an opened file descriptor and returns its next line.
This function has undefined behavior when reading from a binary file.  
PARAMETERS  
#1. A file descriptor  
RETURN VALUES  
If successful, get_next_line returns a string with the full line ending in a line break (`\n`) when there is one. 
If an error occurs, or there's nothing more to read, it returns NULL.  

More info in the pdf.
