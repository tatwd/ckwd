#include "Task.h"

#include <iostream>

Task::Task()
{
    //ctor
}

Task::~Task()
{
    //dtor
}

void Task::_doTask(int _chapter)
{
	std::cout << _chapter << std::endl;
}
