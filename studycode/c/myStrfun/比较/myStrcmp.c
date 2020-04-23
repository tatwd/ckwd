#include <stdio.h>
#include <stdlib.h>

int myStrcmp(char t[],char s[])
{
    int i=0;
    while(t[i]&&s[i]&&t[i]==s[i])
        i++;
    return t[i]-s[i];
}

int main()
{
    char t[20],s[20];
    int k;
    printf("Input t:");
    gets(t);
    printf("Input s:");
    gets(s);
    k=myStrcmp(t,s);
    printf("Result:");
    if(k<0)
        printf("t<s");
        else if(k==0)
            printf("t==s");
            else printf("t>s");

}
