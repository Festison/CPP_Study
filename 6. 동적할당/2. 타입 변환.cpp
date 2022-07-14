#include<iostream>
using namespace std;

class Knight
{
public:
	int _hp = 10;
};

class Dog
{
public:
	Dog() 
	{

	}

public:
	// 타입 변환 생성자
	Dog(const Knight& knight)
	{
		_age = knight._hp;
	}

	// 타입 변환 연산자
	operator Knight()
	{
		return (Knight)(*this);
	}

public:
	int _age = 1;
	int _cuteness = 2;
};

class BullDog : public Dog
{
public:
	bool _french; // 프렌치 불독
};

int main()
{
	// ----------- 타입 변환 유형 (비트열 재구성 여부) ----------

	// [1] 값 타입 변환
	// 특징) 의미를 유지하기 위해서, 원본 객체와 다른 비트열 재구성
	{
		int a = 123456789; // 2의 보수
		float b = (float)a; // 부동소수점(지수 + 유효숫자)
		cout << b << endl;
	}

	// [2] 참조 타입 변환
	// 특징) 비트열을 재구성하지않고 관점만 바꾸는 것
	{
		int a = 123456789; // 2의 보수
		float b = (float&)a; // 부동소수점(지수 + 유효숫자)
		cout << b << endl;
	}

	// ------------------ 안전도 분류 ------------------
	
	// [1] 안전한 변환
	// 특징) 의미가 항상 100% 완전히 일치하는 경우
	// 같은 타입이면서 크기만 더 큰 바구니로 이동
	// 작은 바구니 -> 큰 바구니로 이동 OK(업 캐스팅)
	// ex) char -> short, short -> int, int -> longlong
	{
		int a = 123456789;
		long long b = a;
		cout << b << endl;
	}

	// [2] 불안전한 변환 
	// 특징) 의미가 항상 100% 일치한다고 보장하지 못하는 경우
	// 타입이 다른경우
	// 같은 타입이지만 큰 바구니 -> 작은 바구니로 이동 (다운 캐스팅)
	{
		int a = 123456789;
		float b = a;
		short c = a;
		cout << b << endl;
		cout << c << endl;
	}

	// -------------- 프로그래머 의도에 따라 분류 -------------

	// [1] 암시적 변환
	// 특징) 이미 알려진 타입 변환 규칙에 따라서 컴파일러 자동으로 타입 변환
	{
		int a = 123456789;
		float b = a; //암시적으로 변환
		cout << b << endl;
	}

	// [2] 명시적 변환
	{
		int a = 123456789;
		int* b = (int*)a; // 명시적으로 변환 
		cout << b << endl;
	}

	// ---------------- 아무런 연관 관계가 없는 클래스 사이의 변환 ---------------

	// [1] 연관 없는 클래스 사이의 값 타입 변환
	// 특징) 일반적으로 불가능 (예외: 타입변환 생성자, 타입 변환 연산자를 이용해 가능)
	{
		Knight knight;
		Dog dog = (Dog)knight; // 타입 변환 생성자

		Knight knight2 = dog;  // 타입 변환 연산자
	}

	// [2] 연관없는 클래스 사이의 참조 타입 변환
	{
		Knight knight;
		// 어셈블리 : 포인터 = 참조
		// [ 주소 ] -> [ Dog ]
		Dog& dog = (Dog&)knight; // 명시적으로 타입 변환 가능
		dog._cuteness = 12;
	}

	// ---------------- 상속 관계에 있는 클래스 사이의 변환 ----------------------

	// [1] 상속 관계 클래스의 값 타입 변환

	{
		// 불독을 개로는 변환 가능 하지만 개를 불독으로는 변환 불가능
		BullDog bulldog;
		Dog dog = bulldog;
	}
	 
	// [2] 상속 관계 클래스의 참조 타입 변환
	// 특징) 자식 -> 부모 OK , 부모 -> 자식 명시적으로 OK
	{
		Dog dog;

		BullDog& bulldog = (BullDog&)dog; // 명시적으로 가능
		
		// [ age cuteness french ]
		BullDog bulldog;
		Dog& dog = bulldog;

	}

	// 결론)
	// [값 타입 변환] : 진짜 비트열도 바꾸고 논리적으로 말이 되게 바꾸는 변환
	// 논리적으로 말이 된다 예) BullDog -> Dog 
	// 논리적으로 말이 안된다 예) Dog -> BullDog, Dog -> Knight
	// [참조 타입 변환] : 비트열은 냅두고 우리의 관점만 바꾸는 변환
	// 명시적으로 가능하긴하다 하지만 암시적으로 해주는것이 안전성 여부에 좋다.

	return 0;

}