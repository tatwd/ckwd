#ifndef _CHAPTER06_H_
#define _CHAPTER06_H_

#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdlib>

#include "Chapter.h"

//t.4
/*
  n = 5   m = 3
  1 2 3 4 5 => 3 4 5 1 2
  1 3 4 5 2
  3 4 5 1 2
*/
void put_array(int *ary,int n){
    for(int *p = ary;p < ary + n;p++)
        cout << *p << " ";
    cout << endl;
}
int * move_array(int *ary,int n,int m){
    int *p = ary + n - m -1 ; //a[1]
    if(m <= n){
        for(;p > ary-1;p--){

            int tmp = *p;

            int *q = p;
            for(;q < p + m ;q++)
                *q = *(q+1);

            *q = tmp;
        }
        return p+1;
    }
    else {
        cout << "error:m > n" << endl;
        return p = ary;
    }
}
void Chapter::_ch6_4(){

    int n  = 0;
    cout << "n=";
    cin >> n;
    int a[n] = {0};

    for(int i = 0; a[i] < n;i++)
        a[i] = i+1;

    put_array(a,n);

    int m = 0;
    cout << "m=";
    cin >> m;

    int *p = move_array(a,n,m);
    put_array(p,n);
}

//t.7
char * str_copy(char *s,char *t,int m){
    //char *ps = s;
    //char *pt = t;

    //pt = ps + m -1;

    //return pt;
    return s + m -1;
}
void Chapter::_ch6_7(){
    int n = 0;
    cout << "Input length of a string:";
    cin >> n;
    char str[n];

    for(int i = 0;i < n; i++){
        cin >> str[i];
    }
    str[n] = '\0';
    //cout << "The string is:" << endl << str << endl;

    int m = 0;
    cout << "Copy the string from:";
    cin >> m;

    char *p = str_copy(str,NULL,m);
    cout << "After:" << p << endl;
}

//t.11
//const int N = 10; //N在Chapter05.h中的第204行 N = 10
string * sort_str(string *str){
    string *p = str + N -1;

    // 冒泡排序
    while(p > str){
        string *pose = str;
        for(string *q = str;q < p;q++){
            if(*q > *(q + 1)){
                pose = q;
                string tmp = *q;
                *q = *(q+1);
                *(q+1) = tmp;
            }

        }
        p = pose;

        /*
        // 打印每一次排序
        for(int i = 0;i < N;i++)
           cout << str[i] << " ";
        cout << endl;
        */
    }
    return str;
}
void Chapter::_ch6_11(){
    string str[N];

    // 输入字符串
    for(int i = 0;i < N;i++)
        cin >> str[i];
    cout << endl;

    string *pstr = sort_str(str);  // 排序中

    // 输出字符串
    for(int i = 0;i < N;i++)
        cout << pstr[i] << " ";
}

