// 单例模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string.h>
#include <mutex>

using namespace std;

class SingleInstance
{
public:
	static SingleInstance* get_instance()
	{
		if (NULL == instance)
		{
			m_mutex.lock();
			instance = new SingleInstance();
			m_mutex.unlock();
		}

		return instance;
	}
private:
	SingleInstance() {}
	SingleInstance(const SingleInstance& a) {};
	SingleInstance& operator=(const SingleInstance& a) {};
	static SingleInstance* instance;
	static std::mutex m_mutex;
};

SingleInstance* SingleInstance::instance = NULL;
std::mutex SingleInstance::m_mutex;

int main()
{
	SingleInstance* s1 = SingleInstance::get_instance();
	SingleInstance* s2 = SingleInstance::get_instance();
	return 0;
}

