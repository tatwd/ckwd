#include <stdio.h>
#include <stdlib.h>

/*
  问题描述：
  一只刚出生的奶牛，4年生1只奶牛， 以后每一年生1
  只。现给你一只刚出生的奶牛，求20年后有多少奶牛？
*/

int CalCowsNum(int iYear){
	int iCnt =0;
	long lCowsNum = 1;
	for(iCnt=1; iCnt<=iYear; iCnt++){
	if(iCnt>=4){
		if((iYear-iCnt)>3){
			lCowsNum += CalCowsNum(iYear - iCnt);
			}else{
				lCowsNum++;
			}
		}
	}
	return lCowsNum;
}
int main(){
	int iYear =0;
	printf("Please input require years:");
	scanf ("%d", &iYear);
	printf("In %d years, There is %d cows.\n", iYear, CalCowsNum(iYear));
	return 0;
}