//t.12
//TODO
void sort_str(char *str[]){
    char *tmp = NULL;
    // 冒泡排序
    for(int i = 0;i < N-1;i++){
        for(int j = 0;j < N-1 - i;j++){
            if( strcmp(*(str + j),*(str + j + 1)) > 0){  //需要引入cstring或string.h
               tmp = *(str + j);
               *(str + j) = *(str + j +1);
               *(str + j + 1) = tmp;
            }
        }
    }
}
void Chapter::_ch6_12(){
    char str[N][10];
    char *pstr[N]; //每个元素都是指针
    for(int i = 0;i < N;i++){
        cin >> str[i];
        pstr[i] = str[i];  //每行首地址赋给指针数组
    }

    sort_str(pstr);

    cout << "After sort..." << endl;
    for(int i = 0;i < N;i++)
        cout << pstr[i] << " ";
    cout << endl;
}
//t.15
double avg_one(int *data){
    int *p = data + 1;
    double sumOne = 0;
    for(int i = 0;i < 4;i++){
        //cout << *p << endl;
        sumOne += *p;
        p += 6;
    }

    return sumOne / 4;
}
void find_fail(int *data){
    int *p = data;
    cout << "Failure student(s):" << endl;
    cout << "ID\tC1\tC2\tC3\tC4\tC5\tAVG" << endl;
    cout << "====================================================" << endl;
    int n = 0;
    for(int i = 0;i < 4;i++){

        double sum = 0;
        for(int j = 1;j < 6;j++){
            sum += *(p + j);
            if(*(p + j) < 60) n++;
        }
        if(n >= 2){
            for(int k = 0;k < 6;k++){
                cout << *(p + k) << "\t";
            }
            cout << sum / 5 << endl;
        }
        p += 6;
    }
    if(n < 2) cout << "None!" << endl;
    cout << "====================================================" << endl;
}
void find_good(int *data){
    int *p = data;

    cout << "Excellent student(s):" << endl;
    cout << "ID" << endl << "=====" << endl;;

    int flag[4] = {1};
    for(int i = 0;i < 4;i++){
        int n = 0;
        double sum = 0;
        for(int j = 1;j < 6;j++){
             sum += *(p + j);
             if(*(p + j) > 85) n++;
        }
        double avg = sum / 5;
        //cout << avg << " " << n << endl;
        if(avg > 95 || n == 5){
            cout << *p << endl;
        }
        else flag[i] = 0;
        p += 6;
    }

    //可省
    int nflag = 0;
    for(int i = 0;i < 4;i++){
        if(flag[i] == 0) nflag++;
    }
    if(nflag == 4) cout << "None!" << endl << "=====" << endl;
}
void Chapter::_ch6_15(){
    int data[4][6] = {0};
    int id = 1522;

    srand((unsigned)time(NULL)); //生成随机种子 需引入 ctime 和 cstdlib

    for(int i = 0;i < 4;i++){
        data[i][0] = id;
        for(int j = 1;j < 6;j++){
            data[i][j] = rand()%50 + 50; // 随机数
        }
        id++;
    }

    cout << "ID\tC1\tC2\tC3\tC4\tC5" << endl;
    cout << "==========================================" << endl;
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 6;j++)
            cout << data[i][j] << "\t";
        cout << endl;
    }
    cout << "==========================================" << endl;

    // 科一的平均分
    double avgOne = avg_one(data[0]);
    cout << "AVG of C1:" << avgOne << endl;

    cout << endl;

    // 找出两门以上课程不及格的学生
    find_fail(data[0]);

    cout << endl;

    // 找出平均成绩90以上或所有成绩85以上的学生
    find_good(data[0]);

}

//t.16
void saveNum(char *str){
    int n = 0;
    int a[10] = {0};

    for(char *p = str;p < (str+25);p++){
        int num = 0;
        if(*p >= '0' && *p <= '9'){
            while(*p >= '0' && *p <= '9'){
                num = 10*num + (*p - '0');
                p++;
            }
            n++;
        }
        if(num != 0)
            a[n] = num;
    }

    for(int i = 0;i<10;i++){
        if(a[i] != 0)
            cout << "a[" << i << "]:" << a[i] << endl;
    }
}
void Chapter::_ch6_16(){
    char *str = "a123x456_17960?302tab5876";
    cout << str << endl;
    saveNum(str);
}

//t.17
int strcmp(char *p1,char *p2){
    //int i=0;
    while(*p1 && *p2 && *p1 == *p2){
        p1++;
        p2++;
    }
    return *p1 - *p2;
}
void Chapter::_ch6_17(){
    char *str1 = "BOY";
    char *str2 = "BAD";

    int result = strcmp(str1,str2);

    cout << "Result:" << result << endl;
}

void Chapter::_doCh6(int _title)
{
    switch(_title)
    {
        case 4:
            _ch6_4();
            break;
        case 7:
            _ch6_7();
            break;
        case 11:
            _ch6_11();
            break;
        case 12:
            _ch6_12();
            break;
        case 15:
            _ch6_15();
            break;
        case 16:
            _ch6_16();
            break;
        case 17:
            _ch6_17();
            break;
        default:
            cout << "No code!" << endl;
			//std::cin.get();
			break;
    }
}

#endif //_CHAPTER06_H_
