#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<deque>
#include<set>
#include<algorithm>
using namespace std;

class Creature
{
public:
	virtual void Attack()
	{
		cout << "Creature!" << endl;
	}

};

class Player : public Creature
{
public:
	virtual void Attack() override // 재정의 할때 override 사용
	{
		cout << "Player!" << endl;
	}

	virtual void Attack() final // 더이상 override를 하고싶지 않을때 final 사용
	{
		cout << "Player!" << endl;
	}

};

class Knight : public Player
{
public:
	// 함수의 재정의 : 오버라이딩
	virtual void Attack() override 
	{
		cout << "Knight!" << endl;
	}

	// 오버로딩 : 함수 이름의 재사용
	void Attack(int a)
	{

	}

private:
	int _stamina = 100;

};

int main()
{
	Player* player = new Knight();

	player->Attack();

	return 0;

}