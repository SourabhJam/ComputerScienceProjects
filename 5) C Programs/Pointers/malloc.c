#include <stdio.h>
#include <malloc.h>

void main(){
    char* name = NULL;    //this is a pointer
    name = malloc(10);    //allocating 10 bytes
    strcpy(name, "Sourabh");    //copying bytes into memory

    printf("My name is: %s", name);

    free(name);
}