#include <stdio.h>
#include <stdlib.h>
#define N 2000
int main()
{
    int a,b,c,d,e,f;
    int i=0,j,k,h,z,m=0;
    int total=0;
    int eg1[N];
    int eg2[N];
    int eg3[N];
    int eg4[N];
    for(i=2;i<=8;i++){
    for(h=23;h<=87;h++){
        a=h/10;
        if(a==i||a==0||a==9||a==1)    continue;
        b=h%10;
        if(b==a||b==i||b==0||b==1||b==9)    continue;

         for(j=23;j<=87;j++){
            c=j/10;
            if(c==a||c==i||c==b||c==0||c==9||c==1)  continue;
            d=j%10;
            if(d==c||d==a||d==b||d==i||d==0||d==1||d==9)    continue;

            for(k=23;k<=87;k++){
               e=k/10;
               if(e==i||e==a||e==c||e==d||e==b||e==0||e==9||e==1)   continue;
                    f=k%10;
                    if(f==e||f==c||f==d||f==a||f==b||f==i||f==0||f==9||f==1)    continue;
                    if((i+h+900+j)==(1000+k))
                    {
                        eg1[total]=i;
                        eg2[total]=h;
                        eg3[total]=900+j;
                        eg4[total]=1000+k;
                        total++;
                    }

                }
            }
        }
    }
    		
   			for(j=0;j<12;++j)
			{	
				for(m=j*5;m<(j+1)*5;m++)
					printf("%4d\t",eg1[m]);
				printf("\n");
				for(m=j*5;m<(j+1)*5;m++)
					printf("%4d\t",eg2[m]);
				printf("\n");
				for(m=j*5;m<(j+1)*5;m++)
					printf("+%3d\t",eg3[m]);
				printf("\n");
				for(m=j*5;m<(j+1)*5;m++)
					printf("----\t");
				printf("\n");
				for(m=j*5;m<(j+1)*5;m++)
					printf("%4d\t",eg4[m]);
				printf("\n");
			}	
    printf("total=%d\n",total);
    return 0;
}
