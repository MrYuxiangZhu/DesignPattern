// 访问者模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>

using namespace std;

class Element;//声明抽象内容

//抽象访问者，针对不同组件，提供不同的访问接口
class Visitor
{
public:
	Visitor() = default;
	virtual ~Visitor() = default;
	virtual void VisitCpu(Element* pElem) = 0;
	virtual void VisitGpu(Element* pElem) = 0;
	virtual void VisitDisk(Element* pElem) = 0;
};

//组成计算机的抽象组件
class Element
{
public:
	Element(string strName) : m_strName(strName) {}
	virtual ~Element() = default;
	string GetName() { return m_strName; }
	//组件接受访问者访问的接口
	virtual void AcceptVisitor(Visitor* visitor) = 0;
private:
	string m_strName;
};

//访问者实现类，实现各自的访问方法
class VisitorA : public Visitor
{
public:
	VisitorA() = default;
	~VisitorA() = default;
	void VisitCpu(Element* pElem)
	{
		printf("Visitor A CPU's name:%s\n", pElem->GetName().c_str());
	}
	void VisitGpu(Element* pElem)
	{
		printf("Visitor A GPU's name:%s\n", pElem->GetName().c_str());
	}
	void VisitDisk(Element* pElem)
	{
		printf("Visitor A DISK's name:%s\n", pElem->GetName().c_str());
	}
};

class VisitorB : public Visitor
{
public:
	VisitorB() = default;
	~VisitorB() = default;
	void VisitCpu(Element* pElem)
	{
		printf("Visitor B CPU's name:%s\n", pElem->GetName().c_str());
	}
	void VisitGpu(Element* pElem)
	{
		printf("Visitor B GPU's name:%s\n", pElem->GetName().c_str());
	}
	void VisitDisk(Element* pElem)
	{
		printf("Visitor B DISK's name:%s\n", pElem->GetName().c_str());
	}
};

//组件的实现类，调用访问者相应的访问方法
class CPU : public Element
{
public:
	CPU(string strName) : Element(strName) {}
	~CPU() = default;
	void AcceptVisitor(Visitor* visitor)
	{
		visitor->VisitCpu(this);
	}
};

class GPU : public Element
{
public:
	GPU(string strName) : Element(strName) {}
	~GPU() = default;
	void AcceptVisitor(Visitor* visitor)
	{
		visitor->VisitGpu(this);
	}
};

class Disk : public Element
{
public:
	Disk(string strName) : Element(strName) {}
	~Disk() = default;
	void AcceptVisitor(Visitor* visitor)
	{
		visitor->VisitDisk(this);
	}
};

//Computer类，由各组件组成，访问者访问Computer时将依次访问各组件
class Computer
{
public:
	Computer() = default;
	~Computer()
	{
		for (auto iter : m_list)
		{
			delete iter;
		}
	}

	void AddElement(Element* pElem)
	{
		m_list.push_back(pElem);
	}

	void DeleteElement(Element* pElem)
	{
		m_list.remove(pElem);
	}

	//访问者访问Computer时将依次访问各组件
	void AcceptVisitor(Visitor* visitor)
	{
		for (auto iter : m_list)
		{
			iter->AcceptVisitor(visitor);
		}
	}

private:
	list<Element*> m_list;
};

int main()
{
	Computer* pComputer = new Computer();
	pComputer->AddElement(new CPU("i9-10980XE"));
	pComputer->AddElement(new GPU("Titan RTX"));
	pComputer->AddElement(new Disk("HOF PRO M.2"));
	Visitor* pVisitorA = new VisitorA();
	Visitor* pVisitorB = new VisitorB();
	pComputer->AcceptVisitor(pVisitorA);
	pComputer->AcceptVisitor(pVisitorB);

	delete pVisitorA;
	delete pVisitorB;
	delete pComputer;
	return 0;
}
