#include <iostream>
#include <thread>
using namespace std;

class A
{
public:
	int m_i;
	A(int a):m_i(a){cout<<"形参转换构造类A"<<endl;}
	A(const A ma):m_i(ma.m_i){cout<<"拷贝构造类A"<<endl;}
	~A(){cout<<"析构类A"<<endl;}
}

void myprint(A ma)
{
	cout<<"这个是线程函数"<<endl;
}

void main()
{
	int x=17;
	thread myobj(myprint,A(x));//显式转换类型
	//thread myobj(myprint,x); //隐式转换类型
	myobj.detach();
	//myobj.join();
	
	cout<<"main thread over!!!!"<<endl;
}