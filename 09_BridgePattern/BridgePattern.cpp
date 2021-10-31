// 桥接模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

//抽象游戏
class Game
{
public:
	Game() = default;
	virtual ~Game() = default;
	virtual void Play() = 0;
};

//王者荣耀
class GameA : public Game
{
public:
	GameA() = default;
	~GameA() = default;
	void Play() { cout << "欢迎来到王者荣耀" << endl; }
};

//刺激战场
class GameB : public Game
{
public:
	GameB() = default;
	~GameB() = default;
	void Play() { cout << "欢迎来到刺激战场" << endl; }
};

//抽象手机
class Phone
{
public:
	Phone() = default;
	virtual ~Phone()
	{
		if (pGame)
		{
			delete pGame;
			pGame = nullptr;
		}
	}
	virtual void InstallGame(Game* game) = 0;
	virtual void Play() = 0;
protected:
	Game* pGame;
};

//苹果手机
class iPhone : public Phone
{	
public:
	iPhone() = default;
	~iPhone() = default;
	void InstallGame(Game* game)
	{
		pGame = game;
	}
	void Play()
	{
		pGame->Play();
	}
};

//华为手机
class Huawei : public Phone
{
public:
	Huawei() = default;
	~Huawei() = default;
	void InstallGame(Game* game)
	{
		pGame = game;
	}
	void Play()
	{
		pGame->Play();
	}
};

int main()
{
	Phone* phone = nullptr;
	Game* game = nullptr;
	//苹果手机安装王者荣耀
	phone = new iPhone();
	game = new GameA();
	phone->InstallGame(game);
	phone->Play();
	//华为手机安装刺激战场
	phone = new Huawei();
	game = new GameB();
	phone->InstallGame(game);
	phone->Play();
	return 0;
}
