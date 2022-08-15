#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<deque>
#include<set>
#include<algorithm>
using namespace std;

class Pet
{

};

class Knight
{
public:
	Knight()
	{
		cout << "Knight()" << endl;
	}

	// 복사 생성자
	Knight(const Knight& knight)
	{
		cout << "const Knight&" << endl;
	}

	// 이동 생성자
	Knight(Knight&& knight)
	{

	}

	~Knight()
	{
		if (_pet)
			delete _pet;
	}
	
	// 복사 대입 연산자
	void operator =(const Knight& knight)
	{
		cout << "operator=(const Knight&)" << endl;

		_hp = knight._hp;

		if (knight._pet)
		{
			_pet = new Pet(*knight._pet);
		}

	}

	// 이동 대입 연산자
	void operator=(Knight&& knight) noexcept
	{
		cout << "operator=(Knight&&)" << endl;

		// 얕은 복사
		_hp = knight._hp;
		_pet = knight._pet;

		knight._pet = nullptr;

	}

public:
	int _hp = 100;
	Pet* _pet = nullptr;

};

void TestKnight_Copy(Knight knight) { }
void TestKnight_LValueRef(Knight& knight) { }
void TestKnight_ConstLValueRef(const Knight& knight) { }
void TestKnight_RValueRef(Knight&& knight) { } // 오른 값 참조 : 이동 대상(원본이 필요없다.)

int main()
{
	// 왼값(lvalue) vs 오른값(rvalue)
	// - lvalue : 단일식을 넘어서 계속 지속되는 개체 
	// - rvalue : lvalue가 아닌 나머지 (임시 값, 열거혀으 람다, i++ 등)

	Knight k1;

	TestKnight_Copy(k1);

	TestKnight_LValueRef(k1);

	TestKnight_LValueRef(Knight());

	TestKnight_ConstLValueRef(Knight());

	TestKnight_RValueRef(Knight());

	TestKnight_RValueRef(static_cast<Knight&&>(k1);

	Knight k2;
	k2._pet = new Pet();
	k2.hp = 1000;

	// 원본은 날려도 된다는 힌트를 준다.
	Knight k3;
	k3 = static_cast<Knight&&>(k2);

	k3 = std::move(k2); // 위에 static cast와 같은 의미 오른값 참조로 캐스팅

	Knight* k;
	std::unique_ptr<Knight> uptr = std::make_unique<Knight>(); // 하나만 있어야하는 함수 (복사 불가능)
	std::unique_ptr<Knight> uptr2 = std::move(uptr); // 오른값 참조로 이동으로 사용

	return 0;

}