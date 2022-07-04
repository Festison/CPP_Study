#include<iostream>
using namespace std;

// 1) 주소 연산자 &
// 2) 산술 연산자 +, -
// 3) 간접 연산자 *
// 4) 간접 멤버 연산자 ->

struct Player
{
	int hp;
	int damage;
};

int main()
{
	int number = 1;

	// 1) 주소 연산자 &
	// - 해당 변수의 주소를 알려주세요 -
	// 해당 변수타입에 따라서 TYPE* 반환
	int* pointer = &number; // number의 주소 추출

	// 2) 산술 연산자 +, -

	number += 1;

	// int*
	// - * : 포인터 타입 8바이트 주소를 담는 바구니
	// - int : 주소를 따라가면 int 4바이트 정수형 바구니가 있다고 가정해라
	
	// 포인터에서 +나 -등 산술 연산으로 1을 더하거나 醯 그 숫자를 더하고 빼라는 의미가 아니다
	// 한번에 타입의 크기만큼을 이동해라
	// 다음/이전 바구니로 이동하고 싶다 << [바구니 단위]의 이동
	// 3을 더하면 = 바구니 3개를 이동시켜라

	pointer += 1; // int의 사이즈인 4바이트 만큼 주소값이 커진다.

	// 3) 간접 연산자 *
	// 해당 주소로 이동
	number = 3;
	*pointer = 3;

	Player player;
	player.hp = 100;
	player.damage = 10;

	Player* playerPtr = &player; // 구조체 타입의 포인터

	(*playerPtr).hp = 200; 
	(*playerPtr).damage = 200;

	// 4) 간접 멤버 연산자 ->
	// * 간접 연산자 해당 주소로 이동
	// . 구조체의 특정 멤버를 다룰 때 사용


	playerPtr->hp = 200;
	playerPtr->damage = 200;


	

	return 0;
}
