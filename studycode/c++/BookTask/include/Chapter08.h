#ifndef _CHAPTER08_H_
#define _CHAPTER08_H_

#include <iostream>

#include "Chapter.h"

//t.4
/* 本题修改说明：
 * 1. 把第26~35行代码存入到文件student.h中，切记在此文件首行添加语句:
 *              #include <iostream>
 *              using namespace std;
 * 2. 把第36~45行代码存入到文件student.cpp中，任意改下42~44行三个变量的值，切记在此文件首行添加语句:#include "student.h"
 * 3. 把第46~50行代码存入到文件main.cpp中，把'void'改为'int'，'Chapter::_ch8_4'改为'main'，并在结尾（'}'之前）添加语句: return 0;
 *    切记在此文件首行添加语句: #include "student.h"
 * 4. 建议将以上三个文件一起放到一个文件夹（如8.4）里
 *
 * 如果你已按上述方法进行修改后，并想运行，那么请看下去...
 *
 * 若你在CodeBlocks（以下简称CB）直接打开后无法编译并运行，那么有2种方法解决：
 * 1. 用CB新建一个project后，将上述三个文件添加进去（方法：选中工程文件名，右键选择Add files...），点击编译并运行即可.
 * 2. 如果你已经将c++编译器g++.exe的文件路径添加到系统path变量中，那么启动cmd.exe，进入到那三个文件所在的文件夹下，
 *    先输入：g++ main.cpp student.cpp -o main.exe -std=c++11 然后输入：main  即可看到结果.
 *   （第一条命令必须有那两个cpp文件，如果main.exe改为如xxx.exe的形式，则第二条命令改为xxx即可）
 */
class Student1
{
public:
    void display();
    void set_value();
private:
    int num;
    string name;
    char sex;
};
void Student1::display(){
    cout << "num:" << num << endl;
    cout << "name:" << name << endl;
    cout << "sex:" << sex << endl;
}
void Student1::set_value(){
    num = 1243;
    name = "Tom";
    sex = '男';
}
void Chapter::_ch8_4(){
    Student1 st;
    st.set_value();
    st.display();
}

//t.5
/* 本题修改说明：
 * 1. 把第64~73行代码存入到文件arraymax.h中，切记在此文件首行添加语句:
 *              #include <iostream>
 *              using namespace std;
 * 2. 把第74~85行代码存入到文件arraymax.cpp中，切记在此文件首行添加语句: #include "arraymax.h"
 * 3. 把第86~91行代码存入到文件 file1.cpp中，把'void'改为'int'，'Chapter::_ch8_5'改为'main'，并在结尾（'}'之前）添加语句: return 0;
 *    切记在此文件首行添加语句: #include "arraymax.h"
 * 4. 建议将以上三个文件一起放到一个文件夹（如8.5）里
 *
 * 运行出现的问题参考上题
 */
class Array_max
{
public:
    void set_value();
    void max_value();
    void show_value();
private:
    int array[10];
    int max;
};
void Array_max::set_value(){
    for(int i = 0;i < 10;i++)
        cin >> array[i];
}
void Array_max::max_value(){
    max = array[0];
    for(int i = 1;i < 10;i++)
        if(array[i] > max) max = array[i];
}
void Array_max::show_value(){
    cout << "max=" << max;
}
void Chapter::_ch8_5(){
    Array_max arrmax;
    arrmax.set_value();
    arrmax.max_value();
    arrmax.show_value();
}

//t.6
/* 本题修改说明：
 * 1. 第127行把'void'改为'int'，'Chapter::_ch8_6'改为'main'，并在结尾添加语句: return 0;
 * 2. 其余代码按老规矩修改
 */
class RectangularColumn //长方柱类
{
public:
    double length;
    double width;
    double height;

    virtual double getVolume(); //求体积

    RectangularColumn();
    RectangularColumn(double, double, double); //含参构造函数,传入长宽高
    virtual ~RectangularColumn();
};
RectangularColumn::RectangularColumn()
{
}
RectangularColumn::RectangularColumn(double length, double width, double height)
{
    this->length = length;
    this->width = width;
    this->height = height;
}
RectangularColumn::~RectangularColumn()
{
}
double RectangularColumn::getVolume()
{
    return length * width * height;
}
void Chapter::_ch8_6()
{
    double length, width, height;
    const int n = 3;
    RectangularColumn rectCol_array[n]; //对象数组

    for(int i = 0; i < n; i++)
    {
        cin >> length >> width >> height;
        RectangularColumn rectCol(length, width, height);
        rectCol_array[i] = rectCol;
    }

    for(int j = 0; j < n; j++)
    {
        cout << "Volume of " << j+1 << ":" << rectCol_array[j].getVolume() << endl;
    }
}


void Chapter::_doCh8(int _title)
{
    switch(_title)
    {
    case 4:
        _ch8_4();
        break;
    case 5:
        _ch8_5();
        break;
    case 6:
        _ch8_6();
        break;
    default:
        cout << "NO code!" << endl;
        break;
    }
}

#endif // _CHAPTER08_H_
