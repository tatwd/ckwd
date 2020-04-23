#include <iostream>

using namespace std;

void HanoiTower(int n, char _A, char _B, char _C)
{
    static int num = 0; //计数


    if(n < 1)
    {
        //num++;
        //cout << num << " ";
        num++;
        return;
    }
    else
    {

        HanoiTower(n-1, _A, _C, _B); // 把n-1个盘子从A柱移到B柱
        cout << num << " "; //打印第几次
        cout << "plate " << n << ":" << _A << "->" << _C << endl;
        //num++;
        HanoiTower(n-1, _B, _A, _C); // 把n-1个盘子从B柱移到C柱

    }
}
/**
f(n) = 2*f(n-1) + 1
f(n) = 2^n - 1

*/
