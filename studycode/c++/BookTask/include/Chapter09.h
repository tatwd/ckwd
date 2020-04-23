#ifndef _CHAPTER09_H_
#define _CHAPTER09_H_

#include <iostream>

#include "Chapter.h"

//t.4
class StudentScore
{
    public:
        StudentScore();
        StudentScore(int ,int);
        virtual ~StudentScore();

        virtual void display_info();
        virtual int getId();
        virtual int getGrade();

    protected:

    private:
        int id;
        int grade;
};
StudentScore::StudentScore()
{
}
StudentScore::StudentScore(int id, int grade)
{
    this->id = id;
    this->grade = grade;
}

StudentScore::~StudentScore()
{
}
void StudentScore::display_info()
{
    cout << id << "\t" << grade << endl;
}
int StudentScore::getId()
{
    return id;
}
int StudentScore::getGrade()
{
    return grade;
}
void Chapter::_ch9_4()
{
    StudentScore st_array[5];

    for(int i = 0;i < 5;i++)
    {
        int id, grade;
        cin >> id >> grade;
        StudentScore st(id, grade);
        st_array[i] = st;
    }

    cout << "ID\tGrade" << endl;
    cout << "=============" << endl;
    for(StudentScore *p_st = st_array;p_st < st_array + 5;p_st+=2) //打印第1,3,5学生信息
        p_st->display_info();
}

//t.5
//复用第9~49行代码
void max(StudentScore *s)
{
    StudentScore *p_s = s;

    //int max_grade = p_s->getGrade();
    StudentScore *max_grade = p_s;
    for(;p_s < s + 4;p_s++)
    {
        if(max_grade->getGrade() < (p_s+1)->getGrade())
            max_grade = (p_s+1);
    }

    cout << max_grade->getId() << endl; // 打印成绩最高的学生学号
}
void Chapter::_ch9_5()
{
    StudentScore st_array[5];

    for(int i = 0;i < 5;i++)
    {
        int id, grade;
        cin >> id >> grade;
        StudentScore st(id, grade);
        st_array[i] = st;
    }

    cout << "Max grade of id = ";
    max(st_array);
}

//t.8
class Student
{
public:
    Student(int n, float s): num(n), score(s){}
    void change(int n, float s){num = n;score = s;}
    void display(){cout << num << " " << score << endl;}
private:
    int num;
    float score;
};
void fun(Student &st)
{
    st.display();
    st.change(101, 80.5);
    st.display();
}
void Chapter::_ch9_8()
{
    Student st(101, 78.5);
    fun(st);
}

//t.9
class Product
{
public:
    Product(int, int, double); //传入num,quantity,price
    virtual ~Product();

    virtual void get_sum();
    static double average();
    static void display();

private:
    int num;                //销售员号
    int quantity;           //售货数量
    double price;           //售货单价
    static double discount; //折扣,店家统一规定
    static double sum;      //总销售额
    static int n;           //销售总数
};
Product::Product(int num, int quantity, double price)
{
    this->num = num;
    this->quantity = quantity;
    this->price = price;
}
Product::~Product()
{
}
void Product::get_sum()
{
    double offer = 1.0; //销售员打折
    if(n > 10) offer = 0.98;
    sum = sum + quantity*price*offer*discount;
    n = n+ quantity;
}
double Product::average()
{
    return sum / n;
}
void Product::display()
{
    cout << "sum:" << sum << endl;
    cout << "average:" << average() << endl;
}
double Product::discount = 0.88;
double Product::sum = 0;
int Product::n = 0;
void Chapter::_ch9_9()
{
    Product p_array[3] = {
        Product(101, 5, 23.5), Product(102, 12, 24.56), Product(103, 100, 21.5)
    };

    for(int i = 0;i < 3;i++)
    {
        p_array[i].get_sum();
        //p_array[i].display();
    }
    Product::display();
}

//t.10
class Date;
class Time
{
public:
    Time(int, int, int);
    friend void display(Date &, Time &);
private:
    int hour;
    int minute;
    int sec;
};
class Date
{
public:
    Date(int, int, int);
    friend void display(Date &, Time &);
private:
    int month;
    int day;
    int year;
};
Time::Time(int h, int m, int s)
{
    hour = h;
    minute = m;
    sec = s;
}
Date::Date(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}
void display(Date &d, Time &t)
{

    cout << d.month << "/" << d.day << "/" << d.year << endl;
    cout << t.hour << ":" << t.minute << ":" << t.sec << endl;

}
void Chapter::_ch9_10()
{
    Time t1(10, 13, 56);
    Date d1(12, 25, 2004);
    display(d1, t1);
}


void Chapter::_doCh9(int _title)
{
    switch(_title)
    {
    case 4:
        _ch9_4();
        break;
    case 5:
        _ch9_5();
        break;
    case 8:
        _ch9_8();
        break;
    case 9:
        _ch9_9();
        break;
    case 10:
        _ch9_10();
        break;
    default:
        cout << "NO code!" << endl;
        break;
    }
}

#endif // _CHAPTER09_H_
