// 适配器模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

typedef enum
{
	ELECTRIC = 0,
	OPTICAL
}ADAPTER_TYPE;

//电机基类
class Adapter
{
public:
	Adapter() = default;
	virtual ~Adapter() = default;
	virtual void Driver() = 0;
};

//电能发动机
class ElectricMotor
{
public:
	ElectricMotor() = default;
	~ElectricMotor() = default;
	void ElectricDrive() { cout << "电能发动机驱动汽车" << endl; }
};

//光能发动机
class OpticalMotor
{
public:
	OpticalMotor() = default;
	~OpticalMotor() = default;
	void OpticalDriver() { cout << "光能发动机驱动汽车" << endl; }
};

class ElectricAdapter : public Adapter
{
public:
	ElectricAdapter()
	{
		pMotor = new ElectricMotor();
	}
	
	~ElectricAdapter()
	{
		if (pMotor)
		{
			delete pMotor;
			pMotor = nullptr;
		}
	}

	void Driver()
	{
		pMotor->ElectricDrive();
	}
private:
	ElectricMotor* pMotor;
};

class OpticalAdapter : public Adapter
{
public:
	OpticalAdapter()
	{
		pMotor = new OpticalMotor();
	}

	~OpticalAdapter()
	{
		if (pMotor)
		{
			delete pMotor;
			pMotor = nullptr;
		}
	}

	void Driver() 
	{
		pMotor->OpticalDriver();
	}

private:
	OpticalMotor* pMotor;
};

class AdapterFactory
{
public:
	static Adapter* CreateAdapter(ADAPTER_TYPE type)
	{
		switch (type)
		{
		case ADAPTER_TYPE::ELECTRIC:
			return new ElectricAdapter();
		case ADAPTER_TYPE::OPTICAL:
			return new OpticalAdapter();
		default:
			return nullptr;
		}
	}
};

int main()
{
	Adapter* pAdapter = nullptr;
	pAdapter = AdapterFactory::CreateAdapter(ELECTRIC);
	pAdapter->Driver();
	delete pAdapter;

	pAdapter = AdapterFactory::CreateAdapter(OPTICAL);
	pAdapter->Driver();
	delete pAdapter;
	
	return 0;
}
