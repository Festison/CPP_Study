#include<iostream>
#include<stdlib.h>
#include"Player.h"
using namespace std;

int main()
{
	// Player는 몇 바이트?
	// int 2개 = 2 * 4 = 8 바이트 + sizeof(player*) = 12바이트

	// Player [ hp ] [ attack ] [ 주소 ]
	// sizeof(Monster*) = 4 or 8

	Player p1; // 지역 변수 (Stack)

	Player* p2 = new Player(); // 동적할당 (Heap)

	p1._target = p2;

	return 0;

}