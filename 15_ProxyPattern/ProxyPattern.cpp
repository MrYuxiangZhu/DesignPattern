// 代理模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

//抽象主题角色
class Subject
{
public:
	Subject() = default;
	virtual ~Subject() = default;
	virtual void method() = 0;
};

//阵势主题角色
class RealSubject : public Subject
{
public:
	RealSubject() = default;
	void method()
	{
		cout << "业务方法" << endl;
	}
};

//代理类
class Proxy : public Subject
{
public:
	Proxy()
	{
		real_subject = new RealSubject();
	}
	~Proxy()
	{
		if (nullptr != real_subject)
		{
			delete real_subject;
			real_subject = nullptr;
		}
	}
	void method()
	{
		real_subject->method();
	}
private:
	RealSubject* real_subject;
};

int main()
{
	Subject* obj = new Proxy();
	obj->method();
	return 0;
}