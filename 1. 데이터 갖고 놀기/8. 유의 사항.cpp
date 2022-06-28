#include<iostream>
using namespace std;

// 오늘의 주제 : 유의 사항

// 1) 변수의 유효 범위

// 전역 변수
int hp = 77777;

// 스택
// { } 블록 내에서만 생존 
// 같은 이름을 두번 사용할 떄 문제

int main()
{
	// 지역 변수
	int mp = 10;
	cout << mp << endl;

	// 지역 변수는 두번 초기화 할시 오류 발생 
	int mp = 100;

	// 2) 연산 우선순위

	// 짝수 여부
	bool isEven = ((hp % 2) == 0); // 우선순위가 애매하다 싶을시 괄호 사용

	// 짝수거나 3으로 나뉘는 값인지
	bool isEvenOrDivBy3 = (hp % 2 == 0 || hp % 3 == 0);

	// 3) 타입 변환
	
	// 바구니 교체

	short hp2 = (short)hp; // 자료형이 생략 되어있다. 자료형의 크기 차이로 12241이라는 엉뚱한 값이 대입
	float hp3 = (float)hp; // 실수로 변환시 정밀도 차이가 있기 때문에 데이터 손실이 일어날 수 있다.
	unsigned int hp4 = (unsigned int)hp; // 비트 단위론 같지만 분석 방법이 달라 값에 오류가 생긴다.

	// 4 사칙연산 관련
	
	// 곱셈
	// - 오버플로우
	// int * int =int;
	1234123 * 12312323; // 값이 자료형의 크기를 넘어서 오버플로우 발생

	// 나눗셈
	// 0 나누기 조심
	// 실수 관련

	int maxHp = 0;
	float ratio = hp / maxHp; //자료형이 달라서 0,000 출력



	return 0;
}