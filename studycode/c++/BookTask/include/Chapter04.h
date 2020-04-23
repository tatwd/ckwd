#ifndef _CHAPTER04_H_
#define _CHAPTER04_H_

#include <iostream>
#include <cmath>
#include "Chapter.h"

#define SWAP(a,b) ((a)=(a)^(b),(b)=(a)^(b),(a)=(a)^(b))

using namespace std;

//t.1
void Chapter::_ch4_1(int a,int b,int flg){
    if (a < b) SWAP(a, b);
    int r = a%b;
    if(flg == 1){
        if(r == 0){
            cout << "GCD:" << b << endl;
        }
        else{
            _ch4_1(b,r,flg);
        }
    }
    else{
       cout << "LCM:" << (r ? a*b : a) << endl;
    }
}

//t.2
void Chapter::_ch4_2(){
    int num;
    bool flag = true;
    cin >> num;
    int k = int(sqrt(num));
    for(int i = 2;i <= k;i++){
        if((num%i) == 0){
            flag = false;
            break;
        }
        else{
            //cout << num << " is a prime!" << endl;
            //break;
            continue;
        }
    }
    if(flag)
        cout << num << " is a prime!" << endl;
    else
        cout << num << " is not a prime!" << endl;
}

//t.4
int fac(int num){  //求阶乘
    if(num == 1){
        return 1;
    }
    else{
        return num*fac(num - 1);
    }
}
int Chapter::_ch4_4(int a,int b,int c){
    return fac(a) + fac(b) + fac(c);  //阶乘之和
}

//t.5
#define _E 2.718281828

double getEX(double x){
    if(x == 0) return 1;
    else return _E*getEX(x-1);
}

void Chapter::_ch4_5(){
    double x;
    cin >> x;
    cout << "sinh(x) = " << (getEX(x) - 1/getEX(x))/2 << endl;
}

//t.7
bool prime(int num){  // 判断素数
    bool flag = true;
    int k = int(sqrt(num));

    for(int i = 2;i <= k;i++){
        if(num%i == 0){
            flag = false;
            break;
        }
    }
    return flag;
}
void Chapter::_ch4_7(int num){
    //bool flag = prime(num);
    if( num >= 6){
        int j = 0;
        int i = 3;
        while(i){
            j = num - i;
            if(prime(i) && prime(j)) break;
            i++;
        }
        cout << num << "=" << i << "+" << j << endl;
    }
    else cout << "input error!Number must >= 6!" << endl;
}

//t.8
//递归法求n阶勒让德多项式的值
double Chapter::_ch4_8(double x,int n){
    if(n == 0) return 1;
    else if(n == 1) return x;
    else{
        return (2*n - 1)*x - _ch4_8(x,n-1) - (n -1)*_ch4_8(x,n-2)/n;
    }
}

//t.10
// 整型数字递归法转化为字符串
void Chapter::_ch4_10(int num){
    char str;
    if(num < 10){
        str = num + '0';
    }
    else{
        str = num%10 + '0';  // => str = num%10 + 48
        _ch4_10(num/10);
    }
    cout << " " << str;
}

//t.12
//宏无法指定类型
#define GET_S(a,b,c) (((a)+(b)+(c))/2.0)
#define AREA2(a,b,c,s) ((s)*((s)-(a))*((s)-(b))*((s)-(c)))

void Chapter::_ch4_12(){
    int a,b,c;
    cin >> a >> b >> c;
    //判断是否是三角形
    if(a+b > c && a+c > b && b+c > a){
        int s = GET_S(a,b,c);
        cout << s << " " << AREA2(a,b,c,s) << endl;
        double area = sqrt(AREA2(a,b,c,s));
        cout << "The area of the triangle is " << area << endl;
    }
    else  cout << "It is not a triangle." << endl;
}

void Chapter::_doCh4(int _title)
{
    switch(_title)
        {
        case 1:
            int flg;
            cout << "input 1 to get GCD,input 2 to get LCM:";
            cin >> flg;
            int a,b;
            cout << "input two integer:" << endl;
            cin >> a >> b;
            _ch4_1(a,b,flg);
            break;
        case 2:
            _ch4_2();
            break;
        case 4:
            int ax,bx,cx;
            cin >> ax >> bx >> cx;
            cout << _ch4_4(ax,bx,cx) << endl;
            break;
        case 5:
            _ch4_5();
            break;
        case 7:
            int in;
            cin >> in;
             _ch4_7(in);
             break;
        case 8:
            cout << _ch4_8(8,2) << endl;
            break;
        case 10:
            int num;
            cin >> num;
            _ch4_10(num);
            break;
        case 12:
            _ch4_12();
            break;
        default:
            cout << "No code！" << endl;
            break;
        }
}

#endif //_CHAPTER04_H_
