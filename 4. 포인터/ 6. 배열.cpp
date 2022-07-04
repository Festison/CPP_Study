#include<iostream>
using namespace std;

struct StatInfo
{
	int hp = 0xA;
	int attack = 0xB;
	int defence = 0xC;

};

int main()
{

	// 몬스터가 최대 1만마리
	// TYPE 이름[개수];

	// 배열의 크기는 상수여야 함

	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	int a = 10;
	int b = a;

	// 배열의 이름은 조금 다르게 작동
	// 배열의 이름은 곧 배열의 시작 주소
	// 정확히는 시작 위치를 가리키는 TYPE* 포인터
	auto WhoAml = monsters;

	// StatInfo [ 100,10,1 ] 
	// monster_0 [ 주소 ]
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// 포인터의 덧셈 StatInfo 타입 바구니 한개씩 이동하라는 의미
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// 포인터와 참조는 자유자재로 변환이 가능하다.
	// StatInfo[ ] StatInfo [ ] monster_2 [ ] 
	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// 세번째 데이터에 있는 내용물을 복사 temp [ 내용물 ]
	StatInfo temp;
	temp = *(monsters + 2);
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4;

	// 자동화
	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = 1 * (i + 1);
	}

	// 더 편한 방법으로는 인덱스가 있다.
	// 배열은 0번부터 시작 N번째 인덱스에 해당하는 데이터에 접근하려면 배열이름[N]
	// *(monsters + i) = monster[i]
	
	monsters[0].hp = 100;
	monsters[0].attack = 100;
	monsters[0].defence = 100;

	for (int i = 0; i < 10; i++)
	{
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 10 * (i + 1);
		monsters[i].defence = 1 * (i + 1);
	}

	// 배열 초기화 문법
	int numbers[5] = { 0,1,2,3 };
	cout << numbers << endl;

	

	return 0;
}
