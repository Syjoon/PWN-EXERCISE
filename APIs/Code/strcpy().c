#include<stdio.h>
#include<string.h>

int main()
{
  char str[50] = "Hello World!";
  char copy_str[50];
  strcpy(copy_str, str);
  printf("Copy string: %s", copy_str);
  return 0;
}