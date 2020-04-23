#include <stdio.h>
#include <stdlib.h>

void myStrcpy(char t[],char s[])
{
    int i=0;
    while(s[i]){
        t[i]=s[i];
        i++;
    }
    t[i]='\0';
}


int main()
{
    char t[20],s[20];
    printf("Input t:");
    gets(t);
    printf("Input s:");
    gets(s);
    myStrcpy(t,s);
    printf("After t:");
    puts(t);
}
