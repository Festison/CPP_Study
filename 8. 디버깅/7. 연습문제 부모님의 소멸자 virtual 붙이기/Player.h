#pragma once



class Player
{
public:
	Player();
	Player(int hp);

	virtual ~Player(); // 부모님의 소멸자에는 반드시 virtual을 붙여줘야 한다.

	void PrintInfo();

	void AddHp(int value);
	bool IsDead();

	int GetAttackDamage();

	void OnDamaged(Player* attacker);

public:

	int _hp;
	int _maxHp;
	int _attack;
};

