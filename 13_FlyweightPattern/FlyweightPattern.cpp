// 享元模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

/*【说明】*/
/*当系统中细粒度对象数量太多时，会导致运行代价过高，带来性能下降等问题。享元模式正是为解决这类问题而诞生的*/
/*在享元模式中通常出现工厂模式，需要创建一个享元工厂来负责维护一个单元池，用于存储具有相同内部状态的享元对象*/
/*享元对象能做到享元的关键是区分内部状态和外部状态*/
/*内部状态是存储在单元对象内部，并且不会随环境改变而改变的状态，因此内部状态可以共享*/
/*外部状态是随环境改变而改变的，不可以共享的状态。享元对象的外部状态必须由客户端保存，并在享元对象被创建之后，在需要使用的时候再传入到享元对象内部*/
/*【定义】*/
/*享元模式(Flyweight Pattern)：运用共享技术有效地支持大量细粒度对象的复用*/
/*【角色】*/
/*Flyweight：具有享元实现对象，必须是可共享的，需要封装单元对象的内部状态*/
/*FlyweightFactory：享元工厂，主要用来创建并管理共享的享元对象，并对外提供访问共享单元的接口*/
/*【意义】*/
/*享元模式的优点在于它可以极大减少内存中对象的数量，使得相同对象或者相似对象在内存中只保存一份*/
/*享元模式的缺点是使得系统更加复杂，需要分析出内部状态和外部状态，这使得程序逻辑复杂化，所以应当在多次重复使用享元对象时才值得使用享元模式*/

class FlyWeight
{
public:
	FlyWeight() = default;
	FlyWeight(string key) : m_key(key) {}
	virtual ~FlyWeight() = default;
	virtual void Operate(int value);
private:
	string m_key;
};

void FlyWeight::Operate(int value)
{
	printf("ConcreteFlyWeight m_key[%s], value[%d]\n", m_key.c_str(), value);
}

class FlyWeightFactory
{
public:
	FlyWeightFactory();
	~FlyWeightFactory();
	FlyWeight* GetFlyWeight(string key);
private:
	map<string, FlyWeight*> m_mapfly;
};

FlyWeight* FlyWeightFactory::GetFlyWeight(std::string key)
{
	std::map<std::string, FlyWeight*>::iterator it = m_mapfly.find(key);
	if (it != m_mapfly.end())
	{
		return it->second;
	}

	FlyWeight* fly = new FlyWeight(key);
	//m_mapfly.insert(pair<string, FlyWeight*>(key, fly));
	m_mapfly.insert(map<string, FlyWeight*>::value_type(key, fly));
	
	return fly;
}

FlyWeightFactory::FlyWeightFactory()
{

}

FlyWeightFactory::~FlyWeightFactory()
{
	for (auto iter = m_mapfly.begin(); iter != m_mapfly.end(); ++iter)
	{
		if (iter->second != nullptr)
		{
			delete iter->second;
			iter->second = nullptr;
		}
	}
}

int main()
{
	FlyWeightFactory* flyFactory = new FlyWeightFactory();

	FlyWeight* fly1 = flyFactory->GetFlyWeight("ABC");
	FlyWeight* fly2 = flyFactory->GetFlyWeight("DEF");
	FlyWeight* fly3 = flyFactory->GetFlyWeight("HIJ");
	FlyWeight* fly4 = flyFactory->GetFlyWeight("OPM");

	fly1->Operate(11);

	fly4->Operate(15);

	delete flyFactory;

	return 0;
}
