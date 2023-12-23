# include<stdio.h>
int main(){
	// Initializing the string.
	char string[] = "puts() function in C";
	// Writing our string to stdout.
	puts(string);
    
	return 0;
}
//output: puts() function in C

////////////////////////////////////////////////////////////
#include <stdio.h>

int main()
{
    //file pointer to keep the address of the FILE object
    FILE *fp = NULL;

    // Passing the file name and write mode
    fp = fopen("myFile.txt", "w");

    // Checking if the file is created or not
    if(fp == NULL)
    {
        printf("Error to create the new file\n");
    }

    // Using the fputs method to write the string in the created file
    fputs("Hello, World!",fp);

    // function to close the file
    fclose(fp);


    printf("File creation completed\n");

    return 0;
}

//output: File creation completed
//Data in myFile.txt: Hello, World!
