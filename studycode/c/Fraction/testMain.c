#include <stdio.h>
#include <stdlib.h>

#include "fraction.h"

int main(void){
    int a,b;
    printf("Input a fraction(first fz,next fm):\n");
    scanf("%d%d",&a,&b);
    
    achReduFra(a,b);

    return 0;
}
