#include "Chapter.h"

#include "Chapter01.h"  //第1章习题
#include "Chapter02.h"  //第2章习题
#include "Chapter03.h"  //第3章习题
#include "Chapter04.h"  //第4章习题
#include "Chapter05.h"  //第5章习题
#include "Chapter06.h"  //第6章习题
#include "Chapter07.h"  //第7章习题
#include "Chapter08.h"  //第8章习题
#include "Chapter09.h"  //第9章习题

#include <iostream>

Chapter::Chapter(int chapter,int title)
{
	_chapter = chapter;
	_title = title;
}

Chapter::~Chapter()
{
    //dtor
}

void Chapter::_doTask(int _chapter,int _title){

	cout << "Chapter:"<< _chapter << ","<< "Title:" << _title << endl;


	//根据不同的章节选择不同章节各自的做题函数 _doCh+章节号，通过它来调用每题。
    switch(_chapter)
    {
    case 1:
        _doCh1(_title);  //第1章
        break;
    case 2:
        _doCh2(_title);  //第2章
        break;
    case 3:
        _doCh3(_title);  //第3章
        break;
    case 4:
        _doCh4(_title);  //第4章
        break;
    case 5:
        _doCh5(_title);  //第5章
        break;
    case 6:
        _doCh6(_title);  //第6章
        break;
    case 7:
        _doCh7(_title);  //第7章
        break;
    case 8:
        _doCh8(_title);  //第8章
        break;
    case 9:
        _doCh9(_title);  //第9章
        break;

    //TODO

    default:
        cout << "no code!" << endl;
        break;
    }
}

