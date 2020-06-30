#include<stdio.h>

void main(){
    int num[5] = {10, 2, 3, 7, 50};
    int i;

    int total=0;
    int max=num[0];
    int min=num[0];
    for(i=0;i<5;i++){
        total = num[i] + total;
        if(num[i]<min){
            min = num[i];
        } 
        if(num[i]>max){
            max = num[i];
        }
    }

    int average = total /5;
    printf("Total Value: %d\n", total);
    printf("Average Value: %d\n", average);
    printf("Max Value is: %d\n", max);
    printf("Min Value is: %d\n", min);
}