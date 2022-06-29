#include<iostream>
using namespace std;

int main()
{
	// while for - 동안에
	// // 한 번만 실행하는게 아니라 특정 조건까지 계쏙 반복해야 하는 상황에 사용
	// ex) 목적지에 도달할때까지 계속 이동해라

	int count = 0;

	while (count < 5 )
	{
		cout << "Hello world" << endl;
		count++;
	}

	do // while문과 다르게 블럭에 있는 내용이 한번은 출력
	{
		cout << "Hello world" << endl;
	} while (false);


	// for문
	// break; continue;

	for ( int count = 0; count < 5; count++)
	{
		cout << "Hello world" << endl;
	}

	// 루프문의 흐름 제어 break continue

	int round = 1;
	int hp = 100;
	int damage = 10;

	// 무한 루프 생성
	while (true)
	{
		hp -= damage;
		if (hp < 0)
			hp = 0; // 음수 체력을 0으로 보정

		// 시스템 메시지
		cout << "Round " << round << " 몬스터 체력 " << hp << endl;

		if (hp == 0)
		{
			cout << "몬스터 처치!" << endl;
			break;
		}

		if (round == 5)
		{
			cout << "제한 라운드 종료" << endl;
			break;
		}

		round++;
	}

	// 1~10 사이의 홀수만 출력하기

	for (int i = 1; i <=10; i++)
	{
		bool isEven = (i % 2) == 0;

		if (isEven)
			continue;
		
		cout << i << endl;
		
	}

	return 0;
}