#include <stdio.h>

void main() {

   FILE *fp;
   char buff[255];

   fp = fopen(".//test.txt", "r");

   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );
   
   fclose(fp);

}