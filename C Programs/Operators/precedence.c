#include <stdio.h>

void main(){
    int i = 10;
    int j = i++;
  
    int a = 10;
    int k = ++a;

    printf("Value of I is: %d\n", i);
    printf("Value of J is: %d\n", j);
    printf("Value of K is: %d\n", k);
}