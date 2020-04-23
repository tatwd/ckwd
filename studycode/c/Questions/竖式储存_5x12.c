#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,h;
    int a,b,c,d,e,f;
    int n=0;
    FILE *fp;
    fp=fopen("outTxt/ss_5x12.txt","w");
    if(fp!=NULL)
    {
         for(i=2;i<=8;i++){
             for(j=23;j<=87;j++){
                 a=j/10;
                 if(a==i) continue;
                 b=j-a*10;
                 if(b==i||b==a||b==0||b==1||b==9) continue;
                 for(k=23;k<=87;k++){
                    c=k/10;
                    if(c==i||c==a||c==b||c==0||c==1||c==9) continue;
                    d=k-c*10;
                    if(d==i||d==a||d==b||d==c||d==0||d==1||d==9) continue;
                    for(h=23;h<=87;h++){
                         e=h/10;
                         if(e==i||e==a||e==b||e==b||e==c||e==d||e==0||e==1||e==9) continue;
                         f=h-e*10;
                         if(f==i||f==a||f==b||f==b||f==c||f==d||f==e||f==0||f==1||f==9) continue;
                         if((i+j+900+k)==(1000+h)){
                              n=n+1;
                              fprintf(fp,"%4d\t%4d\t%4d\t%4d\t%4d\n",i,i,i,i,i);
                              fprintf(fp,"%4d\t%4d\t%4d\t%4d\t%4d\n",j,j,j,j,j);
                              fprintf(fp,"+9%d\t+9%d\t+9%d\t+9%d\t+9%d\n",k,k,k,k,k);
                              fprintf(fp,"-----\t----\t----\t----\t----\n");
                              fprintf(fp,"10%d\t10%d\t10%d\t10%d\t10%d\n",h,h,h,h,h);
                         }
                    }
               }
            }
         }
         fprintf(fp,"Result:n=%d\n",n);
         fclose(fp);
         printf("Successful!Please read ss_5x12.txt in outTxt!\n");
    }
    else
     printf("Fail!Please make outTxt!\n");
}
