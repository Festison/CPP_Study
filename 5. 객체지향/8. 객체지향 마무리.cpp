#include<iostream>
using namespace std;

// 1) struct vs class

// C++에서는 struct나 class나 종이 한장 차이다.
// -> struct는 그냥 구조체 데이터의 묶음을 표현하는 용도
// -> class는 객체 지향 프로그래밍의 특징을 나타내는 용도

struct TestStruct // 기본 접근 지정자가 public
{
public:
	int _a;
	int _b;
};

class TestClass // 기본 접근 지정자가 private
{
private:
	int _a;
	int _b;
};

// 2) static 변수, static 함수 (static = 정적 = 고정된)

class Marine
{
public:
	// 특정 마린 객체에 종속적
	int _hp;

	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	static void SetAttack()
	{
		s_attack = 100;
	}

	// 특정 마린 객체와 무관
	// 마린이라는 '클래스' 자체와 연관
	static int s_attack; // 설계도상으로만 존재
};

// static 변수는 어떤 메모리인가?
// 초기화 하면 .data
// 초기화 안하면 .bss
int Marine:: s_attack = 0; //모든 마린의 공격력을 건드린다.

class Player
{
public:
	int _id; 
};

int GeneratedId()
{
	// 생명주기: 프로그램 시작/종료 (메모리에 항상 올라가 있다.)
	// 가시범위:

	// 정적 지역 객체
	static int s_id = 1;

	return s_id++;
}

int main()
{
	Marine m1;
	m1._hp = 40;
	m1.TakeDamage(10);
	Marine::s_attack = 6;

	Marine m2;
	m2._hp = 40;
	m2.TakeDamage(10);

	// 마린 공격력 업그레이드 완료! (Academy에서 업그레이드 완료)
	Marine::s_attack = 7;
	Marine::SetAttack();

	// 스택이아니라 .data 영역에 올라간다.
	static int id = 10;
	int a = id;

	cout << GeneratedId() << endl;
	cout << GeneratedId() << endl;
	cout << GeneratedId() << endl;
	cout << GeneratedId() << endl;
	cout << GeneratedId() << endl;

	return 0;

}