#include<iostream>
using namespace std;


// 데이터 연산


int a = 1;
int b = 2;

int main()
{
#pragma region 산술 연산
	// 산술 연산자
	// 대입연산
	
	a = b; //a 에 b를 대입하고 b 를 반환한다.

#pragma endregion
#pragma region 사칙 연산
	// 사칙연산
	a = b + 3; // 덧셈 add
	a = b - 3; // 뺼셈 sub
	a = b * 3; // 곱셈 mul
	a = b / 3; // 나눗셈 div
	a = b % 3; // 나머지 div

	a += 3; // a = a + 3;
	a -= 3;
	a *= 3;
	a /= 3;
	a %= 3;
#pragma endregion

	//증감 연산자 
	a = a + 1;
	a++; //후위 연산자
	++a; //전위 연산자
	a--;
	--a;

	b = a++; // b = a -> a를 1 증가
	b = ++a; // a를 1증가 -> b=a


	return 0;

}