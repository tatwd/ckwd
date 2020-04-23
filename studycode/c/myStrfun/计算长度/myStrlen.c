#include <stdio.h>
#include <stdlib.h>

int myStrlen(char s[])
{
    int i=0;
    while(s[i]!='\0') i++;
    return i;
}


int main()
{
    char s[20];
    int length;
    printf("Input strings:");
    gets(s);
    length=myStrlen(s);
    printf("length=%d",n);
}
