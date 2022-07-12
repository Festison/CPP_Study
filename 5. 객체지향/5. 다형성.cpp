#include<iostream>
using namespace std;


// 다형성 (Polymorphism) = 겉은 똑같은데 기능이 다르게 동작
// - 오버 로딩 : 함수 중복 정의 , 함수 이름의 재사용 
// - 오버 라이딩 : 재정의 , 부모 클래스 함수를 자식 클래스에서 재정의

// 바인딩 : 묶는다.
// - 정적 바인딩 : 컴파일 시점에 결정
// * - 동적 바인딩 : 실행 시점에 결정

// 일반 함수는 정적 바인딩을 기본으로 사용
// 동적 바인딩을 원한다면 -> 가상 함수 활용

// 실제 객체가 어떤 타입인지 어떻게 알고 알아서 가상함수를 호출해준걸까?
// - 가상 함수 테이블 
// .vftable [] 4바이트(32) 8바이트(64)
// [VMove] [VDie]

// 순수 가상 함수 : 구현은 없고 인터페이스만 전달하는 용도로 사용가능
// 추상 클래스 : 순수 가상 함수가 1개 이상 포함되면 바로 추상 클래스로 간주
// - 직접적으로 객체를 만들 수 없게 된다.

class Player
{
public:

	Player()
	{
		_hp = 100;
	}

	void Move() { cout << "Move Player !" << endl; }

	//void Move(int a){ cout << "Move Player (int) !" << endl; }
	
	virtual void VMove() { cout << "VMove Player !" << endl; }
	virtual void VDie() { cout << "VDie Player !" << endl; }

	// 순수 가상 함수
	virtual void VAttack() = 0;

public:
	int _hp;
};

class Knight : public Player
{
public:

	Knight()
	{
		_stamina = 10;
	}

	void Move() { cout << "Move Knight !" << endl; }

	// 가상 함수는 재정의를 하더라도 가상 함수이다.
	virtual void VMove() { cout << "VMove Knight !" << endl; } 
	virtual void VDie() { cout << "VDie Knight !" << endl; } 

	virtual void VAttack() { cout << "VAttack Knight !" << endl; }

public:
	int _stamina;
};

class Mage : public Player
{
public:
	int _mp;
};

//  [ [ Player ] ]
//  [   Knight   ]

// [ Player ]
void MovePlayer(Player* player)
{
	player->VMove();
	player->VDie();
}

void MoveKnight(Knight* knight)
{
	knight->Move();
}

int main()
{
	Player p;
	MovePlayer(&p);

	Knight k;
	MoveKnight(&k);
	MovePlayer(&k); // 기사는 플레이어다.

	return 0;

}