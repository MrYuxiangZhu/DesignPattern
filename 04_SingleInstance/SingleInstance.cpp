#include <iostream>
#include <windows.h>

using namespace std;

HANDLE  g_Mutex = CreateMutex(NULL, FALSE, NULL);

class Singleton
{
public:
	~Singleton()
	{
		std::cout << "~Singleton" << std::endl;
		if (nullptr != m_pInstance)
		{
			delete m_pInstance;
		}
	}

	static Singleton* get_instance()
	{
		WaitForSingleObject(g_Mutex, INFINITE);

		if (nullptr == m_pInstance)
		{
			m_pInstance = new Singleton();
		}

		ReleaseMutex(g_Mutex);

		return m_pInstance;
	}

	void use() { cout << "use singleton" << endl; }

private:
	Singleton()
	{
		std::cout << "Singleton" << std::endl;
	}

	Singleton(Singleton&) = delete;//禁止调用该函数
	Singleton& operator=(const Singleton&) = delete;//禁止调用该函数
	static Singleton* m_pInstance;
};

Singleton* Singleton::m_pInstance = NULL;

DWORD WINAPI ThreadFunction1(LPVOID lpThreadParameter)
{
	Singleton* Instance1 = Singleton::get_instance();
	return 0;
}

DWORD WINAPI ThreadFunction2(LPVOID lpThreadParameter)
{
	Singleton* Instance2 = Singleton::get_instance();
	return 0;
}

int main()
{
	HANDLE hThread[2];
	hThread[0] = CreateThread(NULL, 0, ThreadFunction1, 0, 0, NULL);
	hThread[1] = CreateThread(NULL, 0, ThreadFunction2, 0, 0, NULL);
	WaitForMultipleObjects(2, hThread, true, INFINITE);

	return 0;
}