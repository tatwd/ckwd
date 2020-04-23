#include <iostream>

using namespace std;

const int N = 3;

//打印幻方
void putOddMagicSquare(int a[][N]){
	//int *p = a;

	//TODO
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}

}

//构造奇数幻方
void createOddMagicSquare(int n){

	int a[N][N] = { 0 };
	int row = 0; //行 y
	int col = (N-1)/2; //列 x

	a[row][col] = 1; //将1放于第一行第二列

	//TODO
	int num = 2;
	while (num <= n*n) //每次循环填好一个数字，1已经填好
	{
		//右上变换
		row = row - 1;
		col = col + 1;

		//line:36~62 could be modified.
		if ((row<0 || row>n-1) && (col>=0 && col<=n-1)) //在上方
		{
			row = row + n;
			a[row][col] = num;
		}
		else if((row>=0 && row<=n-1) && (col<0 || col>n-1)) //在右方
        {
            col = col - n;
            a[row][col] = num;
        }
        else if((row<0 || col>n-1) && (col<0 || col>n-1)) //在右上角
        {
            row = row + 2;
            col = col - 1;
            a[row][col] = num;
        }
        else if((row>=0 && row<=n-1) && (col>=0 && col<=n-1)) //在幻方内
        {
            if(a[row][col]!=0) //已填
            {
                row = row + 2;
                col = col - 1;
                a[row][col] = num;
            }
            else a[row][col] = num; //未填
        }

		num++;
	}


	putOddMagicSquare(a);


}
