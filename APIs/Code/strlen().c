#include<stdio.h>
#include<string.h>

int main()
{
  char str[50] = "Hello World!";
  int length =strlen(str);
  printf("Size of string: %d", length);
  return 0;
}

/////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

int main()
{
    char *str = NULL; // con trỏ NULL không trỏ đến một chuỗi ký tự hợp lệ
    int len = strlen(str); // gọi hàm strlen() với tham số không hợp lệ
    printf("Độ dài của chuỗi là %d\n", len); // in ra kết quả không xác định
    return 0;
}

