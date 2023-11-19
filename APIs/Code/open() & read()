#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[1024];
    ssize_t bytes_read;

    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        perror("read"); 
        exit(EXIT_FAILURE);
    }

    buffer[bytes_read] = '\0'; 

    printf("Dữ liệu đã đọc: %s\n", buffer);

    close(fd);

    return 0;
}
