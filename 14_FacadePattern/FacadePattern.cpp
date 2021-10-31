// 外观模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

class Memory
{
public:
	Memory() = default;
	~Memory() = default;
	void SelfCheck()
	{
		cout << "......内存自检......" << endl;
	}
};

class CPU
{
public:
	CPU() = default;
	~CPU() = default;
	void Run()
	{
		cout << "......运行CPU......" << endl;
	}
};

class HardDisk
{
public:
	HardDisk() = default;
	~HardDisk() = default;
	void Write()
	{
		cout << "......写硬盘......" << endl;
	}
};

class System
{
public:
	System() = default;
	~System() = default;
	void Load()
	{
		cout << "......加载操作系统......" << endl;
	}
};

class Computer
{
public:
	Computer() 
	{
		memory = new Memory();
		cpu = new CPU();
		harddisk = new HardDisk();
		system = new System();
	}
	~Computer()
	{
		if (memory)
		{
			delete memory;
			memory = nullptr;
		}

		if (cpu)
		{
			delete cpu;
			cpu = nullptr;
		}

		if (harddisk)
		{
			delete harddisk;
			harddisk = nullptr;
		}

		if (system)
		{
			delete system;
			system = nullptr;
		}
	}
	void PowerOn()
	{
		cout << "正在开机......" << endl;
		memory->SelfCheck();
		cpu->Run();
		harddisk->Write();
		system->Load();
		cout << "加载完成......" << endl;
	}
private:
	Memory* memory;
	CPU* cpu;
	HardDisk* harddisk;
	System* system;
};

int main()
{
	Computer* computer = new Computer();
	computer->PowerOn();
	return 0;
}
