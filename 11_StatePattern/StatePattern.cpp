// 状态模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

#define random(x)	(rand()%x)

class GameAccount;

class Level
{
public:
	Level() = default;
	Level(GameAccount* pGame);
	virtual ~Level();
	virtual void PlayCard();
	virtual void Play();
	virtual void DoubleScore() = 0;
	virtual void ChangeCards() = 0;
	virtual void PeekCards() = 0;
	virtual void UpgradeLevel() = 0;
public:
	GameAccount* pGameAccount;
};

Level::Level(GameAccount* pGame)
{
	pGameAccount = pGame;
}

class Primary : public Level
{
public:
	Primary() = default;
	Primary(GameAccount* pGame);
	~Primary() = default;
	void DoubleScore()	{ return; }
	void ChangeCards()	{ return; }
	void PeekCards()	{ return;}
	void UpgradeLevel();
};

class Secondary : public Level
{
public:
	Secondary() = default;
	~Secondary() = default;
	Secondary(GameAccount* pGame);
	void DoubleScore()	{ cout << "使用胜利双倍积分技能" << endl; }
	void ChangeCards()	{ return; }
	void PeekCards()	{ return; }
	void UpgradeLevel();
};

class Professional : public Level
{
public:
	Professional() = default;
	~Professional() = default;
	Professional(GameAccount* pGame);
	void DoubleScore()	{ cout << "使用胜利双倍积分技能" << endl; }
	void ChangeCards()	{ cout << "使用换牌技能" << endl; }
	void PeekCards()	{ return; }
	void UpgradeLevel();
};


class Final : public Level
{
public:
	Final() = default;
	~Final() = default;
	Final(GameAccount* pGame);
	void DoubleScore()	{ cout << "使用胜利双倍积分技能" << endl; }
	void ChangeCards()	{ cout << "使用换牌技能" << endl; }
	void PeekCards()	{ cout << "出老千技能" << endl; }
	void UpgradeLevel();
};

class GameAccount
{
public:
	__declspec(property(get = GetScore, put = SetScore))	int Score;
	GameAccount();
	GameAccount(string sName);
	~GameAccount();
	string GetName() { return strName; }
	void Winner();
	void Lose();
	void PlayCard();
	void SetLevel(Level* level);
	int GetScore() { return nScore; }
	void SetScore(int score) { nScore = score; }
private:
	Level* pLevel;
	int nScore;
	string strName;
};

Level::~Level()
{
	if (nullptr != pGameAccount)
	{
		delete pGameAccount;
	}
}

void Level::PlayCard()
{
	Play();
	DoubleScore();
	ChangeCards();
	PeekCards();
}

void Level::Play()
{
	cout << "使用基本技能" << endl;
}

Primary::Primary(GameAccount* pGame) : Level(pGame)
{
	pGameAccount->SetLevel(this);
}

void Primary::UpgradeLevel()
{
	if (pGameAccount->Score > 150) 
	{
		pGameAccount->SetLevel(new Secondary(pGameAccount));
		cout << "升级！ 级别：SECONDARY" << endl;
	}
	else
	{
		cout << endl;
	}
}

Secondary::Secondary(GameAccount* pGame) : Level(pGame)
{
	pGameAccount->SetLevel(this);
}

void Secondary::UpgradeLevel() 
{
	if (pGameAccount->Score < 150) 
	{
		pGameAccount->SetLevel(new Primary(pGameAccount));
		cout << "降级！ 级别：PRIMARY" << endl;
	}
	else if (pGameAccount->Score > 200) 
	{
		pGameAccount->SetLevel(new Professional(pGameAccount));
		cout << "升级！ 级别：PROFESSIONAL" << endl;
	}
};

Professional::Professional(GameAccount* pGame) : Level(pGame)
{
	pGameAccount->SetLevel(this);
}

void Professional::UpgradeLevel()
{
	if (pGameAccount->Score < 200)
	{
		pGameAccount->SetLevel(new Secondary(pGameAccount));
		cout << "降级！ 级别：SECONDARY" << endl;
	}
	else if (pGameAccount->Score > 250)
	{
		pGameAccount->SetLevel(new Final(pGameAccount));
		cout << "升级！ 级别：FINAL" << endl;
	}
};

Final::Final(GameAccount* pGame) : Level(pGame)
{
	pGameAccount->SetLevel(this);
}

void Final::UpgradeLevel()
{
	if (pGameAccount->Score < 250)
	{
		pGameAccount->SetLevel(new Professional(pGameAccount));
		cout << "降级！ 级别：PROFESSIONAL" << endl;
	}
	else
	{
		cout << "最高级别" << endl;
	}
};

GameAccount::GameAccount()
{
	cout << "创立游戏角色，积分：100，级别：PRIMARY" << endl;
	nScore = 100;
	strName = "none";
	pLevel = new Primary(this);
}

GameAccount::GameAccount(string sName)
{
	cout << "创立游戏角色，积分：100，级别：PRIMARY" << endl;
	nScore = 100;
	strName = sName;
	pLevel = new Primary(this);
}

GameAccount::~GameAccount()
{
	if (nullptr != pLevel)
	{
		delete pLevel;
	}
}

void GameAccount::SetLevel(Level* level)
{
	pLevel = level;
}

void GameAccount::PlayCard()
{
	pLevel->PlayCard();

	Sleep(100);
	srand((int)time(0));
	int res = random(2);
	if (res % 2 == 0)
	{
		Winner();
	}
	else
	{
		Lose();
	}

	pLevel->UpgradeLevel();
}

void GameAccount::Winner()
{
	if (Score < 200)
	{
		Score = Score + 50;
	}
	else
	{
		Score = Score + 100;
	}
	cout << "胜利，最新积分为 " << Score << endl;
}

void GameAccount::Lose()
{
	Score = Score + 30;
	cout << "输牌，最新积分为 " << Score << endl;
}

int main()
{
	GameAccount* jungle = new GameAccount("Jungle");

	for (int i = 0; i < 100; i++) 
	{
		printf("第%d局：\n", i + 1);
		jungle->PlayCard();
	}

	return 0;
}
