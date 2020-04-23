#ifndef _CHAPTER05_H_
#define _CHAPTER05_H_

#include <iostream>
#include <string>
#include "Chapter.h"

using namespace std;

//t.3
void Chapter::_ch5_3(){
    int a[3][3] = {{1,1,1},{2,1,2},{3,3,1}};
    //打印3x3矩阵
    for(int i = 0;i < 3; i++){
        for(int j = 0;j < 3;j++)
            cout << a[i][j] << "  ";
        cout << endl;
    }
    //求对角线之和
    int sum = 0;
    for(int k = 0;k < 3;k++)
        sum += a[k][k];
    cout << sum << endl;
}

//t.4
// 插入一个数
#define ENDLINE (cout << endl) // 换行,此处可删,之后的 ENDLINE 改为 cout << endl
void insertNum(int a[11],int num){
   if(num > a[9])
	   a[10] = num;
   else{
	   for(int i = 0;i < 10;i++){
		   if(a[i] > num){
			   for(int j = 9;j >= i;j--)
				   a[j+1] = a[j];
			   a[i] = num;
			   break;
		   }
	   }
   }

   cout << "After: ";
   for(int k = 0;k < 11;k++){
       cout << a[k] << "  ";
   }

   ENDLINE;
}
void Chapter::_ch5_4(){
    int a[11] = {1, 4, 6, 9, 13, 16, 19, 28, 40, 100};

	cout << "Before: ";
	for(int i = 0;i < 10;i++){
       cout << a[i] << "  ";
    }
    ENDLINE;

    int n;
    cout << "Insert a number:";
    cin >> n;

    insertNum(a,n);
}

//t.7
/*
  求鞍点(saddle point)
  e.g.
  1 5 3 4
  3 7 8 9
  5 8 9 9
  7 9 9 9
  鞍点: 5
*/
void _ch5_7(){
    int a[4][4] = {{1,9,3,1},{3,7,8,9},{5,8,9,9},{7,9,9,9}};  //初始化4行4列的二维数组

    // 打印数组
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++)
            cout << a[i][j] << "  ";
        cout << endl;
    }

    int row_max = 0;  // 行最大值
    int col_min = 0;  // 列最小值
    int max_j = 0;    // 记录row_max的列号
    bool flag = true;

    for(int i = 0;i < 4;i++){
        row_max = a[i][0];

        for(int j = 0;j < 4;j++){
            if(row_max < a[i][j]){
                row_max = a[i][j];
                max_j = j;
            }
        }

        col_min = a[0][max_j];
        for(int k = 0;k < 4;k++){

            if(col_min > a[k][max_j]){
                col_min =a[k][max_j];
            }
        }

        if(col_min == row_max){
            cout << "The saddle point is a[" << i << "][" << max_j << "]:"<< row_max << endl;
            break;
        }
        //else cout << "no" << endl;
        flag = false;
    }
    if(!flag) cout << "No saddle point!" << endl;
}

//t.9
void Chapter::_ch5_9(int year,int month,int day){
    int Mar = 28;//二月的天数
    if((year%4 == 0 && year%100 != 0) || year%400 == 0)  Mar = 29;   //判断闰年
    int mday[12] = {31,Mar,31,30,31,30,31,31,30,31,30,31};

    int sumDay = 0;  //第几天
    for(int i = 0;i < month-1;i++)
        sumDay += mday[i];
    sumDay += day;

    //序数词转换  此处(130~145行可省略,147行也要改下)
    int r = sumDay%10;
    char *pc = NULL;
    switch(r){
    case 1:
        pc = "st";
        break;
    case 2:
        pc = "nd";
        break;
    case 3:
        pc = "rd";
    default:
        pc = "th";
        break;
    }

    cout << year << "-" << month << "-" << day << " is the " << sumDay << pc << " day of the year." << endl;
}

//t.10
void Chapter::_ch5_10(){
    string a[3] = {
        "12345_jkdjer&isklq$d12345_jkdj&ruiskl$nd12345_jkdjer&isk$qnd12345_jkdj&rui$klqnd",
        " 2345_jkdJeruisklqnd 2345_jkdJeruisklqnd 2345_jkdJeruisklqnd 2345_jkdJeruisklqnd",
        "12345_JkdjeruIsklqn#12345_JkdjeruIsklqnd12345_JkdjeruIsklqnd12345_JkdjeruIsklqnd"
    };  // 此三行字符串可改为其他，但每行要有80个字符
    int uc = 0;  //大写
    int dc = 0;  //小写
    int nu = 0;  //数字
    int sp = 0;  //空格
    int ot = 0;  //其他

    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 80;j++){
            if(a[i][j] > 'A' && a[i][j] < 'Z')  uc++;
            else if(a[i][j] > 'a' && a[i][j] < 'z')  dc++;
            else if(a[i][j] > '0' && a[i][j] < '9')  nu++;
            else if(a[i][j] == ' ')  sp++;
            else ot++;
            }
    }
    cout << uc << endl
         << dc << endl
         << nu << endl
         << sp << endl
         << ot << endl;
}

//t.11
void Chapter::_ch5_11(){
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < i;j++){
           cout << "  ";
        }
        cout << "* * * * * *" << endl;
    }
}

//t.15
void Chapter::_ch5_15(int n){
    string a[n];

    for(int i = 0;i < n;i++)
        cin >> a[i];

    cout << "First char is \'A\':" << endl;
    for(int j = 0;j <  n;j++){
        if(a[j][0] == 'A')  //每个字符串的第一个字符
            cout << a[j] << endl;
    }
}

//t.17
const int N = 10;
string name[N];     // 姓名
string id[N];       // 学号
int score[N] = {0}; // 成绩
// 输入学生信息
 void input_data(){
    for(int i = 0;i < N;i++){
        cout << "Please input No." << i+1 << " of students:" << endl;
        cin >> name[i] >> id[i] >> score[i];
    }
}
// 输出不及格者
void output_flunk(){
    for(int i = 0;i < N;i++){
        if(score[i] < 60){
            cout << name[i] << "\t" << id[i] << "\t" << score[i] << endl;
        }
    }
}
void Chapter::_ch5_17(){
    input_data();
    cout << "The flunked student(s):" << endl;
    output_flunk();
}


void Chapter::_doCh5(int _title)
{
    switch(_title)
        {
        case 3:
            _ch5_3();
            break;
        case 4:
            _ch5_4();
            break;
        case 7:
            _ch5_7();
            break;
        case 9:
            _ch5_9(2004,3,23);
            break;
        case 10:
            _ch5_10();
            break;
        case 11:
            _ch5_11();
            break;
        case 15:
            _ch5_15(3);
            break;
        case 17:
            _ch5_17();
            break;
        default:
            cout << "No code£¡" << endl;
			//std::cin.get();
			break;
        }
}

#endif //_CHAPTER05_H_
