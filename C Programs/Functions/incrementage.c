#include <stdio.h>

void changeValue(int *x, int *y);

void main(){
    int num1 = 4;
    int num2 = 10;
    printf("Num1 is: %d     Num2 is: %d\n",num1,num2);

    changeValue(&num1,&num2);

    printf("New Num1 is: %d     New Num2 is: %d\n",num1,num2);
}

void changeValue(int *x, int *y){
    *x = (*x)++;
    *y = (*y)--;
}