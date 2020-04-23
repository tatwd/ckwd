#ifndef _CHAPTER07_H_
#define _CHAPTER07_H_

#include <iostream>

#include "Chapter.h"

//t.3
struct Student{
    int num;
    string name;
    int score[3];

    void print();
    //Student input();
    void input();
};
void Student::print(){
    cout << num << "\t" << name << "\t";
    for(auto data:score)
        cout << data << "\t";
    cout << endl;
}
void Chapter::_ch7_3(){
    Student stu[5];

    stu[0] = {1, "Tom", {80, 75, 78}};
    stu[1] = {2, "Leo", {83, 75, 80}};
    stu[2] = {3, "Jam", {56, 80, 94}};
    stu[3] = {4, "Kim", {78, 75, 97}};
    stu[4] = {5, "Bob", {86, 65, 89}};

    cout << "num\tname\tsc[0]\tsc[1]\tsc[2]" << endl;
    cout << "=====================================" << endl;
    for(int i = 0;i<5;i++){
        //stu[i] = {1+i, "Leo", {80, 75, 90}};
        stu[i].print();
    }
}

//t.4
/*
Student Student::input(){
    Student s;
    cin >> s.num >> s.name >> s.score[0] >> s.score[1] >> s.score[2];
    return s;
}*/
//复用第9~23代码
void Student::input(){
    cin >> num >> name >> score[0] >> score[1] >> score[2];
}
void Chapter::_ch7_4(){
    Student stu[5];

    cout << "Please input informations of 5 students:" << endl;
    for(int i = 0;i  < 5;i++)
        stu[i].input();

    cout << "num\tname\tsc[0]\tsc[1]\tsc[2]" << endl;
    cout << "=====================================" << endl;
    for(int i = 0;i<5;i++)
        stu[i].print();
}

//t.6
struct student{
    int id;
    string name;
    struct student *next;
};
void Chapter::_ch7_6(){
    student stu1,stu2;
    student *head = NULL;
    student *p = NULL;

    stu1 = {11, "Leo"};
    stu2 = {12, "Bob"};

    head = &stu1;
    stu1.next = &stu2;
    stu2.next = NULL;

    p = head;
    cout << "id\tname" << endl;
    cout << "============" << endl;
    while(p != NULL){
        cout << p->id << "\t" << p->name << endl;
        p = p->next;
    }
}

//t.7
//复用了第66~70代码
void print(student *head){
    student *p = head;
    cout << "id\tname" << endl;
    cout << "============" << endl;
    while(p != NULL){
        cout << p->id << "\t" << p->name << endl;
        p = p->next;
    }
}
void Chapter::_ch7_7(){
    student s = {12, "leo"};
    print(&s);
}


void Chapter::_doCh7(int _title)
{
    switch(_title)
    {
    case 3:
        _ch7_3();
        break;
    case 4:
        _ch7_4();
        break;
    case 6:
        _ch7_6();
        break;
    case 7:
        _ch7_7();
        break;
    default:
        cout << "No code!" << endl;
        break;
    }
}

#endif // _CHAPTER07_H_
