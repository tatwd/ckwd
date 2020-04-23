#include <stdio.h>
#include <stdlib.h>

int main(void){
    int a = 2,b = 5;
    int m = 3,n = 6;
    int s = 4,t = 7; //二进制为：s == 0100 t == 0111
    printf("Before:\na=%d,b=%d\nm=%d,n=%d\ns=%d,t=%d\n",a,b,m,n,s,t);

    /* 有参交换 */
    
    int temp;
    temp = a;
    a = b;
    b = temp;

    /* 无参交换 */
    
    //法一：算术运算
    m = m + n;
    n = m - n;
    m = m - n;
    
    //法二：位运算
    //发生在二进制间，同0异1。
    //before：a == 0100(4) b == 0111(7)
    
    s = s ^ t;  //  s == 0011(3) t == 0111(7)
    t = s ^ t;  //  s == 0011(3) t == 0011(4)
    s = s ^ t;  //  s == 0111(7) t == 0011(4)
    
    //after:s == 0111(7) t == 0011(4)   Successful!
    
    printf("After:\na=%d,b=%d\nm=%d,n=%d\ns=%d,t=%d\n",a,b,m,n,s,t);
    return 0;
}
