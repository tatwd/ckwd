#ifndef _CHAPTER01_H_
#define _CHAPTER01_H_

#include <iostream>
#include "Chapter.h"

using namespace std;

//t.5
void Chapter::_ch1_5(){
	cout << "this" << "is";
	cout << "a" << "c++";
	cout << "program." << endl;
}

//t.6
void Chapter::_ch1_6(){
	int a, b, c;
	a = 10;
	b = 23;
	c = a + b;
	cout << "a+b=";
	cout << c;
	cout << endl;
}

//t.7
int Chapter::_ch1_7(int x, int y, int z)
{
	int m;
	if (x < y) m = x;
	else m = y;
	if (z < m) m = z;
	return m;
}

//t.9
int Chapter::_ch1_9(int x, int y){

	int z;
	z = x + y;
	return z;
}

//t.10
void Chapter::_ch1_10(int x, int y, int z)
{
	int temp;
	if (x > y){ temp = x, x = y, y = temp; }
	if (z < x)  cout << z << ',' << x << ',' << y << endl;
	else if (z < y) cout << x << ',' << z << ',' << y << endl;
	else cout << x << ',' << y << ',' << z << endl;
}


void Chapter::_doCh1(int _title)
{
    switch (_title)
		{
		case 5:
			_ch1_5();
			break;
		case 6:
			_ch1_6();
			break;
		case 7:
			int a, b, c;
			//int _ch1_7(int x, int y, int z);
			std::cin >> a >> b >> c;
			c = _ch1_7(a, b, c);
			std::cout << c << std::endl;
			//std::cin.get();
			break;
		case 9:
			int m, n, k;
			//int _ch1_9(int x, int y);
			std::cin >> m >> n;
			k = _ch1_9(m, n);
			std::cout << "m+n=" << k << std::endl;
            //std::cin.get();
			break;
		case 10:
			//void _ch1_10(int x, int y, int z);
			int x, y, z;
			std::cin >> x >> y >> z;
			_ch1_10(x, y, z);
			//std::cin.get();
			break;
		default:
			std::cout << "No code！" << std::endl;
			//std::cin.get();
			break;
		}
}

#endif //_CHAPTER01_H_
