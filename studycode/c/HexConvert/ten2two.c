#include <stdio.h>
#include <stdlib.h>

//decimal number to binary number,eg. 4 -> 100
void ten2two(int num){
    if(num == 0){
        return;
    }else{
        int m = num % 2;
        num = num / 2;
        // printf("%d",m);  //sequential printing
        ten2two(num);
        printf("%d",m);     //reverse printing
    }
}

void main(){
    ten2two(4);
}