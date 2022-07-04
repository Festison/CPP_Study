#include<iostream>
using namespace std;

void SetHp(int* hp)
{
	*hp = 100;
}

int main()
{

	int hp = 1;
	SetHp(&hp);

	// 지금까지 사용한 방식
	// number라는 이름의 4바이트 정수 타입의 바구니를 만든다
	// number라는 변수 스택 메모리에 할당
	// number = 1라 함은, number 바구니에 1이라는 숫자를 넣으라는 의미이다
	// 따라서 스택 메모리에 있는 특정 주소(number 바구니)에 우리가 원하는 값을 넣은 셈
	// number는 비유하자면 메모리에 이름을 붙인 것 
	// 편리하지만 단점은 원본 수정이 필요할 때 불리하다

	int number = 1;
	
	// TYPE* 변수이름;
	// 일단 2가지 요소
	// - TYPE
	// - *

	// 바구니는 바구니인데 [주소를 저장하는 바구니이다]
	// 변수를 선언할 때 * 가 등장하면 -> 포인터 = 주소

	int* ptr=&number;

	// 주소로 가서 무엇인가를 해라
	// *변수이름 = 값;

	int value1 = *ptr;
	*ptr = 2;

	// TYPE은 왜 붙여줄까?
	// * = 포인터의 의미 = 주소를 저장하는 바구니 = 4 or 8 바이트 고정 크기

	// 주소에 가면 무엇이 있을까?
	// ex) 명함에 있는 주소 = 회사 주소
	// * = 포인터 (주소를 담는 바구니)


	// 타입의 불일치
	__int64* ptr2 = (__int64*)&number;

	*ptr2 = 0xAABBCCDDEEFF;

	return 0;

}
