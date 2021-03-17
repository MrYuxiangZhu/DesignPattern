// 简单工厂模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

//抽象产品类Abstract_Sport_Product
class Abstract_Sport_Product
{
public:
	Abstract_Sport_Product() {}
	//抽象方法
	void print_name() {}
	void play() {}
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

	void print_name() { cout << "ZhuYuxiang get basket ball!" << endl; }
	void play() { cout << "ZhuYuxiang play basket ball" << endl; }
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

	void print_name() { cout << "ZhuYuxiang get foot ball!" << endl; }
	void play() { cout << "ZhuYuxiang play foot ball" << endl; }
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

	void print_name() { cout << "ZhuYuxiang get volley ball!" << endl; }
	void play() { cout << "ZhuYuxiang play volley ball" << endl; }
};

class Factory
{
public:
	Abstract_Sport_Product* get_sport_product(string product_name)
	{
		Abstract_Sport_Product* obj = NULL;
		if (product_name == "Basket_Ball")
		{
			obj = new Basket_Ball();
		}
		else if (product_name == "Foot_Ball")
		{
			obj = new Foot_Ball();
		}
		else if (product_name == "Volley_Ball")
		{
			obj = new Volley_Ball();
		}

		return obj;
	}
};

int main()
{
	cout << "简单工厂模式" << endl;
	Factory* factory = new Factory();
	Abstract_Sport_Product* product = NULL;
	product = factory->get_sport_product("Basket_Ball");
	product = factory->get_sport_product("Foot_Ball");
	product = factory->get_sport_product("Volley_Ball");
	return 0;
}

