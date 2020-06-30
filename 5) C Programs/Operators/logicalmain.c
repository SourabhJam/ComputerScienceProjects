#include <stdio.h>

void main(){
    boolean i = true;
    boolean j = false;

    if(i && j){
        printf("Both are true");
    }
    if(i || j){
        printf("One is true");
    }
    if(! i){
        printf("i is true");
    }
}