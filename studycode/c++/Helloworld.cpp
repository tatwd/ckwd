#include <iostream>

using namespace std;

void main1() {
	cout << "Hell World!" << endl; 

	/*int a(10);
	cout << &a << endl;*/
	auto a = 1.9;
	auto b = 3.0/2;
	cout << a << " " << b << endl;

	//����auto����һ������
	//��������һ��ָ�볣��
	int num[4] = { 1, 2, 3, 4 };
	for (auto data : num){	//�ʺϱ���һά���飬auto�Զ�ѭ�������������鳣��
		cout << data << " ";
	}

	cin.get();	//��ͣ����
}

void main3(){
	//����const��ʼ������(c���Բ���)
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
	//int *p = (int *)&a;	//c���Է��ǿ��ת��������c++���޷��ı�a��const���� e.g: *p = 4;
	
	int *p = const_cast<int *>(&a);	//ǿ��ȥ��const����
	*p = 5;	//����ͨ��������ִ��
	cout << a << endl;

	cin.get();
}

void main(){
	
	int a = 2;			//����
	const int b = 3;	//����

	//p1,p2��ָ������ָ�������ָ������ݲ��ɸ�ֵ���䱾�����
	int const *p1(&a);
	const int *p2(&b);
	p1 = &a;
	p2 = &b;
	//error: *p1 = a;*p2 = b;

	//p1,p2��ָ�������ָ�볣��
	int * const p3(&a);		//��ʱp3ָ��a�ĵ�ַ�Ҳ��ɸı䣬��*p��ֵ�ɸ�
	//int * const p4(&b);	//���Ͳ�ƥ�䣬bΪconst����
	//*p3 = &a; //p3�ǳ�����&a�Ǳ���
	*p3 = 1;


	//p1,p2��ָ������ָ�볣��
	const int * const p5(&a);
	const int * const p6(&b);

	//ֻ����д int const *p
	//�ɶ���д int * const p �����ܿ��ַд
	//ֻ�� const int * const p �Ҳ��ɿ��ַ
	cin.get();
}