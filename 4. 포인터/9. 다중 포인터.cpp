#include<iostream>
using namespace std;

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye"; // .rdata Bye주소[B][y][e][\0]
}

void Setmessage2(const char** a)
{
	*a = "Bye";
}

void Setmessage3(const char*& a) // 참조도 가능
{
	a = "Wow";
}

int main()
{
	int a = 0;
	SetNumber(&a);
	cout << a << endl;

	// msg[ Hello주소 ] << msg는 8바이트의 주소를 담는 바구니
	// .rdata Hello주소 [H][e][l][l][o][\0]
	const char* msg = "Hello";

	// [매개변수][RET][지역변수(msg(Hello 주소))][매개변수(a(Hello주소))][RET][지역변수]
	SetMessage(msg);
	cout << msg << endl;

	// 다중 포인터
	// 주소2 [ ] << 1바이트 // .rdata Hello주소 [H][e][l][l][o][\0]
	// 주소1[ Hello주소 ] << 8바이트 
	// pp [ &msg ] << 8바이트
	const char** pp = &msg;

	Setmessage2(&msg);
	cout << msg << endl;

	Setmessage3(msg);
	cout << msg << endl;

	return 0;
	
}