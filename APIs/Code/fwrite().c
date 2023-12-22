#include<stdio.h>
int main () {
   FILE *fp;
   char str[] = "C programming tutorial.";
   fp = fopen( "test.txt" , "w" );
   fwrite(str , 1 , sizeof(str) , fp );

   fclose(fp);
   fp = fopen("test.txt","r");
   int c;
   while(1) {
      c = fgetc(fp);
      if( feof(fp) ) {
         break ;
      }
      printf("%c", c);
   }
   fclose(fp);
   return(0);
}

//Output: C programming tutorial.
