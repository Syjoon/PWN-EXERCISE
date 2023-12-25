//Lỗi tràn bộ nhớ (buffer overflow): nếu số byte đọc vào vượt quá kích thước của vùng nhớ, có thể ghi đè lên 
//các vùng nhớ khác hoặc gây ra lỗi chương trình.
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char buffer[10]; // vùng nhớ có kích thước 10 byte
    int fd = open("test.txt", O_RDONLY); // mở tệp test.txt để đọc
    if (fd == -1) // kiểm tra lỗi mở tệp
    {
        perror("open");
        return -1;
    }
    int n = read(fd, buffer, 20); // đọc 20 byte từ tệp vào buffer
    if (n == -1) // kiểm tra lỗi đọc tệp
    {
        perror("read");
        return -1;
    }
    printf("Đã đọc %d byte: %s\n", n, buffer); // in ra kết quả đọc
    close(fd); // đóng tệp
    return 0;
}

//Lỗi đọc ghi (race condition): nếu có nhiều tiến trình cùng đọc hoặc ghi vào cùng một tệp hoặc thiết bị, có thể đọc sai dữ liệu,
//mất mát dữ liệu, hoặc xung đột giữa các tiến trình.
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
    int fd = open("test.txt", O_RDWR); // mở tệp test.txt để đọc và ghi
    if (fd == -1) // kiểm tra lỗi mở tệp
    {
        perror("open");
        return -1;
    }
    int pid = fork(); // tạo một tiến trình con
    if (pid == -1) // kiểm tra lỗi tạo tiến trình
    {
        perror("fork");
        return -1;
    }
    if (pid == 0) // tiến trình con
    {
        char buffer[10];
        int n = read(fd, buffer, 10); // đọc 10 byte từ tệp vào buffer
        if (n == -1) // kiểm tra lỗi đọc tệp
        {
            perror("read");
            return -1;
        }
        printf("Tiến trình con đọc: %s\n", buffer); // in ra kết quả đọc
    }
    else // tiến trình cha
    {
        char *msg = "Hello\n";
        int n = write(fd, msg, 6); // ghi 6 byte từ msg vào tệp
        if (n == -1) // kiểm tra lỗi ghi tệp
        {
            perror("write");
            return -1;
        }
        printf("Tiến trình cha ghi: %s\n", msg); // in ra kết quả ghi
        wait(NULL); // đợi tiến trình con kết thúc
    }
    close(fd); // đóng tệp
    return 0;
}

//Lỗi xử lý dữ liệu (data corruption): nếu dữ liệu đọc vào bị hỏng, sai định dạng, hoặc không phù hợp với kiểu dữ liệu mong muốn, 
//có thể tính toán sai, hiển thị sai, hoặc gây ra các lỗi khác.
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int buffer[10]; // vùng nhớ có kiểu int
    int fd = open("test.txt", O_RDONLY); // mở tệp test.txt để đọc
    if (fd == -1) // kiểm tra lỗi mở tệp
    {
        perror("open");
        return -1;
    }
    int n = read(fd, buffer, 10); // đọc 10 byte từ tệp vào buffer
    if (n == -1) // kiểm tra lỗi đọc tệp
    {
        perror("read");
        return -1;
    }
    printf("Đã đọc %d byte: %d\n", n, buffer[0]); // in ra kết quả đọc
    close(fd); // đóng tệp
    return 0;
}
