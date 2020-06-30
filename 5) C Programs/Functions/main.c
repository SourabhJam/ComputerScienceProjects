#include <stdio.h>

void main(){
    int num1 = 5;
    int num2 = 4;

    int numAdd = add(num1,num2);
    printf("Addition is: %d\n", numAdd);

    int numSub = subtract(num1,num2);
    printf("Subtraction is: %d\n", numSub);

    int numMul = multiply(num1,num2);
    printf("Multiplication is: %d\n", numMul);
}

int add(int x, int y){
    return x+y;
}

int subtract(int x, int y){
    return x-y;
}

int multiply(int x, int y){
    return x*y;
}