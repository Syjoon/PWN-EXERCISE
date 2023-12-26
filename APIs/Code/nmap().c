#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd; // file descriptor
    char *data; // pointer to mapped data
    struct stat st; // file status
    fd = open("test.txt", O_RDONLY); // open file for reading
    if (fd == -1) // check if file is opened successfully
    {
        perror("open"); // print error message
        return -1; // exit with error code
    }
    fstat(fd, &st); // get file status
    data = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0); // map file to memory
    if (data == MAP_FAILED) // check if mapping is successful
    {
        perror("mmap"); // print error message
        close(fd); // close file
        return -1; // exit with error code
    }
    printf("%s\n", data); // print mapped data
    munmap(data, st.st_size); // unmap file from memory
    close(fd); // close file
    return 0; // exit with success code
}
