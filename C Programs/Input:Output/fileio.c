#include <stdio.h>

void main() {
   FILE *fp;

   fp = fopen(".\\test.txt", "w+");
   fprintf(fp, "This is for testing\n");
   fclose(fp);

   

}