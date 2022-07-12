#include<iostream>
using namespace std;

// 연산자 오버로딩 
// 일단 [연산자 함수]를 정의 해야한다.
// 함수도 멤버함수 VS 전역함수가 존재, 연산자 함수도 두가지 방식으로 만들 수 있다.

// - 멤버 연산자 함수 version
// - a op b 형태에서 왼쪽으로 기준으로 실행됨 (a가 클래스여야 가능. a를 '기준 피연산자' 라고 함)
// - 한계) a가 클래스가 아니면 사용 못함

// - 전역 연산자 함수 version
// - a op b 형태라면 a,b 모두를 연산자 함수의 피연산자로 만들어준다
// - 대표적으로 대입 연산자 (a = b)는 전역 연산자 version으로는 못 만든다.

// 복사 대입 연산자
// 대입 연산자 중, 자기 자신의 참조 타입을 인자로 받는 것

// 기타
// - 모든 연산자를 다 오버로딩 할 수 있는 것은 아니다 ( :: . , * 특수문자 불가능)
// - 모든 연산자가 다 2개 항이 있는 건 아니다. ++ --가 대표작 (단항 연산자)
// - 증감 연산자 ++ --
// - 전위 연산자 (++a) operator++()
// - 후위 연산자 (a++) operator++(int)

class Position
{
public:
	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;
		return pos;

	}

	Position operator+(int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;
		return pos;

	}

	// 대입 연산자 함수
	bool operator==(const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}

	// 복사 생성자 
	// 객체가 복사되기를 원하는 특징이있다.
	Position& operator=(Position& arg)
	{
		_x = arg._x;
		_y = arg._y;

		// Position* this = 내자신의 주소
		return *this; //실제 객체를 알수있다.
	}

	Position& operator++()
	{
		_x++;
		_y++;
		return *this;
	}

	Position operator++(int)
	{
		Position ret = *this;
		_x++;
		_y++;
		return ret;
	}

public:
	int _x;
	int _y;
};


// 전역 연산자 함수
Position operator+(int a, const Position& b)
{
	Position ret;

	ret._x = b._x + a;
	ret._y = b._y + a;

	return ret;
}

int main()
{
	int a = 1;
	int b = 2;
	int c = ++(++a);

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos._x = 1;
	pos._y = 1;

	Position pos3 = pos + pos2;

	Position pos4 = pos3 + 1;
	
	bool isSame = (pos3 == pos4);

	Position pos5;
	pos3._x=(pos5._x = 5); // 반드시 왼쪽에만 클래스가 등장하게 해야한다.

	pos3++;
	pos5.operator++(1);

	++(++pos3);

	return 0;

}