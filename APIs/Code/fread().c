#include <stdio.h>

int main () 
{
    // buffer to store data
    char buffer[33];
    
    // FILE object
    FILE * stream;
    // opening a file in read mode
    stream = fopen("file_name.txt", "r");
    
    int count = fread(&buffer, sizeof(char), 33, stream);
    
    // close opened file
    fclose(stream);
    
    printf("Data read from the file: %s \n", buffer);
    printf("Number of elements read: %d", count);
    return 0;
}
//Data read from the file: Program to read input from a file 
//Number of elements read: 33
