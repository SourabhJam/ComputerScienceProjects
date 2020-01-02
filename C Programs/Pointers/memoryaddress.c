#include <stdio.h>

void main () {

   int  var1;
   char var2[10];

   strcpy(var2,"SOURABH");
   var1 = 20;
   printf("Address of var1 variable: %p\n", &var1  );
   printf("Address of var2 variable: %p\n", &var2  );

   printf("var1 value: %d\n", var1);

   int *p;
   p = &var1;
   *p = 30;
   printf("var1 value: %d\n", var1);

   printf("var2 :%s\n", var2);
   char *p1;
   p1 = &var2[0];
   *p1 = 'A';
   printf("var2 :%s\n", var2);
   p1++;
   *p1 = 'X';
   printf("var2 :%s\n", var2);
   printf("p1 is now:%s\n",p1);
}