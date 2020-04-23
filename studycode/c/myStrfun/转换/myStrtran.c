#include <stdio.h>
#include <stdlib.h>

void myStrtran(char s[])
{
    int i=0;

    while(s[i]!='\0'){
        if(s[i]>='a'&&s[i]<='z')
            s[i]=s[i]-32;
           else if(s[i]>='A'&&s[i]<='Z')
                   s[i]=s[i]+32;
                       i++;
    }
    return 0;
}

int main()
{
    char s[20];
    printf("Input strings:");
    gets(s);
    myStrtran(s);
    printf("After strings:");
    puts(s);
}
