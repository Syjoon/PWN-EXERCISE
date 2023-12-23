#include <stdio.h>
#include <unistd.h>

int main()
{
    int id;
    printf("Hello, World!\n");

    id = fork();
    if (id > 0) {
        /*parent process*/
        printf("This is parent section [Process id: %d].\n", getpid());
    }
    else if (id == 0) {
        /*child process*/
        printf("fork created [Process id: %d].\n", getpid());
        printf("fork parent process id: %d.\n", getppid());
    }
    else {
        /*fork creation faile*/
        printf("fork creation failed!!!\n");
    }

    return 0;
}

//Hello, World!
//This is parent section [Process id: 1252].
//fork created [Process id: 1253].
//fork parent process id: 1252.
