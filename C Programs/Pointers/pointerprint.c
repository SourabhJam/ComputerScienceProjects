#include <stdio.h>

void main(){
    char *ptr;
    char name[10];
    strcpy(name, "Sourabh");
    ptr = &name[0];
    int i;

    //using pointer
    for(i=0;*ptr != '\0';i++){
       printf("%c",*ptr);
   }
    //using array
   for(i=0;i<strlen(name);i++){
       printf("%c\n",name[i]);
   }
    

}