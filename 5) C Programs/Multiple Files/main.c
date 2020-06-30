#include <stdio.h>
#include "math.h"

void main(){
    int num1 = 5;
    int num2 = 4;

    int addresult = add(num1,num2);
    int subtractresult = subtract(num1,num2);
    int multiplyresult = multiply(num1,num2);

    printf("Add is: %d\n Subtract is: %d\n Multiply is: %d", 
        addresult,subtractresult,multiplyresult);
}