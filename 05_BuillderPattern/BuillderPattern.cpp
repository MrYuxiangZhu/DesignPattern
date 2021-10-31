// 建造者模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

//实际房子
class House
{
public:
	House() {}
	~House() {}
	void SetArea(int area) { m_nAera = area; }
	void SetWall(string wall) { m_sWall = wall; }
	void SetRoof(string roof) { m_sRoof = roof; }
	//打印House信息
	void GetBulidInfo() 
	{
		cout << "Area: " << m_nAera << endl;
		cout << "Wall: " << m_sWall << endl;
		cout << "Roof: " << m_sRoof << endl;
	}

private:
	int m_nAera;
	string m_sWall;
	string m_sRoof;
};

//抽象建造者AbstractBuilder
class AbstractBuilder
{
public:
	AbstractBuilder() { m_pHouse = new House; }
	virtual ~AbstractBuilder() {}
	//抽象方法
	virtual void BuildArea() = 0;
	virtual void BuildWall() = 0;
	virtual void BuildRoof() = 0;
	virtual House* GetHouse() = 0;
protected:
	House* m_pHouse;
};

//具体建造者ConcreteBuilderA
class ConcreteBuilderA :public AbstractBuilder
{
public:
	ConcreteBuilderA() { cout << "ConcreteBuilderA" << endl; }
	//具体实现方法
	void BuildArea() { m_pHouse->SetArea(90);}
	void BuildWall() { m_pHouse->SetWall("Wall_A"); }
	void BuildRoof() { m_pHouse->SetRoof("Roof_A"); }
	House* GetHouse() { return m_pHouse; }
};

//具体建造者ConcreteBuilderB
class ConcreteBuilderB :public AbstractBuilder
{
public:
	ConcreteBuilderB() { cout << "ConcreteBuilderB" << endl; }
	//具体实现方法
	void BuildArea() { m_pHouse->SetArea(110); }
	void BuildWall() { m_pHouse->SetWall("Wall_B"); }
	void BuildRoof() { m_pHouse->SetRoof("Roof_B"); }
	House* GetHouse() { return m_pHouse; }
};

//指挥者Director
class Director
{
public:
	Director() {}
	~Director() {}
	//分配建筑者
	void AllocateBuilder(AbstractBuilder* builder) { m_pBuilder = builder; }
	//封装组装流程，返回建造结果
	House* CreateHouse()
	{
		m_pBuilder->BuildArea();
		m_pBuilder->BuildWall();
		m_pBuilder->BuildRoof();
		return m_pBuilder->GetHouse();
	}
private:
	AbstractBuilder* m_pBuilder;
};

int main()
{
	//抽象建造者
	AbstractBuilder* Builder = nullptr;
	//指挥者
	Director* Leader = new Director();
	//产品：House
	House* house = nullptr;

	//指定具体建造者A
	Builder = new ConcreteBuilderA();
	Leader->AllocateBuilder(Builder);
	house = Leader->CreateHouse();
	house->GetBulidInfo();

	//指定具体建造者B
	Builder = new ConcreteBuilderB();
	Leader->AllocateBuilder(Builder);
	house = Leader->CreateHouse();
	house->GetBulidInfo();

	system("pause");
	return 0;
}
