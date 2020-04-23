#include <stdio.h>
#include <string.h>

void myStrcat(char t[],char s[])
{
    int i=0,j=0;
    while(t[i]) i++;
    while(t[i++]=s[j++]);
}

int main()
{
    char t[20],s[20];
    printf("Input t:");
    gets(t);
    printf("Input s:");
    gets(s);
    myStrcat(s,t);
    printf("Input s:");
    puts(s);
}
