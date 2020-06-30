#include <stdio.h>

void swap(int *x, int *y);

void main(){
    int num1 = 3;
    int num2 = 4;

    printf("Number 1 is : %d\n", num1);
    printf("Number 2 is : %d\n", num2);

    swap(&num1,&num2);

    printf("New Num1 is: %d     New Num2 is: %d\n",num1,num2);
}


void swap(int *x, int *y){
   // printf("in swap before : x:%p:%d y:%p:%d\n", x, *x, y, *y);
    int x1, y1;
    x1 = *x;
    y1 = *y;
    *x = y1;
    *y = x1;
    //printf("in swap before : x:%d y:%d\n", *x, *y);
}