// 工厂方法模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

//抽象产品类Abstract_Sport_Product
class Abstract_Sport_Product
{
public:
	Abstract_Sport_Product() {}
	//抽象方法
	virtual void print_name() {}
	virtual void play() {}
};

//具体产品类Basket_Ball
class Basket_Ball : public Abstract_Sport_Product
{
public:
	Basket_Ball() 
	{
		print_name();
		play();
	}

	//具体实现方法
	void print_name() { cout << "ZhuYuxiang get basket ball!" << endl; }
	void play() { cout << "ZhuYuxiang play basket ball!" << endl; }
};

//具体产品类Foot_Ball
class Foot_Ball : public Abstract_Sport_Product
{
public:
	Foot_Ball()
	{
		print_name();
		play();
	}

	//具体实现方法
	void print_name() { cout << "ZhuYuxiang get foot ball!" << endl; }
	void play() { cout << "ZhuYuxiang play foot ball!" << endl; }
};

//具体产品类Volley_Ball
class Volley_Ball : public Abstract_Sport_Product
{
public:
	Volley_Ball()
	{
		print_name();
		play();
	}

	//具体实现方法
	void print_name() { cout << "ZhuYuxiang get volley ball!" << endl; }
	void play() { cout << "ZhuYuxiang play volley ball!" << endl; }
};

//定义抽象工厂类Abstract_Factory
class Abstract_Factory
{
public:
	virtual Abstract_Sport_Product* get_sport_product() = 0;
};

//具体工厂类Basket_Ball_Factory
class Basket_Ball_Factory : public Abstract_Factory
{
public:
	Basket_Ball_Factory() { cout << "Create Basket_Ball_Factory!" << endl; }
	Abstract_Sport_Product* get_sport_product() 
	{
		cout << "basket ball!" << endl;
		return new Basket_Ball();
	}
};

//具体工厂类Foot_Ball_Factory
class Foot_Ball_Factory : public Abstract_Factory
{
public:
	Foot_Ball_Factory() { cout << "Create Foot_Ball_Factory!" << endl; }
	Abstract_Sport_Product* get_sport_product()
	{
		cout << "foot ball!" << endl;
		return new Foot_Ball();
	}
};

//具体工厂类Volley_Ball_Factory
class Volley_Ball_Factory : public Abstract_Factory
{
public:
	Volley_Ball_Factory() { cout << "Create Volley_Ball_Factory!" << endl; }
	Abstract_Sport_Product* get_sport_product()
	{
		cout << "volley ball!" << endl;
		return new Volley_Ball();
	}
};

int main()
{
	cout << "工厂方法模式!" << endl;

	//定义工厂类对象和产品类对象
	Abstract_Factory* fac = NULL;
	Abstract_Sport_Product* product = NULL;

	fac = new Basket_Ball_Factory();
	product = fac->get_sport_product();

	fac = new Foot_Ball_Factory();
	product = fac->get_sport_product();

	fac = new Volley_Ball_Factory();
	product = fac->get_sport_product();
	
	return 0;
}
