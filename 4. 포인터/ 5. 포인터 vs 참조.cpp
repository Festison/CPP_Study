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

// 구지 없는 값을 사용 하는 이유
StatInfo* FindMonster()
{
	// TODO : Heap 영역에서 뭔가를 찾아본다.
	// 찾음
	// return monster;

	return nullptr;
	// 몬스터를 못찾음
}

StatInfo globalInfo;
// 1) 주소 전달 방식
// [매개변수][RET][지역변수(info)][매개변수(&info)][RET][지역변수]
void PrintInfo(const StatInfo* info)
{
	if (info==nullptr) // null 체크 크래쉬 문제 해결
	{
		return;
	}

	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;

	// 별 뒤에 붙인다면?
	// info라는 바구니의 주소를 바꿀 수 없다.
	// 주소값을 고정 시킨다.
	// info = &globalInfo;

	// 별 이전에 붙인다면?
	// info가 가리키고 있는 바구니의 내용물을 바꿀 수 없다.
	// info->hp = 10000;
}

// 2) 참조 전달 방식 
// 값 전달처럼 편리하게 사용
// 주소 전달처럼 주소값을 이용 일석이조
void PrintInfo(StatInfo const& info)
{
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;

	
}

int main()
{
	StatInfo info;
	CreateMonster(&info);
	// 1) 편의성 관련
	// 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 준다.
	// 참조는 자연스럽게 모르고 지나칠 수도 있다.
	// ex) 마음대로 고친다면 const를 사용해서 개선가능

	// 포인터도 const를 사용가능
	// * 기준으로 앞에 붙이냐 뒤에 붙이냐에 따라 의미가 달라진다.

	// 2) 초기화 여부
	// 참조 타입은 바구니의 2번째 이름
	// -> 참조하는 대상이 없으면 안됨
	// 포인터는 그냥 어떤 주소라는 의미
	// -> 대상이 실존하지 않을 수도 있다.
	// 포인터에서 '없다'는 의미 nullptr
	// 참조 타입은 이런 nullptr이 없다.

	StatInfo* pointer = nullptr;
	pointer = &info;
	PrintInfo(pointer);

	StatInfo& reference = info;
	PrintInfo(reference);

	// 없는 경우를 고려할 경우 pointer (null 체크 가능)
	// 바뀌지 않고 읽는 용도로만 사용하면 const ref&

	// 포인터로 사용하던걸 참조로 넘겨주려면?
	// PrintInfoByRef(*pointer);

	// 참조로 사용하던걸 포인터로 넘겨주러면?
	// PrintInfoByPtr(&reference);

	return 0;
}
