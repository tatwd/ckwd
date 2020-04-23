#ifndef _CHAPTER02_H_
#define _CHAPTER02_H_

#include <iostream>
#include "Chapter.h"

using namespace std;

//t.3
void Chapter::_ch2_3(){
	char c1 = 'a', c2 = 'b', c3 = 'c', c4 = '\101', c5 = '\116';
	cout << c1 << c2 << c3 << '\n';
	cout << "\t\b" << c4 << '\t' << c5 << '\n';
}

//t.4
void Chapter::_ch2_4(){
	char c1 = 'C', c2 = '+', c3 = '+';
	cout << "I say:\"" << c1 << c2 << c3 << '\"';
	cout << "\t\t" << "He say:\"C++ is very interesting!\"" << '\n';
}

//t.7
void Chapter::_ch2_7(){
	int i, j, m, n;
	i = 8;
	j = 10;
	m = ++i + j++;  //j=11
	n = (++i) + (++j) + m;
	cout << i << '\t' << j << '\t' << m << '\t' << n << endl;
}

void Chapter::_doCh2(int _title)
{
    switch (_title)
		{
		case 3:
			_ch2_3();
			break;
		case 4:
			_ch2_4();
			break;
		case 7:
			_ch2_7();
			break;
		default:
			std::cout << "No code！" << std::endl;
			//std::cin.get();
	    break;
		}
}

#endif //_CHPATER02_H_
