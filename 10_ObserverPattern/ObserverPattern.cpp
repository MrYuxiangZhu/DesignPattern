#include <iostream>
#include <list>
using namespace std;

//抽象观察者
class AbstractObserver
{
public:
	virtual void Update(int) = 0;
};

//抽象目标
class AbstractSubject
{
public:
	virtual void Attach(AbstractObserver*) = 0;
	virtual void Detach(AbstractObserver*) = 0;
	virtual void Notify() = 0;
	virtual void SetState(int state) = 0;
};

//具体观察者1
class ConcreteObserver1 : public AbstractObserver
{
public:
	ConcreteObserver1(AbstractSubject* pSubject) : m_pSubject(pSubject) {}

	void Update(int value)
	{
		cout << "ConcreteObserver1 get the update. New State:" << value << endl;
	}

private:
	AbstractSubject* m_pSubject;
};

//具体观察者2
class ConcreteObserver2 : public AbstractObserver
{
public:
	ConcreteObserver2(AbstractSubject* pSubject) : m_pSubject(pSubject) {}

	void Update(int value)
	{
		cout << "ConcreteObserver2 get the update. New State:" << value << endl;
	}

private:
	AbstractSubject* m_pSubject;
};

//具体观察者3
class ConcreteObserver3 : public AbstractObserver
{
public:
	ConcreteObserver3(AbstractSubject* pSubject) : m_pSubject(pSubject) {}

	void Update(int value)
	{
		cout << "ConcreteObserver3 get the update. New State:" << value << endl;
	}

private:
	AbstractSubject* m_pSubject;
};

//具体目标
class ConcreteSubject : public AbstractSubject
{
public:
	void Attach(AbstractObserver* pObserver);
	void Detach(AbstractObserver* pObserver);
	void Notify();

	void SetState(int state)
	{
		m_iState = state;
	}

private:
	std::list<AbstractObserver*> m_ObserverList;
	int m_iState;
};

void ConcreteSubject::Attach(AbstractObserver* pObserver)
{
	m_ObserverList.push_back(pObserver);
}

void ConcreteSubject::Detach(AbstractObserver* pObserver)
{
	m_ObserverList.remove(pObserver);
}

void ConcreteSubject::Notify()
{
	if (!m_ObserverList.empty())
	{
		for (auto it = m_ObserverList.begin(); it != m_ObserverList.end(); ++it)
		{
			(*it)->Update(m_iState);
		}
	}
}

int main()
{
	// Create Subject
	AbstractSubject* pSubject = new ConcreteSubject();

	// Create Observer
	AbstractObserver* pObserver1 = new ConcreteObserver1(pSubject);
	AbstractObserver* pObserver2 = new ConcreteObserver2(pSubject);
	AbstractObserver* pObserver3 = new ConcreteObserver3(pSubject);

	// Change the state
	pSubject->SetState(2);

	// Register the observer
	pSubject->Attach(pObserver1);
	pSubject->Attach(pObserver2);
	pSubject->Attach(pObserver3);
	pSubject->Notify();

	// Unregister the observer
	pSubject->Detach(pObserver1);

	pSubject->SetState(3);
	pSubject->Notify();

	delete pObserver1;
	delete pObserver2;
	delete pObserver3;
	delete pSubject;
}