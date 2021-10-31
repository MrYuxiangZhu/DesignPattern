// 原型模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

class AbstractPrototype
{
public:
	AbstractPrototype() { strName = ""; }
	AbstractPrototype(string name) { strName = name; }
	virtual ~AbstractPrototype() {}
	virtual AbstractPrototype* clone() = 0;
	virtual void ReviseName(string name) { strName = name; }
	virtual void GetNameInfo() { cout << strName << endl; }
protected:
	string strName;
};

class ConcretePrototypeA : public AbstractPrototype
{
public:
	ConcretePrototypeA() {}
	ConcretePrototypeA(string name) : AbstractPrototype(name) {}
	~ConcretePrototypeA() {}
	AbstractPrototype* clone()
	{
		ConcretePrototypeA* pType = new ConcretePrototypeA();
		pType->strName = this->strName;
		return pType;
	}
};

class ConcretePrototypeB : public AbstractPrototype
{
public:
	ConcretePrototypeB() {}
	ConcretePrototypeB(string name) : AbstractPrototype(name) {}
	~ConcretePrototypeB() {}
	AbstractPrototype* clone()
	{
		ConcretePrototypeB* pType = new ConcretePrototypeB();
		pType->strName = this->strName;
		return pType;
	}
};

int main()
{
	//具体A克隆出B
	ConcretePrototypeA* pTypeA = new ConcretePrototypeA("ConcretePrototypeA");
	ConcretePrototypeB* pTypeB = reinterpret_cast<ConcretePrototypeB*>(pTypeA->clone());
	pTypeA->GetNameInfo();
	pTypeB->GetNameInfo();

	//具体B克隆出A
	pTypeB->ReviseName("ConcretePrototypeB");
	pTypeA = reinterpret_cast<ConcretePrototypeA*>(pTypeB->clone());
	pTypeA->GetNameInfo();
	pTypeB->GetNameInfo();
	return 0;
}
