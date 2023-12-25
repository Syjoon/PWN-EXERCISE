//Lỗi mở tệp (file open error): nếu tệp hoặc thiết bị không tồn tại, không có quyền truy cập, hoặc đã đạt đến giới hạn số 
//tệp có thể mở, hàm open() sẽ trả về giá trị -1 và gán giá trị lỗi vào biến errno1. Điều này có thể dẫn đến việc không thể
//đọc hoặc ghi dữ liệu, gây ra lỗi chương trình, hoặc mất mát dữ liệu2.
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    int fd = open("test.txt", O_RDONLY); // mở tệp test.txt để đọc
    if (fd == -1) // kiểm tra lỗi mở tệp
    {
        perror("open"); // in ra thông báo lỗi
        printf("Giá trị lỗi là: %d\n", errno); // in ra giá trị lỗi
        return -1;
    }
    // tiếp tục đọc dữ liệu từ tệp
    close(fd); // đóng tệp
    return 0;
}

//Lỗi đọc ghi (race condition): nếu có nhiều tiến trình cùng mở cùng một tệp hoặc thiết bị để đọc hoặc ghi, 
//có thể đọc sai dữ liệu, mất mát dữ liệu, hoặc xung đột giữa các tiến trình3. Để tránh lỗi này, ta có thể sử 
//dụng các cờ (flags) để chỉ định chế độ mở tệp hoặc thiết bị, như O_RDONLY (chỉ đọc), O_WRONLY (chỉ ghi), 
//O_RDWR (đọc và ghi), O_APPEND (ghi vào cuối tệp), O_CREAT (tạo tệp mới nếu không tồn tại), O_EXCL (kiểm tra 
//xem tệp đã tồn tại hay chưa), O_TRUNC (xóa nội dung tệp cũ nếu mở để ghi), O_SYNC (đồng bộ hóa dữ liệu khi ghi),
//O_NONBLOCK (không chặn khi đọc hoặc ghi), O_NOCTTY (không gán thiết bị làm thiết bị điều khiển), O_NOFOLLOW (không 
//theo dõi liên kết tượng trưng), O_CLOEXEC (đóng tệp khi thực hiện lệnh exec)1. Ví dụ:
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
    int fd = open("test.txt", O_RDWR | O_APPEND); // mở tệp test.txt để đọc và ghi ở chế độ ghi vào cuối tệp
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

//Lỗi xử lý dữ liệu (data corruption): nếu tệp hoặc thiết bị bị hỏng, sai định dạng, hoặc không
//phù hợp với kiểu dữ liệu mong muốn, có thể tính toán sai, hiển thị sai, hoặc gây ra các lỗi khác4.
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
