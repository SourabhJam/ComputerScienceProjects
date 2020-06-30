#include <stdio.h>
#include <malloc.h>

void getString(char **ptr);

void main(){
    
    int space = 10;
    char* nameInfo;
    nameInfo = NULL;
    getString(&nameInfo);
    printf("%s", nameInfo);
}

void getString(char **ptr){
     *ptr = malloc(10);
     strcpy(*ptr, "Hello");
}