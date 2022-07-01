#include<iostream>
using namespace std;

// 오늘의 주제 : 지역 변수와 값 전달

// 전역 변수 데이터 영역
// 참고) 초기화 여부, const 등 , rodata, data ,bss
int globalValue = 0;

void Test()
{
	cout << "전역 변수의 값은 : " << globalValue << endl;

}

void IncreaseHp(int hp)
{
	hp = hp + 1;
}

// [[매개변수][RET][지역변수(hp=1)] [매개변수(hp=2)][RET][지역변수]]
int main()
{
	cout << "전역 변수의 값은 : " << globalValue << endl;
	globalValue++;

	Test();

	// 지역 변수
	int localValue = 0;
	localValue++;

	int hp = 1;

	cout << "Increase 호출 전 : " << hp << endl;
	IncreaseHp(hp); //지역변수 int hp 가 우선이여서 hp주소에 1이 들어가있다.
	cout << "Increase 호출 후 : " << hp << endl;

	return 0;
}