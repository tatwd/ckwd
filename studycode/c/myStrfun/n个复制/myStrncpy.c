#include <stdio.h>
#include <stdlib.h>

void myStrncpy(char t[],char s[],int n)
{
    int i=0;
    while(s[i]!=s[n]){
        t[i]=s[i];
        i++;
    }
    t[i]='\0';
}


int main()
{
    char t[20],s[20];
    int n;
    printf("Input t:");
    gets(t);
    printf("Input s:");
    gets(s);
    printf("Input n:");
    scanf("%d",&n);
    myStrncpy(t,s,n);
    printf("After t:");
    puts(t);
}
