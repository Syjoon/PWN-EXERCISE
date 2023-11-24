// Đoạn code C minh họa cho lỗi tràn bộ đệm khi sử dụng hàm strcpy()

#include <stdio.h>
#include <string.h>

int main()
{
    char dest[10]; // mảng ký tự đích có kích thước 10
    char src[] = "Hello, world!"; // chuỗi ký tự nguồn có kích thước 14 (bao gồm ký tự kết thúc '\0')
    int x = 100; // một biến số nguyên

    printf("Before strcpy:\n");
    printf("dest = %s\n", dest); // in ra giá trị của mảng đích
    printf("src = %s\n", src); // in ra giá trị của chuỗi nguồn
    printf("x = %d\n", x); // in ra giá trị của biến x

    strcpy(dest, src); // sao chép chuỗi nguồn vào mảng đích

    printf("After strcpy:\n");
    printf("dest = %s\n", dest); // in ra giá trị của mảng đích
    printf("src = %s\n", src); // in ra giá trị của chuỗi nguồn
    printf("x = %d\n", x); // in ra giá trị của biến x

    return 0;
}
//Before strcpy:
//dest = @
//src = Hello, world!
//x = 100
//After strcpy:
//dest = Hello, world!
//src = Hello, world!
//x = 2188396
