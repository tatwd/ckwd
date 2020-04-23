#ifndef CHAPTER_H
#define CHAPTER_H

#include <Task.h>

class Chapter : public Task
{
    public:
        Chapter(int,int);
        virtual ~Chapter();

        int _title;   //题号
        virtual void _doTask(int _chapter,int _title);  //重写做题虚函数

        //第1章
        virtual void _ch1_5();
        virtual void _ch1_6();
        virtual int  _ch1_7(int,int,int);
        virtual int  _ch1_9(int,int);
        virtual void _ch1_10(int,int,int);
        virtual void _doCh1(int);



        //第2章
        virtual void _ch2_3();
        virtual void _ch2_4();
        virtual void _ch2_7();
        virtual void _doCh2(int);

        //第3章
        virtual int  _ch3_12(int);
        virtual void _ch3_14(int, int, int, int);
        virtual int  _ch3_15(int, int, bool);
        virtual void _ch3_16();
        virtual int  _ch3_17(int);
        virtual int  _ch3_18(int);
        virtual void _ch3_19();
        virtual void _ch3_20(int);
        virtual double _ch3_21(int);
        virtual int  _ch3_22(int, int);
        virtual void _ch3_23();
        virtual void _ch3_24();
        virtual void _ch3_25();
        virtual void _doCh3(int);

        //第4章
        virtual void _ch4_1(int, int, int);
        virtual void _ch4_2();
        virtual int  _ch4_4(int, int, int);
        virtual void _ch4_12();
        virtual void _ch4_5();
        virtual void _ch4_7(int);
        virtual void _ch4_10(int);
        virtual double _ch4_8(double, int);
        virtual void _doCh4(int);

        //第5章
        virtual void _ch5_3();
        virtual void _ch5_4();
        virtual void _ch5_9(int, int, int);
        virtual void _ch5_10();
        virtual void _ch5_11();
        virtual void _ch5_15(int);
        virtual void _ch5_17();
        virtual void _doCh5(int);

        //第6章
        virtual void _ch6_4();
        virtual void _ch6_7();
        virtual void _ch6_11();
        virtual void _ch6_12();
        virtual void _ch6_15();
        virtual void _ch6_16();
        virtual void _ch6_17();
        virtual void _doCh6(int);

        //第7章
        virtual void _ch7_3();
        virtual void _ch7_4();
        virtual void _ch7_6();
        virtual void _ch7_7();
        virtual void _doCh7(int);

        //第8章
        virtual void _ch8_4();
        virtual void _ch8_5();
        virtual void _ch8_6();
        virtual void _doCh8(int);

        //第9章
        virtual void _ch9_4();
        virtual void _ch9_5();
        virtual void _ch9_8();
        virtual void _ch9_9();
        virtual void _ch9_10();
        virtual void _doCh9(int);


    protected:

    private:
};

#endif // CHAPTER_H
