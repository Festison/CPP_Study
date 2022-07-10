#include<iostream>
using namespace std;

// 객체지향
// 상속성, 은닉성 , 다형성

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// 메모리
//  [ [ Player ] ]
//  [   Knight   ]

// 상속 -> 부모님이 자식에게 유산을 물려주는 것

// 생성자/소멸자
// 생성자는 탄생을 기념해 호출되는 함수
// Knight를 생성하면 -> Player의 생성자 일까 Knight의 생성자일까?
// 둘다 호출

// GameObject
// - Creature : Player, Monster, Npc
// - Projectile : Arrow, Fireball
// - Env

class GameObject
{
public:
	int _objectId;
};
class Player : public GameObject
{
public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Player() 기본 생성자 호출" << endl;
	}

	Player(int hp)
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Player(int hp) 기본 생성자 호출" << endl;
	}

	~Player()
	{
		cout << "~Player() 소멸자 호출" << endl;
	}

	void Move() { cout << "Player Move 호출" << endl; }
	void Attack() { cout << "Player Attack 호출" << endl; }
	void Die() { cout << "Player Die 호출" << endl; }

public:
	int _hp;
	int _attack;
	int _defence;

};

class Knight : public Player // 기사가 플레이어를 상속 받는다.
{
public:
	Knight()
	{
		// 선처리 영역 여기서 player() 생성자를 호출
		_stamina = 100;
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	Knight(int stamina) : Player(100)
	{
		// Player(int hp) 생성자를 호출
		_stamina = stamina;
		cout << "Knight(int stamina) 기본 생성자 호출" << endl;
	}

	~Knight()
	{
		cout << "~Knight() 소멸자 호출" << endl;
	}

	// 재정의 상속을 무시하고 새로 정의
	void Move() { cout << "Knight Move 호출" << endl; } 
public:
	int _stamina;
};

class Mage : public Player
{
public:

public:
	int _mp;
};

int main()
{
	Knight k(100);

	k._hp = 100;
	k._attack = 10;
	k._defence = 5;
	k._stamina = 50;

	k.Move();
	k.Player::Move();

	k.Attack();
	k.Die();

	return 0;

}