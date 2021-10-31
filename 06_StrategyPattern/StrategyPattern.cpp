// 策略模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iostream>
using namespace std;

enum StrategyType
{
	StrategyA = 0,
	StrategyB,
	StrategyC
};
// The abstract strategy
class Strategy
{
public:
	virtual ~Strategy() {}			//必须定义虚析构函数，防止内存泄露
	virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
	void AlgorithmInterface()
	{
		cout << "ConcreteStrategyA." << endl;
	}
};

class ConcreteStrategyB : public Strategy
{
public:
	void AlgorithmInterface()
	{
		cout << "ConcreteStrategyB." << endl;
	}
};

class ConcreteStrategyC : public Strategy
{
public:
	void AlgorithmInterface()
	{
		cout << "ConcreteStrategyC." << endl;
	}
};

class StrategyFactory
{
public:
	static Strategy* create(StrategyType type)
	{
		switch (type)
		{
		case StrategyA:
			return new ConcreteStrategyA();
			break;
		case StrategyB:
			return new ConcreteStrategyB();
			break;
		case StrategyC:
			return new ConcreteStrategyC();
			break;
		default:
			return nullptr;
			break;
		}
	}
private:
};

int main()
{
	StrategyFactory::create(StrategyA)->AlgorithmInterface();
	StrategyFactory::create(StrategyB)->AlgorithmInterface();
	StrategyFactory::create(StrategyC)->AlgorithmInterface();
	return 0;
}