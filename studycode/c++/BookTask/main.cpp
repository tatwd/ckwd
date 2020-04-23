#include <iostream>

#include "Task.h"
#include "Chapter.h"

/**
 *  每章节的习题存放在 Chapter+章节号.h 中
 *  其中的函数命名格式为：_ch+章节号+_题号
 *  @anthor RastingPasser
 */

//主函数入口
int main()
{
    //创建一个章节对象，传入章节号和题号
	Chapter ch(9, 10);

	ch._doTask(ch._chapter,ch._title);

	return 0;
}
