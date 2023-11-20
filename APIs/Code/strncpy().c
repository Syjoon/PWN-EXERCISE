#include<stdio.h>
#include<string.h>

int main()
{
  char str[50] = "Hello World!";
  char copy_str[50];
  strncpy(copy_str, str, 8);
  printf("Copy string: %s", copy_str);
  return 0;
}
