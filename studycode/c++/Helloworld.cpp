#include <iostream>

using namespace std;

void main1() {
	cout << "Hell World!" << endl; 

	/*int a(10);
	cout << &a << endl;*/
	auto a = 1.9;
	auto b = 3.0/2;
	cout << a << " " << b << endl;

	//利用auto遍历一个数组
	//数组名是一个指针常量
	int num[4] = { 1, 2, 3, 4 };
	for (auto data : num){	//适合遍历一维数组，auto自动循环，必须是数组常量
		cout << data << " ";
	}

	cin.get();	//暂停窗口
}

void main3(){
	//利用const初始化数组(c语言不能)
	const int n = 5;
	int a[n];
	int i = 0;
	for (auto data : a){
		data = i++;
		cout << data << " ";
	}

	cin.get();
}

void main4(){
	const int a = 2;
	//int *p = (int *)&a;	//c语言风格强制转换，但在c++中无法改变a的const属性 e.g: *p = 4;
	
	int *p = const_cast<int *>(&a);	//强制去掉const属性
	*p = 5;	//编译通过，但不执行
	cout << a << endl;

	cin.get();
}

void main(){
	
	int a = 2;			//变量
	const int b = 3;	//常量

	//p1,p2是指向常量的指针变量，指向的数据不可赋值，其本身可以
	int const *p1(&a);
	const int *p2(&b);
	p1 = &a;
	p2 = &b;
	//error: *p1 = a;*p2 = b;

	//p1,p2是指向变量的指针常量
	int * const p3(&a);		//此时p3指向a的地址且不可改变，但*p的值可改
	//int * const p4(&b);	//类型不匹配，b为const常量
	//*p3 = &a; //p3是常量，&a是变量
	*p3 = 1;


	//p1,p2是指向常量的指针常量
	const int * const p5(&a);
	const int * const p6(&b);

	//只读不写 int const *p
	//可读可写 int * const p 但不能跨地址写
	//只读 const int * const p 且不可跨地址
	cin.get();
}