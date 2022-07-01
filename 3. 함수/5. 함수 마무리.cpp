#include<iostream>
using namespace std;

// 오늘의 주제 : 함수 마무리

// 오버로딩 (중복 정의 : 함수 이름의 재사용)
// - 매개변수 갯수가 다르거나
// - 매개변수 타입이 다르거나 (순서가 다른걸 포함)

int Add(int a, int b)
{
	int result = a + b;
	return result;
}

float Add(float a, float b)
{
	float result = a + b;
	return result;
} 

// 기본 인자값
void SetPlayerInfo(int hp, int mp, int attack, int guildId=0) // 기본인수는 항상 마지막에 와야한다.
{
	
}

// 스택 오버플로우
int Factorial(int n)
{
	// 5! = 5*4*3*2*1
	// 1! = 1
	if (n <= 1)
		return 1;

	return n * Factorial(n - 1); // 예외적 처리가 필요
}

int main()
{
	float result = Add(1.5f, 2.1f);
	cout << result << endl;

	SetPlayerInfo(100, 40, 10);

	int fac = Factorial(1000000); // 크기가 너무커서 스택 프레임에 값이 전부 담기지 못한다.
	cout << fac << endl;

	return 0;
}