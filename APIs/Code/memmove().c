#include <stdio.h> 
#include <string.h> 
  
int main() 
{ 
    char str1[] = "Geeks"; // Array of size 100 
    char str2[] = "Quiz"; // Array of size 5 
  
    puts("str1 before memmove "); 
    puts(str1); 
  
    /* Copies contents of str2 to sr1 */
    memmove(str1, str2, sizeof(str2)); 
  
    puts("\nstr1 after memmove "); 
    puts(str1); 
  
    return 0; 
}

//str1 before memmove 
//Geeks

//str1 after memmove 
//Quiz

///////////////////////////////////////////////////////////////////////////////////////////////////

Risk:

#include <stdio.h> 
#include <string.h> 
int main() 
{ 
    char csrc[100] = "Geeksfor"; 
    memcpy(csrc + 5, csrc, strlen(csrc) + 1); 
    printf("%s", csrc); 
    return 0; 
}

//GeeksGeeksfor

//////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h> 
#include <string.h> 
int main() 
{ 
    char str[100] = "Learningisfun"; 
    char *first, *second; 
    first = str; 
    second = str; 
    printf("Original string :%s\n ", str); 
      
    // when overlap happens then it just ignore it 
    memcpy(first + 8, first, 10); 
    printf("memcpy overlap : %s\n ", str); 
  
    // when overlap it start from first position 
    memmove(second + 8, first, 10); 
    printf("memmove overlap : %s\n ", str); 
  
    return 0; 
}

//Original string :Learningisfun
//memcpy overlap : LearningLearningis
//memmove overlap : LearningLearningLe
