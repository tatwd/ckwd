#include <stdio.h>
#include <stdlib.h>

int main()
{
     int a,b,c;
     c=0;
     system("cls"); //清屏
     printf("\t\t\t\t游戏规则\n");
     printf("\t\t******************************************\n");
     printf("\t\t现有21根火柴让人和电脑来拿。人先拿，且人和\n\t\t电脑每次拿的火柴根数在1~4之间，拿到最后一\n\t\t根的为输。此程序设计总为电脑赢。\n\t\tP=人    C=电脑    单位：根\n");
     printf("\t\t******************************************\n");
     printf("\t\t现有21根火柴！\n");
     while(c<21)
     {
          printf("\t\tP：");
          scanf("%d",&a);
          while(a<1||a>4){
               printf("\t\t请再输一次！\n");
               printf("\t\tP：");
               scanf("%d",&a);
               //break;
          }
          if(c==20)
               b=0;
          else
               b=5-a;
          printf("\t\tC：%d\n",b);

          c=c+5;
          if(21-c>0)
               printf("\t\t还有%d根火柴！\n",21-c);
          else
               break;
     }
     printf("\t\t******************************************\n");
     printf("\t\t哈哈，最后一根被你拿到，电脑获胜！\n");
     system("pause");
     return 0;
}
