#include <stdio.h>
#include <stdlib.h>

int sort(int a[],int first,int last)
{
	int p=a[first],i;
	int temp;
	if (last-first<=0)
		return -1;
	while (first!=last)
	{
		while(a[last]>=p&&last!=first)
			last--;
			temp=a[first];
			a[first]=a[last];
			a[last]=temp;

		while(a[first]<=p&&last!=first)
			first++;
			temp=a[first];
			a[first]=a[last];
			a[last]=temp;
         /* for(i=0;i<10;i++)

               printf("%4d\t",a[i]);
               if(i==9)
               {
                    printf("\n");
                    i++;
               }*/
	}for(i=0;i<10;i++)
                    printf("%4d\t",a[i]);
	return last;
}

void quickSort(int a[],int length)
{
	int temp=sort(a,0,length-1);
	if(temp==-1)
          return;
     quickSort(a,temp+1);
	quickSort(&a[temp+1],length-temp-1);
}

int main()
{
	int a[10]={12,11,25,14,9,87,20,22,54,62};
	int i;
	quickSort(a,10);
     //for(i=0;i<10;i++)

	 //printf("%4d",a[i]);
}
