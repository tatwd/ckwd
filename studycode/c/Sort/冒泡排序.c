#include <stdio.h>
#include <stdlib.h>

//ð�������ӡÿһ��
void fun(int a[],int n)
{
     int i,j,pose,temp,k,num=0;
     i=n-1;
     while(i>0)
     {
          pose=0;
          for(j=0;j<i;++j)
               if(a[j]>a[j+1])
               {
                    pose=j;
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    num++;
               }
          i=pose;

          for(k=0;k<n;k++)
               printf("%3d",a[k]);
          printf("\n");
     }
     printf("���������%d\n",num);

}

int main()
{
     int a[10]={1,5,3,6,4,2,7,8,9,10};
     fun(a,10);
     system("pause");
     return 0;
}
