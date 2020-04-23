#ifndef _CHAPTER03_H_
#define _CHAPTER03_H_

#include <iostream>
#include <cmath>
#include "Chapter.h"

#define SWAP(a,b) ((a)=(a)^(b),(b)=(a)^(b),(a)=(a)^(b))
//#define MAX(a,b) ((a)>(b)?(a):(b))

using namespace std;

//t.12
int Chapter::_ch3_12(int num){
	int inum = num;
	int n = 0;

	while (inum){
		int posNum = inum % 10;
		inum = inum / 10;
		cout << posNum;  //逆序打印位数
		n++;
	}

	cout << endl;
	return n;  //返回位数
}

//t.14
void Chapter::_ch3_14(int a, int b, int c, int d){
	int ary[4] = { a, b, c, d };

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 3; j++){
			if (ary[j] > ary[j + 1] && ary[j + 1])
				SWAP(ary[j], ary[j + 1]);
		}
	}

	for (int k = 0; k<4; k++){
		cout << ary[k] << " ";
	}
}

//t.15
int Chapter::_ch3_15(int a, int b, bool flag){
	if (a < b) SWAP(a, b);
	int r = a%b;

	//flag == true 求最大公约数(GCD)
	if (flag){

		while (r != 0){
			a = b;
			b = r;
			r = a%b;
		}
		int gcd = b;
		return gcd;
	}
	//flag == false 求最小公倍数(LCM)
	else{
		return r ? a*b : a;
	}
}

//t.16
void Chapter::_ch3_16(){
	char ch;
	int letter = 0, space = 0, num = 0, other = 0;

	while ((ch = cin.get()) != '\n'){
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			letter++;
		else if (ch >= '0' && ch <= '9')
			num++;
		else if (ch == ' ')
			space++;
		else other++;
	}
	cout << "letter:" << letter << endl;
	cout << "spaces:" << space << endl;
	cout << "number:" << num << endl;
	cout << "others:" << other << endl;
}

//t.17
int Chapter::_ch3_17(int n){
	int sum = 0;
	int a = 2;
	for (int i = 0; i < 5; i++){
		sum = sum + a;
		a = a * 10 + 2;
	}

	return sum;
}

//t.18
//TODO
int Chapter::_ch3_18(int n){
	int sum = 0;

	for (int i = 1; i <= n; i++){
		int x;
		for (int j = 0; j < i; j++){
			x = x*(j + 1);
		}
		sum = sum + x;
	}

	return sum;
}

//t.19
//求3位数水仙花数
void Chapter::_ch3_19(){
	for (int i = 100; i < 1000; i++){
		int x = i % 10;
		int y = i / 10 % 10;
		int z = i / 100;
		int sum = x*x*x + y*y*y + z*z*z;

		if (i == sum) cout << i << endl;
	}
}

//t.20
//求1000以内完数，如6 = 1 + 2 + 3
void Chapter::_ch3_20(int n){
	int s; //因子之和
	int m; //待判定的数
	int i;

	for (m = 2; m < n; m++){
		s = 0;
		for (i = 1; i < m; i++)
		if ((m%i) == 0) s = s + i;  // m%i == 0 , i是m的因子
		if (s == m){
			cout << m << ",its factors are ";
			for (i = 1; i < m; i++)
			if ((m%i) == 0) cout << i << " ";
			cout << endl;
		}
	}

	//return 0;
}

//t.21
//求和 2/1 + 3/2 + 5/3 + 8/5 + ...
double Chapter::_ch3_21(int n){
	double a = 2;
	double b = 1;
	double sum = 0;
	for (int i = 0; i < 5; i++){
		sum = sum + a / b;
		int tmp = a;
		a = a + b;
		b = tmp;
	}
	return sum;
}

//t.22
int Chapter::_ch3_22(int day, int r){
	//int r = 1;
	int num = 0;
	while (day != 1){
		day--;
		r = 2 * (r + 1);
		num += r;
	}
	return num;
}
void Chapter::_ch3_23(){
    double a, x0, x1;
    cin >> a;  //input a
    x0 = a/2;
    x1 = (x0 + a/x0)/2;
    do{
        x0 = x1;
        x1 = (x0 + a/2)/2;
    }
    while(fabs(x0 - x1) >= 1e-5);

    cout << "The square of " << a << " is " << x1 << endl;
}

//t.24
//还可以改进
void Chapter::_ch3_24(){
	int i, j, k, h;
	h = 3;
	for (i = 1; i <= 7; i++){
		if (i <= 4){
			for (j = 1; j <= 2 * i - 1; j++){
				cout << "*";
			}
			cout << endl;
		}


		else{

			for (k = 1; k <= 2 * h - 1; k++){
				cout << "*";
			}
			h--;
			cout << endl;
		}
	}
}

//t.25
//TODO
void Chapter::_ch3_25(){

	char i, j, k;   //i为A对手 j为B对手 k为C对手
	for (i = 'X'; i <= 'Z'; i++)
	for (j = 'X'; j <= 'Z'; j++){
		if (i != j){
			for (k = 'X'; k <= 'Z'; k++){
				if (i != k && j != k){
					if (i != 'X' && k != 'X' && k != 'Z')
						cout << "A vs " << i << endl
						<< "B vs " << j << endl
						<< "C vs " << k << endl;
				}
			}
		}
	}

}

void Chapter::_doCh3(int _title)
{
    switch (_title)
		{

		case 12:
		    int a;
		    cin >> a;
			cout << _ch3_12(a) << endl;
			break;
		case 14:
			_ch3_14(3, 1, 9,4);
			break;
		case 15:
			cout << _ch3_15(4, 8, true) << endl;
			break;
		case 16:
			_ch3_16();
			break;
		case 17:
			cout << _ch3_17(5) << endl;
			break;
		case 18:
			cout << _ch3_18(6) << endl;
			break;
		case 19:
			_ch3_19();
			break;
		case 20:
			_ch3_20(1000);
			break;
		case 21:
			cout << _ch3_21(5) << endl;
			break;
		case 22:
			cout << _ch3_22(10,1) << endl;
			break;
        case 23:
            _ch3_23();
            break;
		case 24:
			_ch3_24();
			break;
		case 25:
			_ch3_25();
			break;
		default:
			cout << "No code！" << endl;
			//std::cin.get();
			break;
		}
}



#endif //_CHAPTER03_H_
