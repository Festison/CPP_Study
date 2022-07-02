#include<iostream>
using namespace std;

struct StatInfo
{
	int hp; // +0
	int attack; // +4
	int defence; // +8
};

void CreateMonster(StatInfo* info);

void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5;
}

// 1) 값 전달 방식
// [매개변수][RET][지역변수(info)][매개변수(info)][RET][지역변수]
void PrintInfoByCopy(StatInfo info)
{
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
}

// 2) 주소 전달 방식
// [매개변수][RET][지역변수(info)][매개변수(&info)][RET][지역변수]
void PrintInfo(StatInfo* info)
{
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
}

// StatInfo 구조체가 1000바이트짜리 대형 구조체라면?
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사된다
// - (주소 전달) StatInfo*는 8바이트가 복사된다.
// - (참조 전달) StatInfo*는 8바이트가 복사된다.

// 3) 참조 전달 방식 
// 값 전달처럼 편리하게 사용
// 주소 전달처럼 주소값을 이용 일석이조
void PrintInfo(StatInfo& info)
{
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
}

int main()
{
	// 4바이트 정수형 바구니를 사용 
	// 바구니 이름을 number라고 한다.
	// number에서 뭘 꺼내거나 number에 뭘 넣는다고 하면 알아서 해당 주소(data, stack, heap)에 1을 넣어준다.
	int number = 1;

	// * 주소를 담는 바구니
	// int 그 바구니를 따라가면 int 바구니가 있다.
	int* pointer = &number;
	// pointer 바구니에 있는 주소를 타고 이동해서 멀리있는 바구니에 2를 넣는다.
	*pointer = 2;

	// 로우레벨(어셈블리) 관점에서 실제 작동 방식은 int*와 똑같음
	int& reference = number;

	// C++ 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것
	// number라는 바구니에 reference라는 다른 이름을 지어준다.
	// 앞으로 reference 바구니에다가 뭘 꺼내거나 넣을때
	// 실제 number 바구니에다 값을 꺼내거나 넣으면 된다.
	reference = 3;

	StatInfo info;
	CreateMonster(&info);

	PrintInfo(&info);
	PrintInfoByCopy(info);
	PrintInfo(info);

	cout << *pointer << endl;
	cout << number << endl;
	cout << reference << endl;

	return 0;
}