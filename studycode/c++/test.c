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


void main2() {
	//printf("Hello world!\n");

	//int a = 10;
	//int b = 10;
	//int c;
	//c = a++;
	//b = b++;
	//printf("a=%d b=%d", a, b);

	printf("%d", getcf(2,3));

	getchar();
}
