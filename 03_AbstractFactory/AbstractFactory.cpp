// 抽象工厂模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

//抽象产品类Abstract_Ball
class Abstract_Ball
{
public:
	Abstract_Ball() {}
	//抽象方法
	virtual void play() {};
};

//具体产品类Basket_Ball
class Basket_Ball : public Abstract_Ball
{
public:
	Basket_Ball()
	{
		play();
	}

	void play() { cout << "zhuyuxiang play basket ball" << endl; }
};

//具体产品类Foot_Ball
class Foot_Ball : public Abstract_Ball
{
public:
	Foot_Ball()
	{
		play();
	}

	void play() { cout << "zhuyuxiang play foot ball" << endl; }
};

//抽象产品类Abstract_Shirt
class Abstract_Shirt
{
public:
	Abstract_Shirt() {}
	//抽象方法
	virtual void wear_shirt() {}
};

//具体产品类Basket_Ball_Shirt
class Basket_Ball_Shirt : public Abstract_Shirt
{
public:
	Basket_Ball_Shirt()
	{
		wear_shirt();
	}

	//具体实现方法
	void wear_shirt()
	{
		cout << "zhuyuxiang wear basket ball shirt" << endl;
	}
};

//具体产品类Foot_Ball_Shirt
class Foot_Ball_Shirt : public Abstract_Shirt
{
public:
	Foot_Ball_Shirt()
	{
		wear_shirt();
	}

	//具体实现方法
	void wear_shirt()
	{
		cout << "zhuyuxiang wear foot ball shirt" << endl;
	}
};

//抽象工厂类Abstract_Factory
class Abstract_Factory
{
public:
	Abstract_Factory() {}
	virtual Abstract_Ball* get_ball_product() = 0;
	virtual Abstract_Shirt* get_shirt_product() = 0;
};

//具体工厂类Basket_Ball_Factory
class Basket_Ball_Factory : public Abstract_Factory
{
public:
	Basket_Ball_Factory() { cout << "Basket_Ball_Factory" << endl; }

	Abstract_Ball* get_ball_product()
	{
		cout << "zhuyuxinag get basket ball" << endl;
		return new Basket_Ball();
	}

	Abstract_Shirt* get_shirt_product()
	{
		cout << "zhuyuxiang get basket ball shirt" << endl;
		return new Basket_Ball_Shirt();
	}
};

//具体工厂类Foot_Ball_Factory
class Foot_Ball_Factory : public Abstract_Factory
{
public:
	Foot_Ball_Factory() { cout << "Foot_Ball_Factory" << endl; }

	Abstract_Ball* get_ball_product()
	{
		cout << "zhuyuxinag get foot ball" << endl;
		return new Foot_Ball();
	}

	Abstract_Shirt* get_shirt_product()
	{
		cout << "zhuyuxiang get foot ball shirt" << endl;
		return new Foot_Ball_Shirt();
	}
};

int main()
{
	Abstract_Factory* fac = NULL;
	Abstract_Ball* ball = NULL;
	Abstract_Shirt* shirt = NULL;

	fac = new Basket_Ball_Factory();
	ball = fac->get_ball_product();
	shirt = fac->get_shirt_product();
	delete fac;
	delete ball;
	delete shirt;

	fac = new Foot_Ball_Factory();
	ball = fac->get_ball_product();
	shirt = fac->get_shirt_product();
	delete fac;
	delete ball;
	delete shirt;

	return 0;
}
