#pragma once

class Knight
{
public:
	Knight();
	Knight(int hp);
	~Knight();

	void PrintInfo();

	void AddHp(int value);
	bool IsDead();

public:
	int _hp; // 오버플로우 떄문에 체력이 음수로간다.
	int _attack;
};

