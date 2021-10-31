// 模板方法模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

class AbstractClass
{
public:
	virtual void PrimitiveOperation1() = 0;
	virtual void PrimitiveOperation2() = 0;
	void TemplateMethod();
	virtual ~AbstractClass() {}
};

class ConcreteClass1 :public AbstractClass
{
public:
	virtual void PrimitiveOperation1();
	virtual void PrimitiveOperation2();
	~ConcreteClass1() {}
};

class ConcreteClass2 :public AbstractClass
{
public:
	virtual void PrimitiveOperation1();
	virtual void PrimitiveOperation2();
	~ConcreteClass2() {}
};

void AbstractClass::TemplateMethod()
{
	//模板方法定义算法的骨架
	PrimitiveOperation1();
	PrimitiveOperation2();
}

void ConcreteClass1::PrimitiveOperation1()
{
	std::cout << "算法步骤1" << std::endl;
}

void ConcreteClass1::PrimitiveOperation2()
{
	std::cout << "算法步骤2" << std::endl;
}

void ConcreteClass2::PrimitiveOperation1()
{
	std::cout << "组成部分1" << std::endl;
}

void ConcreteClass2::PrimitiveOperation2()
{
	std::cout << "组成部分2" << std::endl;
}

int main()
{
	AbstractClass* AC1 = new ConcreteClass1();
	AC1->TemplateMethod();

	AbstractClass* AC2 = new ConcreteClass2();
	AC2->TemplateMethod();

	delete AC1;
	delete AC2;
}
