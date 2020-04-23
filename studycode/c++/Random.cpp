#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// 要生成和返回随机数的函数
int * getRandom(){
    static int r[10];
    
    // 设置种子
    srand((unsigned)time(NULL));
    for(int i = 0;i < 10;++i){
        r[i] = rand();
        //r[i] = rand()%1000+10;
        //cout << r[i] << endl;
    }
    return r;  //返回数组首地址
}

int main(){
    int *p;
    p = getRandom();
    for(int i = 0;i < 10;i++){
        cout << *(p + i)  << endl;
    }
    
    return 0;
}