#include <iostream>

using namespace std;

const int N = 3;

//��ӡ�÷�
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

//���������÷�
void createOddMagicSquare(int n){

	int a[N][N] = { 0 };
	int row = 0; //�� y
	int col = (N-1)/2; //�� x

	a[row][col] = 1; //��1���ڵ�һ�еڶ���

	//TODO
	int num = 2;
	while (num <= n*n) //ÿ��ѭ�����һ�����֣�1�Ѿ����
	{
		//���ϱ任
		row = row - 1;
		col = col + 1;

		//line:36~62 could be modified.
		if ((row<0 || row>n-1) && (col>=0 && col<=n-1)) //���Ϸ�
		{
			row = row + n;
			a[row][col] = num;
		}
		else if((row>=0 && row<=n-1) && (col<0 || col>n-1)) //���ҷ�
        {
            col = col - n;
            a[row][col] = num;
        }
        else if((row<0 || col>n-1) && (col<0 || col>n-1)) //�����Ͻ�
        {
            row = row + 2;
            col = col - 1;
            a[row][col] = num;
        }
        else if((row>=0 && row<=n-1) && (col>=0 && col<=n-1)) //�ڻ÷���
        {
            if(a[row][col]!=0) //����
            {
                row = row + 2;
                col = col - 1;
                a[row][col] = num;
            }
            else a[row][col] = num; //δ��
        }

		num++;
	}


	putOddMagicSquare(a);


}
