#include <stdio.h>
#include <stdlib.h>

//求数的次方值
int getcf(int num, int n) {
	int inum = 1;
	for (int i = 0; i < n; i++) {
		inum = inum * num;
	}
	return inum;
}

//获取数的2次方指数n
int getm(int num){
	int n = 0;
	while (num){
		if (num % 2 == 0) {
			n++;
		    num = num / 2;
		}
		else{
			//printf("error num\n");
			break;
		}
	}
	return n;
}
//对于形如x=2^n转化成16进制
void ten2h(int n){
	int i = 0, j = 0;
	//n = i + 4*j
	i = n % 4;
	j = n / 4;
	printf("i=%d,j=%d\n", i, j);

	printf("%d to hex:0x%d", getcf(2,n),getcf(2,i));
	for (; j != 0; --j){
		printf("0");
	}
	printf("\n");
}
//16进制转10进制
void ten2hex(int num){
	int inum = num;
	//int r;
	if (inum == 0){
		printf("0x");
		return;
	}
	else{
		int y = inum % 16;
		inum = inum / 16;
		ten2hex(inum);
		//printf("0x");
		switch (y){
			case 10: printf("a");break;
			case 11: printf("b"); break;
			case 12: printf("c"); break;
			case 13: printf("d"); break;
			case 14: printf("e"); break;
			case 15: printf("f"); break;
			default:printf("%d", y);
		}
	}
}

void main(){
	int num;
	printf("input num:");
	scanf("%d", &num);
	
	/*int n = getm(num);
	printf("%d=2^%d\n",num,n);
	ten2h(n);*/

	ten2hex(num);

	system("pause");
}
