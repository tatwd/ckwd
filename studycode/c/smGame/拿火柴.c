#include <stdio.h>
#include <stdlib.h>

int main()
{
     int a,b,c;
     c=0;
     system("cls"); //����
     printf("\t\t\t\t��Ϸ����\n");
     printf("\t\t******************************************\n");
     printf("\t\t����21��������˺͵������á������ã����˺�\n\t\t����ÿ���õĻ�������1~4֮�䣬�õ����һ\n\t\t����Ϊ�䡣�˳��������Ϊ����Ӯ��\n\t\tP=��    C=����    ��λ����\n");
     printf("\t\t******************************************\n");
     printf("\t\t����21�����\n");
     while(c<21)
     {
          printf("\t\tP��");
          scanf("%d",&a);
          while(a<1||a>4){
               printf("\t\t������һ�Σ�\n");
               printf("\t\tP��");
               scanf("%d",&a);
               //break;
          }
          if(c==20)
               b=0;
          else
               b=5-a;
          printf("\t\tC��%d\n",b);

          c=c+5;
          if(21-c>0)
               printf("\t\t����%d�����\n",21-c);
          else
               break;
     }
     printf("\t\t******************************************\n");
     printf("\t\t���������һ�������õ������Ի�ʤ��\n");
     system("pause");
     return 0;
}
