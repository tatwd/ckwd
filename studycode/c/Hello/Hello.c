#include <stdio.h>

int main(){
        int b; 
        printf("Hello world!\n");
        b = test();
        printf("%d",b);
        return 0;
}
int test(){
        int a;
        printf("a=");
        scanf("%d",&a);
        return a;
}
