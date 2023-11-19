#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    int fd; 
    char buf[10] = "Hello"; 
    fd = open("file.txt", O_WRONLY | O_CREAT); 
    if (fd == -1) 
    {
        perror("open");
        return 1;
    }
    if (write(fd, buf, 5) != 5) 
    {
        perror("write");
        return 1;
    }
    close(fd); 
    return 0;
}
