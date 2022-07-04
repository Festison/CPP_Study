#include<iostream>
using namespace std;

void Test(int a)
{
	a++;
}

void Test(char a[])
{
	a[0] = 'x';
}

int main()
{

	// test1[ 주소 ] << 8바이트
	const char* test1 = "Hello World";

	// test2 = 주소
	char test2[] = "Hello World";
	test2[0] = 'R';

	cout << test2 << endl;

	// 포인터는 [주소를 담는 바구니]
	// 배열은 [닭장] 데이터끼리 붙어있는 바구니 모음
	// [배열 이름]은 바구니 모음의 시작주소

	// 배열을 함수의 인자로 넘기게 된다면
	int a = 0;
	Test(a);
	cout << a << endl;

	Test(test2);
	cout << test2 << endl;

	return 0;
}
