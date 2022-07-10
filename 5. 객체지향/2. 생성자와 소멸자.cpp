#include<iostream>
using namespace std;

// 생성자와 소멸자
// 클래스에 소속된 함수들을 멤버 함수라고 한다.
// 이 중에서 [시작] 과 [끝] 을 알리는 특별한 함수들이있다.
// 생성자 - (여려개 존재가능) 소멸자 - (한개만 존재)

// 암시적 생성자
// 생정자를 명시적으로 만들지 않으면 아무 인자도 받지않는 기본 생성자가 컴파일러에 의해 자동으로 만들어진다.
// 명시적으로 아무 생성자를 하나라도 만들면 자동으로 만들어지던 기본생성자는 더이상 만들어지지 않는다.

class Knight
{
public:
	// [1] 기본 생성자 (인자가 없다)
	Knight()
	{
		cout << "Knight() 기본 생성자 호출" << endl;

		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}

	// [2] 복사 생성자 (자기 자신의 클래스 참조 타입을 인자로 받음)
	// 일반적으로 똑같은 데이터를 지닌 객체가 생성되기를 기대한다.
	Knight(const Knight& Knight)
	{
		_hp = Knight._hp;
		_attack = Knight._attack;
		_posX = Knight._posX;
		_posY = Knight._posY;
	}

	// [3] 기타 생성자 
	// 인자를 1개만 받는 기타 생성자는 타입변환 생성자라고 부르기도 한다.
	explicit Knight(int hp)
	{
		cout << "Knight() 기본 생성자 호출" << endl;

		_hp = 100;
		_attack = 10;
		_posX = 0;
		_posY = 0;
	}
	
	Knight(int hp, int attack, int posX, int posY)
	{
		_hp = hp;
		_attack = attack;
		_posX = posX;
		_posY = posY;
	}

	// 소멸자
	~Knight()
	{
		cout << "Knight() 소멸자 호출" << endl;
	}
public:
	int _hp;
	int _attack;
	int _posY;
	int _posX;
};

int main()
{
	Knight k1(100, 10, 0, 0);

	Knight k2(k1); // 복사 생성자

	Knight k3 = k1; // 보사 생성자

	Knight k4; // 생성자
	k4 = k1; // 복사

	// 암시적 형변환 -> 컴파일러가 알아서 바꿔준다.
	int num = 1;

	float f = (float)num; // 명시적 - 우리가 코드로 num을 float 바구니에 넣으라고 주문하고 있다.
	double d = num; // 암시적 컴파일러가 알아서 처리

	Knight k5;
	k5 = (Knight)1;

	return 0;

}